#pragma once
#include <string>
#include <atomic>

namespace Resources
{
	enum class ResourceStatus
	{
		UNLOADED,
		LOADING,
		LOADED
	};

	class Resource
	{
	protected:
		std::string m_filePath;

		Resource() = default;
		Resource(const std::string& filePath);

	public:
		std::string m_name;
		std::string getPath() const;
		ResourceStatus resourceFlag;
	};
}