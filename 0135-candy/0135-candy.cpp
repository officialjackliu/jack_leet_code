class Solution {
public:
    int candy(vector<int>& ratings) {
        // base case 
        if (ratings.size() == 1) {
            return 1;
        }
        vector<int> candies(ratings.size(), 1);
        int total_candies = 0;
        // iterate through every ratings, assume to give 1 candy at the start, check ratings vs neighbor, if higher of one if the neighbor, give them more candy 
        // special case for first element
        if (ratings[0] > ratings[1]) {
            candies[0]++;
        }
         // cout << "at first index, current candy is " << candies[0] << "   total candies " << total_candies << endl;
         // first loop only check vs left hand side neighbor, 
        for (int i = 1; i < candies.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            } 
            // cout << "at index " << i << "   current candy is " << candies[i] << "   total candies " << total_candies << endl;
        }
        // second loop goes from right to left, check if ratings is greater than its right hand side neighbor, if it is, increment if 
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i+1] + 1, candies[i]);
            }
        }

        for (int candy: candies) {
            total_candies += candy;
        }
        //  cout << "   total candies " << total_candies << endl;
        return total_candies;
    }
};