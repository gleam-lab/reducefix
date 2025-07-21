#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int MAX = 2e8 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vl dist(MAX * 2), prefix_sum(MAX * 2);
    vi a(n);

    rep(i, n) {
        cin >> a[i];
        dist[a[i] + MAX]++;
    }

    prefix_sum[0] = dist[0];
    rep(i, MAX * 2) {
        prefix_sum[i + 1] = prefix_sum[i] + dist[i + 1];
    }

    rep(i, q) {
        int b, k;
        cin >> b >> k;
        b += MAX;

        int left = 0, right = MAX * 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] - prefix_sum[b - mid] < k)
                left = mid + 1;
            else
                right = mid;
        }

        cout << left - MAX << '\n';
    }

    return 0;
}