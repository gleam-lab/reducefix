auto X_l = x_to_ptr.lower_bound(L);
auto X_r = x_to_ptr.upper_bound(R);

// Ensure that x_to_ptr is not empty and that the bounds are within the valid range.
if (x_to_ptr.empty()) {
    l = 0;
    r = 0;
} else if (X_l == x_to_ptr.begin()) {
    l = X_l->second;
} else {
    l = (X_l - 1)->second;  // Get the second of the last element in the range.
}

if (X_r == x_to_ptr.end()) {
    r = N;
} else if (X_r == x_to_ptr.begin()) {
    r = 0;  // This should not happen due to the initial loop that fills P[0] = 0.
} else {
    r = X_r->second - 1;  // Get the second of the first element in the range.
}

// Ensure that l and r are within the valid range [0, N-1].
l = max(l, 0);
r = min(r, N-1);

int ans = P[r] - P[l];
cout << ans << endl;