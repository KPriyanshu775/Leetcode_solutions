class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);

        for (const auto& entry : freq) {
            pq.push(entry);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }

        return result;
    }
};