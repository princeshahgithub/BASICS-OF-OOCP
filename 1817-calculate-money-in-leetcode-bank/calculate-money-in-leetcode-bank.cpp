class Solution {
public:
    int totalMoney(int n) {
        int a =28;
        int d = 7;

        int t = n/d;
        int rem = n%d;

        int l = a + (t-1) * 7;

        int sum = (t* (a + l))/2;

        int i = t+1;
        while(rem--){
            sum+=i++;
        }

        return sum;
    }
};