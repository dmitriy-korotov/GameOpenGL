#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>
#include <vector>
#include <memory>

namespace Renderer
{
	class ShaderProgram;
	class Texture2D;
	class Sprite2D;
	class subTexture2D;
}

namespace Resources
{
	class ResourceManager
	{
	public:

		ResourceManager(const std::string& executable_path);

		ResourceManager(const ResourceManager&) = delete;
		ResourceManager(ResourceManager&&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;
		ResourceManager& operator=(ResourceManager&&) = delete;
		
		~ResourceManager() = default;

		std::shared_ptr<Renderer::ShaderProgram> loadShaderProrgam(const std::string& shader_name,
																   const std::string& path_to_vertex_shader_source, 
																   const std::string& path_to_fragment_shader_source);
	
		std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shader_name) const;

		std::shared_ptr<Renderer::Texture2D> loadTexture(const std::string& texture_name, const std::string& relative_path_to_texture);

		std::shared_ptr<Renderer::Texture2D> getTexture(const std::string& texture_name) const;

		std::shared_ptr<Renderer::Sprite2D> loadSprite(const std::string& sprite_name,
													   const std::string& shader_program_name,
													   const std::string& texture_name,
													   const unsigned int sprite_width = 1,
													   const unsigned int sprite_height = 1,
													   const std::string& subTexture_name = "default");

		std::shared_ptr<Renderer::Sprite2D> getSprite(const std::string& sprite_name);

		std::shared_ptr<Renderer::Texture2D> loadTextureAtlas(const std::string& texture_name,
																const std::vector<std::string> subTexture_names,
																const std::string& relative_path_to_texture,
																const unsigned int width_subTexture,
																const unsigned int height_subtexture);

	private:

		static std::string getFileString(const std::string& path);

		// VARIEBLES
		typedef std::map<std::string, std::shared_ptr<Renderer::ShaderProgram>> MapShaderProgram;
		MapShaderProgram m_shader_programs;

		typedef std::map<std::string, std::shared_ptr<Renderer::Texture2D>> MapTexture2D;
		MapTexture2D m_textures;

		typedef std::map<std::string, std::shared_ptr<Renderer::Sprite2D>> MapSprite2D;
		MapSprite2D m_sprites;

		std::string m_path;
	};
}

#endif // !RESOURCE_MANAGER_H
