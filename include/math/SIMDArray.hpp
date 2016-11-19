#ifndef SIMDARRAY_HPP
#define SIMDARRAY_HPP

#include <emmintrin.h>
#include "vector4.hpp"

namespace libre{

    namespace math{
    //Just incase i decide to refactor, maybe i can create virtual functions for some of these?
     class simdArray{

     private:

     public:
        simdArray();
     };

     class simdF:public simdArray{
     private:
         __m128 m_data;

     public:

         simdF();
         simdF(const __m128 &data);
         simdF(const math::Vector4<float> &data);

         ~simdF();

         void setData(const __m128 &data);
         void setData(const math::Vector4<float> &data);

         simdF add(const simdF &right);
         simdF sub(const simdF &right);
         simdF multiply(const simdF &right);
         simdF divide(const simdF &right);

         simdF operator+(simdF &right);
         simdF operator-(simdF &right);
         simdF operator*(simdF &right);
         simdF operator/(simdF &right);

         __m128 getData();
         __m128 data()const;



     };
     class simdD:public simdArray{
     private:
         __m128d m_data;

     public:

         simdD();
         simdD(const __m128d &data);
         simdD(const math::Vector4<double> &data);

         void setData(const __m128d &data);

         simdD add(const simdD &right);
         simdD sub(const simdD &right);
         simdD multiply(const simdD &right);
         simdD divide(const simdD &right);

         simdD operator+(simdD &right);
         simdD operator-(simdD &right);
         simdD operator*(simdD &right);
         simdD operator/(simdD &right);

         __m128d getData();
         __m128d data()const;

     };
     class simdI:public simdArray{
     private:
         __m128i m_data;

     public:

         simdI();
         simdI(const __m128i &data);
         simdI(const math::Vector4<int> &data);

         ~simdI();
         void setData(const __m128i &data);

         simdI add(const simdI &right);
         simdI sub(const simdI &right);
         simdI multiply(const simdI &right);


         simdI operator+(simdI &right);
         simdI operator-(simdI &right);
         simdI operator*(simdI &right);


         __m128i getData();
         __m128i data()const;
     };

    }

}
#endif // SIMDARRAY_HPP
