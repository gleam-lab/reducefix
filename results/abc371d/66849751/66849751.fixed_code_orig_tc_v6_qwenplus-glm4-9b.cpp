int l = 0;
if (X_l != x_to_ptr.begin()) {
    --X_l; // Move to the element just before the lower bound
    l = (*X_l).second;
}
int r = N;
if (X_r != x_to_ptr.end()) {
    r = (*X_r).second;
}