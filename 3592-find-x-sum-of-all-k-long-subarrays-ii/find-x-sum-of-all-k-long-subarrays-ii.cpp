class Solution {
public:
        using Map = map<int, set<int, greater<int>>, greater<int>>;

        using P = pair<int, int>;

        struct cmp {
            bool operator()(const P& a, const P& b) const {
                    return a.first != b.first ? a.first > b.first
                                              : a.second > b.second;
            }
        };

        void modify(set<P, cmp> &u, set<P, cmp> &nu, unordered_map<int, int> &h, 
            const int n, const int a, long long &sum, const int x) {
                const auto old = h[n];
                h[n] += a;
                const auto ncnt = h[n];
                const P oldpair = {old, n};
                const P newpair = {ncnt, n};
                if (u.find(oldpair) != u.end())
                        sum -= (long long)oldpair.first * oldpair.second;
                u.erase(oldpair);
                nu.erase(oldpair);
                if (newpair.first > 0) {
                        if (u.empty() || newpair < *u.rbegin()) {
                                nu.insert(newpair);
                        } else {
                                u.insert(newpair);
                                sum += (long long)newpair.first * newpair.second;
                        }
                }
                while ((int)u.size() > x) {
                        auto it = prev(u.end());
                        sum -= (long long)it->first * it->second;
                        nu.insert(*it);
                        u.erase(it);
                }
                while ((int)u.size() < x && !nu.empty()) {
                        auto it = nu.begin();
                        sum += (long long)it->first * it->second;
                        u.insert(*it);
                        nu.erase(it);
                }
        }

        long long init(set<P, cmp>& u, set<P, cmp>& nu,const int x)
        {
                while ((int)u.size() > x) {
                        auto it = prev(u.end());
                        nu.insert({it->first, it->second});
                        u.erase(it);
                }
                long long acc = 0;
                for (auto& [k, v] : u)
                        acc += (long long)k * v;
                return acc;
        }

        vector<long long> findXSum(vector<int>& nums, int k, int x)
        {
                unordered_map<int, int> h;
                set<P, cmp> u;
                set<P, cmp> nu;
                for (int i = 0; i < k; i++)
                        h[nums[i]]++;
                for (auto& [key, v] : h)
                        u.insert({v, key});
                vector<long long> res;

                auto sum = init(u, nu, x);
                res.push_back(sum);
                const int size = nums.size();
                for (int i = k; i < size; i++) {
                        modify(u, nu, h, nums[i - k], -1, sum, x);
                        modify(u, nu, h, nums[i], 1, sum, x);
                        res.push_back(sum);
                }

                return res;
        }
};