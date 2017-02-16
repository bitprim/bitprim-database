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
#ifndef LIBBITCOIN_DATABASE_ALLOCATOR_HPP
#define LIBBITCOIN_DATABASE_ALLOCATOR_HPP

#include <cstddef>
#include <cstdint>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/database/define.hpp>
#include <bitcoin/database/memory/memory.hpp>

namespace libbitcoin {
namespace database {

#ifdef REMAP_SAFETY

/// This class provides remap safe access to file-mapped memory.
/// The memory size is unprotected and unmanaged.
class BCD_API allocator
  : public memory, noncopyable
{
public:
    allocator(shared_mutex& mutex);
    ~allocator();

    /// Get the address indicated by the pointer.
    uint8_t* buffer();

    /// Advance the pointer the specified number of bytes.
    void increment(size_t value);

protected:
    friend class memory_map;

    /// Set the pointer.
    void assign(uint8_t* data);

private:
    shared_mutex& mutex_;
    uint8_t* data_;
};

#endif // REMAP_SAFETY

} // namespace database
} // namespace libbitcoin

#endif
