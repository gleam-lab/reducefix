#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    k -= accumulate(a.begin(), a.end(), 0LL);
    
    // Sort candidates by number of votes received so far
    vector<pair<ll, int>> votes(a.begin(), a.end());
    sort(votes.begin(), votes.end());

    vector<ll> prefix(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + votes[i - 1].first;
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll votes_needed = 0;
        ll max_votes = prefix[n] - prefix[i + 1] - (n - i - 1);

        if (max_votes + votes_needed + votes[i].first < m) {
            votes_needed = m - (max_votes + votes[i].first);
        }

        if (votes_needed > k) {
            ans[i] = -1;
        } else {
            ans[i] = votes_needed;
        }
    }

    for (ll n_i : ans) {
        cout << n_i << ' ';
    }
    cout << '\n';

    return 0;
}