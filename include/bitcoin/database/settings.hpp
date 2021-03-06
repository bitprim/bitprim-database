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
#ifndef LIBBITCOIN_DATABASE_SETTINGS_HPP
#define LIBBITCOIN_DATABASE_SETTINGS_HPP

#include <cstdint>
#include <boost/filesystem.hpp>
#include <bitcoin/database/define.hpp>

namespace libbitcoin {
namespace database {

/// Common database configuration settings, properties not thread safe.
class BCD_API settings
{
public:
    settings();
    settings(config::settings context);

    /// Properties.
    boost::filesystem::path directory;
    bool flush_writes;
    uint16_t file_growth_rate;
    uint32_t index_start_height;

#ifdef BITPRIM_DB_NEW
    uint32_t reorg_pool_limit;
    uint64_t db_max_size;
    bool safe_mode;
#endif // BITPRIM_DB_NEW


#ifdef BITPRIM_DB_LEGACY
    uint32_t block_table_buckets;
    uint32_t transaction_table_buckets;
#endif // BITPRIM_DB_LEGACY

#ifdef BITPRIM_DB_TRANSACTION_UNCONFIRMED
    uint32_t transaction_unconfirmed_table_buckets;
#endif // BITPRIM_DB_STEALTH        

#ifdef BITPRIM_DB_SPENDS
    uint32_t spend_table_buckets;
#endif // BITPRIM_DB_SPENDS

#ifdef BITPRIM_DB_HISTORY
    uint32_t history_table_buckets;
#endif // BITPRIM_DB_HISTORY

// #ifdef BITPRIM_DB_UNSPENT_LIBBITCOIN
    uint32_t cache_capacity;
// #endif // BITPRIM_DB_UNSPENT_LIBBITCOIN

#if defined(WITH_REMOTE_DATABASE)    
    config::endpoint replier;
#endif //defined(WITH_REMOTE_DATABASE)        

};

} // namespace database
} // namespace libbitcoin

#endif
