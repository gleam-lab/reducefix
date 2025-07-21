int main() {
    // ... [rest of the main function] ...

    rep(q, Q) {
        int L, R, l, r;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        // Adjust the beginning of the range if L is smaller than the first key in the map
        if (X_l == x_to_ptr.begin()) {
            l = -1; // Use -1 or some other sentinel value to indicate that the start is beyond the first key
        } else {
            --X_l;
            l = X_l->second;
        }

        // Adjust the end of the range if R is greater than or equal to the last key in the map
        if (X_r == x_to_ptr.end()) {
            r = N; // Use N or some other sentinel value to indicate that the end is beyond the last key
        } else {
            r = X_r->second;
        }

        int ans = P[r] - P[l];
        if (l == -1) {
            ans = P[r]; // If l is out of bounds, the sum is just the sum up to r
        }
        cout << ans << endl;
    }

    // ... [rest of the main function] ...
}