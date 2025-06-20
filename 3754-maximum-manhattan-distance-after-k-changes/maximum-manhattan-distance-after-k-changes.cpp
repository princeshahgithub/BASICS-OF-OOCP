class Solution {
public:
    int maxDistance(string s, int k) {
        vector<vector<int>>v(int(s.size()),vector<int>(4,0));
        for(int i=0;i<s.size();i++){
            if(s[i]=='N')v[i][0]++;
            if(s[i]=='S')v[i][1]++;
            if(s[i]=='E')v[i][2]++;
            if(s[i]=='W')v[i][3]++;
        }
        int c=0;
        for(int i=1;i<s.size();i++){
            for(int j=0;j<4;j++)v[i][j]+=v[i-1][j];
        }
        for(int i=0;i<s.size();i++){
            int o=k,g=0;
            int p=min(v[i][0],v[i][1]),pp=min(v[i][2],v[i][3]);
            int x=max(v[i][0],v[i][1]),y=max(v[i][2],v[i][3]); 
            g=(x-p)+(y-pp);
            int j=min(p,o);
            g+=j*2;
            o-=j;
            j=min(o,pp);
            g+=j*2;
            c=max(c,g);
        }
        return c;
    }
};