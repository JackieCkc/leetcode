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
    int minDeletionSize(vector<string>& A) {
        int l1 = A[0].size(), l2 = A.size(), res = 0, j;
        vector<bool > sorted(l2, false);

        f (i, l1) {
            for (j = 1; j < l2; j++) {
                if (!sorted[j] && A[j][i] < A[j - 1][i]) {
                    res += 1;
                    break;
                }
            }
            if (j < l2) continue;
            f1 (j, 1, l2) {
                if (!sorted[j]) {
                    sorted[j] = A[j][i] > A[j - 1][i];
                }
            }
        }

        return res;
    }
};
