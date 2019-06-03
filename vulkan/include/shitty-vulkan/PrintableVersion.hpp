#include <cstdint>
#include <sstream>

namespace vk
{
	inline std::string PrintableVersion(const std::uint32_t version)
	{
		return (std::stringstream{} << (version >> 22 & 0x03ff) << '.' << (version >> 12 & 0x03ff) << '.' << (version & 0x0fff)).str();
	}
}
