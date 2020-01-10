// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// Example 1:

// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:

// Input: [[7,10],[2,4]]
// Output: 1

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        
        sort(intervals.begin(), intervals.end());
        
        struct cmp {
            bool operator() (int a, int b) {
                return a > b;
            }  
        };
        
        priority_queue<int, vector<int>, cmp> pq;
        
        for (auto t : intervals) {
            if (pq.empty()) {
                res += 1;
                pq.push(t[1]);
                continue;
            }
            
            if (pq.top() > t[0]) res += 1;
            else pq.pop();
            
            pq.push(t[1]);
        }
        
        return res;
    }
};