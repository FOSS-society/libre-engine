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

    class Variant{


    private:
      union m_data{
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
      };

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
      Variant(math::Vector2<int> iv2);
      Variant(math::Vector3<int> iv3);
      Variant(math::Vector4<int> iv4);
      Variant(math::Vector2<short> sv2);
      Variant(math::Vector3<short> sv3);
      Variant(math::Vector4<short> sv4);
      Variant(math::Vector2<long> lv2);
      Variant(math::Vector3<long> lv3);
      Variant(math::Vector4<long> lv4);
      Variant(void *ptr);

      //setData

      //getData

      //Data (const)

    };


  }
}



#endif //LEVariant.hpp
