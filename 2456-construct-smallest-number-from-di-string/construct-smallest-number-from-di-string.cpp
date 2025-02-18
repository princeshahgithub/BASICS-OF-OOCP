class Solution {
public:
    string smallestNumber(string pattern) {
        string s;
        for(int i=1;i<=pattern.size()+1;i++){
            s+=to_string(i);
        }
        for(int  i=0;i<pattern.size();i++){
            int j=i;
            while(j>=0 && pattern[j]=='D'){
                swap(s[j],s[j+1]);
                j--;
            }
        }
        return s;
    }
};