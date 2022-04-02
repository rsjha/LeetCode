class Solution {
public:
    int myAtoi(string s) {
        long long sign=1,res=0,i=0;
        bool foundDigit=false,signset=false;
        while(i<s.length()){
            if(foundDigit||signset){
                if(isdigit(s[i])){
                    foundDigit=true;
                    res*=10;
                    res+=s[i]-'0';
                    if(res*sign>INT_MAX)
                        res=INT_MAX;
                    else if(res*sign<INT_MIN)
                        res=abs((long long)INT_MIN);
                }else if(signset&&!foundDigit){
                    return 0;
                }else
                    return res*sign;
                    
            }else{
                if(s[i]=='-'||s[i]=='+'){
                    sign=s[i]=='-'?-1:1;
                    signset=true;
                }else if(isdigit(s[i])){
                    res=s[i]-'0';
                    foundDigit=true;
                }else if(s[i]!=' ')
                    return 0;
            }
            i++;
        }
        return res*sign;
    }
};