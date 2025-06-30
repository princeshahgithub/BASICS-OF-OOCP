const int N=256, mask=255, bshift=8;
int freq[N];

void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
    const unsigned biased=0x80000000;
    // Convert to biased form (signed to unsigned)
    unsigned M=0;
    for (int i = 0; i < n; i++){
        nums[i] ^= biased;
        M=max(M, (unsigned)nums[i]);
    }
    const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
    int* in=nums;
    int* out=output;
    bool swapped=0;

    for (int round=0; round<Mround; round++) {
        const int shift=round*bshift;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++)
            freq[(in[i] >> shift) & mask]++;

        partial_sum(freq, freq+N, freq);

        for (int i = n - 1; i >= 0; i--) {
            int val = in[i];
            int x = (val >> shift) & mask;
            out[--freq[x]] = val;
        }

        swap(in, out);
        swapped = !swapped;
    }

    // If needed, copy back
    if (swapped)
        memcpy(nums, in, n * sizeof(int));

    // Undo biasing
    for (int i = 0; i < n; i++)
        nums[i] ^= biased;
}

class Solution {
public:
    static int findLHS(vector<int>& nums) {
        const int n=nums.size();
        int* A=nums.data();
        radix_sort(A, n);
        int maxLen=0;
        for(int l=0, r=0; r<n; r++){
            const int x=A[r];
            while(l<r && A[l]<x-1) l++;
            if (A[l]==x-1) maxLen=max(maxLen, r-l+1);
        }
        return maxLen;
    }
};