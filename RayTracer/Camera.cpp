#include "Camera.h"

void Camera::setPosition(const glm::vec3& position)
{
	this->position = position;
}

void Camera::setDirection(const glm::vec3& direction)
{
	this->direction = direction;
}

void Camera::setCamPitch(const glm::vec3& cam_pitch)
{
	camPitch = cam_pitch;
}

void Camera::setCamRoll(const glm::vec3& cam_roll)
{
	camRoll = cam_roll;
}

glm::vec3& Camera::getPosition()
{
	return position;
}

glm::vec3& Camera::getDirection()
{
	return direction;
}

glm::vec3& Camera::getPitch()
{
	return camPitch;
}

glm::vec3& Camera::getRoll()
{
	return camRoll;
}

Camera::Camera() = default;

Camera::Camera(const glm::vec3& position, const glm::vec3& direction, const glm::vec3& cam_pitch, const glm::vec3& cam_roll)
	: position(position),
	direction(direction),
	camPitch(cam_pitch),
	camRoll(cam_roll)
{}
