for (int q = 0; q < Q; q++) {
    int L, R;
    cin >> L >> R;
    auto X_l = x_to_ptr.lower_bound(L);
    auto X_r = x_to_ptr.upper_bound(R);
    // ... rest of the code
}