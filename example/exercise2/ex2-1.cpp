#include <iostream>
#include <string>
using namespace std;

int HammingDistance(string& s1, string& s2) {
    if (s1.size() != s2.size()) {        
        return -1;
    }

    int dist = 0;
    int length = s1.size();
    for (int i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            dist++;
        }
    }
    return dist;
}

int main() {
    string a = "AACCGT";
    string b = "AATCAT";
    string c = "AACCG";

    int dist1 = HammingDistance(a, b);
    if (dist1 != -1) {
        cout << "Hamming Distance: " << dist1 << endl;
    }else{
        cout << "The two strings have different lengths." << endl;
    }
    int dist2 = HammingDistance(a, c);
    if (dist2 != -1) {
        cout << "Hamming Distance: " << dist2 << endl;
    }else{
        cout << "The two strings have different lengths." << endl;
    }

    return 0;
}