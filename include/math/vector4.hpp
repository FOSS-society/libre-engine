#ifndef Vector4_HPP_
#define Vector4_HPP_

#include <iostream>
namespace libre{

	namespace math{


    /**
     *@brief internalv4
     * a simplification for opengl usage. can easily call getInternal().i_x or getInternal().i_y
     */
    template <typename t>
    struct internalv4{
        t i_x;
        t i_y;
        t i_z;
        t i_w;

        internalv4(){}
        internalv4(t x, t y,t z,t w):i_x(x), i_y(y),i_z(z), i_w(w){}
    };
    /**
    *@brief Vector4 Class
    *
    * A generic class to hold a Vector of 4 of the same type of data;
    *
    * DataType: x
    * DataType: y
    * DataType: z
    * DataType: w
    *
    * Notes : As a rule of Templates, All functionality is written in this header
    *         Const Compatible
    */
		template <typename t>
		class Vector4{

		private:
		t m_x;
		t m_y;
		t m_z;
		t m_w;

		public:
        Vector4(){}
		Vector4(const t& x,const t& y,const t& z,const t&w);
        Vector4(const Vector4& copy);
        Vector4(const internalv4<t> vec);

		t& getX();
		t X()const;
		t& getY();
		t Y()const;
		t& getZ();
		t Z()const;
		t& getW();
		t W()const;

		void setX(t x);
		void setY(t y);
		void setZ(t z);
		void setW(t w);

		Vector4<t> add(const Vector4<t> &other);
		Vector4<t> sub(const Vector4<t> &other);
		Vector4<t> multiply(const Vector4<t> &other);
        Vector4<t> multiply(const t &scalar);
		Vector4<t> divide(const Vector4<t> &other);

		Vector4<t> operator=(Vector4 right);
		Vector4<t> operator+(Vector4 right);
		Vector4<t> operator-(Vector4 right);
		Vector4<t> operator*(Vector4 right);
		Vector4<t> operator/(Vector4 right);

		bool operator==(Vector4<t> right);
		bool operator!=(Vector4<t> right);



		const char * toString();


		};



				template <typename t>
				Vector4<t>::Vector4(const t&x, const t&y, const t&z, const t&w){
						this->m_x = x;
						this->m_y = y;
						this->m_z = z;
                    this->m_w = w;
                }

                template <typename t>
                Vector4<t>::Vector4(const internalv4<t> vec):m_x(vec.i_x),m_y(vec.i_y),m_z(vec.i_z),m_w(vec.i_w)
                {

                }
				template <typename t>
				Vector4<t>::Vector4(const Vector4<t>& copy){
					this->m_x = copy.X();
					this->m_y = copy.Y();
					this->m_z = copy.Z();
					this->m_w = copy.W();
				}
				template <typename t>
				t& Vector4<t>::getX(){
					return this->m_x;
				}
				template <typename t>
				t Vector4<t>::X()const{
					return this->m_x;
				}
				template <typename t>
				t& Vector4<t>::getY(){
					return this->m_y;
				}
				template <typename t>
				t Vector4<t>::Y()const{
					return this->m_y;
				}

				template <typename t>
				t& Vector4<t>::getZ(){
					return this->m_z;
				}
				template <typename t>
				t Vector4<t>::Z()const{
					return this->m_z;
				}

				template <typename t>
				t& Vector4<t>::getW(){
					return this->m_w;
				}
				template <typename t>
				t Vector4<t>::W()const{
					return this->m_w;
				}


				template <typename t>
				void Vector4<t>::setX(t x){
					this->m_x = x;
				}

				template <typename t>
				void Vector4<t>::setY(t y){
					this->m_y = y;
				}

				template <typename t>
				void Vector4<t>::setZ(t z){
					this->m_z = z;
				}
				template <typename t>
				void Vector4<t>::setW(t w){
					this->m_w = w;
				}

				template <typename t>
				Vector4<t> Vector4<t>::add(const Vector4<t> &other){
					Vector4<t> vec(this->m_x + other.X(), this->m_y + other.Y(),this->m_z + other.Z(),this->m_w + other.W());
					return vec;
				}
				template <typename t>
				Vector4<t> Vector4<t>::sub(const Vector4<t> &other){
					Vector4<t> vec(this->m_x - other.X(), this->m_y - other.Y(),this->m_z - other.Z(),this->m_w - other.W());
					return vec;
				}
				template <typename t>
				Vector4<t> Vector4<t>::multiply(const Vector4<t> &other){
					Vector4<t> vec(this->m_x * other.X(), this->m_y * other.Y(),this->m_z * other.Z(),this->m_w * other.W());
                    return vec;
                }
                template <typename t>
                Vector4<t> Vector4<t>::multiply(const t &scalar)
                {
                    Vector4<t> vec(this->m_x * scalar, this->m_y * scalar,this->m_z * scalar,this->m_w * scalar);
                    return vec;
                }
				template <typename t>
				Vector4<t> Vector4<t>::divide(const Vector4<t> &other){
					Vector4<t> vec(this->m_x / other.X(), this->m_y / other.Y(),this->m_z / other.Z(),this->m_w / other.W());
					return vec;
				}

				template <typename t>
				Vector4<t> Vector4<t>::operator=(Vector4 right){
					return Vector4<t>(right);
				}
				template <typename t>
				Vector4<t> Vector4<t>::operator+(Vector4 right){
					return this->add(right);
				}
				template <typename t>
				Vector4<t> Vector4<t>::operator-(Vector4 right){
					return this->sub(right);
				}
				template <typename t>
				Vector4<t> Vector4<t>::operator*(Vector4 right){
					return this->multiply(right);
				}
				template <typename t>
				Vector4<t> Vector4<t>::operator/(Vector4 right){
					return this->divide(right);
				}


				template <typename t>
				bool Vector4<t>::operator==(Vector4<t> right){
					return (this->m_x == right->X()) && (this->m_y == right->Y()) && (this->m_z == right->Z());
				}
				template <typename t>
				bool Vector4<t>::operator!=(Vector4<t> right){
								return (this->m_x != right->X()) || (this->m_y != right->Y())|| (this->m_z != right->Z());
				}


                template <typename t>
                const char * Vector4<t>::toString(){

                    std::string vec4String("X: " + this->m_x);
                    vec4String.append(",Y: "+this->m_y);
                    vec4String.append(",Z: "+this->m_z);
                    vec4String.append(",W: "+this->m_w);
                    return vec4String.c_str();
                }





	}
}

#endif //Vector4.h
