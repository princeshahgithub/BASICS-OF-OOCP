const int mod = 1e9 + 7;
using vec26 = array<int, 26>;
using matrix = array<vec26, 26>;

// Identity matrix generator
static matrix identityMatrix() {
    matrix I{};
    for (int i = 0; i < 26; i++)
        I[i][i] = 1;
    return I;
}

// Optimized matrix multiplication (26×26 only)
static matrix operator*(const matrix& A, const matrix& B) {
    matrix C{};
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < 26; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < 26; j++) {
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

// Matrix-vector multiplication
static vec26 operator*(const matrix& A, const vec26& X) {
    vec26 ans = {};
    for (int i = 0; i < 26; i++) {
        int64_t sum = 0;
        for (int j = 0; j < 26; j++) {
            sum += 1LL * A[i][j] * X[j];
        }
        ans[i] = sum % mod;
    }
    return ans;
}

class Solution {
public:
    static matrix I;
    static matrix M;

    // Matrix exponentiation (LSBF)
    static matrix powLSBF(matrix M, int n) {
        matrix ans = I;
        for (; n>0; n>>=1) {
            if (n & 1) ans = ans * M;
            M = M * M;
        }
        return ans;
    }
    // Matrix exponentiation (MSBF)
    static matrix pow(const matrix& M, unsigned n) {
        if (n==0) return I;
        bitset<32> B(n);
        int bMax=31-countl_zero(n);
        matrix ans = M;
        for (int i=bMax-1; i>=0; i--) {
            ans=ans*ans;
            if (B[i]) ans = ans * M;
        }
        return ans;
    }

    // transition matrix
    static matrix build_M(vector<int>& nums) {
        matrix M{};
        for (int i = 0; i < 26; i++) {
            const int jN=i+nums[i];
            for(int j=i+1; j<=jN; j++)
                M[j%26][i] = 1;
        }
        return M;
    }

    static int lengthAfterTransformations(string& s, int t, vector<int>& nums)
    {
        I = identityMatrix();
        vec26 freq = {};
        for (char c : s)
            freq[c - 'a']++;

        M = build_M(nums);
        matrix B = pow(M, t);     // M^t
        vec26 C = B * freq;       // B × freq

       return reduce(C.begin(), C.end(), 0LL)% mod;
    }
};

// Static matrix definitions
matrix Solution::I;
matrix Solution::M;