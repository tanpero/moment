#ifndef _MOMENT_PARSE_REGEX_HH_
#define _MOMENT_PARSE_REGEX_HH_

#include <regex>

constexpr const std::regex match1         (R"(\d)", std::constants::ECMAScript);            //       0 - 9
constexpr const std::regex match2         (R"(\d\d)", std::constants::ECMAScript);          //      00 - 99
constexpr const std::regex match3         (R"(\d{3})", std::constants::ECMAScript);         //     000 - 999
constexpr const std::regex match4         (R"(\d{4})", std::constants::ECMAScript);         //    0000 - 9999
constexpr const std::regex match6         (R"([+-]?\d{6})", std::constants::ECMAScript);    // -999999 - 999999
constexpr const std::regex match1to2      (R"(\d\d?)", std::constants::ECMAScript);         //       0 - 99
constexpr const std::regex match3to4      (R"(\d\d\d\d?)", std::constants::ECMAScript);     //     999 - 9999
constexpr const std::regex match5to6      (R"(\d\d\d\d\d\d?)", std::constants::ECMAScript); //   99999 - 999999
constexpr const std::regex match1to3      (R"(\d{1,3})", std::constants::ECMAScript);       //       0 - 999
constexpr const std::regex match1to4      (R"(\d{1,4})", std::constants::ECMAScript);       //       0 - 9999
constexpr const std::regex match1to6      (R"([+-]?\d{1,6})", std::constants::ECMAScript);  // -999999 - 999999

constexpr const std::regex matchUnsigned  (R"(\d+)", std::constants::ECMAScript);           //       0 - inf
constexpr const std::regex matchSigned    (R"([+-]?\d+)", std::constants::ECMAScript);      //    -inf - inf

constexpr const std::regex matchOffset    (R"(Z|[+-]\d\d:?\d\d)", std::constants::ECMAScript
	| std::regex_constants::icase | std::regex_constants::extended); // +00:00 -00:00 +0000 -0000 or Z
constexpr const std::regex matchShortOffset (R"(Z|[+-]\d\d(?::?\d\d)?)", std::constants::ECMAScript
	| std::regex_constants::icase | std::regex_constants::extended); // +00 -00 +00:00 -00:00 +0000 -0000 or Z

constexpr const std::regex matchTimestamp (R"([+-]?\d+(\.\d{1,3})?)", std::constants::ECMAScript); // 123456789 123456789.123
