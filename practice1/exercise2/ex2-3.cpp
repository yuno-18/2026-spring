#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(void){
    ifstream ist("human_protein_interaction.txt");
    if(!ist){
        cerr << "cannot open human_protein_interaction.txt" << endl;
        exit(1);
    }

    map<string, int> interaction_count;
    string line;
    while(getline(ist, line)){
        int space_pos = line.find(" ");
        string protein1 = line.substr(0,space_pos);
        string protein2 = line.substr(space_pos+1);

        interaction_count[protein1]++;
        interaction_count[protein2]++;
    }

    string max_protein;
    int max_count = -1;
    for(map<string, int>::const_iterator it = interaction_count.begin(); it != interaction_count.end(); it++){
        if (it->second > max_count) {
            max_count = it->second;
            max_protein = it->first;
        }
    }

    cout << "最も多く相互作用しているタンパク質:" << max_protein 
         << "（" << max_count << "件の相互作用）" << endl;

    return 0;
}
