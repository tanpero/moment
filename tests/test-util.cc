#include <iostream>
#include <util/zero-fill.hh>

int main(int argc, char* argv[])
{
	std::cout << "\n\n"
	    << "---- Testing moment.util ----\n"
		<< " run `zeroFill(100, 2, true)`: " << zeroFill(100, 3, true) << std::endl;
}

