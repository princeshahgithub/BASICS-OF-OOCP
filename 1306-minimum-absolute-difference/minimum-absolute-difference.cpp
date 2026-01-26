class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minimum=INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            minimum=min(minimum,arr[i+1]-arr[i]);
        }
        vector<vector<int>>result;

        for(int i=0;i<arr.size()-1;i++)
        {
           if(arr[i+1]-arr[i]==minimum)
           {
            result.push_back({arr[i],arr[i+1]});
           }
        }
        return result;
    }
};