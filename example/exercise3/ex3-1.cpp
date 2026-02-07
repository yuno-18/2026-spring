#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    float a, b, c;
    a =  1; b =  1e4, c = 1;
    
    float d = sqrt(b * b - 4 * a * c);
    float x1 = (-b+d)/(2*a);
    float x2 = (-b-d)/(2*a);

    cout << "桁落ち考慮なし" << endl;
    cout << x1 << " " << x2 << endl;

    if(b > 0){
        x1 = 2*c/ (-b-d);
        x2 = (-b-d)/(2*a);
    }else{
        x1 = (-b+d)/(2*a);
        x2 = 2*c/(d-b);
    }
    //bの正負により、2つの解のうちどちらかで桁落ちが発生する可能性がある。
    //桁落ちが発生する可能性がある方については、式変形をして引き算がない形にするか、あるいは解と係数の関係を利用する。

    cout << "桁落ち考慮あり" << endl;
    cout << x1 << " " << x2 << endl;

}

/*
出力結果
桁落ち考慮なし
0 -10000
桁落ち考慮あり
-0.0001 -10000
*/