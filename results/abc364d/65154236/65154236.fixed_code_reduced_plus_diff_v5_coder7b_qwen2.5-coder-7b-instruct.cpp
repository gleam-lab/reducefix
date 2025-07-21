#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> results(q);
    for (int qi = 0; qi < q; ++qi) {
        int b, k;
        cin >> b >> k;
        
        // Priority queue to store distances
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int ai : a) {
            int dist = abs(b - ai);
            pq.push(dist);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The top of the heap is the k-th smallest distance
        results[qi] = pq.top();
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}