#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> A(n), B(n);
        for(int i = 0; i < n; ++i){
            cin >> A[i].first;
            A[i].second = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> B[i].first;
            B[i].second = i;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        priority_queue<int> pq;
        int sum = 0, ans = INF;
        for(int i = 0; i < n; ++i){
            pq.push(B[i].first);
            sum += B[i].first;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(i >= k-1){
                ans = min(ans, static_cast<long long>(A[i+1].first) * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}