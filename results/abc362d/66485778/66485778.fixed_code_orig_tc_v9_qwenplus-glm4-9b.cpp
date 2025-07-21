if (d[x] + dw + a[y] < d[y]) {
    d[y] = d[x] + dw + a[y];
    pq.emplace(y, d[y]);
}