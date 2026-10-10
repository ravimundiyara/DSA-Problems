class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
         int ld;
         int dup=x;
        long long reversenum=0;
        while(x!=0)
        {
             ld=x%10;
            reversenum=(reversenum*10)+ld;
            x=x/10;
        }
        

        if(reversenum == dup) return true;
         else return false;
    }
    
};