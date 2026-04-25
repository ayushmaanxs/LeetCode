class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int n = nums.size();
        int low = 0;
        int high = 0;
        int res = 0;
        for (high = 0; high < n; high++) {
            if (nums[high] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }
            int len = high - low + 1;
            res = max(len, res);
        }

        return res;
    }
};