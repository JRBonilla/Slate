#pragma once

#include <vector>
#include "Shader.h"
#include "ph/Types.h"

namespace ph { namespace renderer {

	class ShaderManager {
	private:
		static std::vector<Shader*> s_Shaders;
	public:
		static void Init();
		static void Add(Shader* shader);
		static void Clean();

		static Shader* Get();
		static Shader* Get(const std::string& name);
	private:
		ShaderManager() { }
	};

}}