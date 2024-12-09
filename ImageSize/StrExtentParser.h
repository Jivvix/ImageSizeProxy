#pragma once
#include <string>
#include "Rect.h"
#include <optional>
class StrExtentParser final
{
	bool parsed_successful = false;
	std::string str;
	static std::optional<int> try_get_int(std::istream& stream);
public:
	StrExtentParser(const std::string& src) : str(src) {};
	Rect parse();
	bool is_parsed() const {
		return parsed_successful;
	}
};

