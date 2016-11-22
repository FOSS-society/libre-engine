#ifndef MATRIX2_HPP_
#define MATRIX2_HPP_

namespace libre{
	namespace math{

		//* Note: OpenGL Uses Column-Major (0,2),(1,3)


         /**
         *@brief Matrix2 class
         *
         * a generic class which can act as a 2D container holding 2 columns and 2 rows
         *
         * DataType[4]: data
         * formed: [0,1]
         *         [2,3]
         *
         * Notes: By the rule of Templates , all functionality is written in this header
         *        Const Compatible
         *
         */

		template <typename t>
		class Matrix2{

		private:
			t _data[4];

		public:
			Matrix2(const t &e0,const t &e1,const t &e2,const t &e3);
			Matrix2(const Matrix2<t>& copy);

            Matrix2<t> operator=(const Matrix2<t>& copy);

			t getValue(int index);
			t data(int index)const;

            void setValue(int index,const t& data);

            void addElement(int index, const t& data);
			void add(Matrix2 b);
            void subElement(int index,const t& data);
			void sub(Matrix2 b);
            void multElement(int index, const t& data);
			void mult(Matrix2 b);
            void divElement(int index,const t& data);
			void div(Matrix2 b);


            Matrix2<t> &operator+(const Matrix2<t> &other);
            Matrix2<t> &operator+(const t &other);
            Matrix2<t> &operator-(const Matrix2<t> &other);
            Matrix2<t> &operator-(const t& other);
            Matrix2<t> &operator*(const Matrix2<t> &other);
            Matrix2<t> &operator*(const t & other);
            Matrix2<t> &operator/(const Matrix2<t> &other);
            Matrix2<t> &operator/(const t &other);



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
            this->_data[0] = copy.data(0);
            this->_data[1] = copy.data(1);
            this->_data[2] = copy.data(2);
            this->_data[3] = copy.data(3);
		}
		template<typename t>
        Matrix2<t> Matrix2<t>::operator=(const Matrix2<t>& copy){
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
        void Matrix2<t>::setValue(int index, const t & data){
			_data[index] = data;
		}
		template<typename t>
        void Matrix2<t>::addElement(int index, const t & data){
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
        void Matrix2<t>::subElement(int index, const t & data){
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
        void Matrix2<t>::multElement(int index, const t & data){
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
        void Matrix2<t>::divElement(int index,const t& data){
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
        Matrix2<t> &Matrix2<t>::operator+(const Matrix2<t> &other)
        {
            this->add(other);
            return *this;
        }

       template<typename t>
        Matrix2<t> & Matrix2<t>::operator+(const t & other){
            this->addElement(0,other);
            this->addElement(1,other);
            this->addElement(2,other);
            this->addElement(3,other);
            return *this;
        }

        template<typename t>
        Matrix2<t> &Matrix2<t>::operator-(const Matrix2<t> &other)
        {
            this->sub(other);
            return *this;
        }

       template<typename t>
        Matrix2<t> & Matrix2<t>::operator-(const t & other){
            this->subElement(0,other);
            this->subElement(1,other);
            this->subElement(2,other);
            this->subElement(3,other);
            return *this;
        }

        template<typename t>
        Matrix2<t> &Matrix2<t>::operator*(const Matrix2<t> &other)
        {
            this->mult(other);
            return *this;
        }

       template<typename t>
        Matrix2<t> & Matrix2<t>::operator*(const t & other){
            this->multElement(0,other);
            this->multElement(1,other);
            this->multElement(2,other);
            this->multElement(3,other);
            return *this;
        }

        template<typename t>
        Matrix2<t> &Matrix2<t>::operator/(const Matrix2<t> &other)
        {
            this->div(other);
            return *this;
        }

       template<typename t>
        Matrix2<t> & Matrix2<t>::operator/(const t & other){
            this->divElement(0,other);
            this->divElement(1,other);
            this->divElement(2,other);
            this->divElement(3,other);
            return *this;
        }




		template<typename t>
		const char *Matrix2<t>::toString(){
			return "{ " + this->_data[0] + " , " + this->_data[1] + "}\n" +
				    "{ " + this->_data[2] + " , " + this->_data[3] + "}";
		}


	}
}



#endif //matrix2.h
