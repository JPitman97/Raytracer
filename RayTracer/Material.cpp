#include "Material.h"

Material::Material() = default;

Material::Material(const glm::vec3& colour) : diffuse_colour(colour)
{}

glm::ivec3 Material::getDiffuseColour() const
{
	return diffuse_colour;
}
