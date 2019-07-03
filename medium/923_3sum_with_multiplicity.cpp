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
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> c;
        for (int e : A) c[e]++;
        long res = 0;

        int e1, e2, e3;
        for (auto kv1 : c) {
            for (auto kv2 : c) {
                e1 = kv1.first, e2 = kv2.first;
                e3 = target - e1 - e2;
                if (!c.count(e3)) continue;
                if (e1 == e2 && e2 == e3) {
                    res += c[e1] * (c[e1] - 1) * (c[e1] - 2) / 6;
                } else if (e1 == e2) {
                    res += c[e1] * (c[e1] - 1) / 2 * c[e3];
                } else if (e1 < e2 and e2 < e3) {
                    res += c[e1] * c[e2] * c[e3];
                }
            }
        }
        return res % int(1e9 + 7);
    }
};
