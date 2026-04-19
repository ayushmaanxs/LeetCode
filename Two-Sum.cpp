1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        vector<int> arr(2);
5        for(int i = 0;i<nums.size();i++){
6            for(int j = i+1;j<nums.size();j++){
7                long long sum = nums[i]+nums[j];
8                if(sum == target){
9                    arr[0]=i;
10                    arr[1]=j;
11                    return arr;
12                }
13            }
14        }
15        return {};
16    }
17};