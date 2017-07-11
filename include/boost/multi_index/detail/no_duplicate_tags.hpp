/* Copyright 2003-2017 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef BOOST_MULTI_INDEX_DETAIL_NO_DUPLICATE_TAGS_HPP
#define BOOST_MULTI_INDEX_DETAIL_NO_DUPLICATE_TAGS_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <boost/mp11/algorithm.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/set.hpp>

namespace boost{

namespace multi_index{

namespace detail{

/* no_duplicate_tags check at compile-time that a tag list
 * has no duplicate tags.
 */

template<typename TagList>
struct no_duplicate_tags
{
  typedef mp11::mp_fold<
    TagList,
    mp11::mp_list<>,
    mp11::mp_set_push_back
  > aux;
 
  BOOST_STATIC_CONSTANT(
    bool,value=(mp11::mp_size<TagList>::value==mp11::mp_size<aux>::value));
};

/* Variant for an index list: duplication is checked
 * across all the indices.
 */

template<typename Index>
using index_tag_list=typename Index::tag_list;

template<typename IndexList>
using no_duplicate_tags_in_index_list=no_duplicate_tags<
  mp11::mp_apply<
    mp11::mp_append,
    mp11::mp_transform<index_tag_list,IndexList>
  >
>;

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#endif
