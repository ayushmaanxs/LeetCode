class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map <int,int> f;
        int n = nums.size();
        int low = 0;
        int high = 0;
        int res = 0;
        for(high = 0;high <n ;high++){
            f[nums[high]]++; 
            while(f[0]>k){
                f[nums[low]]--;
                low++;
            }
            int len = high - low + 1;
            res = max(len,res);
        }
        return res;
    }
};