class Solution {
public:
    int countSetBits(int x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countSetBits(h) + countSetBits(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};