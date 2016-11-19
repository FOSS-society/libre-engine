#include "../../include/math/SIMDArray.hpp"

namespace libre{

namespace math{

simdF::simdF()
{
    this->m_data = _mm_setzero_ps();
}

simdF::simdF(const __m128 &data)
{
    this->m_data = data;
}

simdF::simdF(const math::Vector4<float> &data)
{
    this->m_data = _mm_set_ps(data.Z(),data.Y(),data.X(),data.W());
}

simdF::~simdF()
{

}

void simdF::setData(const __m128 &data)
{
    this->m_data = data;
}

void simdF::setData(const math::Vector4<float> &data)
{
    this->m_data = _mm_set_ps(data.Z(),data.Y(),data.X(),data.W());
}

simdF simdF::add(const simdF &right)
{
    return simdF(_mm_add_ps(this->m_data,right.data()));
}

simdF simdF::sub(const simdF &right)
{
    return simdF(_mm_sub_ps(this->m_data,right.data()));
}

simdF simdF::multiply(const simdF &right)
{
    return simdF(_mm_mul_ps(this->m_data,right.data()));

}

simdF simdF::divide(const simdF &right)
{
    return simdF(_mm_div_ps(this->m_data,right.data()));

}

simdF simdF::operator+(simdF &right)
{
    return this->add(right);
}

simdF simdF::operator-(simdF &right)
{
    return this->sub(right);
}

simdF simdF::operator*(simdF &right)
{
    return this->multiply(right);
}

simdF simdF::operator/(simdF &right)
{
    return this->divide(right);
}

__m128 simdF::getData()
{
    return m_data;
}

__m128 simdF::data() const
{
    return m_data;
}

simdD::simdD()
{
    this->m_data = _mm_setzero_pd();
}

simdD::simdD(const __m128d &data)
{
    this->m_data = data;
}

simdD::simdD(const math::Vector2<double> &data)
{
    this->m_data = _mm_set_pd(data.X(),data.Y());

}

void simdD::setData(const __m128d &data)
{
    this->m_data = data;
}

simdD simdD::add(const simdD &right)
{
    return _mm_add_pd(this->m_data,right.data());
}

simdD simdD::sub(const simdD &right)
{
    return _mm_sub_pd(this->m_data,right.data());
}

simdD simdD::multiply(const simdD &right)
{
    return _mm_mul_pd(this->m_data,right.data());

}

simdD simdD::divide(const simdD &right)
{
    return _mm_div_pd(this->m_data,right.data());

}

simdD simdD::operator+(simdD &right)
{
    return this->add(right);
}

simdD simdD::operator-(simdD &right)
{
    return this->sub(right);
}

simdD simdD::operator*(simdD &right)
{
    return this->multiply(right);
}

simdD simdD::operator/(simdD &right)
{
    return this->divide(right);
}

__m128d simdD::getData()
{
    return this->m_data;
}

__m128d simdD::data() const
{
    return this->m_data;
}

simdI::simdI()
{
        this->m_data = _mm_setzero_si128();
}

simdI::simdI(const __m128i &data)
{
    this->m_data = data;
}

simdI::simdI(const math::Vector4<int> &data)
{
    this->m_data = _mm_set_epi32(data.Z(),data.Y(),data.X(),data.W());

}

simdI::~simdI()
{

}

simdI simdI::add(const simdI &right)
{
    return simdI(_mm_add_epi32(this->m_data,right.data()));

}

simdI simdI::sub(const simdI &right)
{
    return simdI(_mm_sub_epi32(this->m_data,right.data()));

}

simdI simdI::multiply(const simdI &right){
    return simdI(_mm_mul_epu32(this->m_data,right.data()));

}

simdI simdI::operator+(simdI &right)
{
    return this->add(right);
}

simdI simdI::operator-(simdI &right)
{
    return this->sub(right);
}

simdI simdI::operator*(simdI &right)
{
    return this->multiply(right);
}

__m128i simdI::getData()
{
    return this->m_data;
}

__m128i simdI::data() const
{
    return this->m_data;
}




}

}
