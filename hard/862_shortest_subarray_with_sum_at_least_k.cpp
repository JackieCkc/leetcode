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
    int shortestSubarray(vector<int>& A, int K) {
        int l = A.size();
        int ans = l + 1;

        deque<int> arr(l + 1, 0);
        int_arr pre_sum(l + 1, 0);

        f (i, l) pre_sum[i + 1] = pre_sum[i] + A[i];

        f1 (i, 1, l + 1) {
            while (!arr.empty() && pre_sum[i] - pre_sum[arr.front()] >= K) {
                ans = min(ans, i - arr.front());
                arr.pop_front();
            }
            while(!arr.empty() && pre_sum[i] <= pre_sum[arr.back()]) {
                arr.pop_back();
            }
            arr.push_back(i);
        }

        return ans <= l ? ans : -1;
    }
};
