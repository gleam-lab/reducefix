for(int i = 0; i < n; ++i) {
    int votes_needed = -1;
    for(int j = 0; j < n; ++j) {
        if (i != j && a[j] > a[i]) {
            if (votes_needed == -1 || votes_needed > K - a[i]) {
                votes_needed = K - a[i];
            } else {
                votes_needed += a[j] - a[i];
            }
        }
    }
    if (votes_needed != -1 && votes_needed <= K - sum_a) {
        ans[i] = votes_needed;
    } else {
        ans[i] = -1;
    }
}