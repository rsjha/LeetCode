class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()==0||numRows==1||s.length()<=numRows)
            return s;
        int col=s.length()/numRows;
        vector<vector<char>> vec;
        bool dir=true;
        for(int i=0;i<s.length();){
            if(dir){
                auto v=getColZigZag(s,i,dir,numRows);
                dir=!dir;
                vec.push_back(v);
            }else{
                auto v=getColZigZag(s,i,dir,numRows);
                dir=!dir;
                vec.push_back(v);
            }
        }
        string res="";
        for(int j=0;j<numRows;j++){
            for(int i=0;i<vec.size();i++){
                if(vec[i][j]!='#')
                    res.push_back(vec[i][j]);
            }
        }
        return res;
    }
    
    vector<char> getColZigZag(string &s,int &i,bool dir,int numRows){
        vector<char> v;
        int count=numRows;
        if(!dir){
            count-=2;
            v.push_back('#');
        }
        while(count&&i<s.length()){
            v.push_back(s[i]);
            count--;
            i++;
        }
        if(!dir)
            count++;
        while(count){
            v.push_back('#');
            count--;
        }
        if(!dir)
            reverse(v.begin(),v.end());
        return v;
    }
};