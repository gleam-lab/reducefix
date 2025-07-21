void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    vll v;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    v.push_back(cnt);
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i] > 1 && v[i - 1] > 1) {
            ans -= 1;
        }
    }
    cout << ans << "\n";
}