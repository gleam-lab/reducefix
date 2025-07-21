#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, k;
vector<int> A, B;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> n >> k;
        A.assign(n + 1, 0);
        B.assign(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> B[i];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        long long sum = 0, ans = LLONG_MAX;
        
        for (int i = 1; i <= n; ++i) {
            heap.push({B[i], i});
            sum += B[i];
            
            if (heap.size() > k) {
                sum -= heap.top().first;
                heap.pop();
            }
            
            if (heap.size() == k) {
                ans = min(ans, A[i] * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}