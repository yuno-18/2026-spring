#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void){
    string seq;
    cout << "Enter DNA sequence : " ;
    cin >> seq;

    for(int i = 0; i < seq.size(); i++){
        seq[i] = toupper(seq[i]);
    }

    string motif;
    cout << "Enter motif : ";
    cin >> motif;

    for(int i = 0; i < motif.size(); i++){
        motif[i] = toupper(motif[i]);
    }


    cout << "Found position : " ;

    int L = seq.length() - motif.length() + 1;
    int count = 0;
    for(int i = 0; i < L; i++){
        if(seq.substr(i,motif.size()) == motif){
            count++;
            cout << i + 1 << ", " ;
        }
    }

    cout << endl;
    cout << "Total : " << count << endl;


    return 0;

}
