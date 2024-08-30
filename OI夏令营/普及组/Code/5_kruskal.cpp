struct UnionSet {
    int f[MAXN];
    UnionSet(int n) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }
    UnionSet(){}

    void uni(int x, int y) {
        f[find(x)] = find(y);
    }

    bool query(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
        return f[x] == x ? x : (f[x] = find(f[x]));
    }

} us;

void kruskal() {
    sort(edges, edges+m);
    us = UnionSet(n);
    for (int i = 0; i < m && etop < n * 2 - 1; i++) {
        Edge &e = edges[i];
        if (!us.query(e.from, e.to)) {
            insert(e.from, e.to, e.dist);
            insert(e.to, e.from, e.dist);
            us.uni(e.from, e.to);
        }
    }
}