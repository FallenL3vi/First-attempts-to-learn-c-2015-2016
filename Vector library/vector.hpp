#pragma once

template <class type, int value>

class Vector2D
{
public:

    type x;
    type y;

    Vector2D(type x, type y);

    Vector2D operator-(Vector2D const &object) const;

    Vector2D operator+(Vector2D const &object) const;

    Vector2D operator*(float const value) const;

    Vector2D operator/(float const value) const;

    Vector2D crossProduct(Vector2D const &object) const;

    Vector2D divisionProduct(Vector2D const &object) const;
private:

};

class Vector3D
{
public:

    type x;
    type y;
    type z;

    Vector3D(type x,type y,type z);


    Vector3D operator-(Vector3D const &object) const;

    Vector3D operator+(Vector3D const &object) const;

    Vector3D operator*(float const value) const;

    Vector3D operator/(float const value) const;

    Vector3D crossProduct(Vector3D const &object) const;

    Vector3D divisionProduct(Vector3D const &object) const;

private:

};
