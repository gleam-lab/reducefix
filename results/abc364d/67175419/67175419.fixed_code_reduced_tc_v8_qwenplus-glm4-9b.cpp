int check(int mid, int x, int y) {
    int l = lower_bound(a + 1, a + n + 1, y - mid) - a;
    int r = upper_bound(a + 1, a + n + 1, y + mid) - a;
    return r - l >= k;
}