#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <iostream>
#include <string>

namespace libre{

	namespace math{


         /**
         *@brief Vector2 Class
         *
         * A generic class to hold a Vector of 2 of the same type of data;
         *
         * DataType: x
         * DataType: y
         *
         * Notes : As a rule of Templates, All functionality is written in this header
         *        Const Compatible
         */

		template <typename t>
		class Vector2{

		private:
		t m_x;
		t m_y;

		public:
        Vector2(){}
		Vector2(const t& x,const t& y);
		Vector2(const Vector2& copy);

		t& getX();
		t X()const;
		t& getY();
		t Y()const;

		void setX(t x);
		void setY(t y);

		Vector2<t> add(const Vector2<t> &other);
		Vector2<t> sub(const Vector2<t> &other);
		Vector2<t> multiply(const Vector2<t> &other);
        Vector2<t> multiply(const t &scalar);
		Vector2<t> divide(const Vector2<t> &other);

		Vector2<t> operator=(Vector2 right);
		Vector2<t> operator+(Vector2 right);
		Vector2<t> operator-(Vector2 right);
		Vector2<t> operator*(Vector2 right);
		Vector2<t> operator/(Vector2 right);

		bool operator==(Vector2<t> right);
		bool operator!=(Vector2<t> right);



		const char *toString();

		};


		template <typename t>
		Vector2<t>::Vector2(const t&x, const t&y){
				this->m_x = x;
				this->m_y = y;
		}
		template <typename t>
		Vector2<t>::Vector2(const Vector2<t>& copy){
			this->m_x = copy.X();
			this->m_y = copy.Y();
		}
		template <typename t>
		t& Vector2<t>::getX(){
			return this->m_x;
		}
		template <typename t>
		t Vector2<t>::X()const{
			return this->m_x;
		}
		template <typename t>
		t& Vector2<t>::getY(){
			return this->m_y;
		}
		template <typename t>
		t Vector2<t>::Y()const{
			return this->m_y;
		}


		template <typename t>
		void Vector2<t>::setX(t x){
			this->m_x = x;
		}

		template <typename t>
		void Vector2<t>::setY(t y){
			this->m_y = y;
		}
		template <typename t>
		Vector2<t> Vector2<t>::add(const Vector2<t> &other){
			Vector2<t> vec(this->m_x + other.X(), this->m_y + other.Y());
			return vec;
		}
		template <typename t>
		Vector2<t> Vector2<t>::sub(const Vector2<t> &other){
			Vector2<t> vec(this->m_x - other.X(), this->m_y - other.Y());
			return vec;
		}
		template <typename t>
		Vector2<t> Vector2<t>::multiply(const Vector2<t> &other){
			Vector2<t> vec(this->m_x * other.X(), this->m_y * other.Y());
			return vec;
		}
        template <typename t>
        Vector2<t> Vector2<t>::multiply(const t &scalar){
            Vector2<t> vec(this->m_x * scalar, this->m_y * scalar);
            return vec;
        }
		template <typename t>
		Vector2<t> Vector2<t>::divide(const Vector2<t> &other){
			Vector2<t> vec(this->m_x / other.X(), this->m_y / other.Y());
			return vec;
		}

		template <typename t>
		Vector2<t> Vector2<t>::operator=(Vector2 right){
			return Vector2<t>(right);
		}
		template <typename t>
		Vector2<t> Vector2<t>::operator+(Vector2 right){
			return this->add(right);
		}
		template <typename t>
		Vector2<t> Vector2<t>::operator-(Vector2 right){
			return this->sub(right);
		}
		template <typename t>
		Vector2<t> Vector2<t>::operator*(Vector2 right){
			return this->multiply(right);
		}
		template <typename t>
		Vector2<t> Vector2<t>::operator/(Vector2 right){
			return this->divide(right);
		}


		template <typename t>
		bool Vector2<t>::operator==(Vector2<t> right){
			return (this->m_x == right->X()) && (this->m_y == right->Y());
		}
		template <typename t>
		bool Vector2<t>::operator!=(Vector2<t> right){
						return (this->m_x != right->X()) || (this->m_y != right->Y());
		}


		template <typename t>
		const char * Vector2<t>::toString(){

            std::string vec2String("X: " + std::to_string(this->m_x));
            vec2String.append(",Y: "+std::to_string(this->m_y));

            return vec2String.c_str();
		}




	}
}

#endif //vector2.h
