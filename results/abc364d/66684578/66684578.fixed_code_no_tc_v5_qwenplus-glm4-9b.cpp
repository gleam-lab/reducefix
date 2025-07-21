#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vs vector<vector<int>>

ll dist(int a, int b) {
    return abs(a - b);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vl a(n);
    rep(i, n) cin >> a[i];

    vl b(q), k(q);
    rep(i, q) {
        cin >> b[i] >> k[i];
    }

    // Sort the points A to be able to find the k-th closest
    sort(a.begin(), a.end());

    // Create a map to count occurrences of each distance
    vl dist_count(n);
    for (ll i = 0; i < q; i++) {
        for (ll j = 0; j < n; j++) {
            dist_count[j] += dist(a[j], b[i]) == k[i];
        }
    }

    // Output the k-th closest distance for each point B
    for (ll i = 0; i < q; i++) {
        for (ll j = 0; j < n; j++) {
            if (dist_count[j] > 0) {
                cout << dist(a[j], b[i]) << endl;
                dist_count[j]--;
                break;
            }
        }
    }

    return 0;
}