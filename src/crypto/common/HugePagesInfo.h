/* evildragon
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018-2019 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2019 evildragon       <https://github.com/evildragon>, <support@evildragon.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef evildragon_HUGEPAGESINFO_H
#define evildragon_HUGEPAGESINFO_H


#include <cstdint>
#include <cstddef>


namespace evildragon {


class VirtualMemory;


class HugePagesInfo
{
public:
    HugePagesInfo() = default;
    HugePagesInfo(const VirtualMemory *memory);

    size_t allocated    = 0;
    size_t total        = 0;
    size_t size         = 0;

    inline bool isFullyAllocated() const { return allocated == total; }
    inline double percent() const        { return allocated == 0 ? 0.0 : static_cast<double>(allocated) / total * 100.0; }
    inline void reset()                  { allocated = 0; total = 0; size = 0; }

    inline HugePagesInfo &operator+=(const HugePagesInfo &other)
    {
        allocated += other.allocated;
        total     += other.total;
        size      += other.size;

        return *this;
    }
};


} /* namespace evildragon */


#endif /* evildragon_HUGEPAGESINFO_H */
