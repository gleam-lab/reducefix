#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; ++i) {
        candidates[i].first = a[i];
        candidates[i].second = i;
    }

    sort(candidates.begin(), candidates.end());

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for(int i = 0; i < n; ++i) {
        pq.push({candidates[i].first, candidates[i].second});
    }

    vector<ll> ans(n, -1);
    int remaining_candidates = n - m;
    ll remaining_votes = k;

    while(!pq.empty()) {
        auto [votes, idx] = pq.top();
        pq.pop();

        if(votes + remaining_votes >= candidates[m - 1].first + 1) {
            ans[idx] = 0;
            remaining_votes -= (candidates[m - 1].first + 1 - votes);
            remaining_candidates--;
        } else {
            break;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(ans[i] == -1) {
            ans[i] = -1;
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}