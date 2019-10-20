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

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        int2_arr dp(l1 + 1, int_arr(l2 + 1, 0));

        f (i, l1 + 1) {
            f (j, l2 + 1) {
                if (i == 0) dp[0][j] = j;
                else if (j == 0) dp[i][0] = i;
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[l1][l2];
    }
};