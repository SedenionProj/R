#include "camera.h"

namespace R {
	glm::mat4 PerspectiveCamera::projection = glm::mat4(1);
	glm::mat4 PerspectiveCamera::view = glm::mat4(1);
	unsigned int PerspectiveCamera::_binding = 0;
	glm::vec3 PerspectiveCamera::pos = glm::vec3(0.0f, 0.0f, -5.0f);
	glm::vec3 PerspectiveCamera::front = glm::vec3(0.0f, 0.0f, 1.0);
	glm::vec3 PerspectiveCamera::up = glm::vec3(0.0f, 1.0f, 0.0f);
	UniformBuffer* PerspectiveCamera::VP = nullptr;
	float PerspectiveCamera::yaw = 0;
	float PerspectiveCamera::pitch = 0;
	float lastX = 0, lastY = 0;
	PerspectiveCamera::PerspectiveCamera(const unsigned int binding)
	{
		_binding = binding;

		projection = glm::perspective(glm::radians(110.0f), (float)R::win::w / (float)R::win::h, 0.01f, 1000.0f);
		view = glm::lookAt(pos, pos + front, up);

		VP = new UniformBuffer(2 * sizeof(glm::mat4));
		VP->data(0, projection, sizeof(glm::mat4), _binding);
		VP->data(sizeof(glm::mat4), view, sizeof(glm::mat4), _binding);
		
		
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
		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(direction);
		view = glm::lookAt(pos, pos + front, up);
		VP->data(sizeof(glm::mat4), view, sizeof(glm::mat4),_binding);
	}
	void PerspectiveCamera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
	{
		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos;
		lastX = xpos;
		lastY = ypos;
		float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		R::PerspectiveCamera::yaw += xoffset;
		R::PerspectiveCamera::pitch += yoffset;
		R::PerspectiveCamera::setDirection(R::PerspectiveCamera::yaw, R::PerspectiveCamera::pitch);
	}
}