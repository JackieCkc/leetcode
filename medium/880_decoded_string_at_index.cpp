class Solution {
public:
    string get_char(string S, int i, int K, long len) {
        for (int j = i; j >= 0; j--) {
            char c = S[j];
            if (isalpha(c)) {
                if (len == K) {
                    return string(1, c);
                }
                len -= 1;
            } else{
                len /= c - '0';
                K %= len;
                if (K == 0) {
                    K = len;
                }
            }
        }
        return "";
    }

    string decodeAtIndex(string S, int K) {
        long len = 0;

        for (int i = 0; i < S.length(); i++) {
            char c = S[i];
            if (isalpha(c)) {
                len += 1;
            } else{
                len = len * (c - '0');
            }

            if (len >= K) {
                return get_char(S, i, K, len);
            }
        }
        return "";
    }
};
