#include "vector3.h"

Vector3::Vector3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

Vector3::~Vector3()
{
}

Vector3 & Vector3::operator+=(const Vector3 & oth)
{
	x += oth.x;
	y += oth.y;
	z += oth.z;

	return *this;
}

Vector3 & Vector3::operator+=(const glm::vec3 & oth)
{
	x += oth.x;
	y += oth.y;
	z += oth.z;

	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & oth)
{
	x -= oth.x;
	y -= oth.y;
	z -= oth.z;

	return *this;
}

Vector3 & Vector3::operator/=(const float oth)
{
	x /= oth;
	y /= oth;
	z /= oth;

	return *this;
}

Vector3 & Vector3::operator*=(const float oth)
{
	x *= oth;
	y *= oth;
	z *= oth;

	return *this;
}

void Vector3::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

void Vector3::limit(float by)
{
	float mag = magnitude();
	if (mag > by)
	{
		this->normalize();
		x *= by;
		y *= by;
		z *= by;
	}
}

Vector3 Vector3::operator+(const Vector3 & oth)
{
	return Vector3(x + oth.x, y + oth.y, z + oth.z);
}

Vector3 Vector3::operator-(const Vector3 & oth)
{
	return Vector3(x - oth.x, y - oth.y, z - oth.z);

}

Vector3 Vector3::operator/(const float oth)
{
	return Vector3(x / oth, y / oth, z / oth);
}

Vector3 Vector3::operator*(const float oth)
{
	return Vector3(x, y, z) *= oth;
}

bool Vector3::operator==(const Vector3 & oth)
{
	return
		x == oth.x &&
		y == oth.y &&
		z == oth.z;
}

bool Vector3::operator!=(const Vector3 & oth)
{
	return
		x != oth.x &&
		y != oth.y &&
		z != oth.z;
}
