class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for (const auto& customer : accounts) {
            int current_wealth = 0;
            for (int bank : customer) {
                current_wealth += bank;
            }
            if (current_wealth > max_wealth) {
                max_wealth = current_wealth;
            }
        }
        return max_wealth;
    }
};