#ifndef _VECTOR3
#define _VECTOR3

#include <iostream>
#include <math.h>
#include <string>
#include <glm/glm.hpp>

#define PI 3.14159265359
#define RAD_TO_DEG 57.2957795
#define DEG_TO_RAD 0.0174532925

class Vector3 {
public:
	float x, y, z;
	Vector3(float x_ = 0.0f, float y_ = 0.0f, float _z = 0.0f);

	virtual ~Vector3();

	// Operators
	Vector3 &operator+=(const Vector3 &oth);

	Vector3 &operator-=(const Vector3 &oth);

	Vector3 &operator/=(const float oth);

	Vector3 &operator*=(const float oth);

	Vector3 operator+(const Vector3 &oth);

	Vector3 operator-(const Vector3 &oth);

	Vector3 operator/(const float oth);

	Vector3 operator*(const float oth);

	bool operator==(const Vector3 &oth);
	bool operator!=(const Vector3 &oth);

	//type casting
	operator glm::vec3() { return glm::vec3(x, y, z); };

	float magnitude() { return sqrt((x * x) + (y * y) + (z * z)); }
	float static getAngle(float x, float y) { return atan2(y, x) * 57.2957795; }
	Vector3 normalized() { return Vector3(x, y, z) / magnitude(); };
	void normalize();
	void limit(float by);

	static Vector3 getNormalPoint(Vector3 p, Vector3 a, Vector3 b);
	float dot(Vector3 b);
};
#endif // !_VECTOR3
