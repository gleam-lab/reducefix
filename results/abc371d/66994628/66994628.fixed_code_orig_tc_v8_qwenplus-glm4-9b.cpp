int main() {
    // ...
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Problematic line
    }
    
    // ...
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Using lower_bound and upper_bound correctly
        l = lower_bound(x + 1, x + n + 1, l) - x;
        r = upper_bound(x + 1, x + n + 1, r) - x;
        
        // Problematic line: should not subtract one from r in sum[r]
        cout << sum[r] - sum[l - 1] << endl;
    }
}