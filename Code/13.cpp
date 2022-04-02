class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return ksum(nums,0,0,3);
    }
    
    vector<vector<int>> ksum(vector<int>& nums, int target,int pos,int k){
        vector<vector<int>> res;
        if(pos==nums.size())
            return res;
        
        if(k==2)
            return twoSum(nums,target,pos);

        if(nums[pos]>target/k||nums.back()<target/k)
            return res;
        for(int i=pos;i<nums.size();i++){
            if(i==pos||nums[i-1]!=nums[i]){
                auto tempRes=ksum(nums,target-nums[i],i+1,k-1);
                if(!tempRes.empty()){
                    for(auto v:tempRes){
                        v.push_back(nums[i]);
                        res.push_back(v);
                    }
                }   
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target,int pos){
        vector<vector<int>> res;
        if(nums[pos]>target/2||nums.back()<target/2)
            return res;
        int i=pos,j=nums.size()-1,sum;
        while(i<j){
            sum=nums[i]+nums[j];
            if(target>sum||(i>pos&&nums[i]==nums[i-1]))
                i++;
            else if(target<sum||(j<nums.size()-1&&nums[j]==nums[j+1]))
                j--;
            else{
                res.push_back({nums[i],nums[j]});
                i++;
                j--;
            }
        }
        return res;
    }
};