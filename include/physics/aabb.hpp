#ifndef AABB_HPP_
#define AABB_HPP_

#include "../math/vector2.hpp"

namespace libre{

  namespace physics{

    template<typename t>
    class AABB2{

    private:
      math::Vector2<t> _min;
      math::Vector2<t> _max;

    public:
      AABB2(const math::Vector2<t> &low, const math::Vector2<t> &high);


      void setMin(const math::Vector2<t> min)

      math::Vector2<t> getMin();
      math::Vector2<t> Min()const;

      math::Vector2<t> getMax();
      math::Vector2<t> Max()const;


      int checkBounds(AABB2 other);


    };


    template <typename t>
    AABB2<t>::AABB2(const math::Vector2<t> &low, const math::Vector2<t> &high){
      this->_min = math::Vector2<t>(low);
      this->_max = math::Vector2<t>(high);
    }
    template <typename t>
    math::Vector2<t> AABB2<t>::getMin(){
        return _min;
    }

    template <typename t>
    math::Vector2<t> AABB2<t>::Min()const{
      return _min;
    }

    template <typename t>
    math::Vector2<t> AABB2<t>::getMax(){
      return _max;
    }

    template <typename t>
    math::Vector2<t> AABB2<t>::Max()const{
      return _max;
    }


    template <typename t>
    int AABB2<t>::checkBounds(AABB2<t> other){

      if(this->_max.X() < other.Min().X() || this->_min.x > other.Max().X())
        return -1;
      if(this->_max.Y() < other.Min().Y() || this->_min.Y() > other.Max().Y())
        return -1;

        return 1;
    }


  }
}

#endif
