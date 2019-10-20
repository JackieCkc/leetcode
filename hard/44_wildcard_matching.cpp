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
    bool isMatch(string s, string p) {
        int p1 = 0, p2 = 0;
        int l1 = s.size(), l2 = p.size();
        int star = -1, used_star = -1;

        while (p1 < l1) {
            if (s[p1] == p[p2] || p[p2] == '?') {
                p1++;
                p2++;
                continue;
            }

            if (p[p2] == '*') {
                star = ++p2;
                used_star = p1;
                continue;
            }

            if (star != -1) {
                p2 = star;
                p1 = ++used_star;
                continue;
            }

            return false;
        }

        while (p2 < l2) {
            if (p[p2++] != '*') return false;
        }

        return true;
    }
};
