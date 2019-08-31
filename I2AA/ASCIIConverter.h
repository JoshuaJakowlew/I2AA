#ifndef ASCII_CONVERTER_H
#define ASCII_CONVERTER_H

#include "ImageLoader.h"

namespace ascii
{
	using data_t     = ImageLoader::data_t;
	using data_pair  = std::tuple<data_t*, const data_t*>;
	using image_size = std::tuple<std::size_t, std::size_t>;

	[[nodiscard]] auto convert(data_pair data, image_size size) -> std::string;
} // namespace ascii

#endif
