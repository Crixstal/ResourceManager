#pragma once

#include <string>
#include <memory>
#include <vector>

#include <glad/glad.h>

#include "resource.hpp"
#include "maths.hpp"
#include "thread_manager.hpp"

namespace Resources
{
	class Texture : public Resource
	{
	private:
		GLuint textureID = 0;

		void generateID(int width, int height, float* colorBuffer);

		Core::Engine::ThreadManager threadPool;
		std::atomic_flag spinLock = ATOMIC_FLAG_INIT;
		std::vector<float*> cb;

		void threadTexture(const std::string& filePath);
		int width = 0, height = 0;
		float* colorBuffer;

	public:
		Texture(const std::string& filePath);
		Texture(int width, int height, float* colorBuffer);
		~Texture();

		GLuint getID() const;

		void bind(int textureIndex) const;

		static std::shared_ptr<Texture> defaultAlpha;
		static std::shared_ptr<Texture> defaultAmbient;
		static std::shared_ptr<Texture> defaultDiffuse;
		static std::shared_ptr<Texture> defaultEmissive;
		static std::shared_ptr<Texture> defaultSpecular;
	};	
}
