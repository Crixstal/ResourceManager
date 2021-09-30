#pragma once

#include <vector>
#include <string>

#include <glad\glad.h>

#include "maths.hpp"
#include "resource.hpp"

namespace Resources
{
	class Mesh : public Resource
	{
	private:
		GLuint VAO;

	public:
		~Mesh();

		std::vector<float> attributs;
		std::string name;

		void draw();
		void generateVAO();
		void compute(std::vector<Core::Maths::vec3>& vertices, std::vector<Core::Maths::vec3>& texCoords, std::vector<Core::Maths::vec3>& normals, std::vector<unsigned int>& indices);
	};
}
