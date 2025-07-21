#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<pair<ll, ll>> a(n), b(n);
        
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for(int i = 0; i < n; ++i){
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<ll> pq;
        ll sum = 0, ans = LLONG_MAX;
        
        for(int i = 0; i < n; ++i){
            pq.push(b[i].first);
            sum += b[i].first;
            
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k){
                ans = min(ans, (sum + b[i].first) * a[i + 1].first);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}