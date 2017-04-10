#ifndef COORDINATE2D_H
#define COORDINATE2D_H

#include <stdexcept>
#include "libremath.hpp"
namespace libre{

    namespace math{

        class Coordinate2D{
        private:
            CoordinateSystem m_system;
            Vector2<float> m_coordinates;


            public:
            Coordinate2D(const CoordinateSystem &system,const Vector2<t>& coords):
                m_system(system),m_coordinates(coords){
            }

            CoordinateSystem getSystem(){return m_system;}
            CoordinateSystem System()const{return m_system;}

            Vector2<float> getCoordinates(){return m_coordinates;}
            Vector2<float> Coordinates()const{return m_coordinates;}

            void setSystem(const CoordinateSystem &system){this->m_system = system;}
            void setCoords(const Vector2<float> &coords){this->m_coordinates = coords;}

            Coordinate2D &convertToSystem(const CoordinateSystem &system){
                math::Vector2<float> temp;
                switch(system){
                case CoordinateSystem::CS2_CARTESIAN:
                    if(this->m_system != CoordinateSystem::CS2_POLAR){
                        throw std::runtime_error("Coordinate System already Cartesian");
                    }else{
                        /**
                          To Convert: X = R *cos(theta)
                                      Y = R * sin(theta)

                        **/
                        temp.setX(this->getCoordinates().X() * cos(this->m_coordinates.Y()));
                        temp.setY(this->getCoordinates().X() * sin(this->m_coordinates.Y()));
                        return new Coordinate2D(system,temp);
                    }
                        break;

                case CoordinateSystem::CS2_POLAR:
                    if(this->m_system != CoordinateSystem::CS2_CARTESIAN){
                        throw std::runtime_error("Coordinate System already Polar");
                    }else{
                        /**
                          To Convert: R = sqrt(x^2+y^2)
                                      theta = arctan(y/x)

                        **/
                        temp.setX(sqrt(this->m_coordinates.X()*this->m_coordinates.X()+this->m_coordinates.Y()*this->m_coordinates.Y()));
                        temp.setY(atan(this->m_coordinates.Y()/this->m_coordinates.X()));
                        return new Coordinate2D(system,temp);
                    }
                        break;

                  default:
                    throw std::runtime_error("Coordinate System is incompatable with 2D");
                    break;

                }
            }




        };


    }
}
#endif // COORDINATE2D_H
