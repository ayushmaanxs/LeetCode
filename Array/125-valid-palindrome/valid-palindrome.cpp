class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0;                  // starting pointer
        int right = s.size() - 1;     // ending pointer

        while(left < right)
        {
            // left side se special character skip karo
            while(left < right && !isalnum(s[left]))
            {
                left++;
            }

            // right side se special character skip karo
            while(left < right && !isalnum(s[right]))
            {
                right--;
            }

            // dono character lowercase me compare karo
            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;   // mismatch mila
            }

            // dono pointer andar move karo
            left++;
            right--;
        }
        return true;   // pura string palindrome hai
    }
};