// ... (previous code remains the same)

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        if (X_l == x_to_ptr.end() || (*X_l).first != L) {
            l = N; // Set l to N if L is not found in x_to_ptr
        } else {
            l = (*X_l).second;
        }
        if (X_r == x_to_ptr.end() || (*X_r).first != R) {
            r = N; // Set r to N if R is not found in x_to_ptr
        } else {
            r = (*X_r).second;
        }
        int ans = P[r] - P[l]; // Calculate the difference and print the result for each query
        cout << ans << endl;
    }
}