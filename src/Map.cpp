#include <Map.hpp>
#include <TextureManager.hpp>

Map::Map()
{
    dirt = TextureManager::LoadTexture("/dirt.png");
    grass = TextureManager::LoadTexture("/grass.png");
    water = TextureManager::LoadTexture("/water.png");
}

void Map::LoadMap()
{
}

void Map::DrawMap()
{
}
