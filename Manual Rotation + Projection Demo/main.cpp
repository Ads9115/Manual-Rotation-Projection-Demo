#include<iostream>
#include<GLAD/glad.h>
#include<GLFW/glfw3.h>
#include"mathlib.h"



int main() {

	
	/*vec3 a = { 3, 4, 8 };
	vec3 b = {3 ,4 , 3};
	vec3 c = vec3::cross(a, b);
	std::cout << c << std::endl;*/
	
	mat4 mat = mat4::identity();
	mat.print();
	



	
	
	return 0;
}