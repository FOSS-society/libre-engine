#ifndef Vector3_HPP_
#define Vector3_HPP_

#include <iostream>
#include <string>

namespace libre{

	namespace math{



    /**
    *@brief Vector3 Class
    *
    * A generic class to hold a Vector of 3 of the same type of data;
    *
    * DataType: x
    * DataType: y
    * DataType: z
    *
    * Notes : As a rule of Templates, All functionality is written in this header
    *         Const Compatible
    *
    *
    */

		template <typename t>
		class Vector3{

		private:
		t m_x;
		t m_y;
		t m_z;

		public:
        Vector3(){}
		Vector3(const t& x,const t& y,const t& z);
		Vector3(const Vector3& copy);

		t& getX();
		t X()const;
		t& getY();
		t Y()const;
		t& getZ();
		t Z()const;

		void setX(t x);
		void setY(t y);
		void setZ(t z);

		Vector3<t> add(const Vector3<t> &other);
		Vector3<t> sub(const Vector3<t> &other);
        Vector3<t> multiply(const Vector3<t> &other);
        Vector3<t> multiply(const t &scalar);
		Vector3<t> divide(const Vector3<t> &other);

		Vector3<t> operator=(Vector3 right);
		Vector3<t> operator+(Vector3 right);
		Vector3<t> operator-(Vector3 right);
		Vector3<t> operator*(Vector3 right);
        Vector3<t> operator*(t right);
		Vector3<t> operator/(Vector3 right);

		bool operator==(Vector3<t> right);
		bool operator!=(Vector3<t> right);

        t dot(const Vector3<t> vec);

		const char * toString();


		};


		template <typename t>
		Vector3<t>::Vector3(const t&x, const t&y, const t&z){
				this->m_x = x;
				this->m_y = y;
				this->m_z = z;
		}
		template <typename t>
		Vector3<t>::Vector3(const Vector3<t>& copy){
			this->m_x = copy.X();
			this->m_y = copy.Y();
			this->m_z = copy.Z();
		}
		template <typename t>
		t& Vector3<t>::getX(){
			return this->m_x;
		}
		template <typename t>
		t Vector3<t>::X()const{
			return this->m_x;
		}
		template <typename t>
		t& Vector3<t>::getY(){
			return this->m_y;
		}
		template <typename t>
		t Vector3<t>::Y()const{
			return this->m_y;
		}

		template <typename t>
		t& Vector3<t>::getZ(){
			return this->m_z;
		}
		template <typename t>
		t Vector3<t>::Z()const{
			return this->m_z;
		}


		template <typename t>
		void Vector3<t>::setX(t x){
			this->m_x = x;
		}

		template <typename t>
		void Vector3<t>::setY(t y){
			this->m_y = y;
		}

		template <typename t>
		void Vector3<t>::setZ(t z){
			this->m_z = z;
		}

		template <typename t>
		Vector3<t> Vector3<t>::add(const Vector3<t> &other){
			Vector3<t> vec(this->m_x + other.X(), this->m_y + other.Y(),this->m_z + other.Z());
			return vec;
		}
		template <typename t>
		Vector3<t> Vector3<t>::sub(const Vector3<t> &other){
			Vector3<t> vec(this->m_x - other.X(), this->m_y - other.Y(),this->m_z - other.Z());
			return vec;
		}
		template <typename t>
		Vector3<t> Vector3<t>::multiply(const Vector3<t> &other){
			Vector3<t> vec(this->m_x * other.X(), this->m_y * other.Y(),this->m_z * other.Z());
            return vec;
        }
        template <typename t>
        Vector3<t> Vector3<t>::multiply(const t &scalar)
        {
            Vector3<t> vec(this->m_x * scalar, this->m_y * scalar,this->m_z * scalar);
            return vec;
        }
		template <typename t>
		Vector3<t> Vector3<t>::divide(const Vector3<t> &other){
			Vector3<t> vec(this->m_x / other.X(), this->m_y / other.Y(),this->m_z / other.Z());
			return vec;
		}

		template <typename t>
		Vector3<t> Vector3<t>::operator=(Vector3 right){
			return Vector3<t>(right);
		}
		template <typename t>
		Vector3<t> Vector3<t>::operator+(Vector3 right){
			return this->add(right);
		}
		template <typename t>
		Vector3<t> Vector3<t>::operator-(Vector3 right){
			return this->sub(right);
		}
		template <typename t>
        Vector3<t> Vector3<t>::operator*(Vector3<t> right){
			return this->multiply(right);
		}
        template <typename t>
        Vector3<t> Vector3<t>::operator*(t right){
            return this->multiply(right);
        }
		template <typename t>
		Vector3<t> Vector3<t>::operator/(Vector3 right){
			return this->divide(right);
		}


		template <typename t>
		bool Vector3<t>::operator==(Vector3<t> right){
			return (this->m_x == right->X()) && (this->m_y == right->Y()) && (this->m_z == right->Z());
		}
		template <typename t>
		bool Vector3<t>::operator!=(Vector3<t> right){
            return (this->m_x != right->X()) || (this->m_y != right->Y())|| (this->m_z != right->Z());
        }

        template <typename t>
        t Vector3<t>::dot(const Vector3<t> vec)
        {
            return this->m_x * vec.X() + this->m_y * vec.Y() + this->m_z * vec.Z();
        }



        template <typename t>
        const char * Vector3<t>::toString(){

            std::string vec3String("X: " + std::to_string(this->m_x).c_str());
            vec3String.append(",Y: "+ std::to_string(this->m_y).c_str());
            vec3String.append(",Z: "+ std::to_string(this->m_z).c_str());

            return vec3String.c_str();
        }




	}
}

#endif //Vector3.h
