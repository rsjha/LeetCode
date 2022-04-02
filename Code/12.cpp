class Solution {
public:
    string intToRoman(int num) {
        vector<string> mapping={"I","II","III","IV","V","VI","VII","VIII","IX","X"};
        int place=1,mul=1;
        string res="";
        while(num){
            int rem=num%10;
            num/=10;
            int digit=rem;
            rem*=mul;
            mul*=10;
            if(rem==0)
                continue;
            if(rem<=10){
                res=mapping[rem-1]+res;
            }else if(rem<40){
                while(digit--){
                    res="X"+res;
                }
            }else if(rem==40){
                res="XL"+res;
            }else if(rem<90){
                digit-=5;
                while(digit--){
                    res="X"+res;
                }
                res="L"+res;
            }else if(rem==90){
                res="XC"+res;
            }else if(rem<400){
                while(digit--){
                    res="C"+res;
                }
            }else if(rem==400){
                res="CD"+res;
            }else if(rem<900){
                digit-=5;
                while(digit--){
                    res="C"+res;
                }
                res="D"+res;
            }else if(rem==900){
                res="CM"+res;
            }else{
                while(digit--){
                    res="M"+res;
                }
            }
        }
        return res;
    }
};