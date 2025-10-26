class Bank {
public:
    vector<long long> rupyaa;
    Bank(vector<long long>& balance) { rupyaa = balance; }

    bool transfer(int account1, int account2, long long money) {
        int n = rupyaa.size();
        if ((account1 >= 1 and account1 <= n) and
            (account2 >= 1 and account2 <= n)) {
            long long balanceInAccount1 = rupyaa[account1 - 1];
            long long balanceInAccount2 = rupyaa[account2 - 1];

            if (money <= balanceInAccount1) {
                if (account1 == account2) {
                    rupyaa[account1 - 1] = rupyaa[account2 - 1] = money;
                    return true;
                }

                long long leftMoney = balanceInAccount1 - money;
                rupyaa[account1 - 1] = leftMoney;
                rupyaa[account2 - 1] = balanceInAccount2 + money;
                return true;
            }
        }
        return false;
    }

    bool deposit(int account, long long money) {
        int n = rupyaa.size();
        if (account >= 1 and account <= n) {
            long long beforeAmount = rupyaa[account - 1];
            rupyaa[account - 1] = beforeAmount + money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        int n = rupyaa.size();
        if (account >= 1 and account <= n) {
            long long beforeAmount = rupyaa[account - 1];
            if (money <= beforeAmount) {
                long long leftMoney = beforeAmount - money;
                rupyaa[account - 1] = leftMoney;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */