class Solution {
public:
    static long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int n=happiness.size();
        sort( happiness.begin(), happiness.end());
        
        long long sum=0;
        for(int i=0; i<k; i++){
            long long x=max(0, happiness[n-1-i]-i);
        //    cout<<x<<endl;
            sum+=x;
        }
            
        return sum;
        
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();