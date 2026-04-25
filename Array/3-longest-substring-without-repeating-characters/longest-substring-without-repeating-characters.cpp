class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> f; 
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = 0;
        if(n==0)  return 0;
        for(high = 0;high<n;high++){
            f[s[high]]++;
            int k = high - low + 1; // total characters in window
            // f.size() = number of unique characters
            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]== 0){
                    f.erase(s[low]);
                }
                low++;
                k--;
                if(f.size()==1){
                    break;
                }
            }
            res = max(res,high - low + 1);  
        }
        return res;

    }
};