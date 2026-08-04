class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector <int> ans;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int y = nums[x];
            ans.push_back(y);
            
        }
        return ans;
    }
};