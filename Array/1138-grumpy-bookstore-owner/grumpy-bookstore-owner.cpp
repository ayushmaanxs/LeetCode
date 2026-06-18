class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k = minutes;
        vector <int>& arr = customers; // customers wala array ko pass by reference to arr
        int n = arr.size();
        int prevLoss = 0;
        //Logic - jis K size window meh maximum customers/arr unsatisfied honge us wale window ko find krenge or us winodw meh hi sare grumpy ko 1 krenge taki max satisfaction mile
        // Storing answer of 1st window
        for(int i = 0;i<k;i++){
            if(grumpy[i]==1) prevLoss += arr[i];
        }
        // assuming 1st window as our answer window
        int maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1;
        int j = k;
        //Applying Sliding Window
        while(j<n){
            int currLoss = prevLoss;
            if(grumpy[j]==1) currLoss+=arr[j];
            if(grumpy[i-1]==1) currLoss-=arr[i-1];
            if(maxLoss < currLoss){
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss = currLoss;
            i++;
            j++;
        }
        // modifying grumpy array with 0's 
        for(int i = maxIdx;i<maxIdx+k;i++){
            grumpy[i]=0;
        }
        int maxSatisfied = 0;
        //cacluating the sum of satisfied customers
        for(int i = 0;i<n;i++){
            if(grumpy[i]==0) maxSatisfied+=arr[i];
        }
        return maxSatisfied;
    }
};