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
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, set<int>> trust_to, trust_by;
        int a, b;
        for (vector<int> a_b : trust) {
            a = a_b.front();
            b = a_b.back();
            trust_by[b].insert(a);
            trust_to[a].insert(b);
        }
        for (int i = 1; i < N + 1; i++) {
            if (trust_by[i].size() == N - 1 && trust_to[i].size() == 0) {
                return i;
            }
        }
        return -1;
    }
};
