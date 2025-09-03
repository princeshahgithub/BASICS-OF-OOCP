class Solution {
public:
    int numberOfPairs(vector<vector<int>>& poi) {
        int n = poi.size();
        
        auto lmb = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // If x's are equal, higher y comes first
            return a[0] < b[0]; // Otherwise, sort by increasing x
        };
        
        int cnt = 0;
        sort(begin(poi), end(poi), lmb);
        
        for (int i = 0; i < n; i++) {
            int x1 = poi[i][0];
            int y1 = poi[i][1];
            int maxi = INT_MIN;
            
            for (int j = i + 1; j < n; j++) {
                int x2 = poi[j][0];
                int y2 = poi[j][1];
                
                if (y2 > y1) continue; // Invalid rectangle if Bob is "above" Alice
                
                // y2 is Bob's y, y1 is Alice's y
                // maxi keeps the largest y2 seen so far
                if (y2 > maxi) {
                    maxi = y2;   // This is the best Bob so far for this Alice
                    cnt++;       // Valid pair (Alice i, Bob j)
                }
            }
        }
        
        return cnt;
    }
};