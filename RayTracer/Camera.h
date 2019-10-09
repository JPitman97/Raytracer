#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GLM/glm.hpp"

class Camera
{
private:
	glm::vec3 position, direction, camPitch, camRoll;
public:
	void setPosition(const glm::vec3& position);
	void setDirection(const glm::vec3& direction);
	void setCamPitch(const glm::vec3& cam_pitch);
	void setCamRoll(const glm::vec3& cam_roll);
	glm::vec3& getPosition();
	glm::vec3& getDirection();
	glm::vec3& getPitch();
	glm::vec3& getRoll();

	Camera();
	Camera(const glm::vec3& position, const glm::vec3& direction, const glm::vec3& cam_pitch, const glm::vec3& cam_roll);
};
#endif