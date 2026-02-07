#include <iostream>
#include <cmath>
using namespace std;

double f2(double x){
    return cbrt(x);
}

double f1(double x){
    return exp(x) + x - 5;
}

//関数そのものを引数として渡すことが可能。これは関数ポインタと呼ばれるが詳しい説明は省略。
void bisection(double a, double b, double eps, double f(double)){
    int count = 0;
    double c = 0;

    //本当はここでaとbの間に解があることを保証するためにf(a)*f(b) < 0 であることを確認するのが良い。

    while(true){
        c = (a+b)/2;
        double fc = f(c);

        if(fc > 0){
            b = c;
        }else if(fc < 0){
            a = c;
        }
        count++;
        if(b - a < eps){
            cout <<"解:" << c << " 回数:" << count << endl;
            return;
        } 
    }
}

int main(void){
    double eps = 1e-12;
    cout << "f1: exp(x) + x - 5" << endl;
    bisection(0.0, 2.0, eps, f1);
    cout << "f2: x^(1/3)" << endl;
    bisection(-0.1, 0.2, eps, f2);    
}
/*
出力結果:
f1: exp(x) + x - 5
解:1.30656 回数:41
f2: x^(1/3)
解:1.81899e-13 回数:39
*/