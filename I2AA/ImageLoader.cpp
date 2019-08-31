#include "ImageLoader.h"

#include <opencv2/imgproc.hpp>

namespace ascii
{
	ImageLoader::ImageLoader(std::string_view path) :
		m_image { cv::imread(path.data(), cv::IMREAD_GRAYSCALE) }
	{
		cv::resize(m_image, m_image, {  }, 1.0, 0.666, cv::INTER_AREA);
	}

	auto ImageLoader::getBuffer() -> std::tuple<data_t*, const data_t*>
	{
		return { m_image.data, m_image.dataend };
	}

	auto ImageLoader::getSize() -> std::tuple<std::size_t, std::size_t>
	{
		return { m_image.cols, m_image.rows };
	}

} // namespace ascii
