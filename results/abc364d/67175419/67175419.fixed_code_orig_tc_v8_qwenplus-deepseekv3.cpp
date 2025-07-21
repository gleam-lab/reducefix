#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    while(q--) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = n-1;
        // We will use a priority queue to keep track of the k closest elements
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; ++i) {
            int dist = abs(a[i] - b);
            if(pq.size() < k) {
                pq.push({dist, a[i]});
            } else {
                if(dist < pq.top().first) {
                    pq.pop();
                    pq.push({dist, a[i]});
                }
            }
        }
        cout << pq.top().first << "\n";
    }
    return 0;
}