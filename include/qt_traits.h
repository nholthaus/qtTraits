//--------------------------------------------------------------------------------------------------
// 
//	qtTraits: A compile-time c++14 type trait library for Qt
//
//--------------------------------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
// and associated documentation files (the "Software"), to deal in the Software without 
// restriction, including without limitation the rights to use, copy, modify, merge, publish, 
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or 
// substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//--------------------------------------------------------------------------------------------------
// 
// Copyright (c) 2017 Nic Holthaus
// 
//--------------------------------------------------------------------------------------------------
//
// ATTRIBUTION:
// Parts of this work have been adapted from: 
//
//--------------------------------------------------------------------------------------------------
//
/// @file	qt_traits.h
/// @brief	Complete implementation of `qtTraits` - A compile-time c++14 type trait library for Qt
///			with no dependencies
//--------------------------------------------------------------------------------------------------

#pragma once

#ifndef qt_traits_h__
#define qt_traits_h__

//------------------------
//	INCLUDES
//------------------------

// std
#include <type_traits>

// Qt
#include <QVariant>

#define QT_TRAITS_STRINGIFY(s) #s

//--------------------------------------------------------------------------------------------------
//	TRAITS
//--------------------------------------------------------------------------------------------------
namespace qt_traits
{
	/// Tests whether a type is an enum that uses the Q_ENUM macro
	template <class T>
	struct is_qenum;
}

//--------------------------------------------------------------------------------------------------
//	IMPLEMENTATIONS
//--------------------------------------------------------------------------------------------------
namespace qt_traits
{
	namespace details
	{
		// checks for existance of a static member named `memberX` with return type `int` and arguments `const char *` and `size_t`
		template <class T>
		struct is_qenum_impl
		{
			template<typename U, typename = std::enable_if<std::is_enum<U>::value>::type>
			static auto test(U* p) -> std::bool_constant<QMetaTypeId2<U>::Defined>;

			template<typename U>
			static std::false_type test(...);

			using type = typename std::is_same<std::true_type, decltype(test<T>(0))>::type;
			static constexpr bool value = std::is_same<std::true_type, decltype(test<T>(0))>::value;
		};
	}


	template <typename T>
	struct is_qenum : details::is_qenum_impl<T>::type {};
}

//--------------------------------------------------------------------------------------------------
//	HELPER VARIABLE TEMPLATES
//--------------------------------------------------------------------------------------------------
namespace qt_traits
{
	template<class T>
	constexpr bool is_qenum_v = is_qenum<T>::value;
}

#endif // qt_traits_h__