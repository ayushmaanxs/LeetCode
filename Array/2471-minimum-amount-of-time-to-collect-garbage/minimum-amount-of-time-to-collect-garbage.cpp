class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        int totalTime = 0;
        // Store last house index for each garbage type
        int lastM = 0;
        int lastP = 0;
        int lastG = 0;
        // Traverse all houses
        for(int i = 0; i < n; i++) {

            // Picking each garbage takes 1 minute
            totalTime += garbage[i].size();

            // Check each garbage type in current house
            for(char ch : garbage[i]) {

                // Updating last position of each type garbage
                if(ch == 'M') {
                    lastM = i;
                }
                else if(ch == 'P') {
                    lastP = i;
                }
                else {
                    lastG = i;
                }
            }
        }
        // Adding travel time for Each truck one by one
        for(int i = 0; i < lastM; i++) {
            totalTime += travel[i];
        }
        for(int i = 0; i < lastP; i++) {
            totalTime += travel[i];
        }
        for(int i = 0; i < lastG; i++) {
            totalTime += travel[i];
        }

        return totalTime;
    }
};