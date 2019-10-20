#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <array>
#include <stack>
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
    int sumSubarrayMins(vector<int>& A) {
        long arr_sum = 0;
        vector<pair<int, int>> arr;
        int l = A.size();
        int_arr p(l), n(l);

        f(i, l) {
            p[i] = i + 1;
            n[i] = l - i;
        }

        f (i, l) {
            int e = A[i];
            while (!arr.empty() && arr.back().first > A[i]) {
                n[arr.back().second] = i - arr.back().second;
                arr.pop_back();
            }
            if (!arr.empty()) {
                p[i] = i - arr.back().second;
            }
            arr.push_back({e, i});
        }

        int ans = 0, mod = 1e9 + 7;
        f (i, l) {
            ans = (ans + A[i] * p[i] * n[i]) % mod;
        }
        return ans;
    }
};
