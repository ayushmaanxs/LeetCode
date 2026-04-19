1class Solution {
2public:
3    int reverse(int x) {
4        int reverseNumber = 0;
5        while (x != 0) {
6            int lastDigit = x % 10;
7            x = x / 10;
8            if (reverseNumber > INT_MAX / 10 || reverseNumber < INT_MIN / 10) {
9                return 0;
10            }
11
12            reverseNumber = 10 * reverseNumber + lastDigit;
13        }
14        return reverseNumber;
15    }
16};