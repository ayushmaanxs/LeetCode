class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        k = n - k;  
        vector<int> temp;

        // first k elements
        for(int i = 0; i < k; i++){
            temp.push_back(nums[i]);
        }

        // shift
        for(int i = 0; i < n-k; i++){
            nums[i] = nums[k + i];
        }

        // last mein temp wale vector ke lements
        for(int i = n-k; i < n; i++){
            nums[i] = temp[i-(n-k)];
        }
    }
};