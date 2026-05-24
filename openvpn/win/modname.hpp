//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012- OpenVPN Inc.
//
//    SPDX-License-Identifier: MPL-2.0 OR AGPL-3.0-only WITH openvpn3-openssl-exception
//

// windows SECURITY_ATTRIBUTES utilities

#ifndef OPENVPN_WIN_MODNAME_H
#define OPENVPN_WIN_MODNAME_H

#include <windows.h>

#include <string>

#include <openvpn/common/exception.hpp>
#include <openvpn/common/wstring.hpp>
#include <openvpn/win/winerr.hpp>

namespace openvpn::Win {

inline std::wstring module_name()
{
    // get path to our binary
    wchar_t path[MAX_PATH];
    if (!::GetModuleFileNameW(NULL, path, MAX_PATH))
    {
        const Win::LastError err;
        OPENVPN_THROW_EXCEPTION("GetModuleFileNameW failed: " << err.message());
    }
    return std::wstring(path);
}

inline std::string module_name_utf8()
{
    return wstring::to_utf8(module_name());
}

} // namespace openvpn::Win

#endif
