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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n2 > n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int s = 0, e = n2 * 2 + 1;
        while (s < e) {
            int m2 = (s + e) / 2;
            int m1 = n1 + n2 - m2;

            double l1 = m1 == 0 ? INT_MIN : nums1[(m1 - 1) / 2];
            double r1 = m1 == n1 * 2 ? INT_MAX : nums1[m1 / 2];
            double l2 = m2 == 0 ? INT_MIN : nums2[(m2 - 1) / 2];
            double r2 = m2 == n2 * 2 ? INT_MAX : nums2[m2 / 2];

            if (r1 < l2) e = m2;
            else if (l1 > r2) s = m2 + 1;
            else return (min(r1, r2) + max(l1, l2)) / 2;
        }
        return -1;
    }
};
