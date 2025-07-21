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
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<pair<ll, ll>> ab(n);
        rep(i, n) {
            cin >> a[i];
            ab[i] = {a[i], b[i]};
        }
        
        sort(ab.begin(), ab.end());

        ll sum_b = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        rep(i, k) {
            sum_b += ab[i].second;
            pq.push(-ab[i].second);
        }

        ll ans = -pq.top() * ab[k-1].first;

        rep2(i, k, n) {
            sum_b += ab[i].second + pq.top();
            pq.pop();
            pq.push(-ab[i].second);
            ans = min(ans, -pq.top() * ab[i].first);
        }

        cout << ans << '\n';
    }
    return 0;
}