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
    Solution(int n_rows, int n_cols) {
        n = n_rows;
        c = n_cols;
        t = n * c;
        curr = t;
    }

    vector<int> flip() {
        int i = (rand() % curr) + 1;
        int i1 = i;
        if (m.count(i)) {
            i = m[i];
        }
        int b = curr;
        if (m.count(curr)) {
            b = m[curr];
        }
        m[i1] = b;
        i -= 1;
        curr -= 1;
        return {i / c, i % c};
    }

    void reset() {
        curr = t;
        m.clear();
    }

private:
    map<int, int> m;
    int n, c, t, curr;
};
