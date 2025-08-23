class Solution {
    static constexpr int INF = 1 << 29;
public:
    int minimumSum(vector<vector<int>>& grid) {
        int H = grid.size(), W = grid[0].size();

        vector<vector<int>> nextRight(H, vector<int>(W, W));
        vector<vector<int>> prevLeft(H, vector<int>(W, -1));
        for (int r = 0; r < H; ++r) {
            int nxt = W;
            for (int c = W - 1; c >= 0; --c) {
                if (grid[r][c] == 1) nxt = c;
                nextRight[r][c] = nxt;
            }
            int prv = -1;
            for (int c = 0; c < W; ++c) {
                if (grid[r][c] == 1) prv = c;
                prevLeft[r][c] = prv;
            }
        }

        vector<vector<int>> nextDown(W, vector<int>(H, H));
        vector<vector<int>> prevUp(W, vector<int>(H, -1));
        for (int c = 0; c < W; ++c) {
            int nxt = H;
            for (int r = H - 1; r >= 0; --r) {
                if (grid[r][c] == 1) nxt = r;
                nextDown[c][r] = nxt;
            }
            int prv = -1;
            for (int r = 0; r < H; ++r) {
                if (grid[r][c] == 1) prv = r;
                prevUp[c][r] = prv;
            }
        }

        vector<vector<int>> costCol(W, vector<int>(W));
        {
            vector<int> mn(W, H), mx(W, -1);
            vector<char> has(W, 0);
            for (int c = 0; c < W; ++c) {
                for (int r = 0; r < H; ++r)
                    if (grid[r][c] == 1) { mn[c] = min(mn[c], r); mx[c] = max(mx[c], r); }
                if (mn[c] <= mx[c]) has[c] = 1;
            }
            for (int L = 0; L < W; ++L) {
                int top = H, bot = -1, left = -1, right = -1; bool any = false;
                for (int R = L; R < W; ++R) {
                    if (has[R]) {
                        if (!any) left = R;
                        right = R; any = true;
                        top = min(top, mn[R]); bot = max(bot, mx[R]);
                    }
                    costCol[L][R] = any ? (right-left+1)*(bot-top+1) : 1;
                }
            }
        }

        vector<vector<int>> costRow(H, vector<int>(H));
        {
            vector<int> mn(H, W), mx(H, -1);
            vector<char> has(H, 0);
            for (int r = 0; r < H; ++r) {
                for (int c = 0; c < W; ++c)
                    if (grid[r][c] == 1) { mn[r] = min(mn[r], c); mx[r] = max(mx[r], c); }
                if (mn[r] <= mx[r]) has[r] = 1;
            }
            for (int T = 0; T < H; ++T) {
                int left = W, right = -1, top = -1, bot = -1; bool any = false;
                for (int B = T; B < H; ++B) {
                    if (has[B]) {
                        if (!any) top = B;
                        bot = B; any = true;
                        left = min(left, mn[B]); right = max(right, mx[B]);
                    }
                    costRow[T][B] = any ? (right-left+1)*(bot-top+1) : 1;
                }
            }
        }

        vector<vector<int>> best2H(W, vector<int>(W, INF));
        for (int L = 0; L < W; ++L) {
            for (int R = L; R < W; ++R) {
                vector<int> pref(H), suf(H);
                bool any = false; int top = H, bot = -1, left = W, right = -1;
                for (int r = 0; r < H; ++r) {
                    int lp = nextRight[r][L];
                    if (lp <= R) {
                        any = true; if (top == H) top = r; bot = r;
                        left = min(left, lp);
                        right = max(right, prevLeft[r][R]);
                    }
                    pref[r] = any ? (bot-top+1)*(right-left+1) : 1;
                }
                any = false; top = H; bot = -1; left = W; right = -1;
                for (int r = H - 1; r >= 0; --r) {
                    int lp = nextRight[r][L];
                    if (lp <= R) {
                        any = true; if (bot == -1) bot = r; top = r;
                        left = min(left, lp);
                        right = max(right, prevLeft[r][R]);
                    }
                    suf[r] = any ? (bot-top+1)*(right-left+1) : 1;
                }
                int best = INF;
                for (int r = 0; r + 1 < H; ++r) best = min(best, pref[r] + suf[r+1]);
                best2H[L][R] = best;
            }
        }

        vector<vector<int>> best2V(H, vector<int>(H, INF));
        for (int T = 0; T < H; ++T) {
            for (int B = T; B < H; ++B) {
                vector<int> pref(W), suf(W);
                bool any = false; int l = -1, rgt = -1, top = H, bot = -1;
                for (int c = 0; c < W; ++c) {
                    int fr = nextDown[c][T];
                    if (fr <= B) {
                        any = true; if (l == -1) l = c; rgt = c;
                        top = min(top, fr);
                        bot = max(bot, prevUp[c][B]);
                    }
                    pref[c] = any ? (rgt-l+1)*(bot-top+1) : 1;
                }
                any = false; l = -1; rgt = -1; top = H; bot = -1;
                for (int c = W - 1; c >= 0; --c) {
                    int fr = nextDown[c][T];
                    if (fr <= B) {
                        any = true; if (rgt == -1) rgt = c; l = c;
                        top = min(top, fr);
                        bot = max(bot, prevUp[c][B]);
                    }
                    suf[c] = any ? (rgt-l+1)*(bot-top+1) : 1;
                }
                int best = INF;
                for (int c = 0; c + 1 < W; ++c) best = min(best, pref[c] + suf[c+1]);
                best2V[T][B] = best;
            }
        }

        auto three = [&](const vector<vector<int>>& cost, int N) {
            vector<int> dp1(N), dp2(N, INF), dp3(N, INF);
            for (int i = 0; i < N; ++i) dp1[i] = cost[0][i];
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < i; ++j)
                    dp2[i] = min(dp2[i], dp1[j] + cost[j+1][i]);
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < i; ++j)
                    if (dp2[j] < INF) dp3[i] = min(dp3[i], dp2[j] + cost[j+1][i]);
            return dp3[N-1];
        };

        int ans = min(three(costCol, W), three(costRow, H));
        for (int c = 0; c + 1 < W; ++c) {
            ans = min(ans, costCol[0][c] + best2H[c+1][W-1]);
            ans = min(ans, best2H[0][c] + costCol[c+1][W-1]);
        }
        for (int r = 0; r + 1 < H; ++r) {
            ans = min(ans, costRow[0][r] + best2V[r+1][H-1]);
            ans = min(ans, best2V[0][r] + costRow[r+1][H-1]);
        }
        return ans;
    }
};