void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> s(n+10);
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for(int i = 1; i <= n; i++){
        ans += mp[(s[i] - L % M + M) % M];
        ans += mp[s[i] % M]++;
        // Remove the entry to avoid double counting
        mp.erase(s[i] % M);
    }
    cout << ans;
}