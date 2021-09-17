#pragma once

#include <string>
#include <memory>
#include <thread>
#include <vector>

#include <glad/glad.h>

#include "resource.hpp"
#include "maths.hpp"

namespace Resources
{
	class Texture : public Resource
	{
	private:
		GLuint textureID = 0;
		
		std::vector<std::thread> trd;
		
		void generateID(int width, int height, float* colorBuffer);

	public:
		Texture(const std::string& filePath);
		Texture(int width, int height, float* colorBuffer);
		~Texture();

		void stbiTexture(const std::string& filePath);

		GLuint getID() const;

		void bind(int textureIndex) const;

		static std::shared_ptr<Texture> defaultAlpha;
		static std::shared_ptr<Texture> defaultAmbient;
		static std::shared_ptr<Texture> defaultDiffuse;
		static std::shared_ptr<Texture> defaultEmissive;
		static std::shared_ptr<Texture> defaultSpecular;
	};	
}
