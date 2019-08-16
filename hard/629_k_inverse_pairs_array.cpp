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
#include <regex>

using namespace std;

#define f(x, n) for (int x = 0; x < n; x++)
#define f1(x, s, n) for (int x = s; x < n; x++)

typedef vector<int> int_arr;
typedef vector<string> str_arr;
typedef vector<vector<int>> int2_arr;
typedef vector<vector<string>> str2_arr;

int bl(vector<long>& arr, long v) {
    auto it = lower_bound(arr.begin(), arr.end(), v);
    return distance(arr.begin(), it);
}

int br(vector<long> arr, int v) {
    auto it = upper_bound(arr.begin(), arr.end(), v);
    return distance(arr.begin(), it);
}

template <typename T>
void print(T t) {
    cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

void print_arr(int_arr& arr) {
    for (int e : arr) {
        cout << e << " ";
    }
    cout << endl;
}

string lower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

struct TrieNode {
    TrieNode *nodes[26] = { nullptr };
    string word;
};

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) return 1;

        vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
        int mod = (int)(1e9 + 7);

        f (i, n + 1) dp[i][0] = 1;

        f1 (i, 1, n + 1) {
            f1 (j, 1, k + 1) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (j >= i) dp[i][j] -= dp[i - 1][j - i] % mod;
            }
        }

        return (dp[n][k] + mod) % mod;
    }
};
