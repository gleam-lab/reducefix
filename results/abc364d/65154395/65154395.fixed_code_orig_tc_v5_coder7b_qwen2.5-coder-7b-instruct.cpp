#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

typedef long long ll;

const int MAXN = 100005;
vector<int> a(MAXN);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int qi = 0; qi < q; ++qi) {
        int b, k; cin >> b >> k;
        
        // Min-heap to store the k closest distances
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int ai = 0; ai < n; ++ai) {
            int dist = abs(a[ai] - b);
            if(pq.size() < k) {
                pq.push(dist);
            } else if(dist < pq.top()) {
                pq.pop();
                pq.push(dist);
            }
        }
        
        // The root of the heap will be the k-th smallest distance
        cout << pq.top() << endl;
    }

    return 0;
}