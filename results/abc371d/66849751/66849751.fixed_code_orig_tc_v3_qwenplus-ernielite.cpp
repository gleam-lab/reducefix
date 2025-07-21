if (X_l == x_to_ptr.end()) {
    l = r - 1; // Set l to be one less than r if X_l is at the end of the map
} else {
    l = (*X_l).second; // Otherwise, get l from X_l's second element (the index)
}
if (X_r == x_to_ptr.end()) {
    r = N - 1; // Set r to be N-1 if X_r is at the end of the map (i.e., no element greater than R)
} else {
    r = (*X_r).second - 1; // Get r from X_r's second element minus 1 (since it's one greater than needed)
}