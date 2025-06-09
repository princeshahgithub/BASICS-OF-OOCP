class Solution {
public:
    int n, d;
    vector<int> noPer;
    bool isPerfect;
    long long perfect[10] = {1,         11,          111,     1111,
                             11111,     111111,      1111111, 11111111,
                             111111111, 1111111111LL};
    long long tens[11] = {1,         10,         100,          1000,
                          10000,     100000,     1000000,      10000000,
                          100000000, 1000000000, 10000000000LL};

    // Function to count the  nodes in the lexicographical tree rooted at x
    int cntNodes(long long x) {
        int dx=log10(x), hx=d-dx;     // tree height-1 for tree rooted at x
        hx-=(x>noPer[dx]); // Adjust height if x exceeds noPer[dx]

        // If the tree rooted at x is perfect, use the perfect[] array
        if (isPerfect ||x != noPer[dx]) {
        //    cout <<"hx="<<hx << ", x="<<x
        //         <<", perfect subtree, cnt="<<perfect[hx]<< endl;
            return perfect[hx];
        }

        // Otherwise, compute normally by iterating through the levels
        long long curr = x;
        long long next = x+1;
        int cnt = 0;
        while (curr <= n) {
            cnt+= min(n + 1LL, next)-curr; // Count the nodes in [curr, next)
            curr*= 10;  // Go to the next level (deeper level)
            next*= 10;
        }
    //    cout <<x<<", cnt = "<<cnt<<endl;
        return cnt;
    }

    int findKthNumber(int n, int k) {
        this->n = n;
        d=log10(n);
    //    cout << "d = " << d << endl;
        isPerfect=(n+1==tens[d+1]);
    //    cout<<"isPerfect="<<isPerfect<<endl;
        noPer.assign(d+1, INT_MAX);
        if (!isPerfect){
            for (int i=0, z=n; i <= d; z/=10, i++) 
                noPer[d-i]=z;
        }
        
    //    cout << "k=" << k << ", n=" << n << endl;
    //    print(noPer);
        int curr=1;
        k--; // starting at 1

        while (k > 0) {
            int num=cntNodes(curr); // Count nodes in the tree rooted at curr
            if (num <= k) {
                curr++; // Move to the next sibling node
                k -= num;
            } 
            else {
                curr*=10; // Move to the leftmost child node
                k--;
            }
        }
        return curr;
    }
    void print(auto& c){
        for(auto x: c)cout<<x<<", "; cout<<endl;
    }
};