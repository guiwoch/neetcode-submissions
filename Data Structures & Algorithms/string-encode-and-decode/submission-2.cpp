#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    string encode(vector<string> &strs) {
        string encoded;
        for (string str : strs) {
            encoded.append(to_string(str.length()) + "#" + str);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> encoded;
        string size;
        int i = 0;
        while (i < s.length()) {
            if (s[i] != '#') {
                size += s[i];
                ++i;
            } else {
                ++i;
                int sizeInt = stoi(size);
                size = "";
                string part;
                for (int j = 0; j < sizeInt; j++, i++) {
                    part += s[i];
                }
                encoded.push_back(part);
            }
        }
        return encoded;
    }
};
