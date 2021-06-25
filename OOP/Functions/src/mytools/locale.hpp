#ifndef LOCALE_HPP
#define LOCALE_HPP

#include <locale>
#include <string>


namespace Mts {

  static std::locale locale;

  void SetLocale(const std::string &localeName);

}

#endif // LOCALE_HPP
