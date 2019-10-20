class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return at_most_k(A, K) - at_most_k(A, K - 1);
    }

private:
    int at_most_k(vector<int>& A, int K) {
        unordered_map<int, int> m;
        int p = 0, res = 0;
        for (int i = 0; i < A.size(); i++) {
            int e = A[i];

            if (m[e] == 0) K -= 1;

            m[e] += 1;

            while (K < 0) {
                int e1 = A[p];
                p += 1;
                m[e1] -= 1;
                if (m[e1] == 0) K += 1;
            }

            res += i - p + 1;
        }
        return res;
    }
};
