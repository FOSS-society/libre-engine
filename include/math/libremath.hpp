#ifndef LIBREMATH_HPP_
#define LIBREMATH_HPP_

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix2.hpp"
#include "matrix3.hpp"
#include "matrix4.hpp"
#include <math.h>

namespace libre{

  namespace math{

   template<typename t>
    t length(const Vector3<t> &vec){
        return sqrt( (vec.X()*vec.X())+(vec.Y() * vec.Y()) +(vec.Z()* vec.Z()) );
        }

    template<typename t>
     t length(const Vector2<t> &vec){
         return sqrt( (vec.X()*vec.X())+(vec.Y() * vec.Y()) );
         }

    template<typename t>
    t length(const Vector4<t> &vec){
        return sqrt( (vec.X()*vec.X())+(vec.Y() * vec.Y()) +(vec.Z()* vec.Z())+(vec.W()* vec.W()) );
        }



  }

}

#endif //libremath.h
