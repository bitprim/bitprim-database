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
#ifndef LIBBITCOIN_DATABASE_RECORD_MULTIMAP_HPP
#define LIBBITCOIN_DATABASE_RECORD_MULTIMAP_HPP

#include <cstdint>
#include <string>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/database/define.hpp>
#include <bitcoin/database/memory/memory.hpp>
#include <bitcoin/database/primitives/record_hash_table.hpp>
#include <bitcoin/database/primitives/record_manager.hpp>

namespace libbitcoin {
namespace database {

inline size_t multimap_record_size(size_t value_size)
{
    return sizeof(array_index) + value_size;
}

template <typename KeyType>
BC_CONSTEXPR size_t hash_table_multimap_record_size()
{
    // The hash table maps a key only to the first record index.
    return hash_table_record_size<KeyType>(sizeof(array_index));
}

/**
 * A multimap hashtable where each key maps to a set of fixed size
 * values.
 *
 * The database is abstracted on top of a record map, and linked records.
 * The map links keys to start indexes in the linked records.
 * The linked records are chains of records that can be iterated through
 * given a start index.
 */
template <typename KeyType>
class record_multimap
{
public:
    typedef serializer<uint8_t*>::functor write_function;
    typedef record_hash_table<KeyType> record_hash_table_type;

    record_multimap(record_hash_table_type& map, record_manager& manager);

    /// Add a new row for a key.
    void store(const KeyType& key, write_function write);

    /// Lookup a key, returning a traversable index.
    array_index find(const KeyType& key) const;

    /// Get a remap safe address pointer to the indexed data.
    memory_ptr get(array_index index) const;

    /// Delete the last row that was added for the key.
    bool unlink(const KeyType& key);

private:
    record_hash_table_type& map_;
    record_manager& manager_;
    mutable shared_mutex create_mutex_;
    mutable shared_mutex update_mutex_;
};

} // namespace database
} // namespace libbitcoin

#include <bitcoin/database/impl/record_multimap.ipp>

#endif
