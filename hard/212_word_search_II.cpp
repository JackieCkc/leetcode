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
#include <regex>

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
    for (int e : arr) {
        cout << e << " ";
    }
    cout << endl;
}

string lower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

struct TrieNode {
    TrieNode *nodes[26] = { nullptr };
    string word;
};

class Solution {
    int2_arr dd = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void dfs(vector<string>& r, vector<vector<char>>& b, TrieNode *p, int x, int y) {
        char c = b[x][y], c1;

        if (p->nodes[c - 'a'] == nullptr) return;

        b[x][y] = '-';
        p = p->nodes[c - 'a'];

        if (!p->word.empty()) {
            r.push_back(p->word);
            p->word = "";
        }

        for (auto d1 : dd) {
            int xx = x + d1[0], yy = y + d1[1];
            if (xx >= 0 && xx < b.size() && yy >= 0 && yy < b[0].size()) {
                c1 = b[xx][yy];
                if (c1 == '-' || p->nodes[c1 - 'a'] == nullptr) continue;
                dfs(r, b, p, xx, yy);
            }
        }

        b[x][y] = c;
    }

    TrieNode build_tree(vector<string>& words) {
        TrieNode root = TrieNode();
        TrieNode *p;
        for (string w : words) {
            p = &root;
            for (char& c : w) {
                if (p->nodes[c - 'a'] == nullptr) p->nodes[c - 'a'] = new TrieNode();
                p = p->nodes[c - 'a'];
            }
            p->word = w;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root = build_tree(words);
        vector<string> res;
        int m = board.size(), n = board[0].size();

        f (i, m) {
            f (j, n) {
                dfs(res, board, &root, i, j);
            }
        }
        return res;
    }
};
