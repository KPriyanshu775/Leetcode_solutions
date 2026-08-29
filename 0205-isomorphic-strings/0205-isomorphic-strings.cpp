class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map_s(256, -1);
        vector<int> map_t(256, -1);

        for (int i = 0; i < s.length(); i++) {
            if (map_s[s[i]] != map_t[t[i]]) {
                return false;
            }
            map_s[s[i]] = i;
            map_t[t[i]] = i;
        }

        return true;
    }
};