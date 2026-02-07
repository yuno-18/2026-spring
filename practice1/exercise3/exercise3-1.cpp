#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    const float a = 1;
    const float b = 1e4;
    const float c = 1;

    float d = sqrt(b * b - 4 * a * c);
    float x1 = (-b + d) / (2 * a);
    float x2 = (-b - d) / (2 * a);
}