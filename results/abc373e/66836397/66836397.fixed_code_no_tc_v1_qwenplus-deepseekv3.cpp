#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m, K;
    cin >> n >> m >> K;
    ll total_votes = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total_votes += a[i];
    }
    ll remaining = K - total_votes;

    vector<ll> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    auto find_min_votes = [&](ll candidate_votes) {
        ll low = 0, high = remaining;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll new_votes = candidate_votes + mid;
            
            // Find how many candidates have more votes than new_votes
            ll pos = upper_bound(sorted_a.begin(), sorted_a.end(), new_votes) - sorted_a.begin();
            ll upper_count = n - pos;
            
            if(upper_count < m){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    };

    for(int i = 0; i < n; i++){
        ll min_votes = find_min_votes(a[i]);
        if(min_votes != -1 && min_votes <= remaining){
            cout << min_votes;
        } else {
            cout << -1;
        }
        if(i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}