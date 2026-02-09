#include <iostream>
#include <cmath>

using namespace std;

double f1(double x){
    return exp(x) + x - 5;
}

double f2(double x){
    return cbrt(x);
}

int main(void){
    double a = 0.0;
    double b = 2.0;
    double min, max;
    if(f1(a) < 0 && f1(b) > 0){
        min = a;
        max = b;
    }else if(f1(a) > 0 && f1(b) < 0){
        min = b;
        max = a;
    }else {
        cout << "解なし" << endl;
        return 0;
    }

    double half;
    double dist = max - min;
    int count = 0;
    while(dist > 1e-12){
        half = (min + max) / 2;
        if(f1(half) > 0){
            max = half;
        }else if(f1(half) < 0){
            min = half;
        }else{
            return 0;
        }
        count++;
    }
    
    cout << "解は" << min << "<" <<  max << "にある" << endl;
    cout << "繰り返しの回数は" << count << "回です" << endl;

    return 0;
}