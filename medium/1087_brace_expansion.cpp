//A string S represents a list of words.
//
//Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].
//
//For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].
//
//Return all words that can be formed in this manner, in lexicographical order.
//
//
//
//Example 1:
//
//Input: "{a,b}c{d,e}f"
//Output: ["acdf","acef","bcdf","bcef"]
//Example 2:
//
//Input: "abcd"
//Output: ["abcd"]
//
//
//Note:
//
//1 <= S.length <= 50
//There are no nested curly brackets.
//All characters inside a pair of consecutive opening and ending curly brackets are different.

class Solution {
public:
    vector<string> expand(string S) {
        vector<vector<string>> arr;
        vector<string> curr = {};
        bool in_braket = false;

        for (auto &c : S) {
            if (c == '{' || c == '}') {
                in_braket = c == '{';
                if (!curr.empty()) arr.push_back(curr);
                curr.clear();
            } else if (c != ',') {
                if (in_braket) curr.push_back({string(1, c)});
                else arr.push_back({string(1, c)});
            }
        }

        if (!curr.empty()) arr.push_back(curr);

        vector<string> res = {""};
        for (auto &a : arr) {
            vector<string> next_res;
            for (auto &r : res) {
                for (auto &s : a) {
                    next_res.push_back(r + s);
                }
            }
            res = next_res;
        }

        sort(res.begin(), res.end());

        return res;
    }
};