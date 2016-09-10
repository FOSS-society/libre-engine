
#ifndef Matrix3_HPP_
#define Matrix3_HPP_

namespace libre{

	namespace math{

		//* Note: OpenGL Uses Column-Major (0,3,6),(1,4,7),(2,5,8)


		template <typename t>
		class Matrix3{

		private:
			t _data[9];

		public:
			Matrix3(t *data);
			Matrix3(const Matrix3<t>& copy);

			Matrix3<t> &operator=(const Matrix3<t>& copy);

			t getValue(int index);
			t data(int index)const;

			void setValue(int index, t data);

			void addElement(int index, t data);
			void add(Matrix3 b);
			void subElement(int index, t data);
			void sub(Matrix3 b);
			void multElement(int index, t data);
			void mult(Matrix3 b);
			void divElement(int index, t data);
			void div(Matrix3 b);

			const char *toString();

		};

		template<typename t>
		Matrix3<t>::Matrix3(t* data){
			this->m_data[0] = data;
			this->m_data[4] = data;
			this->m_data[8] = data;
		}
		template<typename t>
		Matrix3<t>::Matrix3(const Matrix3<t>& copy){
			for(int i =0; i<9;i++){
				this->m_data[i] = copy.getValue(i);
			}
		}

		template<typename t>
		Matrix3<t> &Matrix3<t>::operator=(const Matrix3<t>& copy){
			return Matrix3<t>(copy);
		}

		template<typename t>
		t Matrix3<t>::getValue(int index){
			return _data[index];
		}
		template<typename t>
		t Matrix3<t>::data(int index)const{
			return _data[index];
		}

		template<typename t>
		void Matrix3<t>::setValue(int index, t data){
			_data[index] = data;
		}
		template<typename t>
		void Matrix3<t>::addElement(int index, t data){
			this->_data[index] += data;
		}

		template<typename t>
		void Matrix3<t>::add(Matrix3 b){
			for(int i =0; i<9;i++){
				this->m_data[i] += b.getValue(i);
			}
		}

		template<typename t>
		void Matrix3<t>::subElement(int index, t data){
			this->_data[index] -= data;
		}

		template<typename t>
		void Matrix3<t>::sub(Matrix3 b){
			for(int i =0; i<9;i++){
				this->m_data[i] -= b.getValue(i);
			}
		}


		template<typename t>
		void Matrix3<t>::multElement(int index, t data){
			this->_data[index] *= data;
		}

		template<typename t>
		void Matrix3<t>::mult(Matrix3 b){
			for(int i =0; i<9;i++){
				this->m_data[i] *= b.getValue(i);
			}
		}


		template<typename t>
		void Matrix3<t>::divElement(int index, t data){
			this->_data[index] /= data;
		}

		template<typename t>
		void Matrix3<t>::div(Matrix3 b){
			for(int i =0; i<9;i++){
				this->m_data[i] /= b.getValue(i);
			}
		}

		template<typename t>
		const char *Matrix3<t>::toString(){
			return "{ " + this->_data[0] + " , " + this->_data[1] + " , " + this->_data[2] +  "}\n" +
						 "{ " + this->_data[3] + " , " + this->_data[4] + " , " + this->_data[5] +  "}\n" +
						 "{ " + this->_data[6] + " , " + this->_data[7] + " , " + this->_data[8] +  "}\n" ;
		}



	}
}



#endif //Matrix3.h
