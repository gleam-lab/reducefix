#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < N; ++i) {
        pq.push({H[i], i});
    }
    
    ll T = 0;
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        ll h = current.first;
        int idx = current.second;
        
        if (h <= 0) continue;
        
        T++;
        ll damage = (T % 3 == 0) ? 3 : 1;
        h -= damage;
        
        if (h > 0) {
            pq.push({h, idx});
        }
    }
    
    cout << T << endl;
    return 0;
}