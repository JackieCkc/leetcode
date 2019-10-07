class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int l = req_skills.size();
        unordered_map<int, vector<int>> res;
        res.reserve(1 << l);

        unordered_map<string, int> skill_i;
        res[0] = {};

        for (int i = 0; i < req_skills.size(); i++) skill_i[req_skills[i]] = 1 << i;

        for (int i = 0; i < people.size(); i++) {
            int skill = 0;
            for (auto s : people[i]) skill |= skill_i[s];

            for (auto r : res) {
                int new_skill = skill | r.first;
                if (!res.count(new_skill) || res[new_skill].size() > r.second.size() + 1) {
                    r.second.push_back(i);
                    res[new_skill] = r.second;
                }
            }
        }

        return res[(1<<l) - 1];
    }
};
