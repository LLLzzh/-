#include <vector>
using namespace std; //个人习惯

struct Edge {
    int from, to, dist;
    Edge() {}
    Edge(int _from, int _to, int _dist): from(_from), to(_to), dist(_dist) {}
};

vector<Edge> g[MAXN];

void insert(int u, int v, int w) { //双向边带权值w
    g[u].push_back(Edge(u, v, w));
    g[v].push_back(Edge(v, u, w));
}

int now;//枚举点now的出边

//不推荐的写法，完全没有使用STL特性
for (int i = 0; i < g[now].size(); i++) {
    Edge &e = g[now][i];
    printf("%d\n", e.to);
}
//推荐的写法
for (vector<Edge>::iterator it = g[now].begin(); it != g[now].end(); it++) {
    printf("%d\n", it->to);
}
//C++11
for (auto &e : g[now]) {
    printf("%d\n", e.to);
}