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

struct Node {
    int val;
    set<string> keys;
};

class AllOne {
public:
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!node_map.count(key)) {
            node_map[key] = nodes.insert(nodes.begin(), {0, {key}});
        }
        auto next_node = node_map[key], prev_node = next_node++;
        if (next_node == nodes.end() || next_node->val > prev_node->val + 1) {
            next_node = nodes.insert(next_node, {prev_node->val + 1, {}});
        }
        next_node->keys.insert(key);
        node_map[key] = next_node;

        prev_node->keys.erase(key);
        if (prev_node->keys.empty()) nodes.erase(prev_node);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!node_map.count(key)) return;
        auto next_node = node_map[key], prev_node = next_node--;
        node_map.erase(key);
        if (prev_node->val > 1) {
            if (prev_node == nodes.begin() || next_node->val < prev_node->val - 1) {
                next_node = nodes.insert(prev_node, {prev_node->val - 1, {}});
            }
            next_node->keys.insert(key);
            node_map[key] = next_node;
        }

        prev_node->keys.erase(key);
        if (prev_node->keys.empty()) nodes.erase(prev_node);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (nodes.empty()) return "";
        return *(nodes.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (nodes.empty()) return "";
        return *(nodes.begin()->keys.begin());
    }

private:
    unordered_map<string, list<Node>::iterator> node_map;
    list<Node> nodes;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */