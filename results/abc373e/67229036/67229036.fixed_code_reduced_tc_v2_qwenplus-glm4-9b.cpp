#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int n, m, k, sum, a[N], b[N], c[N];

bool is_enough(int x) {
    int votes_needed = 0;
    int votes_left = x;
    int i = 0;
    while (votes_needed < m && i < n) {
        while (i < n && a[i] < votes_needed) {
            i++;
        }
        if (i == n) break;
        votes_needed += min(votes_left, m - a[i]);
        votes_left -= votes_needed;
        i++;
    }
    return votes_needed <= k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (i > 0) a[i] += a[i - 1];
        else a[i] += 0;
    }
    for (int i = 0; i < n; i++) {
        int additional_votes_needed = m - a[i];
        while (!is_enough(additional_votes_needed)) {
            additional_votes_needed++;
        }
        cout << (additional_votes_needed - (i > 0 ? a[i - 1] : 0)) << " ";
    }
    return 0;
}