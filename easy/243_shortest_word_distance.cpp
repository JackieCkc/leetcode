// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1 = -1, i2 = -1;
        int res = words.size();
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (i2 != -1) res = min(res, i - i2);
                i1 = i;
            } else if (words[i] == word2) {
                if (i1 != -1) res = min(res, i - i1);
                i2 = i;
            }
        }
        
        return res;
    }
};
