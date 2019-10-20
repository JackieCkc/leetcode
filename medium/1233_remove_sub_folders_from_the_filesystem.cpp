#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <array>
#include <stack>
#include <list>
#include <set>
#include <unordered_map>
#include <math.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <regex>
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
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<vector<string>> paths;
        for (auto f : folder) paths.push_back(split(f, '/'));
        sort(paths.begin(), paths.end(), [](vector<string> &a, vector<string> &b) { return a.size() < b.size(); });

        set<string> roots;
        vector<string> res;

        for (auto p : paths) {
            string curr;
            bool ok = true;

            f1 (i, 1, p.size()) {
                curr += "/" + p[i];
                if (roots.count(curr)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                roots.insert(curr);
                res.push_back(curr);
            }
        }
        return res;
    }
};

