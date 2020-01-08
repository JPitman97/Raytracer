#include "Ray.h"

glm::vec3& Ray::getOrigin()
{
	return origin;
}

glm::vec3& Ray::getDirection()
{
	return direction;
}

Ray::Ray() = default;

Ray::Ray(const glm::vec3& _origin, const glm::vec3& _direction, const Sphere& _sphere)
	: origin(_origin),
	  direction(_direction)
{
}

glm::ivec3 Ray::castRay(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres, const std::vector<Light>& _lights)
{
	glm::vec3 point, N;
	Material material;

	if (!sceneIntersects(_origin, _direction, _spheres, point, N, material))
		return glm::ivec3(0, 0, 0); //Background 

	float diffuse_light_intensity = 0, specular_light_intensity = 0;
	for (auto& light : _lights)
	{
		glm::vec3 light_dir = glm::normalize(light.getPosition() - point);
		diffuse_light_intensity += light.getIntensity() * std::max(0.f, glm::dot(light_dir, N));

		specular_light_intensity += clamp(powf(std::max(0.0f, reflect(light_dir, N).x * _direction.x), material.getSpecularExponent()) * light.getIntensity(), 0, 255);
	}

	/*return glm::ivec3(material.getDiffuseColour().x * diffuse_light_intensity,
	                  material.getDiffuseColour().y * diffuse_light_intensity,
	                  material.getDiffuseColour().z * diffuse_light_intensity);*/
	//return glm::ivec3(material.getDiffuseColour());
	return material.getDiffuseColour() * diffuse_light_intensity * material.getAlbedo()[0] + glm::vec3(1., 1., 1.) * specular_light_intensity * material.getAlbedo()[1];

}

bool Ray::sceneIntersects(const glm::vec3& _origin, const glm::vec3& _direction, std::vector<Sphere>& _spheres,
                          glm::vec3& _hit, glm::vec3& N, Material& _material) const
{
	float spheres_dist = 0;
	for (auto& sphere : _spheres)
	{
		float dist_i;
		if (sphere.findIntersection(_origin, _direction, dist_i))
		{
			spheres_dist = dist_i;
			_hit = _origin + _direction * dist_i;
			N = glm::normalize(_hit - sphere.getSphereCenter());
			_material = sphere.getSphereMaterial();
		}
	}
	return spheres_dist < 1000;
}

glm::vec3 Ray::reflect(const glm::vec3& I, const glm::vec3& N)
{
	return I - N * 2.f * (I * N);
}
