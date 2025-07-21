if (X_l == x_to_ptr.begin()) {
    l = -1; // Start from the first element
} else {
    l = (*X_l).second;
}

if (X_r == x_to_ptr.end()) {
    r = N; // End till the last element
} else {
    r = (*X_r).second;
}

if (l == -1) {
    // If l is -1, it means X_l is the beginning of the sequence
    ans = P[r];
} else {
    ans = P[r] - P[l];
}
cout << ans << endl;