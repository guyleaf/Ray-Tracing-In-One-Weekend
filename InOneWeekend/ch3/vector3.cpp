#include "vector3.hpp"

#include <cmath>

namespace common
{

double Vector3::length() const { return std::sqrt(this->length_squared()); }

double Vector3::length_squared() const
{
    double result = 0;
    for (auto value : this->values)
    {
        result += value * value;
    }
    return result;
}

// operators

Vector3 Vector3::operator-() const
{
    array_type values(this->values);
    for (auto& value : values)
    {
        value = -value;
    }
    return values;
}

double Vector3::operator[](int index) const { return this->values[index]; }

double& Vector3::operator[](int index) { return this->values[index]; }

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    for (array_type::size_type i = 0; i < rhs.values.size(); i++)
    {
        this->values[i] += rhs.values[i];
    }
    return *this;
}

Vector3& Vector3::operator+=(const double rhs)
{
    for (auto& value : this->values)
    {
        value += rhs;
    }
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    for (array_type::size_type i = 0; i < rhs.values.size(); i++)
    {
        this->values[i] -= rhs.values[i];
    }
    return *this;
}

Vector3& Vector3::operator-=(const double rhs)
{
    *this += (-rhs);
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& rhs)
{
    for (array_type::size_type i = 0; i < rhs.values.size(); i++)
    {
        this->values[i] *= rhs.values[i];
    }
    return *this;
}

Vector3& Vector3::operator*=(const double rhs)
{
    for (auto& value : this->values)
    {
        value *= rhs;
    }
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& rhs)
{
    for (array_type::size_type i = 0; i < rhs.values.size(); i++)
    {
        this->values[i] /= rhs.values[i];
    }
    return *this;
}

Vector3& Vector3::operator/=(const double rhs)
{
    *this *= (1 / rhs);
    return *this;
}

}  // namespace common