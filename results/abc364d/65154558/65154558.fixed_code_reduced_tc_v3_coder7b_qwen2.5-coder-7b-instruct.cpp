#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int qi = 0; qi < q; ++qi) {
        int bj, kj;
        cin >> bj >> kj;

        // Priority queue to store distances
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int ai : a) {
            int dist = abs(ai - bj);
            pq.push(dist);
            if(pq.size() > kj) {
                pq.pop(); // Keep only the k smallest distances
            }
        }

        // The top of the heap is the k-th smallest distance
        cout << pq.top() << '\n';
    }

    return 0;
}