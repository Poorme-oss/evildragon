/* evildragon
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


#ifndef evildragon_FETCH_H
#define evildragon_FETCH_H


#include "3rdparty/http-parser/http_parser.h"
#include "3rdparty/rapidjson/fwd.h"
#include "base/tools/String.h"


#include <map>
#include <memory>
#include <string>


namespace evildragon {


class IHttpListener;


class FetchRequest
{
public:
    FetchRequest() = default;
    FetchRequest(http_method method, const String &host, uint16_t port, const String &path, bool tls = false, bool quiet = false, const char *data = nullptr, size_t size = 0, const char *contentType = nullptr);
    FetchRequest(http_method method, const String &host, uint16_t port, const String &path, const rapidjson::Value &value, bool tls = false, bool quiet = false);

    void setBody(const char *data, size_t size, const char *contentType = nullptr);
    void setBody(const rapidjson::Value &value);

    inline bool hasBody() const { return method != HTTP_GET && method != HTTP_HEAD && !body.empty(); }

    bool quiet          = false;
    bool tls            = false;
    http_method method  = HTTP_GET;
    std::map<const std::string, const std::string> headers;
    std::string body;
    String fingerprint;
    String host;
    String path;
    uint16_t port       = 0;
};


void fetch(FetchRequest &&req, const std::weak_ptr<IHttpListener> &listener, int type = 0);


} // namespace evildragon


#endif // evildragon_FETCH_H

