class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int neg=0;
        int mn=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val=matrix[i][j];
                if(val<0) neg++;
                sum+=abs(val);
                mn=min(mn,abs(val));
            }
        }
        if(neg%2==1)
            sum-=2LL*mn;
        return sum;
    }
};