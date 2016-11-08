#ifndef LIBREMATH_HPP_
#define LIBREMATH_HPP_


#include <cassert>
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix2.hpp"
#include "matrix3.hpp"
#include "matrix4.hpp"
#include <math.h>

#define LE_PI 3.14159265358f

namespace libre{

  namespace math{

  inline float toRadians(const float degrees){
      return (float)degrees * (LE_PI/180.0f);
  }

  inline float toDegrees(const float radians){
      return (float) radians * (180.0f/LE_PI);
  }


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

    template<typename t>
    t dot(const Vector2<t> &a,const Vector2<t> &b){
        return sqrt((a.X()*b.X())+(a.Y()*b.Y()));
    }

    template<typename t>
    t dot(const Vector3<t> &a,const Vector3<t> &b){
        return sqrt((a.X()*b.X())+(a.Y()*b.Y()) + (a.Z()*b.Z()));
    }

    template<typename t>
    t dot(const Vector4<t> &a,const Vector4<t> &b){
        return sqrt((a.X()*b.X())+(a.Y()*b.Y()) + (a.Z()*b.Z()) + (a.W()*b.W()));
    }

    template<typename t>
    Vector3<t> cross(const Vector3<t> &a, const Vector3<t> &b){
        Vector3<t> temp;
        temp.setX((a.Y()*b.Z()) - (a.Z()*b.Y()));
        temp.setY((a.Z()*b.X()) - (a.X() * b.Z()));
        temp.setZ((a.X()*b.Y()) - (a.Y()* b.X()));
                return temp;
    }


    Matrix4<float> perspective(float fov, float aspectRatio, float near, float far){
        Matrix4<float> result(1.0f);

        float a = 1.0f / tan(toRadians(0.5f * fov));
        float b = a / aspectRatio;

        float c = (near +far)/(near - far);
        float d = (2.0f * near * far)/(near -far);

        result.setValue(0,b);
        result.setValue(5,a);
        result.setValue(10,c);
        result.setValue(14,-1.0f);
        result.setValue(11,d);

        return result;
    }


    Matrix4<float>Orthographic(float left, float right, float bottom, float top, float near, float far){

        Matrix4<float> result(1.0f);

        float a = 2.0f/ (right - left);
        float b = 2.0f/ (top - bottom);
        float c = 2.0f/ (near - far);
        float d = (left+right)/ (left-right);
        float e = (bottom+top)/(bottom-top);
        float f = (near+far)/(near-far);

        result.setValue(0,a);
        result.setValue(5,b);
        result.setValue(10,c);
        result.setValue(3,d);
        result.setValue(7,e);
        result.setValue(11,f);

        return result;
    }

    Matrix2<float> InverseMat2(const Matrix2<float> &mat){
       /**
         Solution:
         [a,b]   1/ ad-cb   swap positions of a and d, then put negatives on b and c
         [c,d]              then divide each by ad-bc
      `**/

        Matrix2<float> temp(mat.data(4),mat.data(1)*-1,mat.data(2)*-1,mat.data(0));
        float det = mat.data(0)*mat.data(3)- mat.data(1)*mat.data(2);

        assert(det!=0);

        return temp * (1/det);
    }

    Matrix3<float> InverseMat3(const Matrix3<float> &mat){

    /**
    Step 1: calculating the Matrix of Minors,
    Step 2: then turn that into the Matrix of Cofactors,
    Step 3: then the Adjugate, and
    Step 4: multiply that by 1/Determinant.
    **/
        float fminor[9];
        // Minor Matrix construction
        fminor[0]= mat.data(4) * mat.data(8) - mat.data(5) * mat.data(7);
        fminor[1]= mat.data(3) * mat.data(8) - mat.data(5) * mat.data(6);
        fminor[2]= mat.data(3) * mat.data(7) - mat.data(4) * mat.data(6);
        fminor[3]= mat.data(1) * mat.data(8) - mat.data(2) * mat.data(7);
        fminor[4]= mat.data(0) * mat.data(8) - mat.data(2) * mat.data(6);
        fminor[5]= mat.data(0) * mat.data(7) - mat.data(1) * mat.data(6);
        fminor[6]= mat.data(1) * mat.data(5) - mat.data(2) * mat.data(4);
        fminor[7]= mat.data(0) * mat.data(5) - mat.data(2) * mat.data(3);
        fminor[8]= mat.data(0) * mat.data(4) - mat.data(1) * mat.data(3);

        Matrix3<float> mminor = Matrix3<float>(0);

        for (int i =0; i<9;i++){
            mminor.setValue(i,fminor[i]);
        }

        mminor.multElement(1,-1);
        mminor.multElement(3,-1);
        mminor.multElement(5,-1);
        mminor.multElement(7,-1);

        //minor matrix is now the Matrix of CoFactors
        // time to transpose: 1&3,2&6,5&7
        float temp = mminor.data(1);
        mminor.setValue(1,mminor.data(3));
        mminor.setValue(3,temp);
        temp = mminor.data(6);
        mminor.setValue(6,mminor.data(2));
        mminor.setValue(2,temp);
        temp = mminor.data(5);
        mminor.setValue(5,mminor.data(7));
        mminor.setValue(7,temp);

        //Now we have an Adjugate (or Adjoint)

        float determinant = (mat.data(0)*fminor[0]) -
                            (mat.data(1)*fminor[1]) +
                            (mat.data(2)*fminor[2]);


        return mminor * (1/determinant);



    }


  }

}

#endif //libremath.h
