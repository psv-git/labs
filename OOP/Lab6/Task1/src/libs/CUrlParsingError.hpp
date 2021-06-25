#ifndef CURLPARSINGERROR_HPP
#define CURLPARSINGERROR_HPP

#include "../task/stdafx.h"

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string& msg = "") noexcept;
	~CUrlParsingError();
};

#endif // CURLPARSINGERROR_HPP
