#pragma once

#include <ofstream>
#include <string>

template <typename T>
    inline std::string tostr(const T& t)
    {
        std::ostringstream os;
        os << t;
        return os.str();
    }
