int d[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && j != k)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}