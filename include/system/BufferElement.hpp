#ifndef BUFFERELEMENT_H
#define BUFFERELEMENT_H

#include "../graphics/graphics_common.hpp"

namespace libre{
    namespace system{

    class BufferElement{

    private:

        std::string m_name;
        unsigned int m_type;
        unsigned int m_size;
        unsigned int m_count;
        unsigned int m_offset;
        bool m_normalized;

     public:
        /**
         * @brief BufferElement
         * @param name
         * @param type
         * @param size
         * @param count
         * @param offset
         * @param normalized
         *
         * Probably the ugliest looking thing ive written
         *
         */
        BufferElement(const std::string &name,const unsigned int type,
                      const unsigned int size, const unsigned int count,
                      const unsigned int offset,bool normalized)
            :m_name(name), m_type(type),m_size(size),m_count(count),
             m_offset(offset),m_normalized(normalized){

        }


        inline std::string getName(){ return m_name;}
        inline std::string Name()const{ return m_name;}

        inline unsigned int getType(){ return m_type;}
        inline unsigned int Type()const{ return m_type; }

        inline unsigned int getSize(){return m_size;}
        inline unsigned int Size()const{return m_size;}

        inline unsigned int getCount(){return m_count;}
        inline unsigned int Count()const{return m_count;}

        inline unsigned int getOffset(){return m_offset;}
        inline unsigned int Offset()const{return m_offset;}

        inline bool isNormalized(){ return m_normalized;}
        inline bool Normalized()const{ return m_normalized;}


    };



    }
}



#endif // BUFFERELEMENT_H
