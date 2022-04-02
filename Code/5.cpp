class Solution {
public:
    string longestPalindrome(string s) {
        int res=1;
        pair<int,int> sub(0,1);
        vector<vector<bool>> p(s.length(),vector<bool>(s.length(),false));
        for(int l=1;l<=s.length();l++){
            for(int i=0;i<s.length()-l+1;i++){
                int j=i+l-1;
                if(l==1){
                    p[i][j]=true;
                    continue;
                }
                if(l==2)
                    p[i][j]=(s[i]==s[j]);
                else
                    p[i][j]=(p[i+1][j-1]&&s[i]==s[j]);
                if(p[i][j]){
                    if(res<l){
                        res=l;
                        sub.first=i;
                        sub.second=l;   
                    }
                }
            }
        }
        return s.substr(sub.first,sub.second);
    }
};