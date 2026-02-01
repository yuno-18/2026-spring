#include <iostream>
#include <string>

using namespace std;

int main(void){
    string seq;
    cout << "Enter DNA sequence : " ;
    cin >> seq;

    for(int i = 0; i + 3 <= seq.size(); i += 3){
        cout << seq.substr(i, 3) << " " << endl;
    }


    return 0;
}