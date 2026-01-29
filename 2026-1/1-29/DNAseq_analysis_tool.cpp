#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(void){
    string seq;
    cout << "Enter DNA sequence:" ;
    cin >> seq;

    int A = 0, C = 0, G = 0, T = 0, N = 0;

    for(int i = 0; i < seq.size(); i++){
        char base = seq[i];
        base = toupper(base);

        if(base == 'A') A++;
        else if(base == 'C') C++;
        else if(base == 'G') G++;
        else if(base == 'T') T++;
        else if(base == 'N') N++;
        else{
            cout << "Invalid character: " << base << endl;
        }
    }

    int length = seq.size();
    double gc =(double)(G + C)/length * 100.0;
    double a_prob = (double)A / length * 100.0;
    double c_prob = (double)C / length * 100.0;
    double g_prob = (double)G / length * 100.0;
    double t_prob = (double)T / length * 100.0;

    cout << fixed << setprecision(2);
    cout << "Length:" << length << endl;
    cout << endl;
    cout << "A: " << A << "(" << a_prob << "%)" << endl;
    cout << "C: " << C << "(" << c_prob << "%)" << endl; 
    cout << "G: " << G << "(" << g_prob << "%)" << endl;
    cout << "T: " << T << "(" << t_prob << "%)" << endl;
    cout << endl;
    cout << "GC content: " << gc << "%" << endl;

    return 0;
}