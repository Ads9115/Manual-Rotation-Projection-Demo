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


struct mat4 {

	float m[16];
	
	mat4() {
		
		for (int i = 0; i < 16; i++) m[i] = 0.0f;

		
		m[0] = 1.0f;
		m[5] = 1.0f;
		m[10] = 1.0f;
		m[15] = 1.0f;
	}

	const float* ptr() const { return m; }  //for pointer refrence to gluniformmatrix4fv

	static mat4 identity() {
		
		return mat4();
	}

	void print() const {
		std::cout << "mat4:" << std::endl;
		for (int i = 0; i < 16; ++i) {
			std::cout << m[i] << "\t";  

			
			if ((i + 1) % 4 == 0) {
				std::cout << std::endl; 
			}
		}
	}

static mat4 rotate(float angle_rad, const vec3& axis) {
        vec3 norm_axis = axis.normalize();
        float c = std::cos(angle_rad);
        float s = std::sin(angle_rad);
        float t = 1.0f - c;
        float x = norm_axis.x;
        float y = norm_axis.y;
        float z = norm_axis.z;

        mat4 rot = identity();
        // Col 0
        rot.m[0] = t * x * x + c;
        rot.m[1] = t * x * y + s * z;
        rot.m[2] = t * x * z - s * y;
        // Col 1
        rot.m[4] = t * x * y - s * z;
        rot.m[5] = t * y * y + c;
        rot.m[6] = t * y * z + s * x;
        // Col 2
        rot.m[8] = t * x * z + s * y;
        rot.m[9] = t * y * z - s * x;
        rot.m[10] = t * z * z + c;
        
        return rot;
    }


};
