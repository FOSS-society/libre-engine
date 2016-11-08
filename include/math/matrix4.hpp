#ifndef Matrix4_HPP_
#define Matrix4_HPP_

namespace libre{

	namespace math{

		/** Note: OpenGL Uses Column-Major (0,4,8,12),(1,5,9,13),
						   (2,6,10,14),(3,7,11,15)

		**/



    /**
    *@brief Matrix4 class
    *
    * a generic class which can act as a 2D container holding 3 columns and 3 rows
    *
    * DataType[16]: data
    * formed: [ 0, 1, 2, 3]
    *         [ 4, 5, 6, 7]
    *         [ 8, 9,10,11]
    *         [12,13,14,15]
    *
    * Notes: By the rule of Templates , all functionality is written in this header
    *         Const Compatible
    */

		template <typename t>
		class Matrix4{

		private:
			t _data[16];

		public:
            Matrix4(t data);
			Matrix4(const Matrix4<t>& copy);


			Matrix4<t> &operator=(const Matrix4& copy);

			t getValue(int index);
			t data(int index)const;

			void setValue(int index, t data);

			void addElement(int index, t data);
			void add(Matrix4 b);
			void subElement(int index, t data);
			void sub(Matrix4 b);
			void multElement(int index, t data);
			void mult(Matrix4 b);
			void divElement(int index, t data);
			void div(Matrix4 b);

			const char *toString();

		};

		template<typename t>
        Matrix4<t>::Matrix4(t data){
            this->_data[0] = data;
            this->_data[5] = data;
            this->_data[10] = data;
            this->_data[15] = data;
		}
		template<typename t>
		Matrix4<t>::Matrix4(const Matrix4<t>& copy){
			for(int i =0; i<16;i++){
                this->_data[i] = copy.data(i);
			}
		}

		template<typename t>
		Matrix4<t> &Matrix4<t>::operator=(const Matrix4<t>& copy){
			return Matrix4<t>(copy);
		}

		template<typename t>
		t Matrix4<t>::getValue(int index){
			return _data[index];
		}
		template<typename t>
		t Matrix4<t>::data(int index)const{
			return _data[index];
		}

		template<typename t>
		void Matrix4<t>::setValue(int index, t data){
			_data[index] = data;
		}
		template<typename t>
		void Matrix4<t>::addElement(int index, t data){
			this->_data[index] += data;
		}

		template<typename t>
		void Matrix4<t>::add(Matrix4 b){
			for(int i =0; i<16;i++){
                this->_data[i] += b.getValue(i);
			}
		}

		template<typename t>
		void Matrix4<t>::subElement(int index, t data){
			this->_data[index] -= data;
		}

		template<typename t>
		void Matrix4<t>::sub(Matrix4 b){
			for(int i =0; i<16;i++){
                this->_data[i] -= b.getValue(i);
			}
		}


		template<typename t>
		void Matrix4<t>::multElement(int index, t data){
			this->_data[index] *= data;
		}

		template<typename t>
		void Matrix4<t>::mult(Matrix4 b){
			for(int i =0; i<16;i++){
                this->_data[i] *= b.getValue(i);
			}
		}


		template<typename t>
		void Matrix4<t>::divElement(int index, t data){
			this->_data[index] /= data;
		}

		template<typename t>
		void Matrix4<t>::div(Matrix4 b){
			for(int i =0; i<16;i++){
                this->_data[i] /= b.getValue(i);
			}
		}

		template<typename t>
		const char *Matrix4<t>::toString(){
			return "{ " + this->_data[0] + " , " + this->_data[1] + " , " + this->_data[2] + " , " + this->_data[3] +  "}\n" +
						 "{ " + this->_data[4] + " , " + this->_data[5] + " , " + this->_data[6] + " , " + this->_data[7] +  "}\n" +
						 "{ " + this->_data[8] + " , " + this->_data[9] + " , " + this->_data[10] + " , " + this->_data[11] +  "}\n" +
						 "{ " + this->_data[12] + " , " + this->_data[13] + " , " + this->_data[14] + " , " + this->_data[15] +  "}\n" ;
		}




	}
}
#endif
