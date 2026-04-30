class Solution {
public:
int countSubarrysKodds(vector<int>& nums, int k){
    int low = 0;
        int high = 0;
        int n = nums.size();
        int oddCount = 0;
        int count = 0;
        for(high = 0;high<n;high++){
            if(nums[high]%2==1) oddCount++;
            while(oddCount > k){
                if(nums[low]%2==1) oddCount--;
                low++;
            }
           count = count + (high - low + 1);
        }
        return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarrysKodds(nums, k) -
               countSubarrysKodds(nums, k - 1);;
    }
};