#include "ASCIIConverter.h"

using namespace std::literals;

namespace ascii
{
	char color_to_char(unsigned char color);

	auto convert(data_pair data, image_size size) -> std::string
	{
		const auto [begin, end]    = data;
		const auto [width, height] = size;

		std::string art;
		const auto str_len = width * height + height + 1;
		art.reserve(str_len);

		for (auto pix = begin; pix != end; ++pix)
		{
			art += color_to_char(*pix);
			const auto skip_newline = (pix - begin) % width;
			if (!skip_newline)
				art += '\n';
		}

		return art;
	}

	char color_to_char(unsigned char color)
	{
		constexpr auto palette = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. "sv;
		const auto gray = color * (palette.length() - 1) / 255;
		return palette[gray];
	}

} // namespace ascii
