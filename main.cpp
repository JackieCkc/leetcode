#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <regex>
#include <math.h>
#include <vector>
#include <map>
#include <tuple>
#include <stack>
#include <list>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

#define f(x, n) for (int x = 0; x < n; x++)
#define f1(x, s, n) for (int x = s; x < n; x++)

typedef vector<int> int_arr;
typedef vector<string> str_arr;
typedef vector<vector<int>> int2_arr;
typedef vector<vector<string>> str2_arr;

int bl(vector<long>& arr, long v) {
    auto it = lower_bound(arr.begin(), arr.end(), v);
    return distance(arr.begin(), it);
}

int br(vector<long> arr, int v) {
    auto it = upper_bound(arr.begin(), arr.end(), v);
    return distance(arr.begin(), it);
}

template <typename T>
void print(T t) {
    cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

template <typename T>
void print_a(vector<T>& arr) {
    cout << "[";
    for (const auto& e : arr) cout << e << ", ";
    cout << "]";
    cout << endl;
}

string lower(string s) {
    transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });
    return s;
}

vector<string> split(string s, char dim) {
    vector<string> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, dim)) res.push_back(item);
    return res;
}

class Solution {
public:
    int solve() {
        return 0;
    }
};

int main() {
    Solution s;
    print(s.solve());
    return 0;
}
