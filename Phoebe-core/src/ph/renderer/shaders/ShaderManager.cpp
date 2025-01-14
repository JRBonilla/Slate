#include "ShaderManager.h"

namespace ph { namespace renderer { 

	std::vector<Shader*> ShaderManager::s_Shaders;

	void ShaderManager::Init() {
		Add(new Shader("Basic2D", "shaders/default/Basic2D.phsf"));
		Add(new Shader("Font",    "shaders/default/Font.phsf"));
	}

	void ShaderManager::Add(Shader* shader) {
		s_Shaders.push_back(shader);
	}

	void ShaderManager::Clean() {
		for (uint i = 0; i < s_Shaders.size(); i++) {
			delete s_Shaders[i];
		}
	}

	Shader* ShaderManager::Get() {
		return s_Shaders[0];
	}

	Shader* ShaderManager::Get(const std::string& name) {
		for (Shader* shader : s_Shaders) {
			if (shader->GetName() == name) {
				return shader;
			}
		}
		return nullptr;
	}

}}