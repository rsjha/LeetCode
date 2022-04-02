class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int pos[256];
        memset(pos,-1,sizeof(pos));
        int start=0;
        for(int i=0;i<s.length();i++){
            if(start>pos[s[i]]){
                res=max(res,i-start+1);
                pos[s[i]]=i;
            }else{
                start=pos[s[i]]+1;
                pos[s[i]]=i;
            }
        }
        return res;
    }
};