#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0, j = 0; i < n && j <= m; ) {
        if (a[i] <= x) {
            i++;
        } else {
            if (j == m || b[j] > x) {
                return false;
            }
            j++;
        }
    }

    return true;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    ll low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
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