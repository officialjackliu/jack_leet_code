class Solution {
public:
    int happy_calculate(int num) {
        int output = 0;
        while (num != 0) {
            int digit = num % 10; 
            output += (int) pow(digit, 2); 
            num = num / 10;
        }
        return output;
    }


    bool isHappy(int n) {
        // track of visited set, n is unhappy if the compute rule leads back to a visited number 
        unordered_set<int> visited; 
        int computed_num = n; 
        while (visited.count(computed_num) == 0) {
            visited.insert(computed_num);
            if (computed_num == 1) {
                return true;
            }
            computed_num = happy_calculate(computed_num);
        }
        return false;
    }
};