class Solution {
public:
    int mySqrt(int x) {

        long long int ele = 1;
        while(true)
        {
            if(ele * ele > x)
            {
                break;
            }
            else
            {
                ele++;
            }
        }

        return (ele - 1);
        
    }
};