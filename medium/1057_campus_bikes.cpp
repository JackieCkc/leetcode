// On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

// Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.

// The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

// Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.

 

// Example 1:



// Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
// Output: [1,0]
// Explanation: 
// Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
// Example 2:



// Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
// Output: [0,2,1]
// Explanation: 
// Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].
 

// Note:

// 0 <= workers[i][j], bikes[i][j] < 1000
// All worker and bike locations are distinct.
// 1 <= workers.length <= bikes.length <= 1000


class Solution {
public:
    struct Item {
        int d;
        int worker;
        int bike;

        bool operator < (const Item& rhs) const {
            if (rhs.d != d) return d < rhs.d;
            if (rhs.worker != worker) return worker < rhs.worker;
            return bike < rhs.bike;
        }
    };
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {        
        vector<deque<Item>> arr;
        for (int i = 0; i < workers.size(); i++) {
            deque<Item> arr2;
            for (int j = 0; j < bikes.size(); j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                arr2.push_back({dis, i, j});
            }
            sort(arr2.begin(), arr2.end());
            arr.push_back(arr2);
        }

        priority_queue<Item> q;
        
        for (int i = 0; i < workers.size(); i++) {
            auto [d, k, j] = arr[i].front();
            q.push({-d, -k, -j});
            arr[i].pop_front();
        }
        
        vector<int> ans(workers.size(), -1);
        vector<int> bikes_used(bikes.size(), 0);
        int c = workers.size();
        
        while (c) {
            auto [d, i, j] = q.top(); q.pop();
            i *= -1;
            j *= -1;
            if (ans[i] == -1 && !bikes_used[j]) {
                
                ans[i] = j;
                bikes_used[j] = 1;
                c -= 1;
            }
            
            if (!arr[i].empty()) {
                auto [dd, k, jj] = arr[i].front();
                q.push({-dd, -k, -jj});
                arr[i].pop_front();   
            }
        }
        
        return ans;
    }
};

// bucket
class Solution {
public:
    // bucket sort
    // O(N*M) time, O(N*M) space
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // bucket sort since range of distance is [0, 2000]
        vector<vector<pair<int, int>>> buckets(2001); // buckets[i] is the vector<worker id, bike id> with distance i
        int n = workers.size(), m = bikes.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[dis].push_back({i, j});
            }
        }
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        for (int d = 0; d <= 2000; d++) {
            for (int k = 0; k < buckets[d].size(); k++) {
                if (res[buckets[d][k].first] == -1 && !bikeUsed[buckets[d][k].second]) {
                    bikeUsed[buckets[d][k].second] = true;
                    res[buckets[d][k].first] = buckets[d][k].second;
                }
            }
        }
        return res;
    }
};
