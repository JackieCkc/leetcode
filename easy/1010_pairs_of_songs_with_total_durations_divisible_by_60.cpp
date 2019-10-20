#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <array>
#include <stack>
#include <set>
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
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        int res = 0, v;
        for (int t : time) {
            v = t % 60 == 0 ? 60 : t % 60;
            res += m[60 - v];
            m[t % 60] += 1;
        }
        return res;
    }
};
