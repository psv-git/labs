#include "locale.hpp"

void Mts::SetLocale(const std::string &localeName) {
  std::string ru_locale;
  std::string en_locale;

#if _WIN32 || _WIN64
  ru_locale = "Russian";
  en_locale = "English";
#elif __linux__
  ru_locale = "ru_RU.UTF-8";
  en_locale = "en_US.UTF-8";
#endif

  if (localeName == "ru")
    std::setlocale(LC_ALL, ru_locale.c_str());
  else if (localeName == "en")
    std::setlocale(LC_ALL, en_locale.c_str());
  std::setlocale(LC_NUMERIC, en_locale.c_str());
}
