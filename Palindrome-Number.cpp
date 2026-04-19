1class Solution {
2public:
3    bool isPalindrome(int x) {
4        long revNum = 0;
5        int duplicate = x;
6        while(x>0){
7            int lastDigit = x%10;
8            revNum = (revNum *10 )+lastDigit;
9            x =x/10;
10        }
11        if(duplicate==revNum){
12            return true;
13        }
14        else {
15            return false;
16        }
17    }
18};