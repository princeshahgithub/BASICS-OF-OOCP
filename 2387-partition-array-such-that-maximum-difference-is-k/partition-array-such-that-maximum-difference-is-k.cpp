// the C++ version shown in the film
class Solution {
public:
    static int partitionArray(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return 1; // edge case

        int freq[100001] = {0}, xMax = -1;
        for (int x : nums) {
            freq[x]++;
            xMax = max(xMax, x);
        }

        int partitions = 0;
        for (int x = 0; x <= xMax;) { // start from 0
            // skip x when freq[x]=0
            while (x <= xMax && freq[x] == 0)
                x++;
            if (x > xMax)
                break;

            int end = x + k; // subsequence max
            partitions++;
            x = end + 1; // next subsequence min
        }
        return partitions;
    }
};