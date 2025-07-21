#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while(q--) {
        int b, k;
        cin >> b >> k;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < n; ++i) {
            int dist = abs(a[i] - b);
            if(pq.size() < k) {
                pq.push({dist, a[i]});
            } else if(dist < pq.top().first) {
                pq.pop();
                pq.push({dist, a[i]});
            }
        }
        
        cout << pq.top().first << endl;
    }
    
    return 0;
}