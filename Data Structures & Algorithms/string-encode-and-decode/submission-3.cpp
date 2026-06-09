#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    string encode(vector<string> &strs) {
        string encoded;
        for (const string &s : strs) {
            encoded.append(to_string(s.length()) + '#' + s);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.length()){
            size_t delim = s.find('#', i);
            int len = stoi(s.substr(i, delim - i));
            string str = s.substr(delim + 1, len);
            decoded.push_back(str);
            i = delim + 1 + len;
        }
        return decoded;
    }
};
