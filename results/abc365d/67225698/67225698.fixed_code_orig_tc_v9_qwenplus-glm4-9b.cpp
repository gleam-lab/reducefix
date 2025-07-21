void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 1; // Initialize cnt to 1 to handle the first character
    for (int i = 1; i <= n; i++) {
        if (i < n && s[i] == s[i - 1]) {
            cnt++; // Increment cnt for consecutive identical characters
        } else {
            ans += (cnt + 1) / 2; // Calculate the number of completions
            cnt = 1; // Reset cnt for the new sequence
        }
    }
    cout << ans << "\n";
}