class Solution {
public:
    bool isPerfectSquare(int num) {
     int l=1;
        int r=num;
        while(l<=r)
            {
                long long mid=l+(r-l)/2;
                long long sq=mid*mid;
                if(sq==num)
                {
                    return true;
                }
                else if(sq<num)
                {
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        return false;
    }
};
