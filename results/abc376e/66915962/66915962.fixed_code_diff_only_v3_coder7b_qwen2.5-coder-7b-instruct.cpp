#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        vector<pair<ll, int>> ab(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ab[i] = {a[i], i};
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        sort(ab.begin(), ab.end());
        
        ll max_a = 0;
        ll sum_b = 0;
        for (int i = 0; i < k; ++i) {
            max_a = max(max_a, a[ab[i].second]);
            sum_b += b[ab[i].second];
        }
        
        ll result = max_a * sum_b;
        
        for (int i = k; i < n; ++i) {
            max_a = max(max_a, a[ab[i].second]);
            sum_b += b[ab[i].second] - b[ab[i - k].second];
            result = min(result, max_a * sum_b);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}