#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "../math/vector2.hpp"
#include "../math/vector3.hpp"


namespace libre{

  namespace physics{

    template <typename t>
    class Rectangle2{
    private:
      math::Vector2<t> m_origin;
      math::Vector2<t> m_size;

    private:
      Rectangle2(math::Vector2<t> origin, math::Vector2<t> size);
      ~Rectangle2();

      void setOrigin(const math::Vector2<t> origin){
        this->m_origin = origin;
      }
      void setOrigin(const t x,const t y){
        this->m_origin = math::Vector2<t>(x,y);
      }
      void setSize(const math::Vector2<t> size){
        this->m_size = size;
      }
      void setSize(const t x,const t y){
        this->m_size = math::Vector2<t>(x,y);
      }

      math::Vector2<t> getOrigin(){return this->m_origin;}
      math::Vector2<t> Origin()const{return this->m_origin;}
      math::Vector2<t> getSize(){return this->m_size;}
      math::Vector2<t> Size()const{ return this->m_size;}

      t getOriginX(){return this->m_origin.getX();}
      t OriginX()const{return this->m_origin.X();}
      t getOriginY(){ return this->m_origin.getY();}
      t OriginY()const{return this->m_origin.Y();}

      t getSizeX(){return this->m_size.getX();}
      t SizeX()const{return this->m_size.X();}
      t getSizeY(){return this->m_size.getY();}
      t SizeY()const{return this->m_size.Y();}

    };

    template <typename t>
    class Rectangle3{
    private:
      math::Vector3<t> m_origin;
      math::Vector3<t> m_size;

    private:
      Rectangle3(math::Vector3<t> origin, math::Vector3<t> size);
      ~Rectangle3();

      void setOrigin(const math::Vector3<t> origin){
        this->m_origin = origin;
      }
      void setOrigin(const t x,const t y ,const t z){
        this->m_origin = math::Vector3<t>(x,y,z);
      }
      void setSize(const math::Vector3<t> size){
        this->m_size = size;
      }
      void setSize(const t x,const t y, const t z){
        this->m_size = math::Vector3<t>(x,y,z);
      }

      math::Vector3<t> getOrigin(){return this->m_origin;}
      math::Vector3<t> Origin()const{return this->m_origin;}
      math::Vector3<t> getSize(){return this->m_size;}
      math::Vector3<t> Size()const{ return this->m_size;}

      t getOriginX(){return this->m_origin.getX();}
      t OriginX()const{return this->m_origin.X();}
      t getOriginY(){ return this->m_origin.getY();}
      t OriginY()const{return this->m_origin.Y();}
      t getOriginZ(){ return this->m_origin.getZ();}
      t OriginZ()const{return this->m_origin.Z();}

      t getSizeX(){return this->m_size.getX();}
      t SizeX()const{return this->m_size.X();}
      t getSizeY(){return this->m_size.getY();}
      t SizeY()const{return this->m_size.Y();}
      t getSizeZ(){return this->m_size.getZ();}
      t SizeZ()const{return this->m_size.Z();}

    };




  }
}




#endif
