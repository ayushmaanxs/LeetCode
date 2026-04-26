class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> f;
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = 0;
        int maxfreq = 0;
        for(high = 0; high < n; high++){
            f[s[high]]++;
            // update maxfreq
            maxfreq = max(maxfreq, f[s[high]]);
            int len = high - low + 1;
            // invalid window → shrink
            while(len - maxfreq > k){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
                len = high - low + 1;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};