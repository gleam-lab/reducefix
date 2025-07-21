#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    vector<ll> a(n), prefix_sum(m);
    unordered_map<ll, int> freq;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        prefix_sum[a[i] % m]++;
    }

    for (int i = 0; i < n; ++i) {
        ans += prefix_sum[(m - a[i] % m) % m];
        ans += prefix_sum[(a[i] % m + 1) % m];
        freq[a[i] % m]++;
        prefix_sum[a[i] % m]--;
    }

    printf("%lld\n", ans);
    return 0;
}