//http://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool is_palin(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1])
                return false;
        }
        return true;
    }
    int f(const string &s, vector<vector<string>> &rst, vector<string> &v) {
        if (s.size() == 0) {
            rst.push_back(v);
            return 0;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            string sub = s.substr(0, i+1);
            if (is_palin(sub)) {
                v.push_back(sub);
                f(s.substr(i+1), rst, v);
                v.pop_back();
            }
        }    
    }
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string>> rst;
        vector<string> v;
        f(s, rst, v);
        return rst;
    }
};
