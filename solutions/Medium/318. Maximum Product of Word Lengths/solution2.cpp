class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> masks;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int mask = 0;
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                mask |= 1 << (word[j] - 'a');
            }
            if (masks.count(mask)) {
                if (wordLength > masks[mask]) masks[mask] = wordLength;
            } else masks[mask] = wordLength;
        }
        int maxProd = 0;
        for (auto [mask1, _] : masks) {
            int wordLength1 = masks[mask1];
            for (auto [mask2, _] : masks) {
                int wordLength2 = masks[mask2];
                if ((mask1 & mask2) == 0) {
                    maxProd = max(maxProd, wordLength1 * wordLength2);
                }
            }
        }
        return maxProd;
    }
};