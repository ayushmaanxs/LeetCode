class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        bool flag = false;
        for(int i= 0;i<n;i++){
            if(arr[i]==1) {
                swap(arr[i],arr[0]);
                flag = true;
                break;
            }
        }
        if(flag==false) arr[0]=1;
        for(int i =1;i<n;i++){
            if(abs(arr[i] - arr[i - 1]) <= 1){
                continue;
            }
            else{
                arr[i] = arr[i-1]+1;
            }
        }
        return arr.back();
    }
};