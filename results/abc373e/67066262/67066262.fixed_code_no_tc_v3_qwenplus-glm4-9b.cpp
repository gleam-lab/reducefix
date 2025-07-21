#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

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

    // Sort candidates by votes received in descending order
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> votes_needed(n, -1);

    // Find the minimum votes needed for the top M candidates to guarantee victory
    ll remaining_votes = k;
    for(int i = 0; i < m; ++i) {
        ll max_votes_needed = LLONG_MAX;
        for(int j = 0; j < n; ++j) {
            if(a[j] - a[i] + remaining_votes >= (n - m + 1) * (a[j] + 1)) {
                max_votes_needed = min(max_votes_needed, (n - m + 1) * (a[j] + 1) - (a[j] - a[i] + remaining_votes));
            }
        }
        votes_needed[i] = max_votes_needed;
        remaining_votes -= votes_needed[i];
    }

    // Output the votes needed for each candidate
    vector<ll> ans(n);
    for(int i = 0; i < n; ++i) {
        ans[a[i] - 1] = votes_needed[i];
    }
    for(ll vote : ans) {
        if(vote == -1) {
            cout << "0 ";
        } else {
            cout << vote << " ";
        }
    }
    cout << endl;

    return 0;
}