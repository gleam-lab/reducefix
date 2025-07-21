#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10;

int a[N], b[N];

int solve(int n, int k, vector<PII>& sa) {
    if (k == 1) {
        // If k is 1, the answer is simply the maximum value of A[i] multiplied by B[i]
        return *max_element(sa.begin(), sa.end())second;
    }

    int res = LLONG_MAX, sum = 0, max_sum = 0;
    priority_queue<int> pq;

    // Calculate prefix max of B
    for (int i = 0; i < k; i++) {
        sum += sa[i].se;
        pq.push(sa[i].se);
        max_sum = max(max_sum, sa[i].se);
    }

    // Iterate over the rest of the elements
    for (int i = k; i < n; i++) {
        sum += sa[i].se;
        pq.push(sa[i].se);

        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        res = min(res, max(sa[i].fi, max_sum) * sum);
        max_sum = max(max_sum, sa[i].se);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<PII> sa(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            sa[i] = {a[i], b[i]};
        }

        sort(sa.begin() + 1, sa.end()); // Sort pairs
        cout << solve(n, k, sa) << endl;
    }

    return 0;
}