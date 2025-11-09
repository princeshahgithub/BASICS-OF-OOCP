class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0  || num2 == 0){
            return 0;
        } else if (num1 < num2){
            return countOperations(num2, num1);
        } else {
            return num1 / num2 + countOperations(num2, num1 % num2);
        }
    }
};