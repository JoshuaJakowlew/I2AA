#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

#include <intrin.h>

#include "ImageLoader.h"
#include "ASCIIConverter.h"

auto main(int argc, char* argv[]) -> int
{	
	ascii::ImageLoader loader{ argv[1] };
	auto art = ascii::convert(loader.getBuffer(), loader.getSize());
	
	std::cout << art;
}
