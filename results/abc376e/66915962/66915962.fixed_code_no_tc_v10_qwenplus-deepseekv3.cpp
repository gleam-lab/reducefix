#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr ll LINF = 1001001001001001001ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        for(int i = 0; i < n; ++i) cin >> p[i].first;
        for(int i = 0; i < n; ++i) cin >> p[i].second;
        
        sort(p.begin(), p.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        ll sum_b = 0;
        ll ans = LINF;
        
        for(int i = 0; i < n; ++i){
            ll a_i = p[i].first;
            ll b_i = p[i].second;
            
            if(min_heap.size() < k - 1){
                min_heap.push(b_i);
                sum_b += b_i;
            } else {
                if(!min_heap.empty() && b_i > min_heap.top()){
                    sum_b -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(b_i);
                    sum_b += b_i;
                }
            }
            
            if(min_heap.size() == k - 1){
                ans = min(ans, a_i * (sum_b + b_i));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}