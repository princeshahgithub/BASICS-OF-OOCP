const int N=100000;
int q[N], front=0, back=0;
unsigned dist1[N], dist2[N];
class Solution {
public:
    static void bfs(int node, vector<int>& edges, unsigned* dist){
        front=back=0;
        q[back++]=node;
        for(int d=0; front<back; d++){
            int qz=back-front;
            for(int a=0; a<qz; a++){
                int i=q[front++];
                dist[i]=d;
                int j=edges[i];
                if (j!=-1 && dist[j]==UINT_MAX) 
                    q[back++]=j;
            }
        }
        
    }
    static int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n=edges.size();

        memset(dist1, -1, n*4);
        memset(dist2, -1, n*4);
        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);
        unsigned minD=UINT_MAX;
        int index=-1;
        for (int i=0; i<n; i++) {
            int max12=max(dist1[i], dist2[i]);
            if (max12<minD ) {
                minD=max12;
                index=i;
            }
        }
        return index;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();