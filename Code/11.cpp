class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=INT_MIN,ml=height[0],mr=height.back();
        int start=0,end=height.size()-1;
        while(start<end){
            ml=max(ml,height[start]);
            mr=max(mr,height[end]);
            res=max(res,min(ml,mr)*(end-start));
            if(ml<mr)
                start++;
            else
                end--;
        }
        return res;
    }
};