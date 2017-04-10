#include "../../include/system/BufferLayout.hpp"

namespace libre{
    namespace system{

    BufferLayout::BufferLayout()
            : m_size(0)
        {
        }

    void BufferLayout::pushElement(const std::string& name, unsigned int type, unsigned int size, unsigned int count, bool normalized)
        {

            m_layout.push_back(BufferElement(name, type, size, count,m_size, normalized));
            m_size += size * count;
        }

    }
}
