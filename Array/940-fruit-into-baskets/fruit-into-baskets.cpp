class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // using a hashmap basket 
        unordered_map<int, int> basket;
        int low = 0;
        int high = 0;
        int res = 0;
        int n = fruits.size();
        // agar 1 hi fruit ho bas
        if(n==1) return 1;
        // SLIDING WINDOW TEMPLATE
        // for loop se high ko bdhao
        for(high=0;high<n;high++){
            // 1st high ko include kro basket mein
            basket[fruits[high]]++;
            // 2nd jab tak hmara info galat ho tb tk while loop se window shrink kro 
            while(basket.size()>2){
                basket[fruits[low]]--; // basket se low ko htao
                if(basket[fruits[low]]==0){ // in case kisi ka frequecny 0 hota hai hashmap meh toh woh element delete nhi hota hme use explicitly erase krna hoga
                    basket.erase(fruits[low]);  
                }
                low++; // low ko bdhao to shrink window
            }
            // jaise hi info correct hua , include that in result
            int len = high - low + 1;
           res = max(res, len);
        }
        return res;
    }
};