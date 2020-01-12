//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Find all strobogrammatic numbers that are of length = n.
//
//        Example:
//
//Input:  n = 2
//Output: ["11","69","88","96"]

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, true);
    }

    vector<string> helper(int n, bool is_start=false) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};

        vector<string> res = helper(n - 2);
        vector<string> res3;
        for (string s : res) {
            if (!is_start) res3.push_back("0" + s + "0");
            res3.push_back("1" + s + "1");
            res3.push_back("6" + s + "9");
            res3.push_back("8" + s + "8");
            res3.push_back("9" + s + "6");
        }
        return res3;
    }
};