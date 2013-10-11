class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // DP
        size_t n = s.size();
        vector<bool> f(n, 0);
        for (int i = 0; i < n; ++i) {
            if (dict.find(s.substr(0, i+1)) != dict.end())
                f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (f[j] && dict.find(s.substr(j+1, j-i+1) != dict.end())) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n-1];
    }
};
