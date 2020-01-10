#include "Ray.h"

//Return the rays origin position
glm::vec3& Ray::getOrigin()
{
	return origin;
}

//Return the rays direction
glm::vec3& Ray::getDirection()
{
	return direction;
}

//Default constructor
Ray::Ray() = default;

//Standard constructor, initializes the origin and direction of the ray
Ray::Ray(const glm::vec3& _origin, const glm::vec3& _direction, const Sphere& _sphere)
	: origin(_origin),
	  direction(_direction)
{}

//Casts a new ray in the direction passed in at the origin, with a vector of spheres and lights to "look out" for
glm::vec3 Ray::castRay(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres, const std::vector<Light>& _lights) const
{
	//Variables for use later
	glm::vec3 point, N;
	Material material;

	if (!sceneIntersects(_origin, _direction, _spheres, point, N, material)) //Fire the ray and check all spheres for collision
	{
		return glm::vec3(0, 0, 0); //False means no object was hit, draw the background instead 
	}

	float diffuseIntensity = 0, specularIntensity = 0; //Default diffuse and specular values
	for (auto& light : _lights) //Loop through every light in the scene
	{
		glm::vec3 light_dir = glm::normalize(light.getPosition() - point); //Get the direction of the light (Normalised) from the ray
		diffuseIntensity += light.getIntensity() * std::max(0.f, glm::dot(light_dir, N)); //Calculate the diffuse colour via the light intensity and direction

		glm::vec3 reflectionVector = glm::normalize(glm::reflect(light_dir, N)); //Calculate the reflection vector, used to handle specular highlights

		//Calculate the Specular using the reflection vector  and the specular component of the material hit (Returned via reference) from sceneIntersects
		specularIntensity += powf(std::max(0.0f,  glm::dot(reflectionVector, _direction)), material.getSpecularExponent()) * light.getIntensity(); 
	}

	glm::vec3 finalColour = material.getDiffuseColour() * diffuseIntensity + specularIntensity; //Calculate the final colour of the object hit
	return finalColour; //Return the objects colour to be drawn to the screen

}

//Checks for an intersection with a sphere in the scene
bool Ray::sceneIntersects(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres,
                          glm::vec3& _hit, glm::vec3& N, Material& _material) const
{
	float spheres_dist = 10000; //Absurdly high value to stop false results
	for (auto& sphere : _spheres) //Loop through every sphere in the scene
	{
		float dist_i; //Create initial distance value
		if (sphere.findIntersection(_origin, _direction, dist_i) && dist_i < spheres_dist) //Run findIntersection on every sphere
		{
			spheres_dist = dist_i; //Return the actual distance to the sphere
			_hit = _origin + _direction * dist_i; //Create a hit vector to store the exact location of the hit
			N = glm::normalize(_hit - sphere.getSphereCenter()); //Get the spheres normal
			_material = sphere.getSphereMaterial(); //Get the spheres material
		}
	}
	return spheres_dist < 10000; //Return true if the distance to the sphere is less than 10000, otherwise false
}
