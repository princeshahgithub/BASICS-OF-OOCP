class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]={0}, xMax=0;
        for(int x: arr){
            freq[x]++;
            xMax=max(x, xMax);
        }
        for(int x=xMax; x>=1; x--){
            if (freq[x]==x) return x;
        }
        return -1;
    }
};