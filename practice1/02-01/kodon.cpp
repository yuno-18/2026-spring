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

    for(int i = 0; i + 3 <= seq.size(); i += 3){
        cout << seq.substr(i, 3) << " " ;
    }

    cout << endl;

    for(int i = 0; i + 3 <= seq.size(); i += 3){
        string codon = seq.substr(i, 3);
        if(codon == "ATG"){
            cout << "M";
        }
        else if(codon == "TAA" || codon == "TAG"
                || codon == "TGA" ){
            break;
        }
        else{
            cout << "?" << " " ;
        }
    }
    
    cout << endl;


    return 0;
}