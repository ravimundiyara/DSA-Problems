class Solution {
public:
    int reverse(int x) {
       long long reversenum=0;
        while(x!=0)
        {
            int digit=x%10;
            if (reversenum < INT_MIN/10 || reversenum > INT_MAX/10) {
            return 0;
        }
            reversenum=(reversenum*10)+digit;
            x=x/10;
        }
       

        return (int) reversenum;
    }
};