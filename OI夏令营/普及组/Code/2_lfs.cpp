struct Edge {
    int from, to, dist;
    Edge() {}
    Edge(int _from, int _to, int _dist): from(_from), to(_to), dist(_dist) {}
};

Edge ed[MAXM];
int he[MAXN], ne[MAXM], etop = 1;
//边编号从1开始，0代表没有下一条边，对应链表的NULL
//he[i]代表点i边集中的第一条边编号，对应链表的head指针
//ne[i]代表边i的下一条边编号，对应链表中的next指针
//ed[i]代表边i的信息

void insert(int u, int v, int w) { //单向边带权值w
    ed[etop] = Edge(u, v, w);
    ne[etop] = he[u];
    he[u] = etop++;
    //单向链表从头部插入元素
}

int now;
for (int i = he[now]; i; i = ne[i]) {
    Edge &e = ed[i];
    printf("%d\n", e.to);
}