class Solution {
public:
    int calculatePossibleSubarrays(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int low = 0;
        int high = 0;
        int sum = 0;
        int count = 0;
        int n = nums.size();
        for (high = 0; high < n; high++) {
            sum = sum + nums[high];
            while (sum > goal) {
                sum = sum - nums[low];
                low++;
            }
            count = count + (high - low + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calculatePossibleSubarrays(nums, goal) -
               calculatePossibleSubarrays(nums, goal - 1);
    }
};