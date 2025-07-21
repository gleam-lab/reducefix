void solve() {
    ll n, m; re(n, m);
    vector<pll> q(m);
    FOR(i, 0, m) { re(q[i].fst, q[i].snd); }
    
    // Initialize sets to track attacked squares
    set<ll> row, col, d1, d2;
    vector<vector<ll>> covered(n + 1, vector<ll>(n + 1, 0));

    // Mark the squares attacked by each piece
    FOR(i, 0, m) {
        ll a, b;
        re(a, b);
        row.ins(a), col.ins(b);
        d1.ins(a - b), d2.ins(a + b);
        covered[a][b] = 1;
    }

    ll ans = n * n;

    // Subtract squares attacked by rows and columns
    FOR(a, 1, n + 1) { ans -= covered[a][0]; }
    FOR(b, 1, n + 1) { ans -= covered[0][b]; }

    // Subtract squares attacked by diagonals
    FOR(d, -n + 1, n) {
        bool inverted = d < 0;
        ll start = inverted ? -d : 1;
        ll end = inverted ? n - d : n;
        ll prevA = 1, prevB = start;
        for (ll a = start; a <= end; ++a) {
            ll b = prevA + d;
            if (inBounds({a, b}, n)) {
                covered[a][b] = 1;
            }
            prevA = a;
            prevB = b;
        }
    }

    FOR(d, 1 - n, n) {
        bool inverted = d < 0;
        ll start = inverted ? -d : 1;
        ll end = inverted ? n - d : n;
        ll prevA = 1, prevB = start;
        for (ll a = start; a <= end; ++a) {
            ll b = prevA - d;
            if (inBounds({a, b}, n)) {
                covered[a][b] = 1;
            }
            prevA = a;
            prevB = b;
        }
    }

    // Subtract the number of covered squares
    FOR(a, 1, n + 1) {
        FOR(b, 1, n + 1) {
            if (covered[a][b]) ans--;
        }
    }

    cout << ans;
}