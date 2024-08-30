int d[MAXN];
bool vis[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int dijkstra(int s, int t){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()){
        int now = q.top().second;
        q.pop();
        if(!vis[now]){
            vis[now] = true;
            for(int i = he[now]; i; i = ne[i]){
                Edge& e = ed[i];
                if(d[e.to] > d[now] + e.dist){
                    d[e.to] = d[now] + e.dist;
                    q.push(make_pair(d[e.to], e.to));
                }
            }
        }
    }
    return d[t] == INF ? -1 : d[t];
}