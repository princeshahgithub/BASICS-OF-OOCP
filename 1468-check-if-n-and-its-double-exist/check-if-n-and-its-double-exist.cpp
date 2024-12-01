class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> set;
        for(int i=0;i<n;i++)
        {
            if(set.count(2*arr[i])>0 || ((arr[i]%2==0) && set.count(arr[i]/2)>0))
            {
                return true;
            }
            set.insert(arr[i]);
        }
        return false;
    }
};