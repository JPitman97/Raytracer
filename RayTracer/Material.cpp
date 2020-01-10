#include "Material.h"

Material::Material() = default;

//Simple constructor that takes and initialises the colour and specular values for the material
Material::Material(const glm::vec3& _colour, const float& _spec) : diffuse_colour(_colour), specular_exponent(_spec)
{}

//Return the diffuse colour of the material
glm::vec3 Material::getDiffuseColour() const
{
	return diffuse_colour;
}

//Return the specular exponent of the material
float Material::getSpecularExponent() const
{
	return specular_exponent;
}
