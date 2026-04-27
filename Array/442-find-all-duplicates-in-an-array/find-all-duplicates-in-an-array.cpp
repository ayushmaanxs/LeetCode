class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            
            int idx = abs(nums[i]) - 1;   // correct index
            
            if(nums[idx] < 0) {
                ans.push_back(abs(nums[i])); // already visited = duplicate
            }
            else {
                nums[idx] = -nums[idx];   // mark visited
            }
        }
        
        return ans;
    }
};