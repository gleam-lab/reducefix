#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int n, m, k;
ll a[MAXN], b[MAXN], c[MAXN];

// Function to check if candidate i can win with x additional votes
bool check(ll x, int i) {
    vector<int> scores(n);
    for (int j = 0; j < n; ++j) {
        scores[j] = a[j];
    }
    scores[i] += x;
    
    sort(scores.begin(), scores.end());
    
    int cnt = 0;
    for (int j = n - 1; j >= n - m; --j) {
        if (scores[j] > scores[n - m - 1]) {
            ++cnt;
        } else {
            break;
        }
    }
    
    return cnt == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    for (int i = 0; i < n; ++i) {
        c[i] = c[i - 1] + b[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, i)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if (l <= k) {
            ans[i] = l;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}