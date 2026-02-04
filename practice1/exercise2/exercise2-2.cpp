#include <iostream>
#include <vector>
#include <string>
using namespace std;

double CalcGCContent(string seq){
    double length = seq.size();
    double count_gc = 0.0;
    for(int i = 0; i < seq.size(); i++){
        if(seq[i] == 'C' || seq[i] == 'G') count_gc++;
    }
    return count_gc / length;
}

int main(void){
    vector<string> sequences = {
        "ATGCGAT",
        "GCGCGCGC",
        "ATATATAC",
        "CCCGGGTT",
        "TTAACCGA"
    };

    vector<string> high_gc_sequences;

    for(int i = 0; i < sequences.size(); i++){
        if(CalcGCContent(sequences[i]) >= 0.5){
            high_gc_sequences.push_back(sequences[i]);
        }

    }   
    cout << "GC含量が50%以上の配列：" << endl;
        for(int i = 0; i < high_gc_sequences.size(); i++){
            cout << high_gc_sequences[i] << endl;
        } 

}