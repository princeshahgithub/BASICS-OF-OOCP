class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row1count = 0, row2count = 0;
        int len = bank.size();
        int beamCount = 0;
        int rowLength = bank[0].size();
        if (len == 1) return 0;
        for (const string& row : bank) {
            if (row.find('1') == string::npos) continue;
            row1count = row2count;
            row2count = 0;
            for (int i = 0; i < rowLength; i++) {
                if (row[i] == '1') row2count++;
            }
            beamCount += (row1count * row2count);
        }
        return beamCount;
    }
};