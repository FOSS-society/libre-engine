#include "../../include/graphics/Tile.hpp"


namespace libre{
namespace graphics{

unsigned int Tile::getNextID()
{
    ++Tile::s_nextID;
    return Tile::s_nextID;
}

unsigned int Tile::initID()
{
     Tile::s_nextID = 0;
     return Tile::s_nextID;
}


    }
}
