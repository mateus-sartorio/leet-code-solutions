#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> map;

        for(auto& c : s) {
            map[c]++;
        }

        for(auto& c : t) {
            map[c]--;
        }

        for(auto& pair : map) {
            if(pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
