class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;

        int res = 1;
        int c, prev_c = 1, con = 0;
        int prev = ratings[0];
        int l = ratings.size();

        for (int i = 1; i < l; i++) {
            c = ratings[i];

            if (c >= prev) {
                if (con > 0) {
                    res += (1 + con) * con / 2;
                    res -= min(prev_c, con);
                    prev_c = 1;
                }

                prev_c = c == prev ? 0 : prev_c;
                res += prev_c + 1;
                con = 0;
                prev_c += 1;
            } else con += con == 0 ? 2 : 1;

            prev = c;
        }

        if (con > 0) {
            res += (1 + con) * con / 2;
            res -= min(prev_c, con);
        }

        return res;
    }
};
