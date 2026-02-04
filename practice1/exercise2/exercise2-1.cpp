#include <iostream>
#include <string>
using namespace std;

int HammingDistance(string& s1, string& s2){
    int count = 0;
    if(s1.size() != s2.size()){
        return -1;
    }else{
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
        }
    }

    return count;

}

int main(void){
    string a = "AACCGT";
    string b = "AATCAT";
    string c = "AACCG";

    int dist1 = HammingDistance(a, b);
    if(dist1 != -1){
        cout << "Haming Distance: " << dist1 << endl;
    }else{
        cout << "The two stringh have different lengths." << endl;
    }
    int dist2 = HammingDistance(a,c);
    if(dist2 != -1){
        cout <<  "Haming Distance: " << dist1 << endl;
    }else{
        cout << "The two stringh have different lengths." << endl;
    }
    
    return 0;
    
}
