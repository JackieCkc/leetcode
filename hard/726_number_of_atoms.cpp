class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> counter;
        stack<int> stack1;
        stack1.push(1);

        int l = formula.size(), n = 1;
        string e_curr;
        reverse(formula.begin(), formula.end());

        for (int i = 0; i < l; i++) {
            char& c = formula[i];

            if (c == '(') {
                stack1.pop();
            } else if (c == ')' ) {
                stack1.push(n * stack1.top());
                n = 1;
            } else if (islower(c)) {
                e_curr = c + e_curr;
            } else if (isupper(c)) {
                e_curr = c + e_curr;
                counter[e_curr] += n * stack1.top();
                n = 1;
                e_curr = "";
            } else {
                string n_curr = "";
                while (isdigit(formula[i])) {
                    n_curr = formula[i] + n_curr;
                    i++;
                }
                i--;
                n = stoi(n_curr);
            }
        }

        string res = "";
        for (auto& item : counter) {
            res += item.first;
            if (item.second > 1) res += to_string(item.second);
        }
        return res;
    }
};
