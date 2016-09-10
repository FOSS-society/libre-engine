#ifndef MATRIX2_HPP_
#define MATRIX2_HPP_

namespace libre{
	namespace math{

		//* Note: OpenGL Uses Column-Major (0,2),(1,3)


		template <typename t>
		class Matrix2{

		private:
			t _data[4];

		public:
			Matrix2(const t &e0,const t &e1,const t &e2,const t &e3);
			Matrix2(const Matrix2<t>& copy);

			Matrix2<t> &operator=(const Matrix2<t>& copy);

			t getValue(int index);
			t data(int index)const;

			void setValue(int index, t data);

			void addElement(int index, t data);
			void add(Matrix2 b);
			void subElement(int index, t data);
			void sub(Matrix2 b);
			void multElement(int index, t data);
			void mult(Matrix2 b);
			void divElement(int index, t data);
			void div(Matrix2 b);

			const char *toString();

		};

		template<typename t>
		Matrix2<t>::Matrix2(const t &e0,const t &e1,const t &e2,const t &e3){
			this->_data[0] = e0;
			this->_data[1] = e1;
			this->_data[2] = e2;
			this->_data[3] = e3;
		}
		template<typename t>
		Matrix2<t>::Matrix2(const Matrix2<t>& copy){
			this->_data[0] = copy.getValue(0);
			this->_data[1] = copy.getValue(1);
			this->_data[2] = copy.getValue(2);
			this->_data[3] = copy.getValue(3);
		}
		template<typename t>
		Matrix2<t> &Matrix2<t>::operator=(const Matrix2<t>& copy){
			return Matrix2<t>(copy);
}

		template<typename t>
		t Matrix2<t>::getValue(int index){
			return _data[index];
		}
		template<typename t>
		t Matrix2<t>::data(int index)const{
			return _data[index];
		}

		template<typename t>
		void Matrix2<t>::setValue(int index, t data){
			_data[index] = data;
		}
		template<typename t>
		void Matrix2<t>::addElement(int index, t data){
			this->_data[index] += data;
		}

		template<typename t>
		void Matrix2<t>::add(Matrix2 b){
			this->_data[0] += b.getValue(0);
			this->_data[1] += b.getValue(1);
			this->_data[2] += b.getValue(2);
			this->_data[3] += b.getValue(3);
		}

		template<typename t>
		void Matrix2<t>::subElement(int index, t data){
			this->_data[index] -= data;
		}

		template<typename t>
		void Matrix2<t>::sub(Matrix2 b){
			this->_data[0] -= b.getValue(0);
			this->_data[1] -= b.getValue(1);
			this->_data[2] -= b.getValue(2);
			this->_data[3] -= b.getValue(3);
		}

		template<typename t>
		void Matrix2<t>::multElement(int index, t data){
			this->_data[index] *= data;
		}

		template<typename t>
		void Matrix2<t>::mult(Matrix2 b){
			this->_data[0] *= b.getValue(0);
			this->_data[1] *= b.getValue(1);
			this->_data[2] *= b.getValue(2);
			this->_data[3] *= b.getValue(3);
		}

		template<typename t>
		void Matrix2<t>::divElement(int index, t data){
			this->_data[index] /= data;
		}

		template<typename t>
		void Matrix2<t>::div(Matrix2 b){
			this->_data[0] /= b.getValue(0);
			this->_data[1] /= b.getValue(1);
			this->_data[2] /= b.getValue(2);
			this->_data[3] /= b.getValue(3);
		}
		template<typename t>
		const char *Matrix2<t>::toString(){
			return "{ " + this->_data[0] + " , " + this->_data[1] + "}\n" +
				    "{ " + this->_data[2] + " , " + this->_data[3] + "}";
		}


	}
}



#endif //matrix2.h
