#include "zero-fill.hh"

std::string zeroFill(int number, size_t targetLength, bool forceSign)
{
	std::string absNumber = std::to_string(abs(number));
	int zerosToFill = targetLength - absNumber.length();
	bool sign = number >= 0;
	return (sign ? (forceSign ? "+" : "") : "-") +
			std::to_string(pow(10, std::max(0, zerosToFill))).substr(1) + absNumber;

}
