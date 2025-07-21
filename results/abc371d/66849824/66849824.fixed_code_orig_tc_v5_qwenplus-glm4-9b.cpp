int l, r;
if (X_l == x_to_ptr.end()) {
    l = N; // If lower bound is not found, it must be outside the range of points.
} else {
    l = (*X_l).second;
    if (L <= X[l]) { // Only include the lower bound if it's within the range.
        l--;
    }
}
if (X_r == x_to_ptr.begin()) {
    r = -1; // If upper bound is not found, it must be outside the range of points.
} else {
    r = (*X_r).second;
    if (X[r] < R) { // Only include the upper bound if it's within the range.
        r++;
    }
}
if (l > r) {
    // If the computed range is invalid (l > r), output 0 or an appropriate message.
    cout << "0" << endl;
} else {
    int ans = P[r] - P[l];
    cout << ans << endl;
}