#define ll long long
#define mod ((int)1e9+7)
class Solution {
private:
    ll bin_exp(ll base, ll power){
        //cout<<base<<" "<<power;
        ll r=1;
        while(power!=0){
            if(power&1){
                r=(r*base)%mod;
            }
            base=(base*base)%mod;
            power=power/2;
        }
        return r;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        ll mx=100000;
        vector<ll>ps(mx+1,1);
        ps[0]=ps[1]=0;
        for(ll i=2;i*i<=mx;i++){
            if(ps[i]==1){
                for(ll j=i*i;j<=mx;j+=i){
                    ps[j]=0;
                }
            }
        }
        vector<ll>prime;
        for(ll i=0;i<=mx;i++){
            if(ps[i]==1){
                prime.push_back(i);
            }
        }
        vector<ll>score(mx+1,0);
        for(auto it:prime){
            for(ll i=it;i<=mx;i+=it){
                score[i]++;
            }
        }
        ll n=nums.size();
        vector<ll>x(n);
        for(ll i=0;i<n;i++){
            x[i]=score[nums[i]];
        }
        ll ans=1;
        // indexial next greater and next smallest integer
        // to find each elemen contribution
        vector<ll>next_greater(n);
        vector<ll>prev_greater(n);
        stack<ll>st;
        next_greater[n-1]=n;
        st.push(n-1);
        for(ll i=n-2;i>=0;i--){
            while(!st.empty() && x[i]>=x[st.top()]){
                st.pop();
            }
            if(st.empty()){
                next_greater[i]=n;
            }
            else{
                next_greater[i]=st.top();
            }
            st.push(i);
        }


        stack<ll>st2;
        st2.push(0);
        prev_greater[0]=-1;
        for(ll i=1;i<n;i++){
            while(!st2.empty() && x[i]>x[st2.top()]){
                st2.pop();
            }
            if(st2.empty()){
                prev_greater[i]=-1;
            }
            else{
                prev_greater[i]=st2.top();
            }
            st2.push(i);
        }
        
        vector<ll>ctb(n);
        
        for(ll i=0;i<n;i++){
            ll front=next_greater[i]-i;
            ll back=i-prev_greater[i];
            ctb[i]=front*back;
        }
        vector<pair<ll,ll>>help(n);
        for(ll i=0;i<n;i++){
            help[i]={nums[i],i};
        }
        for(auto it:ctb) cout<<it<<" "; cout<<endl;
        sort(help.begin(),help.end(),greater<pair<ll,ll>>());
        for(ll i=0;i<n;i++){
            ll val=help[i].first;
            ll idx=help[i].second;
            ll cont=ctb[idx];
            ll mx=min((ll)k,cont);
            ans=(ans*(bin_exp(val,mx))%mod)%mod;
            k=k-mx;
            if(k<=0) break;
        }

        
        return ans%mod;

    }
};