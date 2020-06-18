#include "vector.hpp"

Vector2D::Vector2D(type new_x,type new_y)
:   x(new_x),y(new_y)
{

}

Vector2D Vector2D::operator+(Vector2D const &object) const
{
    Vector2D b(x + object.x, y + object.y);

    return b;
}

Vector2D Vector2D::operator-(Vector2D const &object) const
{
    Vector2D b(x - object.x, y - object.y);

    return b;
}

Vector2D Vector2D::operator*(type const value) const
{
    Vector2D b(x * value, y * value);

    return b;
}

Vector2D Vector2D::operator/(type const value) const
{
    Vector2D b(x / value, y / value);

    return b;
}

Vector2D Vector2D::crossProduct(Vector2D const &object) const
{
    Vector2D b(x * object.x, y * object.y);

    return b;
}

Vector2D Vector2D::divisionProduct(Vector2D const &object) const
{
    Vector2D b(x / object.x, y / object.y);

    return b;
}

Vector3D Vector3D::operator-(Vector3D const &object) const
{
    Vector3D b(x - object.x, y - object.y, z - object.z);

    return b;
}

Vector3D Vector3D::operator+(Vector3D const &object) const
{
    Vector3D b(x + object.x, y + object.y, z + object.z);

    return b;
}

Vector3D::Vector3D(type x2, type y2, type z2)
:   x(x2),y(y2),z(z2)
{

}

Vector3D Vector3D::operator*(type value) const
{
    Vector3D b(x * value, y * value, z * value);

    return b;
}

Vector3D Vector3D::operator/(type value) const
{
    Vector3D b(x / value, y / value, z /value);

    return b;
}

Vector3D Vector3D::crossProduct(Vector3D const &object) const
{
    Vector3D b(x * object.x, y * object.y, z * object.z);

    return b;
}

Vector3D Vector3D::divisionProduct(Vector3D const &object) const
{
    Vector3D b(x / object.x, y / object.y, z / object.z);

    return b;
}
