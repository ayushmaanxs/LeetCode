class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> f; // frequency map for a, b, c
        int n = s.size();
        int low = 0;   // window start
        int res = 0;   // final answer
        for (int high = 0; high < n; high++) {
            f[s[high]]++;  // expand window by including current char
            // jab tak window me a, b, c teeno present hain
            while (f['a'] > 0 && f['b'] > 0 && f['c'] > 0) {
                // current window valid hai
                // isliye is low se start hone wale
                // saare substrings count kar sakte hain
                // jo high se aage tak extend honge
                res += (n - high);
                // ab window ko shrink karte hain (left se)
                f[s[low]]--;
                low++;
            }
        }
        return res;
    }
};