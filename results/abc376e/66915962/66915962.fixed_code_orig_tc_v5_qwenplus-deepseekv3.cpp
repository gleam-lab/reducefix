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
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());

        priority_queue<ll, vector<ll>, greater<ll>> min_heap;
        ll sumB = 0;
        ll ans = LINF;

        rep(i, n){
            ll a = p[i].first;
            ll b = p[i].second;
            if(min_heap.size() < k){
                min_heap.push(b);
                sumB += b;
            } else if(b > min_heap.top()){
                sumB -= min_heap.top();
                min_heap.pop();
                min_heap.push(b);
                sumB += b;
            }
            if(min_heap.size() == k){
                ans = min(ans, a * sumB);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}