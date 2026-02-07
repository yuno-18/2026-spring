#include <iostream>
#include <cmath>
using namespace std;

double f2(double x){
    return cbrt(x);
}

double df2(double x){
    return (1.0/3) / cbrt(x * x);
}

double f1(double x){
    return exp(x) + x - 5;
}

double df1(double x){
    return exp(x) + 1;
}

//関数そのものを引数として渡すことが可能。これは関数ポインタと呼ばれるが詳しい説明は省略。
void newton_method(double x, double eps, double f(double), double df(double)){
    int count = 0;
    while(true){
        double fx = f(x);
        double dfx = df(x);
        if(!isfinite(fx) || !isfinite(dfx)){
            cout << "f(x) またはdf(x)が非有限です。解が求まりません。" << endl;
            return;
        }
        //f2(x)はニュートン法では正しい解が求まらない。エラー処理のため上のようなif文を加えている。
        //isfiniteは値が有限か有限でないかを判定する関数。

        double delta = f(x)/df(x);
        x -= delta;
        count++;
        if(fabs(delta) < eps){
            cout <<"解:" << x << " 回数:" << count << endl;
            return;
        } 
    }
}

int main(void){
    double eps = 1e-12;
    cout << "f1: exp(x) + x - 5" << endl;
    newton_method(0.0, eps, f1, df1);  
    cout << "f2: x^(1/3)" << endl;
    newton_method(-0.1, eps, f2, df2);     
}
/*
出力結果:
f1: exp(x) + x - 5
解:1.30656 回数:7
f2: x^(1/3)
f(x) またはdf(x)が非有限です。解が求まりません。

f1の二分法とのループ回数の比較
二分法は41回であったところニュートン法は7回で収束しており、ニュートン法が二分法に比べループ回数が少ないことが確認できた。

f2は数値解が求まらない理由の考察:
1. 導関数がx = 0で定義されず、無限大になるため、ニュートン法の適用がそもそも成り立たない。
2. 反復式がx_(n+1) =  -2 * x_nのようになり、原点に収束せず発散することが明らか。
*/