for (int j = 1; j < n; j++) {
    sum += arr[(i + j) % n];
    if (sum % m == 0)
        ans++;
}