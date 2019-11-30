#include <format/format.hh>

static inline std::regex formattingTokens()
{
	std::string source = std::string(R"((\[[^\[]*\])|(\\)?([Hh]mm(ss)?|Mo|MM?M?M?|Do|DDDo|DD?D?D?|ddd?d?|do?|))")
		+ std::string(R"(w[o|w]?|W[o|W]?|Qo?|YYYYYY|YYYYY|YYYY|YY|gg(ggg?)?|GG(GGG?)?)")
		+ std::string(R"(|e|E|a|A|hh?|HH?|kk?|mm?|ss?|S{1,9}|x|X|zz?|ZZ?|.)");

	std::regex regex(source, std::regex_constants::ECMAScript | std::regex_constants::extended);

	return regex;
}

static inline std::string removeFormattingTokens(std::string input) {
	std::cmatch m;
	std::stringstream stream;
	if (std::regex_match(input, std::regex(R"(\[[\s\S])", std::regex_constants::ECMAScript))) {
		return std::regex_replace(input, 
			std::regex(R"(^\[|\]$)", std::regex_constants::ECMAScript | std::regex_constants::extended), "");
	}
	return std::regex_replace(input,
		std::regex(R"(\\)", std::regex_constants::ECMAScript | std::regex_constants::extended), "");
}
