// ==========================================================================
//                 SeqAn - The Library for Sequence Analysis
// ==========================================================================
// Copyright (c) 2006-2010, Knut Reinert, FU Berlin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Knut Reinert or the FU Berlin nor the names of
//       its contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL KNUT REINERT OR THE FU BERLIN BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ==========================================================================
// Author: Manuel Holtgrewe <manuel.holtgrewe@fu-berlin.de>
// ==========================================================================
// Journal entries implementation using a sorted string of journal elements.
// ==========================================================================

#ifndef SEQAN_SEQUENCE_JOURNALED_JOURNAL_ENTRIES_SORTED_ARRAY_H_
#define SEQAN_SEQUENCE_JOURNALED_JOURNAL_ENTRIES_SORTED_ARRAY_H_

namespace seqan {

// ============================================================================
// Tags, Classes
// ============================================================================

// Tag: SortedArray.
struct SortedArray {};


template <typename TNode, typename TTreeSpec>
class JournalEntries;


template <typename TCargo_>
class JournalEntries<TCargo_, SortedArray>
{
public:
    typedef TCargo_ TCargo;
    typedef typename Size<TCargo>::Type TSize;

    String<TCargo> _journalNodes;
    TSize _originalStringLength;

    JournalEntries() : _originalStringLength(0) {}
};

// ============================================================================
// Metafunctions
// ============================================================================

template <typename TCargo>
struct Iterator<JournalEntries<TCargo, SortedArray>, Standard>
{
    typedef typename Iterator<String<TCargo>, Standard>::Type Type;
};


template <typename TCargo>
struct Iterator<JournalEntries<TCargo, SortedArray> const, Standard>
{
    typedef typename Iterator<String<TCargo> const, Standard>::Type Type;
};

template <typename TCargo>
struct Value<JournalEntries<TCargo, SortedArray> >
{
    typedef TCargo Type;
};

template <typename TCargo>
struct Value<JournalEntries<TCargo, SortedArray> const>
{
    typedef TCargo const Type;
};

template <typename TCargo>
struct Reference<JournalEntries<TCargo, SortedArray> >
{
    typedef TCargo & Type;
};

template <typename TCargo>
struct Reference<JournalEntries<TCargo, SortedArray> const>
{
    typedef TCargo const & Type;
};

// ============================================================================
// Functions
// ============================================================================

template <typename TStream, typename TNode>
inline
TStream &
operator<<(TStream & stream, JournalEntries<TNode, SortedArray> const & tree)
{
    stream << "JournalEntries(";
    for (unsigned i = 0; i < length(tree._journalNodes); ++i) {
        if (i > 0) stream << ", ";
        stream << tree._journalNodes[i];
    }
    stream << ")";
    return stream;
}

template <typename TCargo>
bool _checkSortedArrayTree(JournalEntries<TCargo, SortedArray> const & tree)
{
    SEQAN_CHECKPOINT;
    typedef typename Iterator<String<TCargo> const, Standard>::Type TIterator;
    if (length(tree._journalNodes) == 0)
        return true;
    if (tree._journalNodes[0].virtualPosition != 0)
        return false;
    if (tree._journalNodes[0].length == 0)
        return false;
    for (TIterator it = begin(tree._journalNodes, Standard()) + 1, itend = end(tree._journalNodes, Standard()); it != itend; ++it) {
		if (it->length == 0)
			return false;
        if ((it - 1)->virtualPosition >= it->virtualPosition)
            return false;
        if ((it - 1)->virtualPosition + (it - 1)->length != it->virtualPosition)
            return false;
    }
	return true;
}

template <typename TCargo>
typename Iterator<JournalEntries<TCargo, SortedArray>, Standard>::Type
begin(JournalEntries<TCargo, SortedArray> & journalTree, Standard const &)
{
    SEQAN_CHECKPOINT;
    return begin(journalTree._journalNodes, Standard());
}


template <typename TCargo>
typename Iterator<JournalEntries<TCargo, SortedArray> const, Standard>::Type
begin(JournalEntries<TCargo, SortedArray> const & journalTree, Standard const &)
{
    SEQAN_CHECKPOINT;
    return begin(journalTree._journalNodes, Standard());
}


template <typename TCargo>
typename Iterator<JournalEntries<TCargo, SortedArray>, Standard>::Type
end(JournalEntries<TCargo, SortedArray> & journalTree, Standard const &)
{
    SEQAN_CHECKPOINT;
    return end(journalTree._journalNodes, Standard());
}


template <typename TCargo>
typename Iterator<JournalEntries<TCargo, SortedArray> const, Standard>::Type
end(JournalEntries<TCargo, SortedArray> const & journalTree, Standard const &)
{
    SEQAN_CHECKPOINT;
    return end(journalTree._journalNodes, Standard());
}


template <typename TCargo>
inline
void reinit(JournalEntries<TCargo, SortedArray> & tree,
            typename Size<TCargo>::Type originalStringLength)
{
    SEQAN_CHECKPOINT;
    clear(tree._journalNodes);
    appendValue(tree._journalNodes, TCargo(TCargo(SOURCE_ORIGINAL, 0, 0, originalStringLength)));
    tree._originalStringLength = originalStringLength;
}


template <typename TCargo>
inline
typename Iterator<JournalEntries<TCargo, SortedArray> const, Standard>::Type 
findInJournalEntries(JournalEntries<TCargo, SortedArray> const & journalEntries,
                     typename Position<TCargo>::Type const & pos) {
    typedef typename Size<TCargo>::Type TSize;
    typedef typename Position<TCargo>::Type TPos;
    typedef typename Iterator<String<TCargo>, Standard>::Type TIterator;
    typedef JournalEntryLtByVirtualPos<TPos, TSize> TCmp;

    TCargo refCargo;
    refCargo.virtualPosition = pos;
    TIterator iter = std::upper_bound(begin(journalEntries._journalNodes, Standard()),
                                      end(journalEntries._journalNodes, Standard()),
                                      refCargo,
                                      TCmp());
    SEQAN_ASSERT(iter != begin(journalEntries._journalNodes, Standard()));
    iter -= 1;

    SEQAN_ASSERT(iter != end(journalEntries._journalNodes, Standard()));

    return iter;
}


template <typename TCargo>
inline
TCargo const &
findJournalEntry(JournalEntries<TCargo, SortedArray> const & journalEntries,
                 typename Position<TCargo>::Type const & pos) {
    return *findInJournalEntries(journalEntries, pos);
}


template <typename TCargo>
inline
void recordInsertion(JournalEntries<TCargo, SortedArray> & tree,
                     typename Position<TCargo>::Type const & virtualPosition,
                     typename Position<TCargo>::Type const & physicalBeginPos,
                     typename Size<TCargo>::Type const & len)
{
    SEQAN_CHECKPOINT;
    typedef typename Size<TCargo>::Type TSize;
    typedef typename Position<TCargo>::Type TPos;
    typedef typename Iterator<String<TCargo>, Standard>::Type TIterator;
    typedef JournalEntryLtByVirtualPos<TPos, TSize> TCmp;

	//std::cerr << __FILE__ << ":" << __LINE__ << " -- INSERT(" << virtualPosition << ", " << physicalBeginPos << ", " << len << ")" << std::endl;
    //std::cerr << __FILE__ << ":" << __LINE__ << " -- " << tree << std::endl;

    // Handle special case that the entry list is empty.
    if (empty(tree._journalNodes)) {
        SEQAN_ASSERT_EQ(virtualPosition, 0u);
        if (len == 0)
            return;
        appendValue(tree._journalNodes, TCargo(SOURCE_PATCH, physicalBeginPos, virtualPosition, len));
        return;
    }

    // Find position in sorted array of nodes to insert in.
    TCargo refCargo;
    refCargo.virtualPosition = virtualPosition;
    TIterator iter = std::upper_bound(begin(tree._journalNodes, Standard()),
                                      end(tree._journalNodes, Standard()),
                                      refCargo,
                                      TCmp());
    // TODO(holtgrew): Maybe move and update entries right of pos at the same time?
    
	// MUST NOT find begin.
	SEQAN_ASSERT(iter != begin(tree._journalNodes, Standard()));
	--iter;
	
    // Create new journal entries.
    String<TCargo> buffer;
    reserve(buffer, 3, Exact());
	if (iter->virtualPosition + iter->length > virtualPosition) {
		TPos pos = iter - begin(tree._journalNodes, Standard());
		TPos shiftRightOf = pos;
        // Found node that contains virtualPos.
        SEQAN_ASSERT_LEQ(iter->virtualPosition, virtualPosition);
        if (iter->virtualPosition == virtualPosition) {
            // Simple case:  Insert left of iter.
            insertValue(tree._journalNodes, pos, TCargo(SOURCE_PATCH, physicalBeginPos, virtualPosition, len));
			shiftRightOf += 1;
        } else {
            // Harder case:  Split current and insert new node.
            TPos offset = virtualPosition - iter->virtualPosition;
            appendValue(buffer, TCargo(iter->segmentSource, iter->physicalPosition, iter->virtualPosition, offset));
            appendValue(buffer, TCargo(SOURCE_PATCH, physicalBeginPos, virtualPosition, len));
            appendValue(buffer, TCargo(iter->segmentSource, iter->physicalPosition + offset, virtualPosition + len, iter->length - offset));
            // Insert new journal entries.
            infix(tree._journalNodes, pos, pos + 1) = buffer;
			shiftRightOf += 3;
        }
        // Update journal entries right of pos.
        for (TIterator it = begin(tree._journalNodes, Standard()) + shiftRightOf, itend = end(tree._journalNodes, Standard()); it != itend; ++it)
            it->virtualPosition += len;
    } else {
        // Insert at end.
		SEQAN_ASSERT_EQ(virtualPosition, iter->virtualPosition + iter->length);
        appendValue(tree._journalNodes, TCargo(SOURCE_PATCH, physicalBeginPos, virtualPosition, len));
    }
    //std::cerr << __FILE__ << ":" << __LINE__ << " -- " << tree << std::endl;

    SEQAN_ASSERT(_checkSortedArrayTree(tree));
}

template <typename TCargo>
inline
void recordErase(JournalEntries<TCargo, SortedArray> & tree,
                 typename Position<TCargo>::Type const & pos,
                 typename Position<TCargo>::Type const & posEnd)
{
    SEQAN_CHECKPOINT;
    typedef typename Size<TCargo>::Type TSize;
    typedef typename Position<TCargo>::Type TPos;
    typedef typename Iterator<String<TCargo>, Standard>::Type TIter;
    typedef JournalEntryLtByVirtualPos<TPos, TSize> TCmp;
//	std::cerr << __FILE__ << ":" << __LINE__ << " -- ERASE(" << pos << ", " << posEnd << ")" << std::endl;
//    std::cerr << __FILE__ << ":" << __LINE__ << " -- " << tree << std::endl;

    // Handle special case of removing all of the singleton existing entry.
    if (length(tree._journalNodes) == 1 && pos == 0 && front(tree._journalNodes).length == posEnd) {
        clear(tree._journalNodes);
        return;
    }
    // Handle case of an empty journal.
    if (length(tree._journalNodes) == 0) {
        SEQAN_ASSERT_EQ(pos, 0u);
        SEQAN_ASSERT_EQ(posEnd, 0u);
        return;
    }

    // Find node.
    TCargo refCargo;
    refCargo.virtualPosition = pos;
    TIter it = std::upper_bound(
            begin(tree._journalNodes, Standard()),
            end(tree._journalNodes, Standard()),
            refCargo,
            TCmp());

    // We will shift the virtual positions of all entries right of and
    // including beginShiftPos by delta positions to the left.
    TPos delta = 0;
    TPos beginShiftPos = 0;

	// MUST NOT find begin.
	SEQAN_ASSERT(it != begin(tree._journalNodes, Standard()));
	--it;
	
	TPos itPos = it - begin(tree._journalNodes, Standard());
	if (it->virtualPosition == pos && it->length == posEnd - pos) {
		// Remove the whole entry.
		erase(tree._journalNodes, itPos);
		delta = posEnd - pos;
		beginShiftPos = itPos;
	} else if (it->virtualPosition == pos && it->length > posEnd - pos) {
		// Remove a prefix of the entry.
		SEQAN_ASSERT_LT(pos, it->virtualPosition + it->length);
		delta = posEnd - pos;
		it->physicalPosition += delta;
		it->length -= delta;
		beginShiftPos = itPos + 1;
	} else if (it->virtualPosition < pos && it->virtualPosition + it->length == posEnd) {
		// Remove a suffix of the entry.
		SEQAN_ASSERT_GT(pos, it->virtualPosition);
		delta = posEnd - pos;
		it->length -= delta;
		beginShiftPos = itPos + 1;
	} else if (it->virtualPosition < pos && it->virtualPosition + it->length > posEnd) {
		// Remove a true infix of the entry.
		TSize prefixLength = pos - it->virtualPosition;
		TSize suffixLength = it->length - prefixLength - (posEnd - pos);
		TSize removedInfixLength = posEnd - pos;
		// Update the left part, this must be done before the iterator is possibly invalidate because of copied memory.
		it->length -= removedInfixLength + suffixLength;
		// Insert a new entry for the right part.
		TCargo tmpEntry(it->segmentSource, it->physicalPosition + prefixLength + removedInfixLength, it->virtualPosition + prefixLength, suffixLength);
		insertValue(tree._journalNodes, itPos + 1, tmpEntry);
		// Set shift position and delta.
		delta = removedInfixLength;
		beginShiftPos = itPos + 2;
	} else {
		// Remove more than one entry.
		TPos rmBeginPos = itPos;
		TPos rmEndPos = itPos;
		if (it->virtualPosition != pos) {
			// Do not remove all of first.
			delta += it->length - (pos - it->virtualPosition);
			rmBeginPos += 1;
			rmEndPos += 1;
			it->length = (pos - it->virtualPosition);
		} else {
			// Remove all of first.
			delta = it->length;
			rmEndPos += 1;
		}
		it += 1;
		while (posEnd > it->virtualPosition + it->length) {
			rmEndPos += 1;
			delta += it->length;
			it += 1;
		}
		if (it->virtualPosition + it->length == posEnd) {
			// Remove all of last.
			rmEndPos += 1;
			delta += it->length;
			beginShiftPos = rmBeginPos;
		} else {
			// Do not remove all of last.
			SEQAN_ASSERT_GT(it->virtualPosition + it->length, posEnd);
			TSize tmpDelta = delta;
			delta += posEnd - it->virtualPosition;
			it->physicalPosition += posEnd - it->virtualPosition;
			it->length -= posEnd - it->virtualPosition;
			// We update this entry manually.
			it->virtualPosition -= tmpDelta;
			beginShiftPos = rmBeginPos + 1;
		}
		erase(tree._journalNodes, rmBeginPos, rmEndPos);
	}

    // Perform left-shift of the virtual positions.
    for (TIter it = begin(tree._journalNodes, Standard()) + beginShiftPos; it != end(tree._journalNodes, Standard()); ++it) {
        SEQAN_ASSERT_GEQ(it->virtualPosition, delta);
        it->virtualPosition -= delta;
    }
//	std::cerr << __FILE__ << ":" << __LINE__ << " -- " << tree << std::endl;

    SEQAN_ASSERT(_checkSortedArrayTree(tree));
}


template <typename TNode, typename TJournalSpec, typename TPos>
inline
typename Position<typename Cargo<TNode>::Type >::Type
virtualToHostPosition(JournalEntries<TNode, TJournalSpec> const & journalEntries,
                      TPos const & pos)
{
    SEQAN_CHECKPOINT;
    typedef JournalEntries<TNode, TJournalSpec> TJournalEntries;
    typedef typename Iterator<TJournalEntries>::Type TIterator;

    TIterator it = findInJournalEntries(journalEntries, pos);
    // The easiest case is to find a segment from the original sequence that
    // contains the position.  This case also works if we hit the entry after
    // the last one in a segment from the original sequence.
    if (value(it).segmentSource == SOURCE_ORIGINAL) {
        TPos offset = pos - value(it).virtualPosition;
        return value(it).physicalPosition + offset;
    }
    // The harder case is to find a segment from the patch sequence.  We first
    // try to find an original segment right of it, if this fails a segment
    // left of it.  If this fails, 0 is returned.
    SEQAN_ASSERT_EQ(value(it).segmentSource, SOURCE_PATCH);
    TIterator it2 = it;
    for (++it; it != end(journalEntries, Standard()); ++it) {
        if (value(it).segmentSource == SOURCE_ORIGINAL)
            return value(it).physicalPosition;
    }
	it = it2;
    // Search left;
    while (true) {
        if (value(it).segmentSource == SOURCE_ORIGINAL)
            return value(it).physicalPosition + value(it).length;
        if (it == begin(journalEntries, Standard()))
            return 0;
        --it;
    }

    SEQAN_ASSERT_FAIL("Should never reach here!");
    return 0;
}

template <typename TNode, typename TJournalSpec, typename TPos>
inline
bool
isGapInHost(JournalEntries<TNode, TJournalSpec> const & journalEntries,
            TPos const & pos)
{
    SEQAN_CHECKPOINT;
    typedef JournalEntries<TNode, TJournalSpec> TJournalEntries;
    typedef typename Iterator<TJournalEntries>::Type TIterator;

    TIterator it = findInJournalEntries(journalEntries, pos);
    return value(it).segmentSource == SOURCE_PATCH;
}


}  // namespace seqan

#endif  // SEQAN_SEQUENCE_JOURNALED_JOURNAL_ENTRIES_SORTED_ARRAY_H_
