#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while(Q--){
        ll b, k;
        cin >> b >> k;
        vector<ll> distances;
        int left = lower_bound(a.begin(), a.end(), b) - a.begin();
        int right = left;
        int count = 0;
        vector<ll> temp_dist;
        
        // Collect distances around the query point
        int l = left - 1, r = left;
        while(count < k && (l >= 0 || r < N)){
            ll dist_l = (l >= 0) ? abs(a[l] - b) : LLONG_MAX;
            ll dist_r = (r < N) ? abs(a[r] - b) : LLONG_MAX;
            if(dist_l <= dist_r){
                temp_dist.push_back(dist_l);
                l--;
            } else {
                temp_dist.push_back(dist_r);
                r++;
            }
            count++;
        }
        sort(temp_dist.begin(), temp_dist.end());
        cout << temp_dist[k-1] << '\n';
    }
    return 0;
}