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

    cout << "桁落ち考慮なし" << endl;
    cout << x1 << " " << x2 << endl;

    if(b > 0){
        x1 = (2 * c)/(-b-d);
        x2 = (-b-d) / (2 *a);
    }else{
        x1 = (-b + d) / (2 * a);
        x2 = (2 * c)/(-b+d);
    }

    cout << "桁落ち考慮有" << endl;
    cout << x1 << " " << x2 << endl;
}