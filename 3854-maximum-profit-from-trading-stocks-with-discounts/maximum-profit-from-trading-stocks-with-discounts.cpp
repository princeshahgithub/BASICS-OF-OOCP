class Solution
{
public:
    // DFS to compute DP for subtree rooted at node u
    void dfs(int u, const vector<int>& present, const vector<int>& future,
             const vector<vector<int>>& tree,
             vector<vector<vector<int>>>& dp, int budget)
    {
        // Store DP results of all children:
        // first  -> child dp when parent NOT bought
        // second -> child dp when parent IS bought
        vector<pair<vector<int>, vector<int>>> childDPs;

        // Process all children first (postorder DFS)
        for (int v : tree[u])
        {
            dfs(v, present, future, tree, dp, budget);
            childDPs.emplace_back(dp[v][0], dp[v][1]);
        }

        // Compute dp[u][parentBought] for both cases
        for (int parentBought = 0; parentBought <= 1; ++parentBought)
        {
            // If parent was bought, current node gets 50% discount
            int price = parentBought ? present[u] / 2 : present[u];

            // Profit gained if we buy this node
            int profit = future[u] - price;

            // dp array for node u with given parentBought state
            vector<int> curr(budget + 1, 0);

            // -------------------------
            // Case 1: Do NOT buy node u
            // -------------------------
            vector<int> base(budget + 1, 0);

            // Merge children DP where parent is NOT bought
            for (const auto& child : childDPs)
            {
                vector<int> next(budget + 1, 0);
                for (int b1 = 0; b1 <= budget; ++b1)
                {
                    // Skip unreachable states
                    if (base[b1] == 0 && b1 != 0)
                        continue;

                    for (int b2 = 0; b1 + b2 <= budget; ++b2)
                    {
                        next[b1 + b2] =
                            max(next[b1 + b2], base[b1] + child.first[b2]);
                    }
                }
                base = move(next);
            }

            // Update current dp values for "not buying u"
            for (int b = 0; b <= budget; ++b)
            {
                curr[b] = max(curr[b], base[b]);
            }

            // ---------------------
            // Case 2: Buy node u
            // ---------------------
            if (price <= budget)
            {
                vector<int> baseBuy(budget + 1, 0);

                // Merge children DP where parent IS bought
                for (const auto& child : childDPs)
                {
                    vector<int> next(budget + 1, 0);
                    for (int b1 = 0; b1 <= budget; ++b1)
                    {
                        // Skip unreachable states
                        if (baseBuy[b1] == 0 && b1 != 0)
                            continue;

                        for (int b2 = 0; b1 + b2 <= budget; ++b2)
                        {
                            next[b1 + b2] =
                                max(next[b1 + b2], baseBuy[b1] + child.second[b2]);
                        }
                    }
                    baseBuy = move(next);
                }

                // Pay price of u and add its profit
                for (int b = price; b <= budget; ++b)
                {
                    curr[b] = max(curr[b], baseBuy[b - price] + profit);
                }
            }

            // Save DP result for node u
            dp[u][parentBought] = move(curr);
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget)
    {
        // Build tree from hierarchy list (1-based to 0-based)
        vector<vector<int>> tree(n);
        for (const auto& edge : hierarchy)
        {
            tree[edge[0] - 1].push_back(edge[1] - 1);
        }

        // dp[node][parentBought][budget]
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(budget + 1, 0))
        );

        // Run DFS from root (node 0)
        dfs(0, present, future, tree, dp, budget);

        // Final answer: best profit at root when parent not bought
        int ans = 0;
        for (int b = 0; b <= budget; ++b)
        {
            ans = max(ans, dp[0][0][b]);
        }
        return ans;
    }
};
