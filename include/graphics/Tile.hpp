#ifndef TILE_HPP
#define TILE_HPP

#include "graphics_common.hpp"
#include "../asset/Image.hpp"

namespace libre{

namespace graphics{


/// \brief The tileType enum
///
/// Contains the information that defines whether a tile is there , it is walkable, or special
enum tileType{
    E_TYPE_NONE , // No tile to display, this happens if image == NULL
    E_TYPE_NORMAL, // Normal Tile, walkable
    E_TYPE_BLOCK, // Tile which is unwalkable
    E_TYPE_SPECIAL
};


enum tileFlip{
    E_FLIP_NORMAL, //standard image
    E_FLIP_VERTICAL,
    E_FLIP_HORIZONTAL,
    E_FLIP_BOTH
};



///
/// \brief The Tile class
///
/// Used for the creation of Tile Maps within the editor
    class Tile{

    private:
        unsigned int m_tid;

        math::Vector2<unsigned int> m_size;
        static unsigned int s_nextID;
        asset::Image *m_image;
        tileType m_typeType;
        tileFlip m_flipType;
        unsigned int getNextID(); // use this to return the next id
        static unsigned int initID();

    public:
        Tile(const asset::Image *image,const unsigned int width,const unsigned int height ,
             const tileType type = E_TYPE_NORMAL, const tileFlip ftype = E_FLIP_NORMAL);
        Tile(const asset::Image *image, const math::Vector2<unsigned int> size,
             const tileType type = E_TYPE_NORMAL,const tileFlip ftype = E_FLIP_NORMAL);

        void setTileType(const tileType type);
        void setTileFlip(const tileFlip flip);

        asset::Image *getImage();
        asset::Image *image()const;

        tileType getTileType();
        tileType tiletype()const;


        tileFlip getTileFlip();
        tileFlip tileflip()const;



    };




    } //graphics
} // libre

#endif // TILE_HPP
