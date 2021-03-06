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
//  Author: Andreas Gogol-Doering <andreas.doering@mdc-berlin.de>
// ==========================================================================

#ifndef SEQAN_HEADER_GAPS_BASE_H
#define SEQAN_HEADER_GAPS_BASE_H

namespace SEQAN_NAMESPACE_MAIN
{

//////////////////////////////////////////////////////////////////////////////

/**
.Metafunction.GappedValueType:
..cat:Alignments
..summary:Returns a value type that contains a blank value '-'.
..signature:GappedValueType<T>::Type
..param.T:The value type that should be expanded (if needed) by '-'.
..returns.param.Type:A value type that can be used to store store values in $T$ and the value '-'.
..include:seqan/align.h
*/

template <typename T>
struct GappedValueType
{
	typedef T Type;
};

template <typename TValue, typename TSpec>
struct GappedValueType< SimpleType<TValue, TSpec> >
{
	typedef SimpleType<TValue, TSpec> THost_;
	typedef ModifiedAlphabet<THost_, ModExpand<'-'> > Type;
};

//////////////////////////////////////////////////////////////////////////////


template <typename THost, typename TSpec>
inline ModifiedAlphabet<THost, ModExpand<'-', TSpec> >
gapValueImpl(ModifiedAlphabet<THost, ModExpand<'-', TSpec> > *)
{
SEQAN_CHECKPOINT
	static ModifiedAlphabet<THost, ModExpand<'-', TSpec> > const _gap = '-';
	return _gap;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Tags

struct ArrayGaps;


template <typename TSpec>
struct GapsIterator;


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Gaps
//////////////////////////////////////////////////////////////////////////////
// an instance of the Gaps class is a strictly increasing function
// between N_0 and N_0

/**
.Class.Gaps:
..cat:Alignments
..cat:Sequences
..summary:Stores the gaps in a gapped sequences.
..signature:Gaps<TSource, TSpec>
..param.TSource:Type of the ungapped sequence.
...metafunction:Metafunction.Source
..param.TSpec:The specializing type.
...metafunction:Metafunction.Spec
..remarks:The gaps are stored separately from the sequence.
The ungapped sequence is called the @Function.source@ of the gaps object.
$Gaps$ either stores the source (then it is the owner of the source), or refers to an external source (then it is @Function.dependent@).
..include:seqan/align.h
*/

template <typename TSource, typename TSpec/* = ArrayGaps*/>
class Gaps;


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Size
//////////////////////////////////////////////////////////////////////////////

template <typename TSource, typename TSpec>
struct Size<Gaps<TSource, TSpec> >
{
	typedef typename Size<TSource>::Type Type;
};
template <typename TSource, typename TSpec>
struct Size<Gaps<TSource, TSpec> const>
{
	typedef typename Size<TSource const>::Type Type;
};

//////////////////////////////////////////////////////////////////////////////
// Position
//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Position.param.T.type:Class.Gaps

template <typename TSource, typename TSpec>
struct Position<Gaps<TSource, TSpec> >:
	Position<TSource>
{
};
template <typename TSource, typename TSpec>
struct Position<Gaps<TSource, TSpec> const>:
	Position<TSource>
{
};

//////////////////////////////////////////////////////////////////////////////
// Source
//////////////////////////////////////////////////////////////////////////////

/**
.Metafunction.Source:
..cat:Alignments
..summary:The underlying sequence for alignments or gaps data structures.
..signature:Source<T>::Type
..param.T:Type for which the source type is determined.
...type:Class.Gaps
..returns.param.Type:Source type of $T$.
..include:seqan/align.h
*/

template <typename TSource, typename TSpec>
struct Source<Gaps<TSource, TSpec> >
{
	typedef TSource Type;
};


//////////////////////////////////////////////////////////////////////////////

/**
.Metafunction.GetSource:
..cat:Alignments
..summary:The type returned by the @Function.source@ function.
..signature:GetSource<T>::Type
..param.T:Type for which the source is retrieved by @Function.source@.
...type:Class.Gaps
..returns.param.Type:The type returned by the @Function.source@ function.
...remarks:This type is a reference to @Metafunction.Source@.
..include:seqan/align.h
*/
template <typename T>
struct GetSource
{
	typedef typename Source<T>::Type & Type;
};

//////////////////////////////////////////////////////////////////////////////
// Iterator
//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Iterator.param.T.type:Class.Gaps

template <typename TSource, typename TSpec, typename TIteratorSpec>
struct Iterator<Gaps<TSource, TSpec>, TIteratorSpec>
{
	typedef Iter<Gaps<TSource, TSpec>, GapsIterator<TSpec> > Type;
};
template <typename TSource, typename TSpec, typename TIteratorSpec>
struct Iterator<Gaps<TSource, TSpec> const, TIteratorSpec>
{
	typedef Iter<Gaps<TSource, TSpec> const, GapsIterator<TSpec> > Type;
};

//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Spec.param.T.type:Class.Gaps

template <typename TSource, typename TSpec>
struct Spec<Gaps<TSource, TSpec> >
{
	typedef TSpec Type;
};
template <typename TSource, typename TSpec>
struct Spec<Gaps<TSource, TSpec> const>
{
	typedef TSpec Type;
};

//////////////////////////////////////////////////////////////////////////////
// Value
//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Value.param.T.type:Class.Gaps

template <typename TSource, typename TSpec>
struct Value<Gaps<TSource, TSpec> >:
	Value<TSource>
{
};
template <typename TSource, typename TSpec>
struct Value<Gaps<TSource, TSpec> const>:
	Value<TSource const>
{
};

//////////////////////////////////////////////////////////////////////////////
// GetValue
//////////////////////////////////////////////////////////////////////////////

///.Metafunction.GetValue.param.T.type:Class.Gaps

template <typename TSource, typename TSpec>
struct GetValue<Gaps<TSource, TSpec> >:
	Value<TSource> //no reference
{
};
template <typename TSource, typename TSpec>
struct GetValue<Gaps<TSource, TSpec> const>:
	Value<TSource const> //no reference
{
};


//////////////////////////////////////////////////////////////////////////////
// Reference
//////////////////////////////////////////////////////////////////////////////

///.Metafunction.Reference.param.T.type:Class.Gaps

template <typename TSource, typename TSpec>
struct Reference<Gaps<TSource, TSpec> >
{
	typedef typename Iterator<Gaps<TSource, TSpec>, Standard>::Type TIterator_;
	typedef Proxy<IteratorProxy<TIterator_> > Type;
};

template <typename TSource, typename TSpec>
struct Reference<Gaps<TSource, TSpec> const>
{
	typedef typename Iterator<Gaps<TSource, TSpec> const, Standard>::Type TIterator_;
	typedef Proxy<IteratorProxy<TIterator_> > Type;
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////////////////

///.Function.getObjectId.param.object.type:Class.Gaps

template <typename TSource, typename TSpec>
inline void const *
getObjectId(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	return getObjectId(source(me));
}
template <typename TSource, typename TSpec>
inline void const *
getObjectId(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return getObjectId(source(me));
}

//////////////////////////////////////////////////////////////////////////////

///.Function.begin.param.object.type:Class.Gaps

// returns iterator to left border
template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<Gaps<TSource, TSpec>, Tag<TTag> const>::Type 
begin(Gaps<TSource, TSpec> & me,
	  Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(me, beginPosition(me), tag_);
}
template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<Gaps<TSource, TSpec> const, Tag<TTag> const>::Type 
begin(Gaps<TSource, TSpec> const & me,
	  Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(me, beginPosition(me), tag_);
}
//////////////////////////////////////////////////////////////////////////////

///.Function.end.param.object.type:Class.Gaps

// returns iterator to right border
template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<Gaps<TSource, TSpec>, Tag<TTag> const>::Type 
end(Gaps<TSource, TSpec> & me,
	Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(me, endPosition(me), tag_);
}
template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<Gaps<TSource, TSpec> const, Tag<TTag> const>::Type 
end(Gaps<TSource, TSpec> const & me,
	Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(me, endPosition(me), tag_);
}

//////////////////////////////////////////////////////////////////////////////

///.Function.length.param.object.type:Class.Gaps

template <typename TSource, typename TSpec>
inline typename Size<Gaps<TSource, TSpec> >::Type
length(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return endPosition(me) - beginPosition(me);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/**
.Function.sourceBegin:
..summary:Begin of the source segment. 
..cat:Alignments
..signature:sourceBegin(object)
..param.object:An object that has a source
...type:Class.Gaps
..returns:An iterator that points to the first item in @Function.source.source(object)@ that is used in object.
..see:Function.begin
..see:Function.source
..include:seqan/align.h
*/

template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<TSource, Tag<TTag> const>::Type 
sourceBegin(Gaps<TSource, TSpec> const & me,
			Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(source(me), clippedBeginPosition(me), tag_);
}
template <typename TSource, typename TSpec>
inline typename Iterator<TSource, typename DefaultGetIteratorSpec<TSource>::Type>::Type 
sourceBegin(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	typedef typename DefaultGetIteratorSpec<TSource>::Type TDefaultGetIteratorSpec;
	return iter(source(me), clippedBeginPosition(me), TDefaultGetIteratorSpec());
}


//////////////////////////////////////////////////////////////////////////////


/**
.Function.sourceEnd:
..summary:End of the source segment. 
..cat:Alignments
..signature:sourceEnd(object)
..param.object:An object that has a source
...type:Class.Gaps
..returns:An iterator that points behind the last item in @Function.source.source(object)@ that is used in object.
..see:Function.end
..see:Function.source
..see:Function.sourceBegin
..include:seqan/align.h
*/

template <typename TSource, typename TSpec, typename TTag>
inline typename Iterator<TSource, Tag<TTag> const>::Type 
sourceEnd(Gaps<TSource, TSpec> const & me,
		  Tag<TTag> const tag_)
{
SEQAN_CHECKPOINT
	return iter(source(me), clippedEndPosition(me), tag_);
}
template <typename TSource, typename TSpec>
inline typename Iterator<TSource, typename DefaultGetIteratorSpec<TSource>::Type>::Type 
sourceEnd(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	typedef typename DefaultGetIteratorSpec<TSource>::Type TDefaultGetIteratorSpec;
	return iter(source(me), clippedEndPosition(me), TDefaultGetIteratorSpec());
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/**
.Function.insertGap:
..cat:Alignments
..summary:Insert one blank into a gapped sequence. 
..signature:insertGap(gapped_sequence, view_position)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which the blank is inserted.
..include:seqan/align.h
*/
template <typename TSource, typename TSpec, typename TPosition>
inline void
insertGap(Gaps<TSource, TSpec> & me,
		  TPosition _view_pos)
{
SEQAN_CHECKPOINT
	insertGap(iter(me, _view_pos));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.insertGaps:
..cat:Alignments
..summary:Insert blanks into a gapped sequence. 
..signature:insertGaps(gapped_sequence, view_position, count)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which $count$ blanks are inserted.
..param.count:Number of blanks to insert.
..see:Function.insertGap
..include:seqan/align.h
*/
template <typename TSource, typename TSpec, typename TPosition, typename TSize>
inline void
insertGaps(Gaps<TSource, TSpec> & me,
		   TPosition _view_pos,
		   TSize _size)
{
SEQAN_CHECKPOINT
	insertGaps(iter(me, _view_pos), _size);
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.removeGap:
..cat:Alignments
..summary:Removes one blank from a gapped sequence. 
..signature:removeGap(gapped_sequence, view_position)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which the blank is removed.
..remarks:If there is no gap at position $view_position$ in $gapped_sequence$, then nothing happens.
..see:Function.insertGap
..include:seqan/align.h
*/
template <typename TSource, typename TSpec, typename TPosition>
inline void
removeGap(Gaps<TSource, TSpec> & me,
		  TPosition _view_pos)
{
SEQAN_CHECKPOINT
	removeGap(iter(me, _view_pos));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.removeGaps:
..cat:Alignments
..summary:Removes blanks from a gapped sequence. 
..signature:removeGaps(gapped_sequence, view_position, count)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which up to $count$ blanks are removed.
..param.count:Number of blanks 
..remarks:This funcion removes up to $count$ blanks. 
If there is no gap at position $view_position$ in $gapped_sequence$, nothing happens.
If there are only $x < count$ consecutive blanks starting at position $view_position$ in $gappend_sequence$, then only $x$ blanks are removed.
..see:Function.insertGaps
..see:Function.removeGap
..include:seqan/align.h
*/

template <typename TSource, typename TSpec, typename TPosition, typename TSize>
inline void
removeGaps(Gaps<TSource, TSpec> & me,
		   TPosition _view_pos,
		   TSize _size)
{
SEQAN_CHECKPOINT
	removeGaps(iter(me, _view_pos), _size);
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.isGap:
..cat:Alignments
..summary:Test a gapped sequence for gaps at a specific position. 
..signature:bool isGap(gapped_sequence, view_position)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which $gapped_sequence$ is tested.
..returns:$true$, if there is a gap at position $view_position$ in $gapped_sequence$, $false$ otherwise.
..include:seqan/align.h
*/

template <typename TSource, typename TSpec, typename TPosition>
inline bool 
isGap(Gaps<TSource, TSpec> & me,
	  TPosition view_pos)
{
SEQAN_CHECKPOINT
	return isGap(iter(me, view_pos));
}
template <typename TSource, typename TSpec, typename TPosition>
inline bool 
isGap(Gaps<TSource, TSpec> const & me,
	  TPosition view_pos)
{
SEQAN_CHECKPOINT
	return isGap(iter(me, view_pos));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.countGaps:
..cat:Alignments
..summary:Count blanks at a specific position in a gapped sequence. 
..signature:Size countGaps(gapped_sequence, view_position)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which $gapped_sequence$ is tested.
..returns:Number of consecutive gaps in $gapped_sequence$ starting at position $view_position$.
...metafunction:Metafunction.Size
..remarks:If there is no gap at position $view_position$, the function returns $0$.
...text:If $view_position \geq $@Function.endPosition@$(gapped_sequence)$, the function returns $0$.
..include:seqan/align.h
*/

// count gaps beginning at given view position
// counting trailing gaps returns either the intended trailing gaps or 0

template <typename TSource, typename TSpec, typename TPosition>
inline typename Size<Gaps<TSource, TSpec> >::Type
countGaps(Gaps<TSource, TSpec> & me,
		  TPosition view_pos)
{
SEQAN_CHECKPOINT
	return countGaps(iter(me, view_pos));
}
template <typename TSource, typename TSpec, typename TPosition>
inline typename Size<Gaps<TSource, TSpec> >::Type
countGaps(Gaps<TSource, TSpec> const & me,
		  TPosition view_pos)
{
SEQAN_CHECKPOINT
	return countGaps(iter(me, view_pos));
}

/**
.Function.countCharacters:
..cat:Alignments
..summary:Count characters at a specific position in a gapped sequence.
..signature:Size countCharacters(gapped_sequence, view_position)
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_position:The view position at which $gapped_sequence$ is tested.
..returns:Number of consecutive characters in $gapped_sequence$ starting at position $view_position$.
...metafunction:Metafunction.Size
..remarks:If there is no character at position $view_position$, the function returns $0$.
...text:If $view_position \geq $@Function.endPosition@$(gapped_sequence)$, the function returns $0$.
..include:seqan/align.h
*/

// count characters beginning at given view position

template <typename TSource, typename TSpec, typename TPosition>
inline typename Size<Gaps<TSource, TSpec> >::Type
countCharacters(Gaps<TSource, TSpec> const & me,
				TPosition view_pos)
{
SEQAN_CHECKPOINT
	return countCharacters(iter(me, view_pos));
}

template <typename TSource, typename TSpec, typename TPoistion>
inline typename Size<Gaps<TSource, TSpec> >::Type
countCharacters(Gaps<TSource, TSpec> & me,
				TPoistion view_pos)
{
SEQAN_CHECKPOINT
	return countCharacters(iter(me, view_pos));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.clearGaps:
..cat:Alignments
..summary:Remove blanks from a gapped sequence. 
..signature:clearGaps(gapped_sequence [, view_begin_pos, view_end_pos])
..param.gapped_sequence:A gapped sequence.
...type:Class.Gaps
..param.view_begin_pos:First view position that is scanned for blanks. (optional)
..param.view_end_pos:View Position behind the last item that is scanned for blanks. (optional)
..remarks:All blanks after $view_begin_pos$ and before $view_end_pos$ are removed.
...text:If no $view_begin_pos$ and $view_end_pos$ are specified, all gaps are removed from $gapped_sequence$.
..include:seqan/align.h
*/

template <typename TSource, typename TSpec, typename TPosition1, typename TPosition2>
inline void
clearGaps(Gaps<TSource, TSpec> & me,
		  TPosition1 view_pos_begin,
		  TPosition2 view_pos_end)
{
SEQAN_CHECKPOINT

	TPosition1 pos_left = view_pos_end - view_pos_begin;
	while (pos_left > 0)
	{
		if (isGap(me, view_pos_begin))
		{
			TPosition1 gap_count = countGaps(me, view_pos_begin);
			if (!gap_count)
			{//trailing gaps reached: stop function
				break;
			}
			if (gap_count > pos_left)
			{
				gap_count = pos_left;
			}
			removeGaps(me, view_pos_begin, gap_count);
			pos_left -= gap_count;
		}
		else
		{
			++view_pos_begin;
			--pos_left;
		}
	}
}

//____________________________________________________________________________

template <typename TSource, typename TSpec>
inline void
clearGaps(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	clearGaps(me, 0, endPosition(me));
}

//////////////////////////////////////////////////////////////////////////////

// copy gaps-information from one Gaps-object range into another object
//??? TODO: not tested, not documented

template <typename TSource, typename TSpec, typename TPosition1, typename TSourceGaps, typename TPosition2, typename TPosition3>
inline void
copyGaps(Gaps<TSource, TSpec> & target_gaps,
		 TPosition1 target_view_pos_begin,
		 TSourceGaps const & source_gaps,
		 TPosition2 source_view_pos_begin,
		 TPosition3 source_view_pos_end)
{
SEQAN_CHECKPOINT
	TPosition1 target_view_pos_end = target_view_pos_begin + source_view_pos_end - source_view_pos_begin;
	clearGaps(target_gaps, target_view_pos_begin, target_view_pos_end);
	
	for (TPosition3 i = source_view_pos_end - source_view_pos_begin; i > 0; --i)
	{
		if (isGap(source_gaps, source_view_pos_begin))
		{
			insertGap(target_gaps, target_view_pos_begin);
		}

		++target_view_pos_begin;
		++source_view_pos_begin;
	}
}


//////////////////////////////////////////////////////////////////////////////

///.Function.getValue.param.container.type:Class.Gaps

template <typename TSource, typename TSpec, typename TPosition>
inline typename GetValue<Gaps<TSource, TSpec> >::Type
getValue(Gaps<TSource, TSpec> & me,
		 TPosition view_pos)
{
SEQAN_CHECKPOINT
	typedef typename Value<TSource>::Type TValue;
	if (isGap(me, view_pos)) return gapValue<TValue>();
	else return value(source(me), toSourcePosition(me, view_pos));
}
template <typename TSource, typename TSpec, typename TPosition>
inline typename GetValue<Gaps<TSource, TSpec> >::Type
getValue(Gaps<TSource, TSpec> const & me,
		 TPosition view_pos)
{
SEQAN_CHECKPOINT
	typedef typename Value<TSource>::Type TValue;
	if (isGap(me, view_pos)) return gapValue<TValue>();
	else return value(source(me), toSourcePosition(me, view_pos));
}

//////////////////////////////////////////////////////////////////////////////

///.Function.value.param.container.type:Class.Gaps

template <typename TSource, typename TSpec, typename TPosition>
inline typename Reference<Gaps<TSource, TSpec> >::Type
value(Gaps<TSource, TSpec> & me,
	  TPosition view_pos)
{
SEQAN_CHECKPOINT
	typedef typename Reference<Gaps<TSource, TSpec> >::Type TReference;
	return TReference(iter(me, view_pos));
}
template <typename TSource, typename TSpec, typename TPosition>
inline typename Reference<Gaps<TSource, TSpec> const>::Type
value(Gaps<TSource, TSpec> const & me,
	  TPosition view_pos)
{
SEQAN_CHECKPOINT
	typedef typename Reference<Gaps<TSource, TSpec> const>::Type TReference;
	return TReference(iter(me, view_pos));
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/**
.Function.emptySource:
..summary:Test if there is a source. 
..cat:Alignments
..signature:bool emptySource(object)
..param.object:An object that could habe a source.
...type:Class.Gaps
..returns:$true$ if $object$ has a @Function.source@, $false$ otherwise.
..see:Function.source
..see:Metafunction.Source
..include:seqan/align.h
*/

template <typename TSource, typename TSpec>
inline bool
emptySource(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	bool ret = empty(_dataSource(me));
	return ret;
}
template <typename TSource, typename TSpec>
inline bool
emptySource(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	bool ret = empty(_dataSource(me));
	return ret;
}
//////////////////////////////////////////////////////////////////////////////

/**
.Function.dependentSource:
..summary:Test if object depends from it's source. 
..cat:Alignments
..signature:bool dependentSource(object)
..param.object:An object that has a source.
...type:Class.Gaps
..returns:$true$ if the source of $object$ is a stand alone object that is
not managed by $object$. $false$ otherwise.
..remarks:This function returns $false$, if the @Function.source@ is @Function.emptySource.empty@.
..remarks.text:If both @Function.emptySource@ and @Function.dependentSource@ are false, $object$ is the owner of the source.
..see:Function.source
..see:Metafunction.Source
..see:Function.emptySource
..include:seqan/align.h
*/
template <typename TSource, typename TSpec>
inline bool
dependentSource(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	return dependent(_dataSource(me));
}
template <typename TSource, typename TSpec>
inline bool
dependentSource(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return dependent(_dataSource(me));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.setSource:
..summary:Let an external object be the source.
..cat:Alignments
..signature:setSource(object, source)
..signature:setSource(object, source [, begin_pos, end_pos])
..param.object:An object that will get a new source.
...type:Class.Gaps
..param.source:The new source.
...remarks:The source type can be determined by @Metafunction.Source@.
..param.begin_pos:Position of the first item in $source$ that is used in $object$. (optional)
..param.end_pos:Position behind the last item in $source$ that is used in $object$. (optional)
..remarks:After this function, $object$ @Function.dependentSource.depends@ from $source$,
and $source$ is the new source of $object$.
...text:If no $begin_pos$ and $end_pos$ are specified, the whole $source$ will be used.
..see:Function.source
..see:Function.dependentSource
..see:Metafunction.Source
..include:seqan/align.h
*/
template <typename TSource, typename TSpec, typename TPosition1, typename TPosition2>
inline void
setSource(Gaps<TSource, TSpec> & me,
		  TSource & source_,
		  TPosition1 clipped_begin_pos,
		  TPosition2 clipped_end_pos)
{
SEQAN_CHECKPOINT
	setValue(_dataSource(me), source_);
	_setClippedBeginPosition(me, clipped_begin_pos);
	_setClippedEndPosition(me, clipped_end_pos);
	clearGaps(me);
}

//____________________________________________________________________________

template <typename TSource, typename TSpec>
inline void
setSource(Gaps<TSource, TSpec> & me,
		  TSource & source_)
{
SEQAN_CHECKPOINT
	setSource(me, source_, 0, length(source_));
}

//??? Variante mit zusaetzlich source_begin und source_end

//////////////////////////////////////////////////////////////////////////////

/**
.Function.createSource:
..summary:Creates a new source.
..cat:Alignments
..signature:createSource(object)
..param.object:An object that will get a new source.
...type:Class.Gaps
..remarks:
If $object$ has no @Function.source@, a new one is created.
If $object$ is already the owner of the source, nothing happens.
If $object$ has an external source, this source is copied. 
$object$ is thereupon the owner of the source.
..see:Function.source
..see:Function.dependentSource
..see:Metafunction.Source
..include:seqan/align.h
*/
template <typename TSource, typename TSpec>
inline void
createSource(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	create(_dataSource(me));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.detach:
..cat:Alignments
..param.object.type:Class.Gaps
..include:seqan/align.h
*/
template <typename TSource, typename TSpec>
inline void
detach(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	createSource(me);
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.source:
..summary:The source of an object. 
..cat:Alignments
..signature:source(object)
..param.object:An object.
...type:Class.Gaps
..returns:The source of $object$.
...type:Metafunction.Source
..remarks:The source of a @Class.Gaps@ instance is the underlying sequence without gaps.
..see:Metafunction.Source
..include:seqan/align.h
*/
template <typename TSource, typename TSpec>
inline TSource &
source(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	return value(_dataSource(me));
}
template <typename TSource, typename TSpec>
inline TSource &
source(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return value(_dataSource(me));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.sourceSegment:
..summary:The used part of the source. 
..cat:Alignments
..signature:sourceSegment(object)
..param.object:An object.
...type:Class.Gaps
..returns:The part of the @Function.source@ that is actually used by $object$.
...type:Class.Segment
..remarks:The source of a @Class.Gaps@ instance is the underlying sequence without gaps. 
$sourceSegment$ is useful since @Class.Gaps@ can be limited to work on a subsequence of the source.
..see:Metafunction.Source
..see:Function.source
..include:seqan/align.h
*/
template <typename TSource, typename TSpec>
inline typename Infix<TSource>::Type
sourceSegment(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	return infix(source(me), clippedBeginPosition(me), clippedEndPosition(me));
}

template <typename TSource, typename TSpec>
inline typename Infix<TSource>::Type
sourceSegment(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return infix(source(me), clippedBeginPosition(me), clippedEndPosition(me));
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.sourceLength:
..summary:Length of the source. 
..cat:Alignments
..signature:Size sourceLength(gaps)
..param.gaps:A gaps object.
...type:Class.Gaps
..returns:Length of the used part of the source.
...metafunction:Metafunction.Size
..remarks:This function is equivalent to $clippedEndPosition(gaps) - clippedBeginPosition(gaps)$.
..include:seqan/align.h
*/
//..see:Function.clippedEndPosition
//..see:Function.clippedBeginPosition
template <typename TSource, typename TSpec>
inline typename Size<TSource>::Type
sourceLength(Gaps<TSource, TSpec> & me)
{
SEQAN_CHECKPOINT
	return clippedEndPosition(me) - clippedBeginPosition(me);
}
template <typename TSource, typename TSpec>
inline typename Size<TSource>::Type
sourceLength(Gaps<TSource, TSpec> const & me)
{
SEQAN_CHECKPOINT
	return clippedEndPosition(me) - clippedBeginPosition(me);
}

//////////////////////////////////////////////////////////////////////////////

/**
.Function.assignSource:
..summary:Assigns the source to a new value. 
..cat:Alignments
..signature:assignSource(object, source_in)
..param.object:An object.
...type:Class.Gaps
..param.source_in:An object that is assigned to the source of $object$.
..remarks:
...note:$source_in$ is not the new @Function.source@ of $object$, but $source_in$ is assigned (copied) to @Function.source.source(object)@.
That means that the current source of $object$ is modified by this function. 
If you want $object$ to drop its current source and take another object as source, use @Function.setSource@ instead.
...text:If no $begin_pos$ and $end_pos$ are specified, the whole source will be used.
...text:This function does not change whether $object$ is @Function.dependentSource.dependent@ or not.
...text:The source of $object$ must not be @Function.emptySource.empty@ for executing this function.
..see:Metafunction.Source
..see:Function.source
..see:Function.setSource
..see:Function.emptySource
..see:Function.dependentSource
..see:Function.assign
..include:seqan/align.h
*/

//____________________________________________________________________________

template <typename TSource, typename TSpec, typename TSource2>
inline void
assignSource(Gaps<TSource, TSpec> & me,
			 TSource2 const & source_)
{
SEQAN_CHECKPOINT
	assignValue(me.data_source, source_);
	_setClippedBeginPosition(me, 0);
	_setClippedEndPosition(me, length(source_));
	clearGaps(me);
}


//////////////////////////////////////////////////////////////////////////////

/**
.Function.moveSource:
..summary:Moves the source to a new value. 
..cat:Alignments
..signature:moveSource(object, source_in [, begin_pos, end_pos])
..param.object:An object.
...type:Class.Gaps
..param.source_in:An object that is moved to the source of $object$.
..param.begin_pos:Position of the first item in the source that is used in $object$. (optional)
..param.end_pos:Position behind the last item in the source that is used in $object$. (optional)
..remarks:
...note:$source_in$ is not the new @Function.source@ of $object$, but $source_in$ is moved into @Function.source.source(object)@.
"Moved" means that $source_in$ is assigned to $source(object)$ with the possibility that $source_in$ looses its content.
That means that the current source of $object$ is modified by this function. 
If you want $object$ to drop its current source and take another object as source, use @Function.setSource@ instead.
If you want $source_in$ not to become empty, use @Function.assignSource@ instead.
...text:If no $begin_pos$ and $end_pos$ are specified, the whole source will be used.
...text:This function does not change whether $object$ is @Function.dependentSource.dependent@ or not.
...text:The source of $object$ must not be @Function.emptySource.empty@ for executing this function.
..see:Metafunction.Source
..see:Function.source
..see:Function.setSource
..see:Function.emptySource
..see:Function.dependentSource
..see:Function.move
..see:Function.assignSource
..include:seqan/align.h
*/
template <typename TSource, typename TSpec, typename TSource2, typename TPosition1, typename TPosition2>
inline void
moveSource(Gaps<TSource, TSpec> & me,
		   TSource2 const & source_,
		   TPosition1 clipped_begin_pos,
		   TPosition2 clipped_end_pos)
{
SEQAN_CHECKPOINT
	moveValue(_dataSource(me), source_);
	_setClippedBeginPosition(me, clipped_begin_pos);
	_setClippedEndPosition(me, clipped_end_pos);
	clearGaps(me);
}

//____________________________________________________________________________

template <typename TSource, typename TSpec, typename TSource2>
inline void
moveSource(Gaps<TSource, TSpec> & me,
		   TSource2 const & source_)
{
SEQAN_CHECKPOINT
	moveSource(me, source_, 0, length(source_));
}



//////////////////////////////////////////////////////////////////////////////

template <typename TFile, typename TSource, typename TIDString, typename TSpec>
inline void
write(TFile & target,
	  Gaps<TSource, TSpec> const & source, 
	  TIDString const &,
	  Raw)
{
//IOREV _nodoc_ specialization not documented
SEQAN_CHECKPOINT
//	_streamWriteRange(target, begin(source), end(source));

	// Print gaps row
	typedef typename Iterator<Gaps<TSource, TSpec> const>::Type TIter;
	TIter begin_ = begin(source);
	TIter end_ = end(source);
	for (; begin_ != end_; ++begin_) {
		if (isGap(begin_))
			_streamPut(target, gapValue<char>());
		else 
			_streamPut(target, *begin_);
	}
}

//////////////////////////////////////////////////////////////////////////////
// stream operators
//////////////////////////////////////////////////////////////////////////////

template <typename TStream, typename TSource, typename TSpec>
inline TStream &
operator << (TStream & target, 
			 Gaps<TSource, TSpec> const & source)
{
//IOREV _nodoc_ specialization not documented
SEQAN_CHECKPOINT
	write(target, source);
	return target;
}

//////////////////////////////////////////////////////////////////////////////
/*
template <typename TStream, typename TSource, typename TSpec>
inline TStream &
operator >> (TStream & source, 
			 Gaps<TSource, TSpec> & target)
{
SEQAN_CHECKPOINT
	read(source, target);
	return source;
}
*/
//////////////////////////////////////////////////////////////////////////////
// Comparison Operators
//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator == (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isEqual(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight >
inline bool
operator == (Gaps<TLeftSource, TLeftSpec> const & left, 
			 TRight const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isEqual(_lex);
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator == (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isEqual(_lex);
}

//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator != (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isNotEqual(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight >
inline bool
operator !=(Gaps<TLeftSource, TLeftSpec> const & left, 
			TRight const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isNotEqual(_lex);
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator != (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isNotEqual(_lex);
}
//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator < (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isLess(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight>
inline bool
operator < (Gaps<TLeftSource, TLeftSpec> const & left, 
			TRight const & right)
{
SEQAN_CHECKPOINT
	return isLess(left, right, typename DefaultPrefixOrder<Gaps<TLeftSource, TLeftSpec> >::Type());
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator < (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isLess(_lex);
}

//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator <= (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isLessOrEqual(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight>
inline bool
operator <= (Gaps<TLeftSource, TLeftSpec> const & left, 
			 TRight const & right)
{
SEQAN_CHECKPOINT
	return isLessOrEqual(left, right, typename DefaultPrefixOrder<Gaps<TLeftSource, TLeftSpec> >::Type());
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator <= (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isLessOrEqual(_lex);
}
//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator > (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isGreater(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight>
inline bool
operator > (Gaps<TLeftSource, TLeftSpec> const & left, 
		TRight const & right)
{
SEQAN_CHECKPOINT
	return isGreater(left, right, typename DefaultPrefixOrder<Gaps<TLeftSource, TLeftSpec> >::Type());
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator > (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isGreater(_lex);
}
//////////////////////////////////////////////////////////////////////////////

template <typename TLeftSource, typename TLeftSpec, typename TRightSource, typename TRightSpec >
inline bool
operator >= (Gaps<TLeftSource, TLeftSpec> const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TLeftSource, TLeftSpec> >::Type _lex(left, right);
    return isGreaterOrEqual(_lex);
}
template <typename TLeftSource, typename TLeftSpec, typename TRight>
inline bool
operator >= (Gaps<TLeftSource, TLeftSpec> const & left, 
		TRight const & right)
{
SEQAN_CHECKPOINT
	return isGreaterOrEqual(left, right, typename DefaultPrefixOrder<Gaps<TLeftSource, TLeftSpec> >::Type());
}
template <typename TLeft, typename TRightSource, typename TRightSpec >
inline bool
operator >= (TLeft const & left, 
			 Gaps<TRightSource, TRightSpec> const & right)
{
SEQAN_CHECKPOINT
	typename Comparator<Gaps<TRightSource, TRightSpec> >::Type _lex(left, right);
    return isGreaterOrEqual(_lex);
}

//////////////////////////////////////////////////////////////////////////////

}// namespace SEQAN_NAMESPACE_MAIN

#endif //#ifndef SEQAN_HEADER_...
