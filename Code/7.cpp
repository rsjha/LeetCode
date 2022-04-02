class Solution {
public:
    int reverse(int x) {
        int sign=x>0?1:-1;
        string s=to_string(x);
        int start=0,end=s.length()-1;
        while(start<end)
            swap(s[start++],s[end--]);
        if(sign==-1)
            s.pop_back();
        string max=to_string(INT_MAX);
        if(sign==1){
            if(s.length()==max.length()&&s>max)
                return 0;
        }else{
            max.back()='8';
            if(s.length()==max.length()&&s>max)
                return 0;
        }
        int res=0;
        for(char &c:s){
            res*=10;
            res+=c-'0';
        }
        return sign*res;
    }
};