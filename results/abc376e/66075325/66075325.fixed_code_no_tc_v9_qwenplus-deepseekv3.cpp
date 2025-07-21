#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

struct Element {
    int a, b;
};

bool compareA(const Element &x, const Element &y) {
    return x.a < y.a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Element> elements(n);
        for (int i = 0; i < n; i++) {
            cin >> elements[i].a;
        }
        for (int i = 0; i < n; i++) {
            cin >> elements[i].b;
        }
        
        sort(elements.begin(), elements.end(), compareA);
        
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; i++) {
            if (i >= k - 1) {
                int current_max_a = elements[i].a;
                int current_sum = sum + elements[i].b;
                ans = min(ans, current_max_a * current_sum);
            }
            sum += elements[i].b;
            max_heap.push(elements[i].b);
            if (max_heap.size() >= k) {
                sum -= max_heap.top();
                max_heap.pop();
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}