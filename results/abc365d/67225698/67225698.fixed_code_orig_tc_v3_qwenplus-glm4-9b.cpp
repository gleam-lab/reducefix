void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 1; // start with 1 as the first character always starts a new count
    vll v;
    for (ll i = 0; i < n; i++)
    {
        if (i == n - 1 || s[i] != s[i + 1]) // compare current character to the next one
        {
            ans += (cnt + 1) / 2; // calculate the number of characters for the current group
            v.push_back(cnt); // store the count of the previous group
            cnt = 1; // reset count for the next group
        }
        else
        {
            cnt++; // increment count for consecutive characters
        }
    }
    cout << ans << "\n"; // output the final result
}