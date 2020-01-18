// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// Example 1:

// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.
// Example 2:

// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.


class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int res = 0, n = 0;
        int be = 0, en = 0;
        Map<Character, Integer> map = new HashMap<>();
        while (en < s.length()) {
            char c = s.charAt(en);
            if (!map.containsKey(c)) {
                map.put(c, 0);
                n += 1;
            }
            map.put(c, map.get(c) + 1);
            while (n > k) {
                char c2 = s.charAt(be++);
                map.put(c2, map.get(c2) - 1);
                if (map.get(c2) == 0) {
                    map.remove(c2);
                    n -= 1;
                }
            }
            res = Math.max(res, en - be + 1);
            en += 1;
        }
        return res;
    }
}
