#ifndef LEVARIANT_HPP_
#define LEVARIANT_HPP_


#include <iostream>
#include "../math/vector2.hpp"
#include "../math/matrix2.hpp"
#include "../math/vector3.hpp"
#include "../math/matrix3.hpp"
#include "../math/vector4.hpp"
#include "../math/matrix4.hpp"
#include <lua5.2/lua.hpp>




/**
 *Variant Notes:
 * cant use templated classes where the data is a pointer
 * such as: libre::math::Vector2<int*> or else toString throws a bitchfit
 * so i am not allowing it.
 */


namespace libre{
    namespace core{

    union VariantData{
        int asInt;
        int *asIntPtr;
        char asChar;
        char *asCharPtr;
        short asShort;
        short *asShortPtr;
        float asFloat;
        float *asFloatPtr;
        double asDouble;
        double *asDoublePtr;
        long asLong;
        long *asLongPtr;
        math::Vector2<int> asVec2Int;
        math::Vector2<float> asVec2Float;
        math::Vector3<float> asVec3Float;
        math::Vector4<float> asVec4Float;
        math::Matrix2<float> asMat2Float;
        math::Matrix3<float> asMat3Float;
        math::Matrix4<float> asMat4Float;



        VariantData():asInt(0){} // defaults to int
        VariantData(const VariantData &copy){

        }

        VariantData(int i):asInt(i){}
        VariantData(int *ip):asIntPtr(ip){}
        VariantData(char c):asChar(c){}
        VariantData(char *cp):asCharPtr(cp){}
        VariantData(short s):asShort(s){}
        VariantData(short *sp):asShortPtr(sp){}
        VariantData(float f):asFloat(f){}
        VariantData(float *fp):asFloatPtr(fp){}
        VariantData(double d):asDouble(d){}
        VariantData(double *dp):asDoublePtr(dp){}
        VariantData(long l):asLong(l){}
        VariantData(long *lp):asLongPtr(lp){}
        VariantData(math::Vector2<int> v2i):asVec2Int(v2i){}
        VariantData(math::Vector2<float> v2f):asVec2Float(v2f){}
        VariantData(math::Vector3<float> v3f):asVec3Float(v3f){}
        VariantData(math::Vector4<float> v4f):asVec4Float(v4f){}
        VariantData(math::Matrix2<float> m2f):asMat2Float(m2f){}
        VariantData(math::Matrix3<float> m3f):asMat3Float(m3f){}
        VariantData(math::Matrix4<float> m4f):asMat4Float(m4f){}


        ~VariantData(){}
        VariantData& operator=(const VariantData &copy){
            asInt= copy.asInt;
            asIntPtr = copy.asIntPtr;
            asChar = copy.asChar;
            asCharPtr = copy.asCharPtr;
            asShort = copy.asShort;
            asShortPtr = copy.asShortPtr;
            asFloat = copy.asFloat;
            asFloatPtr = copy.asFloatPtr;
            asDouble = copy.asDouble;
            asDoublePtr = copy.asDoublePtr;
            asLong = copy.asLong;
            asLongPtr = copy.asLongPtr;
            asVec2Int = copy.asVec2Int;
            asVec2Float = copy.asVec2Float;
            asVec3Float = copy.asVec3Float;
            asVec4Float = copy.asVec4Float;
            asMat2Float = copy.asMat2Float;
            asMat3Float = copy.asMat3Float;
            asMat4Float = copy.asMat4Float;
        }
        };

    enum class DataType{
        INT,INTPTR,CHAR,CHARPTR,
        SHORT,SHORTPTR,FLOAT,FLOATPTR,
        DOUBLE,DOUBLEPTR,LONG,LONGPTR,
        VEC2INT,VEC2FLOAT,VEC3FLOAT,VEC4FLOAT,
        MAT2FLOAT,MAT3FLOAT,MAT4FLOAT
        };

    class Variant{

        private:
        DataType m_type;
        VariantData m_data;

        public:

        Variant(DataType type):m_type(type),m_data(VariantData()){ setType(type);}
        Variant():m_type(DataType::INT),m_data(VariantData()){}
        Variant(int i):m_type(DataType::INT),m_data(VariantData(i)){}
        Variant(int *ip):m_type(DataType::INTPTR),m_data(VariantData(ip)){}
        Variant(short s):m_type(DataType::SHORT),m_data(VariantData(s)){}
        Variant(short *sp):m_type(DataType::SHORTPTR),m_data(VariantData(sp)){}
        Variant(char c):m_type(DataType::CHAR),m_data(VariantData(c)){}
        Variant(char *cp):m_type(DataType::CHARPTR),m_data(VariantData(cp)){}
        Variant(float f):m_type(DataType::FLOAT),m_data(VariantData(f)){}
        Variant(float *fp):m_type(DataType::FLOATPTR),m_data(VariantData(fp)){}
        Variant(double d):m_type(DataType::DOUBLE),m_data(VariantData(d)){}
        Variant(double *dp):m_type(DataType::DOUBLEPTR),m_data(VariantData(dp)){}
        Variant(long l):m_type(DataType::LONG),m_data(VariantData(l)){}
        Variant(long *lp):m_type(DataType::LONGPTR),m_data(VariantData(lp)){}
        Variant(math::Vector2<int> v2i):m_type(DataType::VEC2INT),m_data(VariantData(v2i)){}
        Variant(math::Vector2<float> v2f):m_type(DataType::VEC2FLOAT),m_data(VariantData(v2f)){}
        Variant(math::Vector3<float> v3f):m_type(DataType::VEC3FLOAT),m_data(VariantData(v3f)){}
        Variant(math::Vector4<float> v4f):m_type(DataType::VEC4FLOAT),m_data(VariantData(v4f)){}
        Variant(math::Matrix2<float> m2f):m_type(DataType::MAT2FLOAT),m_data(VariantData(m2f)){}
        Variant(math::Matrix3<float> m3f):m_type(DataType::MAT3FLOAT),m_data(VariantData(m3f)){}
        Variant(math::Matrix4<float> m4f):m_type(DataType::MAT4FLOAT),m_data(VariantData(m4f)){}

        ~Variant()= default;

        void operator=(const Variant &v){
            this->m_data = v.Data();
            this->m_type = v.Type();
        }

        void setData(VariantData d){
        this->m_data = d;
        }

        void setType(DataType t){
            this->m_type = t;
        }

        DataType getType(){return m_type;}
        VariantData getData(){return m_data;}

        DataType Type()const{return m_type;}
        VariantData Data()const{return m_data;}

        friend std::ostream& operator<<(std::ostream &os,const Variant &v){
               switch(v.Type()){
               case DataType::INT:
                   os << "Type: Int\nData: " << v.Data().asInt;
                   break;

               case DataType::INTPTR:
                   os << "Type: Int Pointer\nData: " << v.Data().asIntPtr;
                   break;

                case DataType::CHAR:
                   os << "Type: Char\nData: " << v.Data().asChar;
                   break;

                case DataType::CHARPTR:
                   os << "Type: Char Pointer\nData: " << v.Data().asCharPtr;
                   break;

                 case DataType::SHORT:
                   os << "Type: Short\nData: " << v.Data().asShort;
                   break;

               case DataType::SHORTPTR:
                   os << "Type: Short Pointer\nData: " << v.Data().asShortPtr;
                   break;

               case DataType::FLOAT:
                   os << "Type: Float\nData: " << v.Data().asFloat;
                   break;

               case DataType::FLOATPTR:
                   os << "Type: Float Pointer\nData: " << v.Data().asFloatPtr;
                   break;

               case DataType::DOUBLE:
                   os << "Type: Double\nData: " << v.Data().asDouble;
                   break;

               case DataType::DOUBLEPTR:
                   os << "Type: Double Pointer\nData: " << v.Data().asDoublePtr;
                   break;

               case DataType::LONG:
                   os << "Type: Long\nData: " << v.Data().asLong;
                   break;

               case DataType::LONGPTR:
                   os << "Type: Long Pointer\nData: " << v.Data().asLongPtr;
                   break;

               case DataType::VEC2INT:
                   os << "Type: Vector 2 Int\nData: " << v.Data().asVec2Int.toString();
                   break;


               case DataType::VEC2FLOAT:
                   os << "Type: Vector 2 Float\nData: " << v.Data().asVec2Float.toString();
                   break;


        }
               os << std::endl;
               return os;
        }






        };





  }
}



#endif //LEVariant.hpp
