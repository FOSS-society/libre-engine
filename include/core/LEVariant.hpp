#ifndef LEVARIANT_HPP_
#define LEVARIANT_HPP_

#include <stdint.h>
#include <iostream>

#include "../math/vector2.hpp"
#include "../math/vector3.hpp"
#include "../math/vector4.hpp"

#include "../math/matrix2.hpp"
#include "../math/matrix3.hpp"
#include "../math/matrix4.hpp"


namespace libre{
  namespace core{

    enum class DataType{INT, INTPTR, INT8, INT8PTR, SHORT, INT16, SHORTPTR, INT16PTR,
                        UINT, UINTPTR, UINT8, UINT8PTR, USHORT, UINT16, USHORTPTR,
                        UINT16PTR, CHAR, UCHAR, FLOAT, FLOATPTR, STRING, VEC2INT,
                        VEC2INTPTR, PTRVEC2INT, PTRVEC2INTPTR,VEC3INT, PTRVEC3INT,
                        VEC3INTPTR, PTRVEC3INTPTR,VEC4INT, PTRVEC4INT,
                        VEC4INTPTR, PTRVEC4INTPTR, VEC2UINT, VEC2UINTPTR,
                        PTRVEC2UINT, PTRVEC2UINTPTR,VEC3UINT, PTRVEC3UINT,
                        VEC3UINTPTR, PTRVEC3UINTPTR,VEC4UINT, PTRVEC4UINT,
                        VEC4UINTPTR, PTRVEC4UINTPTR, VEC2INT8,
                        VEC2INT8PTR, PTRVEC2INT8, PTRVEC2INT8PTR,VEC3INT8, PTRVEC3INT8,
                        VEC3INT8PTR, PTRVEC3INT8PTR,VEC4INT8, PTRVEC4INT8,
                        VEC4INT8PTR, PTRVEC4INT8PTR, VEC2UINT8, VEC2UINT8PTR,
                        PTRVEC2UINT8, PTRVEC2UINT8PTR,VEC3UINT8, PTRVEC3UINT8,
                        VEC3UINT8PTR, PTRVEC3UINT8PTR,VEC4UINT8, PTRVEC4UINT8,
                        VEC4UINT8PTR, PTRVEC4UINT8PTR, VEC2INT16,
                        VEC2INT16PTR, PTRVEC2INT16, PTRVEC2INT16PTR,VEC3INT16, PTRVEC3INT16,
                        VEC3INT16PTR, PTRVEC3INT16PTR,VEC4INT16, PTRVEC4INT16,
                        VEC4INT16PTR, PTRVEC4INT16PTR, VEC2UINT16, VEC2UINT16PTR,
                        PTRVEC2UINT16, PTRVEC2UINT16PTR,VEC3UINT16, PTRVEC3UINT16,
                        VEC3UINT16PTR, PTRVEC3UINT16PTR,VEC4UINT16, PTRVEC4UINT16,
                        VEC4UINT16PTR, PTRVEC4UINT16PTR, VEC2INT32,
                        VEC2INT32PTR, PTRVEC2INT32, PTRVEC2INT32PTR,VEC3INT32, PTRVEC3INT32,
                        VEC3INT32PTR, PTRVEC3INT32PTR,VEC4INT32, PTRVEC4INT32,
                        VEC4INT32PTR, PTRVEC4INT32PTR, VEC2UINT32, VEC2UINT32PTR,
                        PTRVEC2UINT32, PTRVEC2UINT32PTR,VEC3UINT32, PTRVEC3UINT32,
                        VEC3UINT32PTR, PTRVEC3UINT32PTR,VEC4UINT32, PTRVEC4UINT32,
                        VEC4UINT32PTR, PTRVEC4UINT32PTR, VEC2INT64,
                        VEC2INT64PTR, PTRVEC2INT64, PTRVEC2INT64PTR,VEC3INT64, PTRVEC3INT64,
                        VEC3INT64PTR, PTRVEC3INT64PTR,VEC4INT64, PTRVEC4INT64,
                        VEC4INT64PTR, PTRVEC4INT64PTR, VEC2UINT64, VEC2UINT64PTR,
                        PTRVEC2UINT64, PTRVEC2UINT64PTR,VEC3UINT64, PTRVEC3UINT64,
                        VEC3UINT64PTR, PTRVEC3UINT64PTR,VEC4UINT64, PTRVEC4UINT64,
                        VEC4UINT64PTR, PTRVEC4UINT64PTR,VEC2LONG,
                        VEC2LONGPTR, PTRVEC2LONG, PTRVEC2LONGPTR,VEC3LONG, PTRVEC3LONG,
                        VEC3LONGPTR, PTRVEC3LONGPTR,VEC4LONG, PTRVEC4LONG,
                        VEC4LONGPTR, PTRVEC4LONGPTR, VEC2ULONGLONG, VEC2LONGLONGPTR,
                        PTRVEC2LONGLONG, PTRVEC2LONGLONGPTR,VEC3LONGLONG, PTRVEC3LONGLONG,
                        VEC3LONGLONGPTR, PTRVEC3LONGLONGPTR,VEC4LONGLONG, PTRVEC4LONGLONG,
                        VEC4LONGLONGPTR, PTRVEC4LONGLONGPTR,};

    class Variant{


    private:
      union Data{
        int asInt;
        int* asIntptr;
        math::Vector2<int> asVec2Int;
        math::Vector2<int> *asVec2Intptr;
        math::Vector2<int*> asVec2IntPtr;
        math::Vector2<int*> *asVec2IntPtrptr;
        math::Vector3<int> asVec3Int;
        math::Vector3<int> *asVec3Intptr;
        math::Vector3<int*> asVec3IntPtr;
        math::Vector4<int*> *asVec3IntPtrptr;
        math::Vector4<int> asVec4Int;
        math::Vector4<int> *asVec4Intptr;
        math::Vector4<int*> asVec4IntPtr;
        math::Vector4<int*> *asVec4Inttrptr;
        short asShort;
        math::Vector2<short> asVec2short;
        math::Vector2<short> *asVec2shortptr;
        math::Vector2<short*> asVec2shortPtr;
        math::Vector2<short*> *asVec2shortPtrptr;
        math::Vector3<short> asVec3short;
        math::Vector3<short> *asVec3shortptr;
        math::Vector3<short*> asVec3shortPtr;
        math::Vector4<short*> *asVec3shortPtrptr;
        math::Vector4<short> asVec4short;
        math::Vector4<short> *asVec4shortptr;
        math::Vector4<short*> asVec4shortPtr;
        math::Vector4<short*> *asVec4shorttrptr;
        short* asShortptr;
        long asLong;
        math::Vector2<long> asVec2long;
        math::Vector2<long> *asVec2longptr;
        math::Vector2<long*> asVec2longPtr;
        math::Vector2<long*> *asVec2longPtrptr;
        math::Vector3<long> asVec3long;
        math::Vector3<long> *asVec3longptr;
        math::Vector3<long*> asVec3longPtr;
        math::Vector4<long*> *asVec3longPtrptr;
        math::Vector4<long> asVec4long;
        math::Vector4<long> *asVec4longptr;
        math::Vector4<long*> asVec4longPtr;
        math::Vector4<long*> *asVec4longtrptr;
        long* aslongptr;
        long long asLongLong;
        math::Vector2<long long> asVec2longlong;
        math::Vector2<long long> *asVec2longlongptr;
        math::Vector2<long long*> asVec2longlongPtr;
        math::Vector2<long long*> *asVec2longlongPtrptr;
        math::Vector3<long long> asVec3longlong;
        math::Vector3<long long> *asVec3longlongptr;
        math::Vector3<long long*> asVec3longlongPtr;
        math::Vector4<long long*> *asVec3longlongPtrptr;
        math::Vector4<long long> asVec4longlong;
        math::Vector4<long long> *asVec4longlongptr;
        math::Vector4<long long*> asVec4longlongPtr;
        math::Vector4<long long*> *asVec4longlongtrptr;
        long long* asLongLongptr;
        char asChar;
        math::Vector2<char> asVec2SChar;
        math::Vector2<char> *asVec2SCharptr;
        math::Vector2<char*> asVec2SCharPtr;
        math::Vector2<char*> *asVec2CharPtrptr;
        math::Vector3<char> asVec3Char;
        math::Vector3<char> *asVec3Charptr;
        math::Vector3<char*> asVec3CharPtr;
        math::Vector3<char*> *asVec3CharPtrptr;
        math::Vector4<char> asVec4Char;
        math::Vector4<char> *asVec4Charptr;
        math::Vector4<char*> asVec4CharPtr;
        math::Vector4<char*> *asVec4CharPtrptr;
        char *asCharptr;
        std::string asString;
        std::string *asStringptr;
        math::Vector2<std::string> asVec2String;
        math::Vector2<std::string> *asVec2Stringptr;
        math::Vector2<std::string*> asVec2StringPtr;
        math::Vector2<std::string*> *asVec2StringPtrptr;
        math::Vector3<std::string> asVec3String;
        math::Vector3<std::string> *asVec3Stringptr;
        math::Vector3<std::string*> asVec3StringPtr;
        math::Vector3<std::string*> *asVec3StringPtrptr;
        math::Vector4<std::string> asVec4String;
        math::Vector4<std::string> *asVec4Stringptr;
        math::Vector4<std::string*> asVec4StringPtr;
        math::Vector4<std::string*> *asVec4StringPtrptr;
        int8_t asInt8;
        int8_t* asInt8ptr;
        math::Vector2<int8_t> asVec2Int8;
        math::Vector2<int8_t> *asVec2Int8ptr;
        math::Vector2<int8_t*> asVec2Int8Ptr;
        math::Vector2<int8_t*> *asVec2Int8Ptrptr;
        math::Vector3<int8_t> asVec3Int8;
        math::Vector3<int8_t> *asVec3Int8ptr;
        math::Vector3<int8_t*> asVec3Int8Ptr;
        math::Vector3<int8_t*> *asVec3Int8Ptrptr;
        math::Vector4<int8_t> asVec4Int8;
        math::Vector4<int8_t> *asVec4Int8ptr;
        math::Vector4<int8_t*> asVec4Int8Ptr;
        math::Vector4<int8_t*> *asVec4Int8Ptrptr;
        uint8_t asUInt8;
        uint8_t* asUInt8ptr;
        math::Vector2<uint8_t> asVec2UInt8;
        math::Vector2<uint8_t> *asVec2UInt8ptr;
        math::Vector2<uint8_t*> asVec2UInt8Ptr;
        math::Vector2<uint8_t*> *asVec2UInt8Ptrptr;
        math::Vector3<uint8_t> asVec3UInt8;
        math::Vector3<uint8_t> *asVec3UInt8ptr;
        math::Vector3<uint8_t*> asVec3UInt8Ptr;
        math::Vector3<uint8_t*> *asVec3UInt8Ptrptr;
        math::Vector4<uint8_t> asVec4UInt8;
        math::Vector4<uint8_t> *asVec4UInt8ptr;
        math::Vector4<uint8_t*> asVec4UInt8Ptr;
        math::Vector4<uint8_t*> *asVec4UInt8Ptrptr;
        int16_t asInt16;
        int16_t* asInt16ptr;
        math::Vector2<int16_t> asVec2Int16;
        math::Vector2<int16_t> *asVec2Int16ptr;
        math::Vector2<int16_t*> asVec2Int16Ptr;
        math::Vector2<int16_t*> *asVec2Int16Ptrptr;
        math::Vector3<int16_t> asVec3Int16;
        math::Vector3<int16_t> *asVec3Int16ptr;
        math::Vector3<int16_t*> asVec3Int16Ptr;
        math::Vector3<int16_t*> *asVec3Int16Ptrptr;
        math::Vector4<int16_t> asVec4Int16;
        math::Vector4<int16_t> *asVec4Int16ptr;
        math::Vector4<int16_t*> asVec4Int16Ptr;
        math::Vector4<int16_t*> *asVec4Int16Ptrptr;
        uint16_t asUInt16;
        uint16_t* asUInt16ptr;
        math::Vector2<uint16_t> asVec2UInt16;
        math::Vector2<uint16_t> *asVec2UInt16ptr;
        math::Vector2<uint16_t*> asVec2UInt16Ptr;
        math::Vector2<uint16_t*> *asVec2UInt16Ptrptr;
        math::Vector3<uint16_t> asVec3UInt16;
        math::Vector3<uint16_t> *asVec3UInt16ptr;
        math::Vector3<uint16_t*> asVec3UInt16Ptr;
        math::Vector3<uint16_t*> *asVec3UInt16Ptrptr;
        math::Vector4<uint16_t> asVec4UInt16;
        math::Vector4<uint16_t> *asVec4UInt16ptr;
        math::Vector4<uint16_t*> asVec4UInt16Ptr;
        math::Vector4<uint16_t*> *asVec4UInt16Ptrptr;
        int32_t asInt32;
        int32_t* asInt32ptr;
        math::Vector2<int32_t> asVec2Int32;
        math::Vector2<int32_t> *asVec2Int32ptr;
        math::Vector2<int32_t*> asVec2Int32Ptr;
        math::Vector2<int32_t*> *asVec2Int32Ptrptr;
        math::Vector3<int32_t> asVec3Int32;
        math::Vector3<int32_t> *asVec3Int32ptr;
        math::Vector3<int32_t*> asVec3Int32Ptr;
        math::Vector3<int32_t*> *asVec3Int32Ptrptr;
        math::Vector4<int32_t> asVec4Int32;
        math::Vector4<int32_t> *asVec4Int32ptr;
        math::Vector4<int32_t*> asVec4Int32Ptr;
        math::Vector4<int32_t*> *asVec4Int32Ptrptr;
        uint32_t asUInt32;
        uint32_t* asUInt32ptr;
        math::Vector2<uint32_t> asVec2UInt32;
        math::Vector2<uint32_t> *asVec2UInt32ptr;
        math::Vector2<uint32_t*> asVec2UInt32Ptr;
        math::Vector2<uint32_t*> *asVec2UInt32Ptrptr;
        math::Vector3<uint32_t> asVec3UInt32;
        math::Vector3<uint32_t> *asVec3UInt32ptr;
        math::Vector3<uint32_t*> asVec3UInt32Ptr;
        math::Vector3<uint32_t*> *asVec3UInt32Ptrptr;
        math::Vector4<uint32_t> asVec4UInt32;
        math::Vector4<uint32_t> *asVec4UInt32ptr;
        math::Vector4<uint32_t*> asVec4UInt32Ptr;
        math::Vector4<uint32_t*> *asVec4UInt32Ptrptr;
        int64_t asInt64;
        int64_t* asInt64ptr;
        math::Vector2<int64_t> asVec2Int64;
        math::Vector2<int64_t> *asVec2Int64ptr;
        math::Vector2<int64_t*> asVec2Int64Ptr;
        math::Vector2<int64_t*> *asVec2Int64Ptrptr;
        math::Vector3<int64_t> asVec3Int64;
        math::Vector3<int64_t> *asVec3Int64ptr;
        math::Vector3<int64_t*> asVec3Int64Ptr;
        math::Vector3<int64_t*> *asVec3Int64Ptrptr;
        math::Vector4<int64_t> asVec4Int64;
        math::Vector4<int64_t> *asVec4Int64ptr;
        math::Vector4<int64_t*> asVec4Int64Ptr;
        math::Vector4<int64_t*> *asVec4Int64Ptrptr;
        uint64_t asUInt64;
        uint64_t* asUInt64ptr;
        math::Vector2<uint64_t> asVec2UInt64;
        math::Vector2<uint64_t> *asVec2UInt64ptr;
        math::Vector2<uint64_t*> asVec2UInt64Ptr;
        math::Vector2<uint64_t*> *asVec2UInt64Ptrptr;
        math::Vector3<uint64_t> asVec3UInt64;
        math::Vector3<uint64_t> *asVec3UInt64ptr;
        math::Vector3<uint64_t*> asVec3UInt64Ptr;
        math::Vector3<uint64_t*> *asVec3UInt64Ptrptr;
        math::Vector4<uint64_t> asVec4UInt64;
        math::Vector4<uint64_t> *asVec4UInt64ptr;
        math::Vector4<uint64_t*> asVec4UInt64Ptr;
        math::Vector4<uint64_t*> *asVec4UInt64Ptrptr;
        void * asVoidPtr;
      }m_data;

    public:
      Variant();
      Variant(const Variant &copy);
      Variant(Variant &&move);

      Variant(int i);
      Variant(int * ip);
      Variant(short s);
      Variant(short * sp);
      Variant(long l);
      Variant(long * lp);
      Variant(long long ll);
      Variant(long long * llp);
      Variant(char c);
      Variant(char * p);
      Variant(std::string s);
      Variant(std::string *sp);
      Variant(int8_t i8);
      Variant(int8_t *i8p);
      Variant(uint8_t u8);
      Variant(uint8_t *u8p);
      Variant(uint16_t u16);
      Variant(uint16_t *u16p);
      Variant(uint32_t u32);
      Variant(uint32_t *u32p);
      Variant(uint64_t u64);

      Variant(math::Vector2<int8_t> i8v2);
      Variant(math::Vector3<int8_t> i8v3);
      Variant(math::Vector4<int8_t> i8v4);
      Variant(math::Vector2<uint8_t> ui8v2);
      Variant(math::Vector3<uint8_t> ui8v3);
      Variant(math::Vector4<uint8_t> ui8v4);
      Variant(math::Vector2<int16_t> i16v2);
      Variant(math::Vector3<int16_t> i16v3);
      Variant(math::Vector4<int16_t> i16v4);
      Variant(math::Vector2<uint16_t> ui16v2);
      Variant(math::Vector3<uint16_t> ui16v3);
      Variant(math::Vector4<uint16_t> ui16v4);
      Variant(math::Vector2<int32_t> i32v2);
      Variant(math::Vector3<int32_t> i32v3);
      Variant(math::Vector4<int32_t> i32v4);
      Variant(math::Vector2<uint32_t> ui32v2);
      Variant(math::Vector3<uint32_t> ui32v3);
      Variant(math::Vector4<uint32_t> ui32v4);
      Variant(math::Vector2<int64_t> i64v2);
      Variant(math::Vector3<int64_t> i64v3);
      Variant(math::Vector4<int64_t> i64v4);
      Variant(math::Vector2<uint64_t> ui64v2);
      Variant(math::Vector3<uint64_t> ui64v3);
      Variant(math::Vector4<uint64_t> ui64v4);


      Variant(math::Vector2<int8_t*> i8v2);
      Variant(math::Vector3<int8_t*> i8v3);
      Variant(math::Vector4<int8_t*> i8v4);
      Variant(math::Vector2<uint8_t*> ui8v2);
      Variant(math::Vector3<uint8_t*> ui8v3);
      Variant(math::Vector4<uint8_t*> ui8v4);
      Variant(math::Vector2<int16_t*> i16v2);
      Variant(math::Vector3<int16_t*> i16v3);
      Variant(math::Vector4<int16_t*> i16v4);
      Variant(math::Vector2<uint16_t*> ui16v2);
      Variant(math::Vector3<uint16_t*> ui16v3);
      Variant(math::Vector4<uint16_t*> ui16v4);
      Variant(math::Vector2<int32_t*> i32v2);
      Variant(math::Vector3<int32_t*> i32v3);
      Variant(math::Vector4<int32_t*> i32v4);
      Variant(math::Vector2<uint32_t*> ui32v2);
      Variant(math::Vector3<uint32_t*> ui32v3);
      Variant(math::Vector4<uint32_t*> ui32v4);
      Variant(math::Vector2<int64_t*> i64v2);
      Variant(math::Vector3<int64_t*> i64v3);
      Variant(math::Vector4<int64_t*> i64v4);
      Variant(math::Vector2<uint64_t*> ui64v2);
      Variant(math::Vector3<uint64_t*> ui64v3);
      Variant(math::Vector4<uint64_t*> ui64v4);


      Variant(math::Vector2<int8_t> *i8v2);
      Variant(math::Vector3<int8_t> *i8v3);
      Variant(math::Vector4<int8_t> *i8v4);
      Variant(math::Vector2<uint8_t> *ui8v2);
      Variant(math::Vector3<uint8_t> *ui8v3);
      Variant(math::Vector4<uint8_t> *ui8v4);
      Variant(math::Vector2<int16_t> *i16v2);
      Variant(math::Vector3<int16_t> *i16v3);
      Variant(math::Vector4<int16_t> *i16v4);
      Variant(math::Vector2<uint16_t> *ui16v2);
      Variant(math::Vector3<uint16_t> *ui16v3);
      Variant(math::Vector4<uint16_t> *ui16v4);
      Variant(math::Vector2<int32_t> *i32v2);
      Variant(math::Vector3<int32_t> *i32v3);
      Variant(math::Vector4<int32_t> *i32v4);
      Variant(math::Vector2<uint32_t> *ui32v2);
      Variant(math::Vector3<uint32_t> *ui32v3);
      Variant(math::Vector4<uint32_t> *ui32v4);
      Variant(math::Vector2<int64_t> *i64v2);
      Variant(math::Vector3<int64_t> *i64v3);
      Variant(math::Vector4<int64_t> *i64v4);
      Variant(math::Vector2<uint64_t> *ui64v2);
      Variant(math::Vector3<uint64_t> *ui64v3);
      Variant(math::Vector4<uint64_t> *ui64v4);

      Variant(math::Vector2<int8_t*> *i8v2);
      Variant(math::Vector3<int8_t*> *i8v3);
      Variant(math::Vector4<int8_t*> *i8v4);
      Variant(math::Vector2<uint8_t*> *ui8v2);
      Variant(math::Vector3<uint8_t*> *ui8v3);
      Variant(math::Vector4<uint8_t*> *ui8v4);
      Variant(math::Vector2<int16_t*> *i16v2);
      Variant(math::Vector3<int16_t*> *i16v3);
      Variant(math::Vector4<int16_t*> *i16v4);
      Variant(math::Vector2<uint16_t*> *ui16v2);
      Variant(math::Vector3<uint16_t*> *ui16v3);
      Variant(math::Vector4<uint16_t*> *ui16v4);
      Variant(math::Vector2<int32_t*> *i32v2);
      Variant(math::Vector3<int32_t*> *i32v3);
      Variant(math::Vector4<int32_t*> *i32v4);
      Variant(math::Vector2<uint32_t*> *ui32v2);
      Variant(math::Vector3<uint32_t*> *ui32v3);
      Variant(math::Vector4<uint32_t*> *ui32v4);
      Variant(math::Vector2<int64_t*> *i64v2);
      Variant(math::Vector3<int64_t*> *i64v3);
      Variant(math::Vector4<int64_t*> *i64v4);
      Variant(math::Vector2<uint64_t*> *ui64v2);
      Variant(math::Vector3<uint64_t*> *ui64v3);
      Variant(math::Vector4<uint64_t*> *ui64v4);

      Variant(void *ptr);

      //setData

      //getData
      template<typename T>
      T data(){
        return reinterpret_cast<T>(this->m_data);
      }

      //Data (const)

    };


  }
}



#endif //LEVariant.hpp
