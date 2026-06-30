class Solution {
public:
    int numberOfSubstrings(string s) {
        int low = 0;
        int high = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mpp;
        for(high = 0;high < n;high++){
            mpp[s[high]]++;
            while(mpp.size()==3){
                ans += n - high;
                mpp[s[low]]--;
                if(mpp[s[low]]==0) mpp.erase(s[low]);
                low++;
            }
        }
        return ans;
    }
};