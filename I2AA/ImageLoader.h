#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string_view>
#include <tuple>

#include <opencv2/imgcodecs.hpp>

namespace ascii
{
	class ImageLoader
	{
	public:
		using data_t = unsigned char;

		ImageLoader(std::string_view path);

		[[nodiscard]] auto isEmpty() -> bool;
		[[nodiscard]] auto getBuffer() -> std::tuple<data_t*, const data_t*>;
		[[nodiscard]] auto getSize() -> std::tuple<std::size_t, std::size_t>;
	private:
		cv::Mat m_image;
	};

} // namespace ascii

#endif
