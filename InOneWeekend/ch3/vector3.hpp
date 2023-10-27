#ifndef VEC3_HPP
#define VEC3_HPP

#include <array>
#include <ostream>

namespace common
{

class Vector3
{
   public:
    using array_type = std::array<double, 3>;

    // constructors
    Vector3() : values{0, 0, 0} {}
    Vector3(double x, double y, double z) : values{x, y, z} {}
    Vector3(const array_type& values) : values(values) {}

    // getters
    inline double x() const { return this->values[0]; }
    inline double y() const { return this->values[1]; }
    inline double z() const { return this->values[2]; }

    // methods
    double length() const;
    double length_squared() const;

    // operators
    Vector3 operator-() const;

    double operator[](int index) const;
    double& operator[](int index);

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator+=(const double rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3& operator-=(const double rhs);
    Vector3& operator*=(const Vector3& rhs);
    Vector3& operator*=(const double rhs);
    Vector3& operator/=(const Vector3& rhs);
    Vector3& operator/=(const double rhs);

   private:
    array_type values;
};

using Point3 = Vector3;
using Color = Vector3;

#define DEFINE_BINARY_OPERATOR(_Op)                                         \
    inline Vector3 operator##_Op(const Vector3& lhs, const Vector3& rhs)    \
    {                                                                       \
        Vector3 result(lhs);                                                \
        result _Op## = rhs;                                                 \
        return result;                                                      \
    }                                                                       \
                                                                            \
    inline Vector3 operator##_Op(const Vector3::array_type::value_type lhs, \
                                 const Vector3& rhs)                        \
    {                                                                       \
        Vector3 result{lhs, lhs, lhs};                                      \
        result _Op## = rhs;                                                 \
        return result;                                                      \
    }                                                                       \
                                                                            \
    inline Vector3 operator##_Op(const Vector3& lhs,                        \
                                 const Vector3::array_type::value_type rhs) \
    {                                                                       \
        Vector3 result(lhs);                                                \
        result _Op## = rhs;                                                 \
        return result;                                                      \
    }

// define binary operators

DEFINE_BINARY_OPERATOR(+)
DEFINE_BINARY_OPERATOR(-)
DEFINE_BINARY_OPERATOR(*)
DEFINE_BINARY_OPERATOR(/)

#undef DEFINE_BINARY_OPERATOR

inline std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

}  // namespace common

#endif