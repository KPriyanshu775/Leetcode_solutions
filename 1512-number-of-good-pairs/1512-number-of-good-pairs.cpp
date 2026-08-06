class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int good_pairs = 0;
        unordered_map<int, int> count_map;
        for (int num : nums) {
            good_pairs += count_map[num];
            count_map[num]++;
        }
        return good_pairs;
    }
};