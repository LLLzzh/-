bool inq[MAXN];
queue<int> q;
inline int spfa(int s, int t) {
    q.push(s);
    inq[s] = true;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        inq[now] = false;
        for (int i = he[now]; i; i = ne[i]) {
            Edge &e = ed[i];
            if (d[now] + e.dist < d[e.to]) {
                d[e.to] = d[now] + e.dist;
                if (!inq[e.to]) {
                    q.push(e.to);
                    inq[e.to] = true;
                }
            }
        }
    }
    return d[t] == INF ? -1 : d[t];
}