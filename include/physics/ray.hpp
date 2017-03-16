#ifndef RAY_HPP
#define RAY_HPP


namespace libre{

    //foward declare
    template <typename t>
    class math::vector2<t>;

    template <typename t>
    class math::vector3<t>;

    namespace graphics{


    class Ray2D{
    private:
        math::vector2<float> m_origin;
        math::vector2<float> m_direction;
        bool m_biDirectional;

    public:
        Ray2D(math::vector2<float> origin,math::vector2<float> direction, bool bidir);
        Ray2D(const Ray2D *copy);

        bool hitObj(const vector2<float> *other);



    };
    class Ray3D{
    private:
        math::vector3<float> m_origin;
        math::vector3<float> m_direction;
        bool m_biDirectional;

    public:
        Ray3D(math::vector3<float> origin,math::vector3<float> direction, bool bidir);
        Ray3D(const Ray3D *copy);

        bool hitObj(const vector3<float> *other);
    };


    }
}

#endif // RAY_HPP
