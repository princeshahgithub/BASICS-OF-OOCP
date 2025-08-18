class Solution {
private:
    // Target value.
    static constexpr double kTarget = 24.0;
    // Max tolerable error.
    static constexpr double kEpsilon = 1e-5;
    bool IsApproxEqual(double a, double b) {
        return std::abs(a - b) < kEpsilon;
    }

    bool ContinueOrBacktrack (std::vector<double>& res) {
        // Using the current operations, either keep adding new ones or
        // resolve to less operations.
        if(find24(res)) {
            return true;
        }
        // If we got here, it means the path we went down did not work.
        // So we backtrack.
        res.pop_back();
        return false;
    }
public:
bool judgePoint24(const vector<int>& nums) {
    // Convert the integers to double.
    vector<double> vec;
    for(int n : nums){
        vec.push_back(static_cast<double>(n));
    }
    return find24(vec);
}

bool find24(vector<double>& vec){
    // When there's only a single operation, evaluate it against the target.
    if(vec.size() == 1) {
        return IsApproxEqual(vec[0], kTarget);
    }

    // Compare all numbers against each other.
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec.size(); ++j) {
            // Operations can only happen when i != j.
            if(i == j) continue;
            vector<double> res;
            // Get the other numbers.
            for(int k = 0; k < vec.size(); ++k){
                if(k != i && k != j) res.push_back(vec[k]);
            }

            // Addition and multiplication are commutative.
            if(i < j) {
                res.push_back(vec[i] + vec[j]);
                if (ContinueOrBacktrack(res)) return true;
                res.push_back(vec[i] * vec[j]);
                if (ContinueOrBacktrack(res)) return true;
            }
            res.push_back(vec[i] - vec[j]);
            if (ContinueOrBacktrack(res)) return true;
            if (vec[j] != 0.0) {
                res.push_back(vec[i] / vec[j]);
                if (ContinueOrBacktrack(res)) return true;
            }
        }
    }
    return false;
}
};