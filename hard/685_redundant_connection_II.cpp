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

void print_arr(int_arr& arr) {
    for (int e : arr) cout << e << " ";
    cout << endl;
}

string lower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), a, b, cand_a = -1, cand_b = -1, pa, last = -1;
        vector<int> count(n + 1, -1), parent(n + 1, 0);
        f (i, n + 1) parent[i] = i;

        f (i, n) {
            auto e = edges[i];
            a = e[0], b = e[1];

            if (count[b] != -1) {
                cand_a = count[b];
                cand_b = i;
                continue;
            }

            count[b] = i;

            pa = find(parent, a);
            if (pa == b) {
                last = i;
            }
            parent[b] = pa;
        }

        if (last == -1) return edges[cand_b];
        if (cand_b == -1) return edges[last];
        return edges[cand_a];
    }

private:
    int find(vector<int>& parent, int n) {
        if (parent[n] == n) return n;
        return find(parent, parent[n]);
    }
};
