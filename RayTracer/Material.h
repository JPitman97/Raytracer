#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <GLM/glm.hpp>

class Material
{
public:
	Material();
	Material(const glm::vec3& colour);

	glm::ivec3 getDiffuseColour() const;

private:
	glm::ivec3 diffuse_colour;
};

#endif