class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;
            if (prefixSumFreq.find(currentSum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[currentSum - k];
            }
            prefixSumFreq[currentSum]++;
        }

        return count;
    }
};