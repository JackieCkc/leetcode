class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        long max_with_prev = A[0], max_without_prev = 0;
        long min_with_prev = A[0], min_without_prev = 0;
        long sum_v = A[0];
        long max_value = -30000;
        bool all_n = true;

        for (int i = 1; i < A.size(); i++) {
            long j = A[i];
            if (j >= 0) {
                all_n = false;
            }

            long temp1 = max_with_prev, temp2 = max_without_prev;
            max_with_prev = max(j + temp1, j);
            max_without_prev = max(temp1, temp2);

            temp1 = min_with_prev, temp2 = min_without_prev;
            min_with_prev = min(j + temp1, j);
            min_without_prev = min(temp1, temp2);

            max_value = max(max_value, j);
            sum_v += j;
        }

        if (all_n) {
            return max_value;
        }

        return max(
                max(min_with_prev, max_without_prev),
                sum_v - min(min_with_prev, min_without_prev)
        );
    }
};
