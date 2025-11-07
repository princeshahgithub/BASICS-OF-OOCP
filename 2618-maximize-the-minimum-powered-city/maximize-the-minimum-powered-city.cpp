class Solution {
public:

    bool check(long long x, vector<int>&stations, int k, int r) {
        int n = stations.size();
        long long power = 0;
        vector<long long>prefix(n+1,0);

        for(int i=0; i<n; i++) {
            prefix[max(0,i-r)] += stations[i];
            prefix[min(n,i+r+1)] -= stations[i];
        }

        for(int i=0; i<n; i++) {
            power += prefix[i];
            if(power < x) {
                if(x-power > k) return false;
                long long requiredPower = x - power;
                prefix[i] += requiredPower;
                prefix[min(n,i+1 + 2*r)] -= requiredPower;
                k -= requiredPower;
                power += requiredPower;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        long long L = 0, R = 1e12;

        while(L <= R) {
            long long mid = L + (R-L)/2;

            if(check(mid,stations,k,r)) {
                L = mid+1;
            }
            else R = mid-1;
        }

        return R;
    }
};