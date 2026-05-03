class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> added;
        vector<string> ans;
        if (s.size() < 10) return ans;
        for (int i = 0; i <= s.size() - 10; i++) {
            string part = s.substr(i, 10);
            // agar pehle dekha hua hai
            if (seen.find(part) != seen.end() &&
                added.find(part) == added.end()) {
                ans.push_back(part);
                added.insert(part);
            }
            seen.insert(part);
        }
        return ans;
    }
};