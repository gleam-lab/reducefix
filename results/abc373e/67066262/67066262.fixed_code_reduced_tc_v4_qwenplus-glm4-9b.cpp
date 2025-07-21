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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end(), greater<ll>());
    
    vector<ll> suffix(n);
    ll acc = 0;
    for(int i = n - 1; i >= 0; i--) {
        acc += sorted_a[i];
        suffix[i] = acc;
    }

    // Calculate the number of votes needed for each candidate to guarantee their victory
    vector<ll> votes_needed(n);
    for(int i = 0; i < n; i++) {
        ll votes_to_beat = (i >= m ? suffix[i - m] : 0);
        votes_needed[i] = votes_to_beat - a[i] + 1;
    }
    
    // Sort the votes_needed to process from the most demanding to the least
    sort(votes_needed.begin(), votes_needed.end(), greater<ll>());

    vector<ll> result(n, -1);
    ll remaining_votes = k;
    for(int i = 0; i < n; i++) {
        if(votes_needed[i] <= remaining_votes) {
            result[i] = 0;
        } else {
            result[i] = votes_needed[i] - remaining_votes;
        }
        remaining_votes -= votes_needed[i];
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}