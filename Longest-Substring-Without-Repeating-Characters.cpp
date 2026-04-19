1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, int> last_seen; // char -> last index it was seen at
5        int best = 0;
6        int left = 0;  // left boundary of current window
7
8        for (int right = 0; right < s.size(); right++) {
9            char ch = s[right];
10
11            // if char was seen inside current window, shrink from left
12            if (last_seen.count(ch) && last_seen[ch] >= left) {
13                left = last_seen[ch] + 1;
14            }
15
16            last_seen[ch] = right;
17            best = max(best, right - left + 1);
18        }
19
20        return best;
21    }
22};