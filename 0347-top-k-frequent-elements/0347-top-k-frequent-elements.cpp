class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket: index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency
        for (int i = nums.size(); i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};
