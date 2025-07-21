#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> p(N);
        for (int i = 0; i < N; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> p[i].second;
        }
        
        sort(p.begin(), p.end());
        
        priority_queue<int> q;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < N; ++i) {
            sum += p[i].second;
            q.push(p[i].second);
            
            if (q.size() > K) {
                sum -= q.top();
                q.pop();
            }
            
            if (q.size() == K) {
                ans = min(ans, p[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}