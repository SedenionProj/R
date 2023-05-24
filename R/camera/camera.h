#pragma once
#include <GL/glew.h>
#include "../libs/GLM/glm/glm.hpp"
#include "../libs/GLM/glm/gtc/matrix_transform.hpp"
#include "../libs/GLM/glm/gtc/type_ptr.hpp"
#include "../window/window.h"
#include "../glObj/buffer.h"

namespace R {
	class PerspectiveCamera{
	public:
		static float _yaw;
		static float _pitch;
		static float _sensitivity;
		static glm::vec3 _pos ;
		static glm::vec3 front ;
		static glm::vec3 up;
		static glm::mat4 projection;
		static glm::mat4 view;
		static UniformBuffer* VP;
		static unsigned int _binding;
		
		PerspectiveCamera(const unsigned int binding = 0,const glm::vec3& worldPos = glm::vec3(0,0,0),const float sensitivity = 0.1f, const float yaw = 0, const float pitch=0);
		
		~PerspectiveCamera();

		static void setDirection(float yaw, float pitch);

		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

		static void setPosition(const glm::vec3& position);
	};
	
}