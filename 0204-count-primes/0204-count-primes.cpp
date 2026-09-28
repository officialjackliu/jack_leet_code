class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        // Initially consider all numbers from 2 to n-1 as prime
        int cnt = n - 2;
        vector<char> prime(n, 1);

        for(int i = 2; i * i < n; i++) {

            if(prime[i]) {

                // Start from i*i because smaller multiples
                // have already been marked by smaller primes
                for(int j = i * i; j < n; j += i) {

                    if(prime[j]) {
                        prime[j] = 0;
                        cnt--;
                    }
                }
            }
        }

        return cnt;
    }
};
