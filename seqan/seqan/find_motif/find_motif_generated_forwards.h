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


#ifndef SEQAN_HEADER_FIND_MOTIF_GENERATED_FORWARDS_H 
#define SEQAN_HEADER_FIND_MOTIF_GENERATED_FORWARDS_H 

//////////////////////////////////////////////////////////////////////////////
// NOTE: This file is automatically generated by build_forwards.py
//       Do not edit this file manually!
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// CLASSES
//////////////////////////////////////////////////////////////////////////////

namespace SEQAN_NAMESPACE_MAIN {

//____________________________________________________________________________
// CMode_

struct CMode_;       	// "extras/include/seqan/find_motif/pseudocount_mode_c.h"(58)

//____________________________________________________________________________
// EPatternBranching_

struct EPatternBranching_;       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(67)

//____________________________________________________________________________
// FrequencyDistribution

template <typename TValue, typename TSpec > class FrequencyDistribution;       	// "extras/include/seqan/find_motif/frequency_distribution.h"(62)

//____________________________________________________________________________
// Motif

template <typename T> struct Motif;       	// "extras/include/seqan/find_motif/find_motif_base.h"(311)

//____________________________________________________________________________
// MotifFinder

template <typename TValue, typename TSpec, typename TRng > class MotifFinder;       	// "extras/include/seqan/find_motif/find_motif_base.h"(66)

//____________________________________________________________________________
// MotifFinderClass_

struct MotifFinderClass_;       	// "extras/include/seqan/find_motif/find_motif_base.h"(62)

//____________________________________________________________________________
// Omops

struct Omops;       	// "extras/include/seqan/find_motif/sequence_model_types.h"(70)

//____________________________________________________________________________
// Oops

struct Oops;       	// "extras/include/seqan/find_motif/sequence_model_types.h"(54)

//____________________________________________________________________________
// PMode_

struct PMode_;       	// "extras/include/seqan/find_motif/pseudocount_mode_p.h"(59)

//____________________________________________________________________________
// Pms1_

struct Pms1_;       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(66)

//____________________________________________________________________________
// Pmsp_

struct Pmsp_;       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(62)

//____________________________________________________________________________
// Projection_

struct Projection_;       	// "extras/include/seqan/find_motif/find_motif_projection.h"(63)

//____________________________________________________________________________
// Pseudocount

template <typename TValue, typename TSpec> class Pseudocount;       	// "extras/include/seqan/find_motif/pseudocount_base.h"(57)

//____________________________________________________________________________
// Tcm

struct Tcm;       	// "extras/include/seqan/find_motif/sequence_model_types.h"(115)

//____________________________________________________________________________
// Zoops

struct Zoops;       	// "extras/include/seqan/find_motif/sequence_model_types.h"(86)

} //namespace SEQAN_NAMESPACE_MAIN


//////////////////////////////////////////////////////////////////////////////
// TYPEDEFS
//////////////////////////////////////////////////////////////////////////////

namespace SEQAN_NAMESPACE_MAIN {

//____________________________________________________________________________
// CMode

typedef Tag<CMode_> CMode;       	// "extras/include/seqan/find_motif/pseudocount_mode_c.h"(59)

//____________________________________________________________________________
// EPatternBranching

typedef Tag<EPatternBranching_> const EPatternBranching;       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(68)

//____________________________________________________________________________
// MotifFinderClass

typedef Tag<MotifFinderClass_> MotifFinderClass;       	// "extras/include/seqan/find_motif/find_motif_base.h"(63)

//____________________________________________________________________________
// PMode

typedef Tag<PMode_> PMode;       	// "extras/include/seqan/find_motif/pseudocount_mode_p.h"(60)

//____________________________________________________________________________
// Pms1

typedef Tag<Pms1_> const Pms1;       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(67)

//____________________________________________________________________________
// Pmsp

typedef Tag<Pmsp_> const Pmsp;       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(63)

//____________________________________________________________________________
// Projection

typedef Tag<Projection_> const Projection;       	// "extras/include/seqan/find_motif/find_motif_projection.h"(64)

} //namespace SEQAN_NAMESPACE_MAIN


//////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

namespace SEQAN_NAMESPACE_MAIN {

//____________________________________________________________________________
// _buildVariants

template <typename TIntVect, typename TStringIter, typename TType, typename TBitset, typename TValue, typename TSpec> void _buildVariants(TIntVect & variants, TStringIter l_mer_begin, TType const & d, TBitset const & bitset, Shape<TValue, TSpec> & shape);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(763)

//____________________________________________________________________________
// _computeBucketThreshold

template <typename TType> TType _computeBucketThreshold(TType const & alp_size, TType const & l, TType const & d, TType const & m_total, TType const & k);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(290)

//____________________________________________________________________________
// _computeEStep

template <typename TMatrix, typename TProfile, typename TIter, typename TType> void _computeEStep(TMatrix & matrix_w, double & joint_log_likelihood, TProfile & profile, TIter dataset_start, TType const & t, TType const & l, Oops const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(136)
template <typename TMatrix, typename TProfile, typename TIter, typename TType> void _computeEStep(TMatrix & matrix_w, double & joint_log_likelihood, TProfile & profile, TIter dataset_start, double & gamma, TType const & t, TType const & l, Zoops const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(364)
template <typename TMatrix, typename TProfile, typename TIter, typename TType> void _computeEStep(TMatrix & matrix_w, double & joint_log_likelihood, TProfile & profile, TIter dataset_start, double & lambda, TType const & t, TType const & l, Tcm const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(631)

//____________________________________________________________________________
// _computeLikelihoodRatioOfLMer

template <typename TStrIter, typename TProfile> double _computeLikelihoodRatioOfLMer(TStrIter l_mer_begin, TStrIter l_mer_end, TProfile const & profile);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1115)

//____________________________________________________________________________
// _computeLikelihoodRatioOfLMers

template <typename TStrings, typename TProfile> double _computeLikelihoodRatioOfLMers(TStrings const & l_mers, TProfile const & profile);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1157)

//____________________________________________________________________________
// _computeMStep

template <typename TProfile, typename TIter, typename TMatrix, typename TType> void _computeMStep(TProfile & profile, TIter dataset_start, TMatrix const & matrix_w, TType const & t, TType const & l, Oops const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(235)
template <typename TProfile, typename TIter, typename TMatrix, typename TType> void _computeMStep(TProfile & profile, TIter dataset_start, TMatrix const & matrix_w, TType const & t, TType const & l, Zoops const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(494)
template <typename TProfile, typename TIter, typename TMatrix, typename TType> void _computeMStep(TProfile & profile, TIter dataset_start, TMatrix const & matrix_w, TType const & t, TType const & l, Tcm const & );       	// "extras/include/seqan/find_motif/em_algorithm.h"(728)

//____________________________________________________________________________
// _computeNumOfTrials

template <typename TType> TType _computeNumOfTrials(TType const & t, TType const & l, TType const & d, TType const & k, TType const & s, double const & prob_q);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(343)

//____________________________________________________________________________
// _computeProjectionSize

template <typename TType> TType _computeProjectionSize(TType const & alp_size, TType const & l, TType const & d, TType const & m_total);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(247)

//____________________________________________________________________________
// _filteringStep

template <typename TBucketAr, typename TArray, typename TType, typename TStrings, typename TPositions> void _filteringStep(TBucketAr & buckets, TArray & count_ar, TType & num_of_relevant_buckets, TStrings & dataset, TPositions & positions, TType const & l, TType const & s);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(530)

//____________________________________________________________________________
// _getLMersWithTheLargestLikelihoodRatio

template <typename TStrings, typename TIter, typename TType, typename TProfile> void _getLMersWithTheLargestLikelihoodRatio(TStrings & l_mers, TIter dataset_start, TIter dataset_end, TProfile const & profile, TType const & l);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1047)

//____________________________________________________________________________
// _getVariantsOfBitset

template <typename TStrings, typename TType> void _getVariantsOfBitset(TStrings & bitsets, TType const & l, TType const & d);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(703)

//____________________________________________________________________________
// _refinementStep

template <typename TString, typename TType> int _refinementStep(TString & consensus_seq, String<TString> const & l_mers, String<TString> & dataset, TType const & l, TType const & d, bool const & is_exact, Oops const & );       	// "extras/include/seqan/find_motif/find_motif_projection.h"(599)
template <typename TString, typename TType> int _refinementStep(TString & consensus_seq, String<TString> const & l_mers, String<TString> & dataset, TType const & l, TType const & d, bool const & is_exact, Omops const & );       	// "extras/include/seqan/find_motif/find_motif_projection.h"(682)
template <typename TString, typename TType> int _refinementStep(TString & consensus_seq, String<TString> const & l_mers, String<TString> & dataset, TType const & l, TType const & d, bool const & is_exact, Zoops const & zoops);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(760)
template <typename TString, typename TType> int _refinementStep(TString & consensus_seq, String<TString> const & l_mers, String<TString> & dataset, TType const & l, TType const & d, bool const & is_exact, Tcm const & tcm);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(862)

//____________________________________________________________________________
// _smoothingStep

template <typename TMatrix, typename TIter, typename TType> void _smoothingStep(TMatrix & matrix_w, TIter dataset_start, TType const & t, TType const & l);       	// "extras/include/seqan/find_motif/em_algorithm.h"(803)

//____________________________________________________________________________
// absFreqOfLettersInSeq

template <typename TValue, typename TSpec, typename TSeqIter> void absFreqOfLettersInSeq(FrequencyDistribution<TValue, TSpec> & fd, TSeqIter seq_start, TSeqIter seq_end);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(330)

//____________________________________________________________________________
// absFreqOfLettersInSetOfSeqs

template <typename TValue, typename TSpec, typename TIter> void absFreqOfLettersInSetOfSeqs(FrequencyDistribution<TValue, TSpec> & fd, TIter seq_start, TIter seq_end);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(361)

//____________________________________________________________________________
// addValue

template <typename TValue, typename TSpec, typename TType> void addValue(FrequencyDistribution<TValue, TSpec> & fd, TType const & val);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(386)

//____________________________________________________________________________
// backgroundFrequency

template <typename TValue, typename TSpec,typename TDatasetIter> void backgroundFrequency(FrequencyDistribution<TValue, TSpec> & fd, TDatasetIter dataset_start, TDatasetIter dataset_end);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(415)

//____________________________________________________________________________
// begin

template <typename TValue, typename TSpec> inline typename Iterator< FrequencyDistribution<TValue, TSpec> >::Type begin(FrequencyDistribution<TValue, TSpec> & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(436)
template <typename TValue, typename TSpec> inline typename Iterator< FrequencyDistribution<TValue, TSpec> >::Type begin(FrequencyDistribution<TValue, TSpec> const & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(442)

//____________________________________________________________________________
// bestNeighbors

template <typename TIntSet, typename TType, typename TStrings> void bestNeighbors(TIntSet & neighbors, int & l_mer, TType const & j, TType const & l, TType const & d, TStrings & dataset);       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(520)

//____________________________________________________________________________
// binomialCoefficient

template <typename TType> TType binomialCoefficient(TType n, TType k);       	// "extras/include/seqan/find_motif/find_motif_base.h"(162)

//____________________________________________________________________________
// choosePositions

template <typename TAssociativeContainer, typename TType, typename TRng> void choosePositions(TAssociativeContainer & positions, TType const & l, TType const & k, TRng & rng);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(966)

//____________________________________________________________________________
// clear

template <typename TValue, typename TSpec> void clear(FrequencyDistribution<TValue, TSpec> & fd);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(453)

//____________________________________________________________________________
// completeProfile

template <typename TProfile> void completeProfile(TProfile & profile, typename Value<TProfile>::Type & background_distribution);       	// "extras/include/seqan/find_motif/profile.h"(190)

//____________________________________________________________________________
// computeH

template <typename TType, typename TIntAr> TType computeH(TType const & t, TType const & l, TType const & d, bool const & is_exact, TIntAr & n_ar);       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(188)

//____________________________________________________________________________
// convertPatternToProfile

template <typename TProfile, typename TIterStr> void convertPatternToProfile(TProfile & profile, TIterStr str_begin, TIterStr str_end);       	// "extras/include/seqan/find_motif/profile.h"(75)

//____________________________________________________________________________
// convertResidueToFrequencyDist

template <typename TValue, typename TSpec> void convertResidueToFrequencyDist(FrequencyDistribution<TValue, TSpec> & fd, TValue const & residue);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(477)

//____________________________________________________________________________
// convertSetOfPatternsToProfile

template <typename TProfile, typename TStrings, typename TPseudocountMode> void convertSetOfPatternsToProfile(TProfile & profile, TStrings & l_mers, TPseudocountMode & pseudocount);       	// "extras/include/seqan/find_motif/profile.h"(112)

//____________________________________________________________________________
// createDVariants

template <typename TIntVect, typename TIterString, typename TType, typename TShape> void createDVariants(TIntVect & variants, TIterString l_mer_begin, TType const & l, TType const & d, bool is_exact, TShape & shape);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(638)

//____________________________________________________________________________
// determineConsensusSeq

template <typename TString, typename TProfile> void determineConsensusSeq(TString & consensus_seq, TProfile & profile, typename Size<TString>::Type const & l);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1193)

//____________________________________________________________________________
// display

template <typename TStrings> void display(TStrings & strings);       	// "extras/include/seqan/find_motif/profile.h"(223)

//____________________________________________________________________________
// displayResult

template <typename TValue, typename TAlgorithm, typename TRng> void displayResult(MotifFinder<TValue, TAlgorithm, TRng> & finder);       	// "extras/include/seqan/find_motif/find_motif_base.h"(276)
template <typename TValue, typename TRng> void displayResult(MotifFinder<TValue, Projection, TRng> & projection);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1238)

//____________________________________________________________________________
// ePatternBranching

template <typename TStrings, typename TType> void ePatternBranching(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, TType & h, Omops const & );       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(297)
template <typename TStrings, typename TType> void ePatternBranching(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, TType & h, Oops const & );       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(400)

//____________________________________________________________________________
// em

template <typename TProfile, typename TIter, typename TType> double em(TProfile & profile, TIter dataset_start, TType const & t, TType const & l, Oops const & oops);       	// "extras/include/seqan/find_motif/em_algorithm.h"(83)
template <typename TProfile, typename TIter, typename TType> double em(TProfile & profile, TIter dataset_start, TType const & t, TType const & l, double & gamma, Zoops const & zoops);       	// "extras/include/seqan/find_motif/em_algorithm.h"(307)
template <typename TProfile, typename TIter, typename TType> double em(TProfile & profile, TIter dataset_start, TType const & t, TType const & l, double & lambda, Tcm const & tcm);       	// "extras/include/seqan/find_motif/em_algorithm.h"(574)

//____________________________________________________________________________
// end

template <typename TValue, typename TSpec> inline typename Iterator< FrequencyDistribution<TValue, TSpec> >::Type end(FrequencyDistribution<TValue, TSpec> & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(502)
template <typename TValue, typename TSpec> inline typename Iterator< FrequencyDistribution<TValue, TSpec> const >::Type end(FrequencyDistribution<TValue, TSpec> const & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(508)

//____________________________________________________________________________
// factorial

template <typename TType> TType factorial(TType n);       	// "extras/include/seqan/find_motif/find_motif_base.h"(127)

//____________________________________________________________________________
// findMotif

template <typename TSeqType, typename TStrings, typename TModel, typename TRng> inline void findMotif(MotifFinder<TSeqType, EPatternBranching, TRng> & epb2, TStrings & dataset, TModel seq_model);       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(247)
template <typename TSeqType, typename TStrings, typename TModel, typename TRng> inline void findMotif(MotifFinder<TSeqType, Pms1, TRng> & finder, TStrings & dataset, TModel seq_model);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(144)
template <typename TSeqType, typename TStrings, typename TModel, typename TRng> inline void findMotif(MotifFinder<TSeqType, Pmsp, TRng> & finder, TStrings & dataset, TModel seq_model);       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(141)
template <typename TSeqType, typename TStrings, typename TModel, typename TRng> void findMotif(MotifFinder<TSeqType, Projection, TRng> & finder, TStrings & dataset, TModel seq_model);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(401)

//____________________________________________________________________________
// getMotif

template <typename TValue, typename TSpec, typename TPosition, typename TRng> inline typename Motif<MotifFinder<TValue, TSpec, TRng> >::Type & getMotif(MotifFinder<TValue, TSpec, TRng> & me, TPosition pos);       	// "extras/include/seqan/find_motif/find_motif_base.h"(335)
template <typename TValue, typename TSpec, typename TRng> inline typename Motif<MotifFinder<TValue, TSpec, TRng> >::Type & getMotif(MotifFinder<TValue, TSpec, TRng> & me);       	// "extras/include/seqan/find_motif/find_motif_base.h"(344)

//____________________________________________________________________________
// getScore

template <typename TValue, typename TRng> inline int getScore(MotifFinder<TValue, Projection, TRng> & me);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(1258)

//____________________________________________________________________________
// hammingDistance

template <typename TType, typename TStringIterator> TType hammingDistance(TStringIterator start1, TStringIterator end1, TStringIterator start2);       	// "extras/include/seqan/find_motif/find_motif_base.h"(204)

//____________________________________________________________________________
// hasAtLeastOneOccurrence

template <typename TStringIter, typename TType> bool hasAtLeastOneOccurrence(TStringIter l_mer_begin, TStringIter seq_begin, TStringIter seq_end, TType const & l, TType const & d, bool const & is_exact);       	// "extras/include/seqan/find_motif/find_motif_epatternbranching.h"(739)

//____________________________________________________________________________
// hasExactOneOccurrence

template <typename TStringIter, typename TType> bool hasExactOneOccurrence(TStringIter l_mer_begin, TStringIter seq_begin, TStringIter seq_end, TType const & l, TType const & d, bool const & is_exact);       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(765)

//____________________________________________________________________________
// inverseHash

template <typename TValue, typename TType> String<TValue> inverseHash(TType const & hash_value, typename Size<TValue>::Type const & alp_size, typename Size< String<TValue> >::Type const & seq_size);       	// "extras/include/seqan/find_motif/find_motif_base.h"(240)

//____________________________________________________________________________
// length

template <typename TValue, typename TSpec> inline typename Size< FrequencyDistribution<TValue, TSpec> >::Type length(FrequencyDistribution<TValue, TSpec> & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(519)
template <typename TValue, typename TSpec> inline typename Size< FrequencyDistribution<TValue, TSpec> >::Type length(FrequencyDistribution<TValue, TSpec> const & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(526)

//____________________________________________________________________________
// logarithmize

template <typename TValue, typename TSpec> void logarithmize(FrequencyDistribution<TValue, TSpec> & fd);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(545)

//____________________________________________________________________________
// motifCount

template <typename TValue, typename TSpec, typename TRng> inline size_t motifCount(MotifFinder<TValue, TSpec, TRng> const & me);       	// "extras/include/seqan/find_motif/find_motif_base.h"(363)

//____________________________________________________________________________
// normalize

template <typename TValue, typename TSpec> void normalize(FrequencyDistribution<TValue, TSpec> & fd);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(570)
template <typename TProfile> void normalize(TProfile & profile);       	// "extras/include/seqan/find_motif/profile.h"(161)
template <typename TProfile, typename TValue> void normalize(TProfile & profile, Pseudocount<TValue, CMode> const & mode);       	// "extras/include/seqan/find_motif/pseudocount_mode_c.h"(128)
template <typename TProfile, typename TValue> void normalize(TProfile & profile, Pseudocount<TValue, PMode> & mode);       	// "extras/include/seqan/find_motif/pseudocount_mode_p.h"(130)

//____________________________________________________________________________
// operator*

template <typename TValue, typename TSpec, typename TType> FrequencyDistribution<TValue, TSpec> operator* (FrequencyDistribution<TValue, TSpec> const & fd_, TType value_);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(181)

//____________________________________________________________________________
// operator+

template <typename TValue, typename TSpec> FrequencyDistribution<TValue, TSpec> operator+ (FrequencyDistribution<TValue, TSpec> const & lhs_, FrequencyDistribution<TValue, TSpec> const & rhs_);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(160)

//____________________________________________________________________________
// operator-

template <typename TValue, typename TSpec> FrequencyDistribution<TValue, TSpec> operator- (FrequencyDistribution<TValue, TSpec> const & lhs_, FrequencyDistribution<TValue, TSpec> const & rhs_);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(171)

//____________________________________________________________________________
// operator<<

template <typename TValue, typename TSpec> inline std::ostream & operator<< (std::ostream & ostr, FrequencyDistribution<TValue, TSpec> & fd_);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(191)

//____________________________________________________________________________
// pms1

template <typename TStrings, typename TType> void pms1(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Oops const & );       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(193)
template <typename TStrings, typename TType> void pms1(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Omops const & );       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(311)
template <typename TStrings, typename TType> void pms1(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Zoops const & model_type);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(401)
template <typename TStrings, typename TType> void pms1(TStrings & result_set, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Tcm const & model_type);       	// "extras/include/seqan/find_motif/find_motif_pms1.h"(510)

//____________________________________________________________________________
// pmsp

template <typename TStrings, typename TType> void pmsp(TStrings & result, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Oops const & );       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(194)
template <typename TStrings, typename TType> void pmsp(TStrings & result, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Omops const & );       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(317)
template <typename TStrings, typename TType> void pmsp(TStrings & result, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Zoops const & model_type);       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(436)
template <typename TStrings, typename TType> void pmsp(TStrings & result, TStrings & dataset, TType const & l, TType const & d, bool const & is_exact, Tcm const & model_type);       	// "extras/include/seqan/find_motif/find_motif_pmsp.h"(585)

//____________________________________________________________________________
// posOfMax

template <typename TValue, typename TSpec> typename Position< FrequencyDistribution<TValue, TSpec> >::Type posOfMax(FrequencyDistribution<TValue, TSpec> & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(596)

//____________________________________________________________________________
// projectLMer

template <typename TValue, typename TIter> inline std::set<int>::value_type projectLMer(std::set<int> & positions, TIter it);       	// "extras/include/seqan/find_motif/find_motif_projection.h"(996)

//____________________________________________________________________________
// sum

template <typename TValue, typename TSpec> TSpec sum(FrequencyDistribution<TValue, TSpec> & me);       	// "extras/include/seqan/find_motif/frequency_distribution.h"(629)

} //namespace SEQAN_NAMESPACE_MAIN

#endif

