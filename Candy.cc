// http://oj.leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        if (n < 2)
            return n;
        vector<int> candies(n, 0);
        if (n > 1 && ratings[0] <= ratings[1])
            candies[0] = 1;
        if (n > 1 && ratings[n-1] <= ratings[n-2])
            candies[n-1] = 1;
        for (int i = 1; i < n-1; ++i) {
            if (ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1])
                candies[i] = 1;
        }
        for (int i=1; i<n; ++i) {
            if (candies[i-1] != 0 && ratings[i]>=ratings[i-1]) {
                candies[i] = candies[i-1]+(ratings[i-1]==ratings[i]);
            }
        }
        for (int i=n-2; i>=0; --i) {
            if (0 == candies[i])    
                candies[i] = candies[i+1]+1;
            else if (i>0 && ratings[i] > ratings[i-1] && candies[i] < candies[i+1]+1)
                candies[i] = candies[i+1]+1;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += candies[i];
        }
        return sum;
    }
};
