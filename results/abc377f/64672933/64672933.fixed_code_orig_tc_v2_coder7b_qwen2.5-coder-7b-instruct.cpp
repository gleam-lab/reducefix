#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N, M; cin >> N >> M;
    vector<pair<ll, ll>> g(M);
    set<ll> A, B, C, D;
    for (ll i = 0; i < M; ++i) {
        ll a, b; cin >> a >> b;
        g[i] = {a, b};
        A.insert(a + b);
        B.insert(a - b);
        C.insert(a);
        D.insert(b);
    }
    
    auto remove_duplicates = [&](set<ll>& s) {
        vector<ll> temp(s.begin(), s.end());
        s.clear();
        for (auto& x : temp) {
            if (s.empty() || s.rbegin()->second != x) {
                s.insert(x);
            }
        }
    };
    remove_duplicates(A);
    remove_duplicates(B);
    remove_duplicates(C);
    remove_duplicates(D);
    
    ll ans = 0;
    for (auto line : B) {
        ll L = max(1LL, min(line + 1, N)), R = min(N, line + N);
        ans -= R - L + 1;
    }
    for (auto line : A) {
        ll L = max(1LL, min(line - 1, N)), R = max(1LL, min(N, line - N));
        ans -= R - L + 1;
    }

    map<ll, ll> checkx, checky;
    for (auto line : A) {
        for (auto line1 : B) {
            if ((line + line1) % 2 == 0) {
                ll x = (line + line1) / 2, y = line - x;
                if (x >= 1 && x <= N && y >= 1 && y <= N) checkx[x]++;
            }
            if ((line - line1) % 2 == 0) {
                ll y = (line - line1) / 2, x = line - y;
                if (x >= 1 && x <= N && y >= 1 && y <= N) checky[y]++;
            }
        }
    }

    for (auto line : C) {
        ans -= N;
        for (auto lineA : A) {
            ll y = lineA - line;
            if (y >= 1 && y <= N) ans++;
        }
        for (auto lineB : B) {
            ll x = line + lineB;
            if (x >= 1 && x <= N) ans++;
        }
        if (checkx.count(line)) ans -= checkx[line];
    }

    for (auto line : D) {
        ans -= N;
        for (auto lineA : A) {
            ll x = lineA - line;
            if (x >= 1 && x <= N) ans++;
        }
        for (auto lineB : B) {
            ll y = line + lineB;
            if (y >= 1 && y <= N) ans++;
        }
        ans += C.size();

        for (auto line1 : C) {
            ll v = line + line1;
            if (v >= 1 && v <= N && A.count(v)) ans--;
        }

        for (auto line1 : C) {
            ll v = line1 - line;
            if (v >= 1 && v <= N && B.count(v)) ans--;
        }

        if (checky.count(line)) ans -= checky[line];
    }

    set<pair<ll, ll>> ss;
    for (auto x : A) {
        for (auto y : B) {
            ss.insert({x, y});
        }
    }

    for (auto x : C) {
        for (auto y : D) {
            if (ss.count({x + y, x - y})) ans++;
        }
    }

    cout << N * N + ans << '\n';
    return 0;
}