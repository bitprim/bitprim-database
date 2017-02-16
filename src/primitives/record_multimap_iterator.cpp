/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/database/primitives/record_multimap_iterator.hpp>

#include <bitcoin/database/primitives/record_list.hpp>
#include <bitcoin/database/primitives/record_multimap_iterable.hpp>

namespace libbitcoin {
namespace database {

record_multimap_iterator::record_multimap_iterator(const record_list& records,
    array_index index)
  : index_(index), records_(records)
{
}

void record_multimap_iterator::operator++()
{
    index_ = records_.next(index_);
}
array_index record_multimap_iterator::operator*() const
{
    return index_;
}

record_multimap_iterator record_multimap_iterable::begin() const
{
    return record_multimap_iterator(records_, begin_);
}
record_multimap_iterator record_multimap_iterable::end() const
{
    return record_multimap_iterator(records_, records_.empty);
}

bool record_multimap_iterator::operator==(record_multimap_iterator other) const
{
    return this->index_ == other.index_;
}

bool record_multimap_iterator::operator!=(record_multimap_iterator other) const
{
    return this->index_ != other.index_;
}

} // namespace database
} // namespace libbitcoin
