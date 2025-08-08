class Solution {
public:
    vector<vector<double>> t;
    double helper(int a,int b){
        if(a<=0 || b<=0){
            if(a<=0 && b<=0) return 0.5;
            if(a<=0) return 1.0;
            if(b<=0) return 0.0;
        }
        if(t[a][b]!=-1.0) return t[a][b];
        return t[a][b] = (helper(a-100,b)+helper(a-75,b-25)+helper(a-50,b-50)+helper(a-25,b-75))*0.25;
    }
    double soupServings(int n) {
        if(n>=4800) return 1.0;
        t.resize(n+1,vector<double>(n+1,-1.0));
        return helper(n,n);
    }
};