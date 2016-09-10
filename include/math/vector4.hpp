#ifndef Vector4_HPP_
#define Vector4_HPP_

namespace libre{

	namespace math{

		template <typename t>
		class Vector4{

		private:
		t m_x;
		t m_y;
		t m_z;
		t m_w;

		public:
		Vector4(const t& x,const t& y,const t& z,const t&w);
		Vector4(const Vector4& copy);

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

					return "X: " + this->m_x +"\nY: " + this->m_y + "\nZ: " + this->m_z + "\nW: " +this->m_w;
				}





	}
}

#endif //Vector4.h
