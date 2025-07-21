# Given code
for (ll i = 0; i < n; i++) {
    ll temp1 = h[i] / 5;
    ll temp2 = h[i] % 5;

    ans += temp1 * 3;
    if (temp2 >= 3) ans += 3;
    else ans += temp2;
}