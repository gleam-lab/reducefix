#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    // Sort based on the first element of pairs
    vector<pair<ll, ll>> ab(n);
    for(int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
    sort(ab.begin(), ab.end());

    // Calculate prefix sums for B
    vector<ll> ps(n + 1);
    for(int i = 0; i < n; ++i) ps[i + 1] = ps[i] + ab[i].second;

    // Initialize variables to store the result and the current sum
    ll res = INF, curr_sum = 0;
    
    // Iterate through the sorted array to find the minimum value of the expression
    for(int i = k - 1; i < n; ++i) {
        curr_sum += ab[i].second;
        res = min(res, (curr_sum + ps[n] - ps[i + 1]) * ab[i].first);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}