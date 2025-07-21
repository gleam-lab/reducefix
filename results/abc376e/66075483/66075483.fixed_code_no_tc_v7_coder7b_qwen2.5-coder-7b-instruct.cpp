#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
pair<int, int> a[N], b[N];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort both arrays based on their first elements
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        int sumB = 0, maxA = -1;
        priority_queue<int> pq;

        for(int i = 0; i < n; ++i){
            sumB += b[i].first;
            pq.push(b[i].first);

            if(pq.size() > k){
                sumB -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                maxA = a[i+1].first;
                ans = min(ans, maxA * sumB);
            }
        }

        cout << ans << endl;
    }
    return 0;
}