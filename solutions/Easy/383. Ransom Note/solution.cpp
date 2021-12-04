class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        vector<int> cnts(26);
        for (char c : ransomNote) cnts[c - 'a']++;
        for (char c : magazine) cnts[c - 'a']--;
        for (int cnt : cnts) if (cnt > 0) return false;
        return true;
    }
};