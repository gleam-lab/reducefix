int c = lower_bound(x, x+n+1, L) - x; // Get index of first element >= L
int d = upper_bound(x, x+n+1, R) - x; // Get index of first element > R (which is one after R)
cout << sum[d-1] - sum[c-1] << endl; // Calculate sum of range [c-1..d-1] (since sum is 0-indexed)