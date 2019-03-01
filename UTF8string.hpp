#ifndef UTF8STRING_HPP
#define UTF8STRING_HPP

#include <iostream>
#include <string>

class UTF8string {
      std::string  m_s;

  public:
      // Constructors - No code required
      UTF8string(){ };
      UTF8string(const char *s) {m_s = std::string(s);};
      UTF8string(std::string s) {m_s = s;};
      // 
      // The four following functions need to be coded
      // in UTF8string.cpp
      //
      size_t  length();  // Number of UTF-8 characters in the string
      size_t  bytes();   // Number of bytes in the string
      // IMPORTANT: for find(), 1st character = 1 (not zero)
      // Return 0 if not found
      int     find(std::string substr);
      void    replace(UTF8string remove, UTF8string replacement);
      // ---------------------------------------
      // value() is for checking what was done
      // No code required
      std::string  value() {return m_s;}; 

      // Test destructor to trace the object
      // ~UTF8string() {
      //       std::cout << "destroyed" << std::endl;
      // }

      friend std::ostream &operator<<(std::ostream &os, const UTF8string &str);

      UTF8string operator+(const UTF8string &s1, const UTF8string &s2);

      friend UTF8string operator*(const UTF8string &str, const int &n);

      friend UTF8string operator*(const int &n, const UTF8string &str);

      friend UTF8string operator!(const UTF8string &str);

      UTF8string &operator+=(const UTF8string &str);
};

#endif
