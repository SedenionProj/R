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
		static float yaw;
		static float pitch;
		static glm::vec3 pos ;
		static glm::vec3 front ;
		static glm::vec3 up;
		static glm::mat4 projection;
		static glm::mat4 view;
		static UniformBuffer* VP;
		static unsigned int _binding;
		
		PerspectiveCamera(const unsigned int binding = 0 );
		
		~PerspectiveCamera();

		static void setDirection(float yaw, float pitch);

		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	};
	
}