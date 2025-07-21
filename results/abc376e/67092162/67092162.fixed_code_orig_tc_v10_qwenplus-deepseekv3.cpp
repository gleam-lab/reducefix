#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> p[i].second;
        }
        
        sort(p, p + N);
        
        priority_queue<int> pq;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < N; ++i) {
            sum += p[i].second;
            pq.push(p[i].second);
            
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == K) {
                ans = min(ans, sum * p[i].first);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}