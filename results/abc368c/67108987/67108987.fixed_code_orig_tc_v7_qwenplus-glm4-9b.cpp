for (int i = 1; i <= N; i++) {
    long long a = H[i] / 5;
    H[i] -= a * 5;
    T += a * 3;
    if (H[i] > 0) {
        T += 1;
        H[i] -= 1;
    }
    if (H[i] > 0) {
        T += 1;
        H[i] -= 1;
    }
    if (H[i] > 0) {
        T += 1;
        H[i] -= 3;
    }
}