We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.(Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.

 

Example 1:

Input: 20
Output: 6
Explanation: 
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.
Example 2:

Input: 100
Output: 19
Explanation: 
The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100].
 

Note:

1 <= N <= 10^9


class Solution {
public:
    int confusingNumberII(int N) {
        string s = to_string(N);
		// list all confusing numbers with length no longer than N
        vector<string> pairs = {"00", "11", "88", "69", "96"};
        unordered_map<int, vector<string>> level;
        level[0] = {""};
        unordered_set<long> cache;
        for (int m = 1; m <= s.size(); m++) {
            if (m == 1)
                level[m] = {"0", "1", "8"};
            else {
                for (string mid : level[m - 2])
                for (string p : pairs)
                    level[m].push_back(p[0] + mid + p[1]);
            }
            for (string t : level[m]) {
                if (t[0] == '0') continue;
                long n = stol(t);
                if (n <= N) cache.insert(n);
            }
        }
		// The minus 1 is to get rid of 0
        return helper(s) - 1 - cache.size();
    }
private:
	// count number with digits in "01689" from 0 to s
    int helper(string s) {
        string digits = "01689";
        if (s.size() == 1) {
            int ret = 0;
            for (char c : digits) ret += c <= s[0];
            return ret;
        } else {
            int smaller = 0;
            for (char c : digits) smaller += c < s[0];
            int ret = smaller * powl(5, s.size() - 1);
            if (digits.find(s[0]) != string::npos)
                ret += helper(to_string(stol(s.substr(1))));
            return ret;
        }
    }
};
