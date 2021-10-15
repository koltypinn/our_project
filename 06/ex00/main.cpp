#include "convert.hpp"



int main(int argc, char **argv)
{
    if (argc == 2)
        convert(argv[1]);
	else
		std::cout << "Error: invalid number of arguments" << std::endl;
}
