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
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> cs, cs2;
        int r = grid.size(), c = grid[0].size();
        int f = 0;

        f (i, r) {
            f (j, c) {
                int e = grid[i][j];
                if (e == 1) {
                    f += 1;
                }
                if (e == 2) {
                    cs.emplace_back(i, j);
                }
            }
        }

        int res = 0;
        vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int a, b, d1, d2, a1, a2;

        while (true) {
            for (auto p : cs) {
                a = p.first, b = p.second;
                for (auto dd : d) {
                    a1 = a + dd.first, a2 = b + dd.second;
                    if (a1 >= 0 && a1 < r && a2 >= 0 && a2 < c && grid[a1][a2] == 1) {
                        grid[a1][a2] = 2;
                        f -= 1;
                        cs2.emplace_back(a1, a2);
                    }
                }
            }

            if (cs2.empty()) {
                return f == 0 ? res : -1;
            }

            cs = cs2, cs2 = {};
            res += 1;
        }
    }
};
