#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <array>
#include <stack>
#include <set>
#include <unordered_map>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

#define f(x, n) for (int x = 0; x < n; x++)
#define f1(x, s, n) for (int x = s; x < n; x++)

typedef vector<int> int_arr;
typedef vector<string> str_arr;
typedef vector<vector<int>> int2_arr;
typedef vector<vector<string>> str2_arr;

template <typename T>
void print(T t) {
    cout << t << endl ;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int ans = 2, l = A.size(), d;

        f (i, l) {
            f (j, i) {
                d = A[i] - A[j];
                dp[i][d] = dp[j].count(d) ? dp[j][d] + 1: 2;
                ans = max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};
