#include "../../include/core/transformcomponent.hpp"

namespace libre{
    namespace core{


    TransformComponent *TransformComponent::getRoot() const
    {
        return root;
    }

    void TransformComponent::setRoot(TransformComponent *value)
    {
        root = value;
    }

    std::vector<TransformComponent *> TransformComponent::children() const
    {
        return m_children;
    }

    void TransformComponent::setChildren(const std::vector<TransformComponent *> &children)
    {
        m_children = children;
    }

    TransformComponent *TransformComponent::parentTransform() const
    {
        return m_parentTransform;
    }

    void TransformComponent::setParentTransform(TransformComponent *parentTransform)
    {
        m_parentTransform = parentTransform;
    }

    math::Vector4<float> TransformComponent::localRotation() const
    {
        return m_localRotation;
    }

    void TransformComponent::setLocalRotation(const math::Vector4<float> &localRotation)
    {
        m_localRotation = localRotation;
    }

    math::Vector4<float> TransformComponent::rotation() const
    {
        return m_rotation;
    }

    void TransformComponent::setRotation(const math::Vector4<float> &rotation)
    {
        m_rotation = rotation;
    }

    math::Vector3<float> TransformComponent::localScale() const
    {
        return m_localScale;
    }

    void TransformComponent::setLocalScale(const math::Vector3<float> &localScale)
    {
        m_localScale = localScale;
    }

    math::Vector3<float> TransformComponent::scale() const
    {
        return m_scale;
    }

    void TransformComponent::setScale(const math::Vector3<float> &scale)
    {
        m_scale = scale;
    }

    math::Vector3<float> TransformComponent::localPosition() const
    {
        return m_localPosition;
    }

    void TransformComponent::setLocalPosition(const math::Vector3<float> &localPosition)
    {
        m_localPosition = localPosition;
    }

    math::Vector3<float> TransformComponent::position() const
    {
        return m_position;
    }

    void TransformComponent::setPosition(const math::Vector3<float> &position)
    {
        m_position = position;
    }

    math::Matrix4<float> TransformComponent::wtlMatrix() const
    {
        return m_wtlMatrix;
    }

    void TransformComponent::setWtlMatrix(const math::Matrix4<float> &wtlMatrix)
    {
        m_wtlMatrix = wtlMatrix;
    }

    math::Matrix4<float> TransformComponent::ltwMatrix() const
    {
        return m_ltwMatrix;
    }

    void TransformComponent::setLtwMatrix(const math::Matrix4<float> &ltwMatrix)
    {
        m_ltwMatrix = ltwMatrix;
    }

    math::Vector3<float> TransformComponent::right() const
    {
        return m_right;
    }

    void TransformComponent::setRight(const math::Vector3<float> &right)
    {
        m_right = right;
    }

    math::Vector3<float> TransformComponent::up() const
    {
        return m_up;
    }

    void TransformComponent::setUp(const math::Vector3<float> &up)
    {
        m_up = up;
    }

    math::Vector3<float> TransformComponent::foward() const
    {
        return m_foward;
    }

    void TransformComponent::setFoward(const math::Vector3<float> &foward)
    {
        m_foward = foward;
    }

    math::Vector3<float> TransformComponent::localEulerAngles() const
    {
        return m_localEulerAngles;
    }

    void TransformComponent::setLocalEulerAngles(const math::Vector3<float> &localEulerAngles)
    {
        m_localEulerAngles = localEulerAngles;
    }

    math::Vector3<float> TransformComponent::eulerAngles() const
    {
        return m_eulerAngles;
    }

    void TransformComponent::setEulerAngles(const math::Vector3<float> &eulerAngles)
    {
        m_eulerAngles = eulerAngles;
    }

    int TransformComponent::childCount() const
    {
        return m_childCount;
    }

    void TransformComponent::setChildCount(int childCount)
    {
        m_childCount = childCount;
    }

    bool TransformComponent::getChanged() const
    {
        return changed;
    }

    void TransformComponent::setChanged(bool value)
    {
        changed = value;
    }
    TransformComponent::TransformComponent(Entity *parent, char *name, const math::Vector3<float> &position, const math::Vector3<float> &scale, math::Vector4<float> &rotation):Component(parent,name)
    , m_position(position),m_scale(scale),m_rotation(rotation){

    }
    }
}
