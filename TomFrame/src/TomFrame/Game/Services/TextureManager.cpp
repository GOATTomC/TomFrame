#include "TextureManager.h"
#include "../../Debug/Logger.h"
#include <SFML/Graphics.hpp>


TomFrame::TextureManager::TextureManager()
{

}

TomFrame::TextureManager::~TextureManager()
{

}

sf::Texture* TomFrame::TextureManager::GetTexture(std::string spritePath)
{
	if (spritePath == "")
	{
		//We don't log error but return nullptr because user can do this on purpose for empty WorldObjects (WorldObjects without sprite)
		return nullptr;
	}

	//Look if we have stored this texture and return if we have
	sf::Texture* texture = SearchTexture(spritePath);
	if (texture != nullptr)
	{
		return texture;
	}

	//Look up the file and store it into the manager
	texture = InsertTexture(spritePath);
	if (texture != nullptr)
	{
		return texture;
	}

	//We get here if we can't find the picture
	//User probably entered invalid spritePath
	//Log the error
	TomFrame::Debug::Logger::LogError("couldn't find texture at path: " + spritePath + " possible cause: Invalid file path, please check your path. FILE: TextureManager.cpp, LINE: 29");

	return nullptr;
}

sf::Texture* TomFrame::TextureManager::SearchTexture(std::string spritePath)
{
	//Get the texture from the map. Value can be nullptr will be checked function calling this function
	std::map<std::string, sf::Texture*>::iterator it;
	sf::Texture* texture = nullptr;
	it = m_LoadedTextures.find(spritePath);
	if (it != m_LoadedTextures.end())
	{
		texture = m_LoadedTextures.at(spritePath);
	}

	return texture;
}

sf::Texture* TomFrame::TextureManager::InsertTexture(std::string spritePath)
{
	//Create a pointer to memory for a new texture
	sf::Texture* texture = new sf::Texture();

	if (!texture->loadFromFile(spritePath))
	{
		//Free memory because something failed
		delete texture;
		TomFrame::Debug::Logger::LogError("Texture couldn't be loaded from path: " + spritePath + " FILE: TextureManager.cpp, LINE: 51");
		return nullptr;
	}

	//Insert the texture into the map where we store all textures
	m_LoadedTextures.insert(std::pair<std::string, sf::Texture*>(spritePath, texture));

	//Return the loaded texture
	return texture;
}

