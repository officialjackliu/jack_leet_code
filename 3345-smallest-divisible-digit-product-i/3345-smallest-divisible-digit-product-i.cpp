class Solution {
public:
    int product_calculate(int small_prod) {
        int products = 1; 
        while (small_prod > 0) {
            products *= small_prod % 10;
            small_prod /= 10; 
        }
        return products;
    }

    int find_smallestNum(int smallest_divisible, int t) {
        int divisible_product = product_calculate(smallest_divisible); 
        cout << "digit product is " << divisible_product << endl;
        if (divisible_product % t != 0) {
            cout << smallest_divisible << " 's product is not divisble" << endl;
            return find_smallestNum(smallest_divisible + 1, t);
        }
        cout << smallest_divisible<< " is divisble" << endl;
        return smallest_divisible;
    }

    int smallestNumber(int n, int t) {
        // brute force approach
        // let's try GCD algorithm later
        return find_smallestNum(n, t);
    }
};