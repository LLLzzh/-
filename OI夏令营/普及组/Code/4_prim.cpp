bool vis[MAXN];
int minc[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int prim() {
    int ans = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int c = q.top().first, now = ed[q.top().second].to;
        if (!vis[now]) {
            vis[now] = true;
            ans += c;
            insert(ed[i].from, ed[i].to, ed[i].cost);
            insert(ed[i].to, ed[i].from, ed[i].cost);
            for (int i = he[now]; i; i = ne[i]) {
                Edge &e = ed[i];
                if (minc[e.to] > e.cost && !vis[e.to]) {
                    minc[e.to] = e.cost;
                    q.push(make_pair(e.cost, i));
                }
            }
        }
    }
    return ans;
}