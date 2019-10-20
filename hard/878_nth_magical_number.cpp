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
    long gcd(long x, long y) {
        int z;
        while (y > 0) {
            z = y;
            y = x % y;
            x = z;
        }
        return x;
    }

    long lcm(long x, long y) {
        return x * y / gcd(x, y);
    }

    int nthMagicalNumber(int N, int A, int B) {
        int ans = 0, mod = 1e9 + 7;
        long temp = lcm(A, B);
        set<long> arr;
        long a = A, b = B;
        f1 (i, 1, temp / a + 1) arr.insert(a * i);
        f1 (i, 1, temp / b + 1) arr.insert(b * i);
        vector<long> arr2(arr.begin(), arr.end());
        sort(arr2.begin(), arr2.end());
        N -= 1;
        int n1 = N % arr2.size(), n2 = N / arr2.size();
        return (arr2[n1] + n2 * temp) % mod;
    }
};
