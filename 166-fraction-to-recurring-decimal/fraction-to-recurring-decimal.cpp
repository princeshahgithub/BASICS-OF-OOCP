// updated code with more comments
class Solution {
public:
    // upgraded parameter types
    string fractionToDecimal(long long n, long long d) {
        // edge case: zero numerator
        if (n == 0) return "0";

        string res;
        // step1 : deal with sign
        // determine the sign
        if (n < 0 ^ d < 0) res += '-';

        // remove sign of operands
        n = abs(n), d = abs(d);

        // step2: deal with integer part
        // append integer part
        res += to_string(n / d);

        // edge case: in case no fractional part
        if (n % d == 0) return res;

        // step3: deal with fractional part
        res += '.';

        unordered_map<int, int> map; // {소수점 자리 : 소수점 자리가 있는 인덱스}

        // simulate the division process
        for (long long r = n % d; r != 0; r %= d) {

            // meet a known remainder
            // so we reach the end of the repeating part
            if (map.count(r) > 0) {
                res.insert(map[r], 1, '('); // res.insert(position(넣을 index), 넣을 갯수, 넣을 character)
                res += ')';
                break;
            }

            // the remainder is first seen
            // remember the current position for it
            map[r] = res.size(); // r이 들어간 위치를 넣음

            r *= 10;

            // append the quotient digit
            res += to_string(r / d);
        }
        return res;
    }
};
