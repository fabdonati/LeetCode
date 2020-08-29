#include <unordered_set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a_pointer = 0;
        int b_pointer = 0;
        int maxLength = 0;
        unordered_set<char> hash_set;
        while (b_pointer < s.length()) {
            if (hash_set.find(s[b_pointer]) == hash_set.end()) {
                hash_set.insert(s[b_pointer]);
                b_pointer++;
                maxLength = max(static_cast<int>(hash_set.size()), maxLength);
            } else {
                hash_set.erase(s[a_pointer]);
                a_pointer++;
            }
        }
        return maxLength;
    }
};
