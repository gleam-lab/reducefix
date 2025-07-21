#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<pair<ll, ll>> p(n);
        
        rep(i, n){
            cin >> p[i].first >> p[i].second;
        }
        
        sort(p.rbegin(), p.rend()); // Sort in descending order based on the first element
        
        ll max_a = 0;
        ll sum_b = 0;
        
        rep(i, k){
            max_a = max(max_a, p[i].first);
            sum_b += p[i].second;
        }
        
        ll result = max_a * sum_b;
        
        rep2(i, k, n){
            max_a = max(max_a, p[i].first);
            sum_b -= p[i-k].second; // Remove the smallest element from sum_b
            sum_b += p[i].second; // Add the current element to sum_b
            
            result = min(result, max_a * sum_b);
        }
        
        cout << result << '\n';
    }
    return 0;
}