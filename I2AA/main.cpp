#include <iostream>
#include <string>

#include "ImageLoader.h"
#include "ASCIIConverter.h"

using namespace std::literals;

auto main(int argc, char* argv[]) -> int
{	
	if (argc < 2)
	{
		std::cerr << "Error: image is not specified\n"s;
		return 1;
	}

	ascii::ImageLoader loader{ argv[1] };
	if (loader.isEmpty())
	{
		std::cerr << "Error: Cannot load image \""s + argv[1] + "\"\n"s;
		return 1;
	}
	auto art = ascii::convert(loader.getBuffer(), loader.getSize());
	
	std::cout << art;
}
