class Solution {
public:
    int mySqrt(int x) {
        int start =  1;
        int end=  1e9 ;
        int ans  = 0 ;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(1LL*mid*mid<=x){
                ans= mid;
                start = mid+1;
            }else{
                end =mid-1;
            }
        }
        return ans;
    }
};