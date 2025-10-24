#pragma once
#include<iostream>
#include<cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


struct vec3 {

	float x, y, z;

	vec3( float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f):x(x_),y(y_), z(z_) {}

	friend std::ostream& operator<<(std::ostream& os,const vec3& v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}

	vec3 operator+(const vec3& v) const{

		return vec3(x + v.x, y + v.y, z + v.z);
	
	}

	vec3 operator-(const vec3& v)const {

		return vec3(x - v.x, y - v.y, z - v.z);
	}

	vec3 operator*(float s) const {

		return vec3(x * s, y * s, z * s);

	}

	vec3 operator-()const{
		return vec3(-x, -y, -z);
	}


	float length() const {
		return std::sqrt(x * x + y * y + z * z);
	}


	vec3 normalize() const {

		float l = length();
		
		if (l > 0) return vec3(x / l, y / l, z / l);
		return vec3(0, 0, 0);
	}


	static float dot(const vec3& v1, const vec3& v2) {

		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static vec3 cross(const vec3& v1, const vec3& v2) {

		return vec3(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
	}
};