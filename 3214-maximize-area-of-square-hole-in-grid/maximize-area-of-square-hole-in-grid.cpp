class Solution {
private:
    int maxLen(vector<int>& Bars) {
        int count = 2, length = 2;
        for(int i = 1; i < Bars.size(); i++) {
            if(Bars[i] - Bars[i-1] == 1) count++;
            else count = 2;
            length = max(length, count);
        }
        return length;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side = min(maxLen(hBars), maxLen(vBars));
        return side * side; 
    }
};