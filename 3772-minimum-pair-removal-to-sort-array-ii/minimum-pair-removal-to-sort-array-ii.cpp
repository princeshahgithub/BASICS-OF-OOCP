struct Item {
    int64_t val;
    int pos;
};

using Iterator = std::list<Item>::iterator;
struct Pair {
    int64_t sum;
    Iterator it;
};

bool operator<(const Pair& lhs, const Pair& rhs) {
    return std::tie(lhs.sum, lhs.it->pos) < std::tie(rhs.sum, rhs.it->pos);
}

class Solution {
public:
    int minimumPairRemoval(const vector<int>& nums_raw) {
        std::list<Item> nums;
        for (size_t i = 0; i != nums_raw.size(); ++i) {
            nums.emplace_back(nums_raw[i], i);
        }

        size_t decs = 0;
        std::set<Pair> queue;
        auto add = [&](Iterator it) {
            assert(it != nums.end());
            auto next = std::next(it);
            if (next != nums.end()) {
                queue.emplace(it->val + next->val, it);
                decs += it->val > next->val;
            }
        };
        auto remove = [&](Iterator it) {
            assert(it != nums.end());
            auto next = std::next(it);
            if (next != nums.end()) {
                queue.erase({it->val + next->val, it});
                decs -= it->val > next->val;
            }
        };
        for (auto it = nums.begin(); std::next(it) != nums.end(); ++it) {
            add(it);
        }
        
        int result = 0;
        while (decs) {
            ++result; 
            auto [_, right] = *queue.begin();
            remove(right);
            if (right != nums.begin()) {
                remove(std::prev(right));
            }
            auto left = std::next(right);
            remove(left);
            right->val += left->val;
            nums.erase(left);
            add(right);
            if (right != nums.begin()) {
                add(std::prev(right));
            }
        }
        return result;
    }
};