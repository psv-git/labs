#include "Global.hpp"

ProtocolParameters HTTP_PARMS = { "http", 80 };
ProtocolParameters HTTPS_PARMS = { "https", 443 };

std::map<Protocol, ProtocolParameters> PROTOCOL_DESCRIPTION = {
	{ Protocol::HTTP, HTTP_PARMS },
	{ Protocol::HTTPS, HTTPS_PARMS }
};
