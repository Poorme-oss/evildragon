/* evildragon
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018-2020 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2020 evildragon       <https://github.com/evildragon>, <support@evildragon.com>
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

#ifndef evildragon_PROCESS_H
#define evildragon_PROCESS_H


#include "base/tools/Arguments.h"


namespace evildragon {


class Process
{
public:
    enum Location {
        ExeLocation,
        CwdLocation,
        DataLocation,
        HomeLocation,
        TempLocation
    };

#   ifdef WIN32
    constexpr const static char kDirSeparator = '\\';
#   else
    constexpr const static char kDirSeparator = '/';
#   endif

    Process(int argc, char **argv);

    static int pid();
    static int ppid();
    static String exepath();
    static String location(Location location, const char *fileName = nullptr);

    inline const Arguments &arguments() const { return m_arguments; }

private:
    Arguments m_arguments;
};


} /* namespace evildragon */


#endif /* evildragon_PROCESS_H */