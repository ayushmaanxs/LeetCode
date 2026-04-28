class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rows = grid.size();
        int cols = grid[0].size();
        // Step 1: storing 2d grid in a 1d vector
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        // Step 2: Check if making them equal possible or not
        int rem = nums[0] % x;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] % x != rem) {
                return -1;
            }
        }
        // Step 3: Sort for getting the median
        sort(nums.begin(), nums.end());
        // Step 4: Find median
        int n = nums.size();
        int target = nums[n / 2];
        // Step 5: Count total operations
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = ans + abs(nums[i] - target) / x;
        }
        return ans;
    }
};