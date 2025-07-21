#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
long long n, m, k, sum, c[MAXN], a[MAXN], b[MAXN];

bool check(vector<long long>& votes, int idx, int x) {
    vector<long long> new_votes(votes.begin(), votes.end());
    new_votes[idx] += x;
    sort(new_votes.rbegin(), new_votes.rend());
    return new_votes[0] > new_votes[m];
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    k -= sum;
    
    if (k == 0) {
        for (int i = 0; i < n; ++i) cout << "0 ";
        cout << endl;
        return;
    }

    sort(b, b + n);
    reverse(b, b + n);

    vector<long long> current_votes(n);
    for (int i = 0; i < n; ++i) current_votes[i] = a[i];

    vector<int> result(n, -1);
    for (int i = 0; i < n; ++i) {
        if (current_votes[i] > b[m - 1]) {
            result[i] = 0;
            continue;
        }
        long long min_votes_needed = b[m - 1] - current_votes[i] + 1;
        if (min_votes_needed <= k) {
            result[i] = min_votes_needed;
        }
    }

    for (int i = 0; i < n; ++i) cout << result[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}