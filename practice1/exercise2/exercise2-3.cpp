#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main(void){
    ifstream ist("human_protein_interaction.txt");
    if(!ist){
        cerr << "cannot open human_protein_interaction.txt" << endl;
        exit (1);
    }

    map<string, int> interaction_count;
    string line;
    while(getline(ist, line)){
        int space_pos = line.find(" ");
        string protein1 = line.substr(0, space_pos);
        string protein2 = line.substr(space_pos + 1);

        interaction_count[protein1]++;
        interaction_count[protein2]++;
    }

    string max_protein;
    int max_count = -1;
    for(auto it = interaction_count.cbegin(); it != interaction_count.cend(); it++){
        if(it-> second > max_count){
            max_count = it-> second;
            max_protein = it-> first;
        }
    }

    cout << "最も相互作用するたんぱく質が多いたんぱく質は" << max_protein << "です" << endl;
    cout << "その回数は" << max_count << "回です" << endl;
    return 0;


}