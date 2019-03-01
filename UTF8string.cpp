#include <iostream>
#include <string>

#include "UTF8string.hpp"
#include "utf8.h"

using namespace std;

size_t UTF8string::length() {
    return (size_t)utf8_charlen((unsigned char*)this->m_s.c_str());
}

size_t UTF8string::bytes() {
    return this->m_s.size();
}

int UTF8string::find(std::string substr) {
    const unsigned char* txt = (unsigned char*)this->m_s.c_str();
    const unsigned char* pat = (unsigned char*)substr.c_str();
    unsigned char* findpt = utf8_search(txt, pat);
    if (findpt == NULL)
        return 0;
    else 
        return 1 + utf8_bytes_to_charpos(const_cast<unsigned char*>(txt),
                                         static_cast<int>(findpt - txt));
}

void UTF8string::replace(UTF8string remove, UTF8string replacement) {
    string ret = string(), txt = this->value();
    string::size_type pos = string::npos;
    while ((pos = txt.find(remove.value())) != string::npos) {
        ret += txt.substr(0, pos) + replacement.value();
        txt = txt.substr(pos + remove.bytes(), txt.size());
    }
    this->m_s = ret + txt;
}

std::ostream &operator<<(std::ostream &os, const UTF8string &str) {
    os << str.m_s;
    return os;
}

UTF8string operator+(const UTF8string &s1, const UTF8string &s2) {
    UTF8string ret = UTF8string();
    ret.m_s = s1.value() + s2.value();
    return ret;
}

UTF8string operator*(const UTF8string &str, const int &n) {
    UTF8string ret = UTF8string();
    for (int i = 1; i <= n; ++ i)
        ret.m_s += str.m_s;
    return ret;
}

UTF8string operator*(const int &n, const UTF8string &str) {
    UTF8string ret = UTF8string();
    for (int i = 1; i <= n; ++ i)
        ret.m_s += str.m_s;
    return ret;
}

UTF8string operator!(const UTF8string &str) {
    UTF8string ret = UTF8string();
    string UTF8words[str.m_s.size()]; //str.bytes()
    int cnt = 0;
    unsigned char* txt = (unsigned char*)str.m_s.c_str();
    unsigned char* pt = txt;
    while (*pt != '\0') {
        unsigned char* prev_pt = pt;
        _utf8_incr(pt);
        ++ cnt;
        UTF8words[cnt - 1] = str.m_s.substr(prev_pt - txt, pt - prev_pt);
    }
    for (int i = cnt - 1; i >= 0; -- i)
        ret += UTF8words[i];
    return ret;
}

UTF8string &UTF8string::operator+=(const UTF8string &str) {
    m_s += str.m_s;
    return *this;
}
