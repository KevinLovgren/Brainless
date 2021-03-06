#include "ResourceLoader.h"
#include <stdexcept>
#include "Error.h"

ResourceLoader::ResourceLoader()
{

}

ResourceLoader& ResourceLoader::instance()
{
	static ResourceLoader theInstance;
	return theInstance;
}

void ResourceLoader::loadTexture(const std::string &name, const std::string &filePath)
{
	auto itr = m_textures.find(name);

	// A texture by this name does not exist already
	if (itr == m_textures.end())
	{
		TexturePtr texPtr = TexturePtr(new sf::Texture());
		if (texPtr->loadFromFile(filePath))
			m_textures[name] = std::move(texPtr);
		else
			BRAINLESS_ERROR("The file '" + filePath + "' could not be loaded!");
	}
}
void ResourceLoader::loadShader(const std::string &name, const std::string &filePath)
{
	auto itr = m_shaders.find(name);

	// A shader by this name does not exist already
	if (itr == m_shaders.end())
	{
		// TODO, only supports fragment shaders for now
		ShaderPtr shadPtr = ShaderPtr(new sf::Shader());
		if (shadPtr->loadFromFile(filePath, sf::Shader::Fragment))
			m_shaders[name] = std::move(shadPtr);
		else
			BRAINLESS_ERROR("The file '" + filePath + "' could not be loaded!");
	}
}
void ResourceLoader::loadSound(const std::string &name, const std::string &filePath)
{

}
void ResourceLoader::loadMusic(const std::string &name, const std::string &filePath)
{

}

sf::Texture& ResourceLoader::retrieveTexture(const std::string &name)
{
	auto itr = m_textures.find(name);

	// A texture by this name does not exist already
	if (itr == m_textures.end())
		BRAINLESS_ERROR("The texture resource '" + name + "' could not be found!");
	else
		return *itr->second.get();
}
sf::Shader& ResourceLoader::retrieveShader(const std::string &name)
{
	auto itr = m_shaders.find(name);

	// A shader by this name does not exist already
	if (itr == m_shaders.end())
		BRAINLESS_ERROR("The shader resource '" + name + "' could not be found!");
	else
		return *itr->second.get();
}
sf::Sound& ResourceLoader::retrieveSound(const std::string &name)
{
	auto itr = m_sounds.find(name);

	// A sound by this name does not exist already
	if (itr == m_sounds.end())
		BRAINLESS_ERROR("The sound resource '" + name + "' could not be found!");
	else
		return *itr->second.get();
}
sf::Music& ResourceLoader::retrieveMusic(const std::string &name)
{
	auto itr = m_music.find(name);

	// A sound by this name does not exist already
	if (itr == m_music.end())
		BRAINLESS_ERROR("The music resource '" + name + "' could not be found!");
	else
		return *itr->second.get();
}

bool ResourceLoader::unloadTexture(const std::string &name)
{
	auto itr = m_textures.find(name);
	if (itr != m_textures.end()) // Resource was found
	{
		m_textures.erase(itr);
		return true;
	}
	else
		return false;
		
}
bool ResourceLoader::unloadShader(const std::string &name)
{
	auto itr = m_shaders.find(name);
	if (itr != m_shaders.end()) // Resource was found
	{
		m_shaders.erase(itr);
		return true;
	}
	else
		return false;
}
bool ResourceLoader::unloadSound(const std::string &name)
{
	auto itr = m_sounds.find(name);
	if (itr != m_sounds.end()) // Resource was found
	{
		m_sounds.erase(itr);
		return true;
	}
	else
		return false;
}
bool ResourceLoader::unloadMusic(const std::string &name)
{
	auto itr = m_music.find(name);
	if (itr != m_music.end()) // Resource was found
	{
		m_music.erase(itr);
		return true;
	}
	else
		return false;
}