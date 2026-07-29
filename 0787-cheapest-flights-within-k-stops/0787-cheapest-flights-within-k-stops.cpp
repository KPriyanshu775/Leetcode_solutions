class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using namespace std;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [node, cost] = q.front();
                q.pop();

                for (const auto& [neighbor, price] : adj[node]) {
                    if (cost + price < minCost[neighbor]) {
                        minCost[neighbor] = cost + price;
                        q.push({neighbor, minCost[neighbor]});
                    }
                }
            }
            stops++;
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};