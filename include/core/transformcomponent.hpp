#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "../math/libremath.hpp"
#include "Component.hpp"
#include <vector>




namespace libre{
    namespace core{



        class TransformComponent : public Component
        {

            bool changed;
            int m_childCount;
            math::Vector3<float> m_eulerAngles;
            math::Vector3<float> m_localEulerAngles;

            //Determining Direction
            math::Vector3<float> m_foward;
            math::Vector3<float> m_up;
            math::Vector3<float> m_right;

            math::Matrix4<float> m_ltwMatrix;
            math::Matrix4<float> m_wtlMatrix;

            math::Vector3<float> m_position;
            math::Vector3<float> m_localPosition;
            math::Vector3<float> m_scale;
            math::Vector3<float> m_localScale;
            math::Vector4<float> m_rotation;
            math::Vector4<float> m_localRotation;
            TransformComponent *m_parentTransform;
            std::vector<TransformComponent *> m_children;
            TransformComponent *root;

        public:
            TransformComponent(Entity * parent,char * name,const math::Vector3<float> &position, const math::Vector3<float> &scale, math::Vector4<float> &rotation);
            TransformComponent *getRoot() const;
            void setRoot(TransformComponent *value);
            std::vector<TransformComponent *> children() const;
            void setChildren(const std::vector<TransformComponent *> &children);
            TransformComponent *parentTransform() const;
            void setParentTransform(TransformComponent *parentTransform);
            math::Vector4<float> localRotation() const;
            void setLocalRotation(const math::Vector4<float> &localRotation);
            math::Vector4<float> rotation() const;
            void setRotation(const math::Vector4<float> &rotation);
            math::Vector3<float> localScale() const;
            void setLocalScale(const math::Vector3<float> &localScale);
            math::Vector3<float> scale() const;
            void setScale(const math::Vector3<float> &scale);
            math::Vector3<float> localPosition() const;
            void setLocalPosition(const math::Vector3<float> &localPosition);
            math::Vector3<float> position() const;
            void setPosition(const math::Vector3<float> &position);
            math::Matrix4<float> wtlMatrix() const;
            void setWtlMatrix(const math::Matrix4<float> &wtlMatrix);
            math::Matrix4<float> ltwMatrix() const;
            void setLtwMatrix(const math::Matrix4<float> &ltwMatrix);
            math::Vector3<float> right() const;
            void setRight(const math::Vector3<float> &right);
            math::Vector3<float> up() const;
            void setUp(const math::Vector3<float> &up);
            math::Vector3<float> foward() const;
            void setFoward(const math::Vector3<float> &foward);
            math::Vector3<float> localEulerAngles() const;
            void setLocalEulerAngles(const math::Vector3<float> &localEulerAngles);
            math::Vector3<float> eulerAngles() const;
            void setEulerAngles(const math::Vector3<float> &eulerAngles);
            int childCount() const;
            void setChildCount(int childCount);
            bool getChanged() const;
            void setChanged(bool value);
        };
    }
}
#endif // TRANSFORMCOMPONENT_HPP
