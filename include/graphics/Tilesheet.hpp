#ifndef TILESHEET_HPP
#define TILESHEET_HPP


namespace libre{
    //Foward declare
    class asset::Image;

    template<typename t>
    class math::vector2<t>;

    namespace graphics{

    //Foward declare
    class Tile;

    class TileSheet{

    private:
        const char * m_name;
        asset::Image *m_image;
        math::vector2<unsigned int> m_sizeOfTile;
        math::vector2<unsigned int> m_arraySize;
        const char * m_filepath;



    public:
        TileSheet(const char * name, unsigned int width,
                  unsigned int height,unsigned int columns,unsigned int rows,
                  const char *filepath);
        TileSheet(const char * name,asset::Image *img,
                  math::vector2<unsigned int> size,math::vector2<unsigned int> amount);
        TileSheet(const char * name,asset::Image *img, unsigned int width,
                  unsigned int height,unsigned int columns,unsigned int rows);
        TileSheet(const char * name, const char * filepath,
                  math::vector2<unsigned int> size,math::vector2<unsigned int> amount);
        TileSheet(TileSheet &&mov);


        const Tile returnTile(unsigned int row, unsigned int colunn);



    };



    }

}



#endif // TILESHEET_HPP
