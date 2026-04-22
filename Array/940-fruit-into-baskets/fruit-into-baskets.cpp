class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int low = 0;
        int high = 0;
        int res = 0;
        int n = fruits.size();
        if(n==1) return 1;
        for(high=0;high<n;high++){
            basket[fruits[high]]++;
            while(basket.size()>2){
                basket[fruits[low]]--;
                if(basket[fruits[low]]==0){
                    basket.erase(fruits[low]);
                }
                low++;
            }
           res = max(res, high - low + 1);
        }
        return res;
    }
};