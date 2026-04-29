class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(m > n) return ans;
        unordered_map<char,int> need;
        unordered_map<char,int> win;
        for(char ch : p)
        {
            need[ch]++;
        }
        int low = 0;
        // SLIDING WINDOW
        for(int high = 0; high < n; high++)
        {
            // add high char
            win[s[high]]++;
            // invalid window -> shrink
            while((high - low + 1) > m)
            {
                win[s[low]]--;

                if(win[s[low]] == 0)
                    win.erase(s[low]);

                low++;
            }
            // valid window ---> Store in ans
            if((high - low + 1) == m && win == need)
            {
                ans.push_back(low);
            }
        }
        return ans;
    }
};