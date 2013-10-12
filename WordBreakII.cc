
//src is http://oj.leetcode.com/problems/word-break-ii/
//

class Solution {
public:
    int get_rst(const vector<vector<int> > & m) {
        
        return 0;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        size_t n = s.size();
        vector<vector<int> > m;
        m.push_back(vector<int>());
        // m[i] all pre_node of path from 0 to i
        for (int i = 1; i < n+1; ++i) {
            vector<int> tmp;
            if (dict.find(s.substr(0, i))!=dict.end())
                tmp.push_back(0); // 0 means match from begining
            // j traverse from 1 to i-1     
            for (int j = 1; j < i; ++j) {
                if (m[j].size() && dict.find(s.substr(j+1, i-j+1)) != dict.end()) {
                    tmp.push_back(j);
                }
            }
        }
    }
};
