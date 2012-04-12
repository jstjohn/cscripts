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


#ifndef SEQAN_HEADER_MATH_GENERATED_FORWARDS_H 
#define SEQAN_HEADER_MATH_GENERATED_FORWARDS_H 

//////////////////////////////////////////////////////////////////////////////
// NOTE: This file is automatically generated by build_forwards.py
//       Do not edit this file manually!
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// CLASSES
//////////////////////////////////////////////////////////////////////////////

namespace seqan {
namespace detail {

//____________________________________________________________________________
// GcdOptimalEvaluator

template <typename T > struct GcdOptimalEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(282)
template <typename T > struct GcdOptimalEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(298)

//____________________________________________________________________________
// GcdOptimalEvaluatorHelper

template <typename T, bool IsSpecialized, bool IsSigned > struct GcdOptimalEvaluatorHelper;       	// "extras/include/seqan/math/math_common_factor.h"(230)
template <typename T, bool IsSpecialized, bool IsSigned > struct GcdOptimalEvaluatorHelper;       	// "extras/include/seqan/math/math_common_factor.h"(276)

//____________________________________________________________________________
// GcdOptimalEvaluatorHelper2

template <bool IsSpecialized, bool IsSigned > struct GcdOptimalEvaluatorHelper2;       	// "extras/include/seqan/math/math_common_factor.h"(248)

//____________________________________________________________________________
// LcmOptimalEvaluator

template <typename T > struct LcmOptimalEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(408)
template <typename T > struct LcmOptimalEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(424)

//____________________________________________________________________________
// LcmOptimalEvaluatorHelper

template <typename T, bool IsSpecialized, bool IsSigned > struct LcmOptimalEvaluatorHelper;       	// "extras/include/seqan/math/math_common_factor.h"(356)
template <typename T, bool IsSpecialized, bool IsSigned > struct LcmOptimalEvaluatorHelper;       	// "extras/include/seqan/math/math_common_factor.h"(402)

//____________________________________________________________________________
// LcmOptimalEvaluatorHelper2

template <bool IsSpecialized, bool IsSigned > struct LcmOptimalEvaluatorHelper2;       	// "extras/include/seqan/math/math_common_factor.h"(374)

//____________________________________________________________________________
// empty_base

template <typename T> class empty_base;       	// "extras/include/seqan/math/math_operators.h"(55)

//____________________________________________________________________________
// false_t

struct false_t;       	// "extras/include/seqan/math/math_operators.h"(662)

//____________________________________________________________________________
// true_t

struct true_t;       	// "extras/include/seqan/math/math_operators.h"(661)

} //namespace detail
} //namespace seqan
//////////////////////////////////////////////////////////////////////////////

namespace seqan {

//____________________________________________________________________________
// GcdEvaluator

template <typename IntegerType > class GcdEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(63)

//____________________________________________________________________________
// LcmEvaluator

template <typename IntegerType > class LcmEvaluator;       	// "extras/include/seqan/math/math_common_factor.h"(79)

//____________________________________________________________________________
// Rational

template <typename TInt> class Rational;       	// "extras/include/seqan/math/math_rational.h"(48)
template <typename TInt> class Rational;       	// "extras/include/seqan/math/math_rational.h"(77)

//____________________________________________________________________________
// additive1

template <class T, class B > struct additive1;       	// "extras/include/seqan/math/math_operators.h"(371)

//____________________________________________________________________________
// additive2

template <class T, class U, class B > struct additive2;       	// "extras/include/seqan/math/math_operators.h"(365)

//____________________________________________________________________________
// arithmetic1

template <class T, class B > struct arithmetic1;       	// "extras/include/seqan/math/math_operators.h"(407)

//____________________________________________________________________________
// arithmetic2

template <class T, class U, class B > struct arithmetic2;       	// "extras/include/seqan/math/math_operators.h"(401)

//____________________________________________________________________________
// bidirectional_iteratable

template <class T, class P, class B > struct bidirectional_iteratable;       	// "extras/include/seqan/math/math_operators.h"(580)

//____________________________________________________________________________
// bitwise1

template <class T, class B > struct bitwise1;       	// "extras/include/seqan/math/math_operators.h"(433)

//____________________________________________________________________________
// bitwise2

template <class T, class U, class B > struct bitwise2;       	// "extras/include/seqan/math/math_operators.h"(426)

//____________________________________________________________________________
// decrementable

template <class T, class B > struct decrementable;       	// "extras/include/seqan/math/math_operators.h"(228)

//____________________________________________________________________________
// dereferenceable

template <class T, class P, class B > struct dereferenceable;       	// "extras/include/seqan/math/math_operators.h"(243)

//____________________________________________________________________________
// equality_comparable1

template <class T, class B > struct equality_comparable1;       	// "extras/include/seqan/math/math_operators.h"(100)

//____________________________________________________________________________
// equality_comparable2

template <class T, class U, class B > struct equality_comparable2;       	// "extras/include/seqan/math/math_operators.h"(92)

//____________________________________________________________________________
// equivalent1

template <class T, class B > struct equivalent1;       	// "extras/include/seqan/math/math_operators.h"(312)

//____________________________________________________________________________
// equivalent2

SEQAN_BINARY_OPERATOR( left_shiftable, << ) SEQAN_BINARY_OPERATOR( right_shiftable,  ) template <class T, class U, class B = detail::empty_base<T> > struct equivalent2;       	// "extras/include/seqan/math/math_operators.h"(303)

//____________________________________________________________________________
// euclidean_ring_operators1

template <class T, class B > struct euclidean_ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(545)

//____________________________________________________________________________
// euclidean_ring_operators2

template <class T, class U, class B > struct euclidean_ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(538)

//____________________________________________________________________________
// euclidian_ring_operators1

template <class T, class B > struct euclidian_ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(517)

//____________________________________________________________________________
// euclidian_ring_operators2

template <class T, class U, class B > struct euclidian_ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(510)

//____________________________________________________________________________
// field_operators1

template <class T, class B > struct field_operators1;       	// "extras/include/seqan/math/math_operators.h"(489)

//____________________________________________________________________________
// field_operators2

template <class T, class U, class B > struct field_operators2;       	// "extras/include/seqan/math/math_operators.h"(483)

//____________________________________________________________________________
// forward_iteratable

template <class T, class P, class B > struct forward_iteratable;       	// "extras/include/seqan/math/math_operators.h"(574)

//____________________________________________________________________________
// incrementable

SEQAN_BINARY_OPERATOR_COMMUTATIVE( multipliable, * ) SEQAN_BINARY_OPERATOR_COMMUTATIVE( addable, + ) SEQAN_BINARY_OPERATOR_NON_COMMUTATIVE( subtractable, - ) SEQAN_BINARY_OPERATOR_NON_COMMUTATIVE( dividable, / ) SEQAN_BINARY_OPERATOR_NON_COMMUTATIVE( modable, % ) SEQAN_BINARY_OPERATOR_COMMUTATIVE( xorable, ^ ) SEQAN_BINARY_OPERATOR_COMMUTATIVE( andable, & ) SEQAN_BINARY_OPERATOR_COMMUTATIVE( orable, | ) template <class T, class B > struct incrementable;       	// "extras/include/seqan/math/math_operators.h"(215)

//____________________________________________________________________________
// indexable

template <class T, class I, class R, class B > struct indexable;       	// "extras/include/seqan/math/math_operators.h"(252)

//____________________________________________________________________________
// input_iteratable

template <class T, class P, class B > struct input_iteratable;       	// "extras/include/seqan/math/math_operators.h"(564)

//____________________________________________________________________________
// integer_arithmetic1

template <class T, class B > struct integer_arithmetic1;       	// "extras/include/seqan/math/math_operators.h"(419)

//____________________________________________________________________________
// integer_arithmetic2

template <class T, class U, class B > struct integer_arithmetic2;       	// "extras/include/seqan/math/math_operators.h"(413)

//____________________________________________________________________________
// integer_multiplicative1

template <class T, class B > struct integer_multiplicative1;       	// "extras/include/seqan/math/math_operators.h"(395)

//____________________________________________________________________________
// integer_multiplicative2

template <class T, class U, class B > struct integer_multiplicative2;       	// "extras/include/seqan/math/math_operators.h"(389)

//____________________________________________________________________________
// is_chained_base

template <class T> struct is_chained_base;       	// "extras/include/seqan/math/math_operators.h"(668)

//____________________________________________________________________________
// less_than_comparable1

template <class T, class B > struct less_than_comparable1;       	// "extras/include/seqan/math/math_operators.h"(84)

//____________________________________________________________________________
// less_than_comparable2

template <class T, class U, class B > struct less_than_comparable2;       	// "extras/include/seqan/math/math_operators.h"(73)

//____________________________________________________________________________
// multiplicative1

template <class T, class B > struct multiplicative1;       	// "extras/include/seqan/math/math_operators.h"(383)

//____________________________________________________________________________
// multiplicative2

template <class T, class U, class B > struct multiplicative2;       	// "extras/include/seqan/math/math_operators.h"(377)

//____________________________________________________________________________
// operators

template <class T, class U > struct operators;       	// "extras/include/seqan/math/math_operators.h"(835)
template <class T> struct operators<T, T> template <class T> struct operators;       	// "extras/include/seqan/math/math_operators.h"(845)

//____________________________________________________________________________
// operators2

SEQAN_OPERATOR_TEMPLATE(less_than_comparable) SEQAN_OPERATOR_TEMPLATE(equality_comparable) SEQAN_OPERATOR_TEMPLATE(multipliable) SEQAN_OPERATOR_TEMPLATE(addable) SEQAN_OPERATOR_TEMPLATE(subtractable) SEQAN_OPERATOR_TEMPLATE2(subtractable2_left) SEQAN_OPERATOR_TEMPLATE(dividable) SEQAN_OPERATOR_TEMPLATE2(dividable2_left) SEQAN_OPERATOR_TEMPLATE(modable) SEQAN_OPERATOR_TEMPLATE2(modable2_left) SEQAN_OPERATOR_TEMPLATE(xorable) SEQAN_OPERATOR_TEMPLATE(andable) SEQAN_OPERATOR_TEMPLATE(orable) SEQAN_OPERATOR_TEMPLATE1(incrementable) SEQAN_OPERATOR_TEMPLATE1(decrementable) SEQAN_OPERATOR_TEMPLATE2(dereferenceable) SEQAN_OPERATOR_TEMPLATE3(indexable) SEQAN_OPERATOR_TEMPLATE(left_shiftable) SEQAN_OPERATOR_TEMPLATE(right_shiftable) SEQAN_OPERATOR_TEMPLATE(equivalent) SEQAN_OPERATOR_TEMPLATE(partially_ordered) SEQAN_OPERATOR_TEMPLATE(totally_ordered) SEQAN_OPERATOR_TEMPLATE(additive) SEQAN_OPERATOR_TEMPLATE(multiplicative) SEQAN_OPERATOR_TEMPLATE(integer_multiplicative) SEQAN_OPERATOR_TEMPLATE(arithmetic) SEQAN_OPERATOR_TEMPLATE(integer_arithmetic) SEQAN_OPERATOR_TEMPLATE(bitwise) SEQAN_OPERATOR_TEMPLATE1(unit_steppable) SEQAN_OPERATOR_TEMPLATE(shiftable) SEQAN_OPERATOR_TEMPLATE(ring_operators) SEQAN_OPERATOR_TEMPLATE(ordered_ring_operators) SEQAN_OPERATOR_TEMPLATE(field_operators) SEQAN_OPERATOR_TEMPLATE(ordered_field_operators) SEQAN_OPERATOR_TEMPLATE(euclidian_ring_operators) SEQAN_OPERATOR_TEMPLATE(ordered_euclidian_ring_operators) SEQAN_OPERATOR_TEMPLATE(euclidean_ring_operators) SEQAN_OPERATOR_TEMPLATE(ordered_euclidean_ring_operators) SEQAN_OPERATOR_TEMPLATE2(input_iteratable) SEQAN_OPERATOR_TEMPLATE1(output_iteratable) SEQAN_OPERATOR_TEMPLATE2(forward_iteratable) SEQAN_OPERATOR_TEMPLATE2(bidirectional_iteratable) SEQAN_OPERATOR_TEMPLATE4(random_access_iteratable)  template <class T, class U> struct operators2;       	// "extras/include/seqan/math/math_operators.h"(831)

//____________________________________________________________________________
// ordered_euclidean_ring_operators1

template <class T, class B > struct ordered_euclidean_ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(557)

//____________________________________________________________________________
// ordered_euclidean_ring_operators2

template <class T, class U, class B > struct ordered_euclidean_ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(551)

//____________________________________________________________________________
// ordered_euclidian_ring_operators1

template <class T, class B > struct ordered_euclidian_ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(529)

//____________________________________________________________________________
// ordered_euclidian_ring_operators2

template <class T, class U, class B > struct ordered_euclidian_ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(523)

//____________________________________________________________________________
// ordered_field_operators1

template <class T, class B > struct ordered_field_operators1;       	// "extras/include/seqan/math/math_operators.h"(501)

//____________________________________________________________________________
// ordered_field_operators2

template <class T, class U, class B > struct ordered_field_operators2;       	// "extras/include/seqan/math/math_operators.h"(495)

//____________________________________________________________________________
// ordered_ring_operators1

template <class T, class B > struct ordered_ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(476)

//____________________________________________________________________________
// ordered_ring_operators2

template <class T, class U, class B > struct ordered_ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(470)

//____________________________________________________________________________
// output_iteratable

template <class T, class B > struct output_iteratable;       	// "extras/include/seqan/math/math_operators.h"(569)

//____________________________________________________________________________
// partially_ordered1

template <class T, class B > struct partially_ordered1;       	// "extras/include/seqan/math/math_operators.h"(338)

//____________________________________________________________________________
// partially_ordered2

template <class T, class U, class B > struct partially_ordered2;       	// "extras/include/seqan/math/math_operators.h"(321)

//____________________________________________________________________________
// random_access_iteratable

template <class T, class P, class D, class R, class B > struct random_access_iteratable;       	// "extras/include/seqan/math/math_operators.h"(592)

//____________________________________________________________________________
// ring_operators1

template <class T, class B > struct ring_operators1;       	// "extras/include/seqan/math/math_operators.h"(464)

//____________________________________________________________________________
// ring_operators2

template <class T, class U, class B > struct ring_operators2;       	// "extras/include/seqan/math/math_operators.h"(458)

//____________________________________________________________________________
// shiftable1

template <class T, class B > struct shiftable1;       	// "extras/include/seqan/math/math_operators.h"(451)

//____________________________________________________________________________
// shiftable2

template <class T, class U, class B > struct shiftable2;       	// "extras/include/seqan/math/math_operators.h"(445)

//____________________________________________________________________________
// template_name

template <class T, class U, class V, class W, class B > \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(628)
template <class T, class U, class V, class B > \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(632)
template <class T, class U, class B > \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(636)
template <class T, class B > \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(640)
template <class T                         \ ,class U ,class B ,class O >                             \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(728)
\ \ SEQAN_OPERATOR_TEMPLATE2(template_name##2)             \ SEQAN_OPERATOR_TEMPLATE1(template_name##1) SEQAN_IMPORT_TEMPLATE4(template_name4) SEQAN_IMPORT_TEMPLATE3(template_name3) SEQAN_IMPORT_TEMPLATE2(template_name2) SEQAN_IMPORT_TEMPLATE1(template_name1)  template <class T, class B >  \ struct template_name;       	// "extras/include/seqan/math/math_operators.h"(762)

//____________________________________________________________________________
// totally_ordered1

template <class T, class B > struct totally_ordered1;       	// "extras/include/seqan/math/math_operators.h"(359)

//____________________________________________________________________________
// totally_ordered2

template <class T, class U, class B > struct totally_ordered2;       	// "extras/include/seqan/math/math_operators.h"(353)

//____________________________________________________________________________
// unit_steppable

template <class T, class B > struct unit_steppable;       	// "extras/include/seqan/math/math_operators.h"(439)

} //namespace seqan


//////////////////////////////////////////////////////////////////////////////
// TYPEDEFS


//////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

namespace seqan {
namespace detail {

//____________________________________________________________________________
// gcdEuclidean

template <typename RingType > RingType gcdEuclidean ( RingType a, RingType b );       	// "extras/include/seqan/math/math_common_factor.h"(102)

//____________________________________________________________________________
// gcdInteger

template <typename IntegerType > inline IntegerType gcdInteger ( IntegerType const & a, IntegerType const & b );       	// "extras/include/seqan/math/math_common_factor.h"(128)

//____________________________________________________________________________
// gcdOptimal

template <typename T > inline T gcdOptimal ( T const & a, T const & b );       	// "extras/include/seqan/math/math_common_factor.h"(441)

//____________________________________________________________________________
// gcd_binary

template <typename BuiltInUnsigned > BuiltInUnsigned gcd_binary ( BuiltInUnsigned u, BuiltInUnsigned v );       	// "extras/include/seqan/math/math_common_factor.h"(144)

//____________________________________________________________________________
// lcmEuclidean

template <typename RingType > inline RingType lcmEuclidean ( RingType const & a, RingType const & b );       	// "extras/include/seqan/math/math_common_factor.h"(201)

//____________________________________________________________________________
// lcmInteger

template <typename IntegerType > inline IntegerType lcmInteger ( IntegerType const & a, IntegerType const & b );       	// "extras/include/seqan/math/math_common_factor.h"(217)

//____________________________________________________________________________
// lcmOptimal

template <typename T > inline T lcmOptimal ( T const & a, T const & b );       	// "extras/include/seqan/math/math_common_factor.h"(455)

} //namespace detail
} //namespace seqan
//////////////////////////////////////////////////////////////////////////////

namespace seqan {

//____________________________________________________________________________
// ()

template <typename IntegerType > inline typename GcdEvaluator<IntegerType>::resultType GcdEvaluator<IntegerType>::operator () ( firstArgumentType const &  a, secondArgumentType const & b ) const;       	// "extras/include/seqan/math/math_common_factor.h"(474)
template <typename IntegerType > inline typename LcmEvaluator<IntegerType>::resultType LcmEvaluator<IntegerType>::operator () ( firstArgumentType const &  a, secondArgumentType const & b ) const;       	// "extras/include/seqan/math/math_common_factor.h"(489)

//____________________________________________________________________________
// Rational<TInt>::assign

template <typename TInt> inline Rational<TInt>& Rational<TInt>::assign(param_type n, param_type d);       	// "extras/include/seqan/math/math_rational.h"(161)

//____________________________________________________________________________
// Rational<TInt>::normalize

template <typename TInt> void Rational<TInt>::normalize();       	// "extras/include/seqan/math/math_rational.h"(454)

//____________________________________________________________________________
// Rational<TInt>::operator*=

template <typename TInt> Rational<TInt>& Rational<TInt>::operator*= (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(238)
template <typename TInt> inline Rational<TInt>& Rational<TInt>::operator*= (param_type i);       	// "extras/include/seqan/math/math_rational.h"(298)

//____________________________________________________________________________
// Rational<TInt>::operator++

template <typename TInt> inline const Rational<TInt>& Rational<TInt>::operator++();       	// "extras/include/seqan/math/math_rational.h"(312)

//____________________________________________________________________________
// Rational<TInt>::operator+=

template <typename TInt> Rational<TInt>& Rational<TInt>::operator+= (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(184)
template <typename TInt> inline Rational<TInt>& Rational<TInt>::operator+= (param_type i);       	// "extras/include/seqan/math/math_rational.h"(284)

//____________________________________________________________________________
// Rational<TInt>::operator--

template <typename TInt> inline const Rational<TInt>& Rational<TInt>::operator--();       	// "extras/include/seqan/math/math_rational.h"(320)

//____________________________________________________________________________
// Rational<TInt>::operator-=

template <typename TInt> Rational<TInt>& Rational<TInt>::operator-= (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(219)
template <typename TInt> inline Rational<TInt>& Rational<TInt>::operator-= (param_type i);       	// "extras/include/seqan/math/math_rational.h"(291)

//____________________________________________________________________________
// Rational<TInt>::operator/=

template <typename TInt> Rational<TInt>& Rational<TInt>::operator/= (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(253)
template <typename TInt> inline Rational<TInt>& Rational<TInt>::operator/= (param_type i);       	// "extras/include/seqan/math/math_rational.h"(305)

//____________________________________________________________________________
// Rational<TInt>::operator<

template <typename TInt> bool Rational<TInt>::operator< (const Rational<TInt>& r) const;       	// "extras/include/seqan/math/math_rational.h"(329)
template <typename TInt> bool Rational<TInt>::operator< (param_type i) const;       	// "extras/include/seqan/math/math_rational.h"(404)

//____________________________________________________________________________
// Rational<TInt>::operator==

template <typename TInt> inline bool Rational<TInt>::operator== (const Rational<TInt>& r) const;       	// "extras/include/seqan/math/math_rational.h"(433)
template <typename TInt> inline bool Rational<TInt>::operator== (param_type i) const;       	// "extras/include/seqan/math/math_rational.h"(439)

//____________________________________________________________________________
// Rational<TInt>::operator>

template <typename TInt> bool Rational<TInt>::operator> (param_type i) const;       	// "extras/include/seqan/math/math_rational.h"(422)

//____________________________________________________________________________
// Rational<TInt>::test_invariant

template <typename TInt> inline bool Rational<TInt>::test_invariant() const;       	// "extras/include/seqan/math/math_rational.h"(446)

//____________________________________________________________________________
// SEQAN_IMPORT_TEMPLATE1

SEQAN_IMPORT_TEMPLATE1(template_name1)              \ template <class T, class B>                    \ struct is_chained_base< template_name1<T, B> >;       	// "extras/include/seqan/math/math_operators.h"(704)

//____________________________________________________________________________
// SEQAN_IMPORT_TEMPLATE2

SEQAN_IMPORT_TEMPLATE2(template_name2)              \ template <class T, class U, class B>               \ struct is_chained_base< template_name2<T, U, B> >;       	// "extras/include/seqan/math/math_operators.h"(695)

//____________________________________________________________________________
// SEQAN_IMPORT_TEMPLATE3

SEQAN_IMPORT_TEMPLATE3(template_name3)               \ template <class T, class U, class V, class B>            \ struct is_chained_base< template_name3<T, U, V, B> >;       	// "extras/include/seqan/math/math_operators.h"(686)

//____________________________________________________________________________
// SEQAN_IMPORT_TEMPLATE4

SEQAN_IMPORT_TEMPLATE4(template_name4)               \ template <class T, class U, class V, class W, class B>        \ struct is_chained_base< template_name4<T, U, V, W, B> >;       	// "extras/include/seqan/math/math_operators.h"(677)

//____________________________________________________________________________
// abs

template <typename TInt> inline Rational<TInt> abs(const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(545)

//____________________________________________________________________________
// ceil

template <typename TInt> inline TInt ceil(const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(569)

//____________________________________________________________________________
// floor

template <typename TInt> inline TInt floor(const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(555)

//____________________________________________________________________________
// greatestCommonDivisor

template <typename IntegerType > inline IntegerType greatestCommonDivisor ( IntegerType const & a, IntegerType const & b );       	// "extras/include/seqan/math/math_common_factor.h"(503)

//____________________________________________________________________________
// leastCommonMultiple

template <typename IntegerType > inline IntegerType leastCommonMultiple ( IntegerType const & a, IntegerType const & b );       	// "extras/include/seqan/math/math_common_factor.h"(516)

//____________________________________________________________________________
// operator+

template <typename TInt> inline Rational<TInt> operator+ (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(171)

//____________________________________________________________________________
// operator-

template <typename TInt> inline Rational<TInt> operator- (const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(177)

//____________________________________________________________________________
// operator<<

template <typename TInt> std::ostream& operator<< (std::ostream& os, const Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(528)

//____________________________________________________________________________
// operator>>

template <typename TInt> std::istream& operator>> (std::istream& is, Rational<TInt>& r);       	// "extras/include/seqan/math/math_rational.h"(483)

//____________________________________________________________________________
// rational_cast

template <typename T, typename TInt> inline T rational_cast(const Rational<TInt>& src);       	// "extras/include/seqan/math/math_rational.h"(536)

} //namespace seqan

#endif

