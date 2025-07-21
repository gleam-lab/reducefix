#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n - 1 && b[j] < a[i]) ++j;
        if (j == n - 1 && b[j] < a[i]) return false;
        ++j;
    }

    return true;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N - 1; ++i) cin >> b[i];

    if (!check(a, b, *max_element(a.begin(), a.end()))) {
        cout << "-1" << endl;
        return;
    }

    ll low = 1, high = 1e9, ans = -1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}