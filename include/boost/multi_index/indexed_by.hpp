/* Copyright 2003-2017 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef BOOST_MULTI_INDEX_INDEXED_BY_HPP
#define BOOST_MULTI_INDEX_INDEXED_BY_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <boost/mp11/list.hpp>

/* An alias to mp11::mp_list used to hide Mp11 from the user.
 * indexed_by contains the index specifiers for instantiation
 * of a multi_index_container.
 */

namespace boost{

namespace multi_index{

template<typename... T>
using indexed_by=mp11::mp_list<T...>;

} /* namespace multi_index */

} /* namespace boost */

#undef BOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM
#undef BOOST_MULTI_INDEX_INDEXED_BY_SIZE

#endif
