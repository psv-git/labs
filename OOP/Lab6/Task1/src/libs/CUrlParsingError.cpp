#include "CUrlParsingError.hpp"

CUrlParsingError::CUrlParsingError(const std::string& msg) noexcept
	: std::invalid_argument(msg)
{
}

CUrlParsingError::~CUrlParsingError() {}
