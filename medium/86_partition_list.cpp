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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *res = head, *pt = head;
        ListNode *l = NULL, *s = NULL, *s1 = NULL, *l1 = NULL;
        int val;
        while (pt) {
            val = pt->val;
            if (val >= x) {
                if (l) {
                    l1->next = pt;
                    l1 = pt;
                } else {
                    l = pt;
                    l1 = pt;
                }
            } else {
                if (s) {
                    s1->next = pt;
                    s1 = pt;
                } else {
                    s = pt;
                    s1 = pt;
                }
            }
            pt = pt->next;
        }
        if (s1) s1->next = l;
        if (l1) l1->next = NULL;
        return s ? s : l;
    }
};
