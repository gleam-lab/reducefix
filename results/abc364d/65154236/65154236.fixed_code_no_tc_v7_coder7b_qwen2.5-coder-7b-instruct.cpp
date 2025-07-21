#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    a.resize(n + 1);
    b.resize(q + 1);
    k.resize(q + 1);

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
    }

    for(int i = 1; i <= q; ++i) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int j = 1; j <= n; ++j) {
            int dist = abs(a[j] - b[i]);
            pq.push(dist);
            if(pq.size() > k[i]) 
                pq.pop();
        }
        cout << pq.top() << '\n';
    }

    return 0;
}