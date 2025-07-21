#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];
int bb[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> bb[i];
        }
        
        // Sort the array a in increasing order of A_i
        sort(a, a + n);
        
        // Rearrange B according to the sorted A
        for (int i = 0; i < n; ++i) {
            b[i] = {bb[a[i].second], a[i].first};
        }
        
        int ans = inf;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (int i = 0; i < n; ++i) {
            int current_b = b[i].first;
            int current_a = b[i].second;
            
            if (min_heap.size() < k - 1) {
                min_heap.push(current_b);
                sum += current_b;
            } else {
                if (k > 1 && current_b > min_heap.top()) {
                    sum -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(current_b);
                    sum += current_b;
                }
            }
            
            if (min_heap.size() == k - 1) {
                int total_sum = sum + current_b;
                int current_val = current_a * total_sum;
                if (current_val < ans) {
                    ans = current_val;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}