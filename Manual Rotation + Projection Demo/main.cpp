#include<iostream>
#include<GLAD/glad.h>
#include<GLFW/glfw3.h>
#include"mathlib.h"



int main() {

	
    // 1. Create a 90-degree rotation around the Z-axis
    mat4 rot = mat4::rotate(1.5708f, vec3(0.0f, 0.0f, 1.0f));

    // 2. Create a translation (move 5 units down the X-axis)
    mat4 trans = mat4::identity();
    trans.m[12] = 5.0f;

    // 3. Perform both multiplications
    mat4 result_RotThenTrans = trans * rot;
    mat4 result_TransThenRot = rot * trans;

    // 4. Print and compare
    std::cout << "--- Rotate first, then Translate ---" << std::endl;
    result_RotThenTrans.print();

    std::cout << "\n--- Translate first, then Rotate ---" << std::endl;
    result_TransThenRot.print();
    return 0;
}