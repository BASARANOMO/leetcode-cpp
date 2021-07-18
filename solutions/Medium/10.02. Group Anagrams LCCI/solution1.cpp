#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_map;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            str_map[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = str_map.begin(); it != str_map.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};