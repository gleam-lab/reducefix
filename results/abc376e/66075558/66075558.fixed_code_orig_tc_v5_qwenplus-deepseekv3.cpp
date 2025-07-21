#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int inf = 1e18;

struct Element {
    int a, b;
};

bool compareA(const Element& x, const Element& y) {
    return x.a < y.a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].a;
        }
        for (int i = 0; i < n; ++i) {
            cin >> elements[i].b;
        }
        
        sort(elements.begin(), elements.end(), compareA);
        
        priority_queue<int> max_heap;
        int sum_heap = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_a = elements[i].a;
            int current_b = elements[i].b;
            
            if (max_heap.size() < k - 1) {
                max_heap.push(current_b);
                sum_heap += current_b;
            } else {
                if (k == 1) {
                    ans = min(ans, current_a * current_b);
                } else {
                    ans = min(ans, current_a * (sum_heap + current_b));
                }
                
                if (!max_heap.empty() && current_b < max_heap.top()) {
                    sum_heap -= max_heap.top();
                    max_heap.pop();
                    max_heap.push(current_b);
                    sum_heap += current_b;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}