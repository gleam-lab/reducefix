int check(int x, int y, int z) {
    int a1 = lower_bound(a + 1, a + n + 1, y - x) - a - 1; // Get the lower bound index
    int b1 = upper_bound(a + 1, a + n + 1, y + x) - a; // Get the upper bound index
    
    // Adjust b1 to make sure we include the last point in the range
    if (a[b1] == y + x) {
        b1--;
    }
    
    // Check if the number of points between a1 and b1 is at least z
    return b1 - a1 + 1 >= z;
}