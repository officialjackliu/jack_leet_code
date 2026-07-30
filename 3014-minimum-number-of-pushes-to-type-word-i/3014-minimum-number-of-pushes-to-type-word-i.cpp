class Solution {
public:
    int minimumPushes(string word) {
        /*
        solve from a greedy approach
        phone number can fit 8 distinct character, calculate the number pushes
        increases pushes when iteration is equal to a number that is multiple of 8
        */
        int pushes = 0;
        int min_pushes = 0; 
        int characters = word.size(); 
        int iterations = 0;
        while (iterations < characters) {
            if (iterations % 8 == 0) {
                pushes++;
            }
            min_pushes += pushes;
            iterations++;
        }
        return min_pushes;
    }
};