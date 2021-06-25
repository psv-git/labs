#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "../task/stdafx.h"

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

struct ProtocolParameters
{
	std::string protToStr;
	unsigned short defaultPort;
};

extern ProtocolParameters HTTP_PARMS;
extern ProtocolParameters HTTPS_PARMS;

extern std::map<Protocol, ProtocolParameters> PROTOCOL_DESCRIPTION;

constexpr unsigned short USINT_MAX = std::numeric_limits<unsigned short>::max();

#endif // GLOBAL_HPP
