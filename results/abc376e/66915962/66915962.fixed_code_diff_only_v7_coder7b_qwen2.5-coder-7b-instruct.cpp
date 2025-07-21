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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];

        // Create pairs and sort based on A values
        vector<pair<ll, ll>> ab(n);
        rep(i, n) ab[i] = {a[i], b[i]};
        sort(ab.begin(), ab.end());

        // Use a max heap to maintain the largest K elements of B
        priority_queue<ll> pq;
        ll sumB = 0;
        rep(i, n){
            pq.push(ab[i].second);
            sumB += ab[i].second;
        }

        // Initialize answer with the first K elements
        ll ans = LLONG_MAX;
        rep(i, k){
            ans = min(ans, ab[i].first * sumB);
        }

        // Slide the window across the array
        rep2(i, k, n){
            sumB -= pq.top();
            pq.pop();
            pq.push(ab[i].second);
            sumB += ab[i].second;
            ans = min(ans, ab[i].first * sumB);
        } 

        cout << ans << '\n';
    }
}