#include "StrExtentParser.h"
#include<sstream>
//add negative number check
Rect StrExtentParser::parse() {
    size_t extent_start_pos = str.find_last_of('_');
    parsed_successful = false;
    if (extent_start_pos == str.npos) {
        return Rect(0, 0);
    }
    std::istringstream ss( str.substr(extent_start_pos + 1));
    auto width_opt = try_get_int(ss);
    if (!width_opt.has_value() ) {
        return Rect(0, 0);
    }
    char ex;//nhnhbhbihnik
    ss >> ex;
    if (ex != 'x') {
        return Rect(0, 0);
    }
    auto height_opt = try_get_int(ss);
    if (!height_opt.has_value()) {
        return Rect(0, 0);
    }
    parsed_successful = true;
    return Rect(width_opt.value(), height_opt.value());
}

std::optional<int> StrExtentParser::try_get_int(std::istream& stream) {
    int n;
    stream >> n;
    if (stream.fail()){
        stream.clear();
        return std::optional<int>();
    }
    return std::optional(n);
}