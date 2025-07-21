#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];

    vl dists(q);
    rep(j, q) {
        int b, k;
        cin >> b >> k;
        rep(i, n) {
            dists[j] += abs(a[i] - b);
        }
        dists[j] /= n;
        sort(dists.begin(), dists.begin() + j + 1);
        cout << dists[k - 1] << '\n';
    }

    return 0;
}