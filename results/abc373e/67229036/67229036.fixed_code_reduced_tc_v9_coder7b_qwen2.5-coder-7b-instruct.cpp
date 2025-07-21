#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;

int n, m, k, sum;
ll a[MAXN], b[MAXN], c[MAXN];

// Function to check if a candidate can win with at least x additional votes
bool check(ll x, ll y) {
    // Find the position where candidate i would rank after adding x votes
    int pos = lower_bound(b + 1, b + 1 + n, x + y + 1) - b - 1;
    
    // Check if there are fewer than M candidates ranked higher than candidate i
    if (pos < n - m) return false;
    
    // Calculate the total votes needed for candidate i to win
    ll needed_votes = (x + y + 1) * (pos - n + m) - (c[pos] - c[n - m - 1] - max(x, b[n - m]));
    
    // Return true if the needed votes do not exceed the remaining votes
    return needed_votes <= k - y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + 1 + n);
    partial_sum(b + 1, b + 1 + n, c + 1);

    vector<ll> results(n);
    for (int i = 1; i <= n; ++i) {
        ll l = 0, r = k - sum + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (check(a[i], mid)) r = mid;
            else l = mid + 1;
        }
        if (l <= k - sum) results[i - 1] = l;
        else results[i - 1] = -1;
    }

    for (int res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}