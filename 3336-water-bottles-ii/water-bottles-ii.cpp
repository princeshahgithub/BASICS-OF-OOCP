class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int answer = 0;

        while (numBottles >= numExchange) {

            answer += numExchange;
            numBottles -= numExchange;
            numBottles++;
            numExchange++;
        }

        answer += numBottles;
        return answer;
    }
};