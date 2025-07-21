if (X_l == x_to_ptr.end()) {
    // If X_l is not found, it means L is greater than any value in X.
    // Set l to N (end of array X).
    l = N;
} else {
    l = (*X_l).second; // Get the index corresponding to the found value in X.
}
if (X_r == x_to_ptr.end() || (*X_r).first >= R) {
    // If X_r is not found or its value is greater than or equal to R,
    // set r to N (end of array X) since R is too large.
    r = N - 1; // Change to N - 1 since we want to find the index before R.
} else {
    r = (*X_r).second; // Get the index corresponding to the found value in X.
}