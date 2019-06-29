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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int_arr B, res;
        while (K > 0) {
            B.push_back(K % 10);
            K /= 10;
        }
        reverse(B.begin(), B.end());
        int l1 = A.size(), l2 = B.size();
        int e1, e2, v, c = 0;
        f (i, l2) {
            e1 = i < l1 ? A[l1 - i - 1] : 0;
            e2 = B[l2 - i - 1];
            v = e1 + e2 + c;
            if (v >= 10) {
                c = 1;
                v = v % 10;
            } else {
                c = 0;
            }
            res.push_back(v);
        }
        if (l1 > l2) {
            for (int i = l2; i < l1; i++) {
                v = A[l1 - i - 1] + c;
                if (v >= 10) {
                    c = 1;
                    v = v % 10;
                } else {
                    c = 0;
                }
                res.push_back(v);
            }
        }
        if (c > 0) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
