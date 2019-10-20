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
    bool check(vector<int>& arr) {
        if (arr.size() % 2 != 0) {
            return false;
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, int> s;
        for (int e : arr) s[e] += 1;
        for (int e : arr) {
            if (s[e] <= 0) continue;
            if (s[e * 2] <= 0) return false;
            s[e] -= 1;
            s[e * 2] -= 1;
        }
        return true;
    }

    bool canReorderDoubled(vector<int>& A) {
        int_arr arr1, arr2;
        for (int e : A) {
            e >= 0 ? arr1.push_back(e) : arr2.push_back(e * -1);
        }
        return check(arr1) && check(arr2);
    }
};
