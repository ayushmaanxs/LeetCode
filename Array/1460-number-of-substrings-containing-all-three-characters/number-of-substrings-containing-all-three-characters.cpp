class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> f;
        int low = 0;
        int res = 0;
        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            // jab tak window valid hai
            while (f['a'] > 0 && f['b'] > 0 && f['c'] > 0) {
                res = res + (n - high); // store in
                f[s[low]]--;
                low++;
            }
        }
        return res;
    }
};