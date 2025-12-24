class Solution {
public:
    int minimumBoxes(vector<int>&ap, vector<int>&cp){
        sort(cp.begin(),cp.end());
        int i,s=0,c=0,n=cp.size();
        for(i=0;i<ap.size();i++) s+=ap[i];
        while(s>0){
            s=s-cp[n-1-c];
            c++;
        }
        return c;
    }
};