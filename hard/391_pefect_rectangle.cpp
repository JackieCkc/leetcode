class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, sum_area = 0;
        set<pair<int, int>> s;

        for (auto rect : rectangles) {
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);

            sum_area += (rect[2] - rect[0]) * (rect[3] - rect[1]);

            if (s.count({rect[0], rect[1]})) {
                s.erase({rect[0], rect[1]});
            } else {
                s.insert({rect[0], rect[1]});
            }

            if (s.count({rect[0], rect[3]})) {
                s.erase({rect[0], rect[3]});
            } else {
                s.insert({rect[0], rect[3]});
            }

            if (s.count({rect[2], rect[1]})) {
                s.erase({rect[2], rect[1]});
            } else {
                s.insert({rect[2], rect[1]});
            }

            if (s.count({rect[2], rect[3]})) {
                s.erase({rect[2], rect[3]});
            } else {
                s.insert({rect[2], rect[3]});
            }
        }

        if (s.size() != 4 || s.count({x1, y1}) != 1 || s.count({x2, y2}) != 1) {
            return false;
        }

        return sum_area == (x2 - x1) * (y2 - y1);
    }
};
