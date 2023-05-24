#include "camera.h"

namespace R {
	glm::mat4 PerspectiveCamera::projection = glm::mat4(1);
	glm::mat4 PerspectiveCamera::view = glm::mat4(1);
	unsigned int PerspectiveCamera::_binding = 0;
	glm::vec3 PerspectiveCamera::_pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PerspectiveCamera::front = glm::vec3(0.0f, 0.0f, 1.0);
	glm::vec3 PerspectiveCamera::up = glm::vec3(0.0f, 1.0f, 0.0f);
	UniformBuffer* PerspectiveCamera::VP = nullptr;
	float PerspectiveCamera::_yaw = 0.f;
	float PerspectiveCamera::_pitch = 0.f;
	float PerspectiveCamera::_sensitivity = 0.1f;
	float lastX = 0, lastY = 0;
	PerspectiveCamera::PerspectiveCamera(const unsigned int binding, const glm::vec3& worldPos, const float sensitivity, const float yaw, const float pitch)
	{
		_binding = binding;
		_pos = worldPos;
		_sensitivity = sensitivity;
		_yaw = yaw;
		_pitch = pitch;
		projection = glm::perspective(glm::radians(110.0f), (float)R::win::w / (float)R::win::h, 0.01f, 1000.0f);
		view = glm::lookAt(_pos, _pos + front, up);
		VP = new UniformBuffer(2 * sizeof(glm::mat4));
		VP->data(0, projection, sizeof(glm::mat4), _binding);
		VP->data(sizeof(glm::mat4), view, sizeof(glm::mat4), _binding);
		setDirection(_yaw, _pitch);
	}
	PerspectiveCamera::~PerspectiveCamera()
	{
	}
	void PerspectiveCamera::setDirection(float yaw, float pitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		_pitch = pitch;
		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(direction);
		view = glm::lookAt(_pos, _pos + front, up);
		VP->data(sizeof(glm::mat4), view, sizeof(glm::mat4), _binding);
	}
	void PerspectiveCamera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
	{
		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos;
		lastX = xpos;
		lastY = ypos;
		xoffset *= _sensitivity;
		yoffset *= _sensitivity;
		_yaw += xoffset;
		_pitch += yoffset;
		setDirection(_yaw, _pitch);
	}

	void PerspectiveCamera::setPosition(const glm::vec3& position) {
		_pos = position;
	}
}