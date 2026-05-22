#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<int, int> hashMap;
        hashMap.reserve(s.length());
        for (char i : s){
            hashMap[i]++;
        }
        for (char i : t){
            auto it = hashMap.find(i);
            if (it != hashMap.end()){
                hashMap[i]--;
                if (it->second == 0){
                    hashMap.erase(it);
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
