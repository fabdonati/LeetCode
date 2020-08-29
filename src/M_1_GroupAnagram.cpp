#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string strSort(string input) {
    string t;
    int counter[26] = {0};
    for (auto c : input) {
        counter[c-'a']++;
    }
    for (int i=0; i<sizeof(counter)/sizeof(counter[0]); i++){
        t += string(counter[i], i +'a'); // fills the string with n consecutive chars
    }
    return t;
}

int main() {
    vector<string> strings{"eat","tae","ear","rae","tac"};
    unordered_map<string, vector<string>> mp; 
    for (auto s : strings) {
        mp[strSort(s)].push_back(s);
    }

    for (unordered_map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << endl;
        for (auto word : it->second) {
            cout << word << endl;
        }
    }
    return 0;
}