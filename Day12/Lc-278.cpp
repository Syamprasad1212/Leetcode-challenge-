class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,ans=n,r=n;
        while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(isBadVersion(mid))
                {
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
                
            }
        return ans;
    }
};
