class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string ns = to_string(N);
        int res = 0, n = D.size(), n1 = ns.size();

        for (int i = 1; i < n1; i++) res += pow(n, i);

        for (int i = 0; i < n1; i++) {
            bool same_num = false;

            for (string &d : D) {
                if (d[0] < ns[i]) res += pow(n, n1 - i - 1);
                else if (d[0] == ns[i]) {
                    same_num = true;
                    break;
                } else break;
            }

            if (!same_num) return res;
        }

        return res + 1;
    }
};
