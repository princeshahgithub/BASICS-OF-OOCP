class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long sum = 0;
        for(auto it: skill) sum+=it;

        int n = skill.size();
        int size = n/2;
        if(sum%size!=0) return -1;
        
        long long target = sum/size;
        long long ans=0;
        int i=0, j=n-1;
        while(i<=j){
            if(skill[i]+skill[j] == target){
                ans+=(skill[i]*skill[j]);
            }
            else return -1;
            i++;
            j--;
        }
        return ans;
    }
};