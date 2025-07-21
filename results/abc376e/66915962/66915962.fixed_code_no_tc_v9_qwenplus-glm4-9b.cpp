#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i].second;
        }
        
        // Sort by A values, and secondarily by B values (ascending)
        sort(p.begin(), p.end(), [](const P& a, const P& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        ll ans = LLONG_MAX;
        ll sumB = 0;
        multiset<ll> sB; // Use multiset to handle duplicates efficiently
        
        for (int i = 0; i < k; ++i) {
            sumB += p[i].second;
            sB.insert(p[i].second);
        }
        
        // We are looking for the smallest possible maximum A_i multiplied by the sum of B_i's
        for (int i = 0; i < n - k; ++i) {
            // Remove the smallest B_i and add the next element
            auto it = sB.begin();
            sumB -= *it;
            sB.erase(it);
            sB.insert(p[i + k].second);
            sumB += p[i + k].second;
            
            // Calculate current answer
            ans = min(ans, p[i].first * sumB);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}