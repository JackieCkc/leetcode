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
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> cur, cur2, res;

        for (int e : A) {
            cur2 = {e};
            for (int e1 : cur) {
                cur2.insert(e1 | e);
            }
            cur = cur2;
            for (auto e1 : cur2) {
                res.insert(e1);
            }
        }

        return res.size();
    }
};
