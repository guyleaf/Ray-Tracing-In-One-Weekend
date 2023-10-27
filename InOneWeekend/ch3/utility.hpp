#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "vector3.hpp"

namespace common
{

inline double dot(const Vector3 &u, const Vector3 &v)
{
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

inline Vector3 cross(const Vector3 &u, const Vector3 &v)
{
    return {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
            u[0] * v[1] - u[1] * v[0]};
}

inline Vector3 unit_vector(const Vector3 &v) { return v / v.length(); }

}  // namespace common

#endif