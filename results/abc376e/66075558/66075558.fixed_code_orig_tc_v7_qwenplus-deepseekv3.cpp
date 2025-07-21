#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int inf = 1LL << 60;

struct Element {
    int a, b;
};

bool compareA(const Element &x, const Element &y) {
    return x.a < y.a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Element> elements(N);
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].a;
        }
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].b;
        }
        
        sort(elements.begin(), elements.end(), compareA);
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_a = elements[i].a;
            int current_b = elements[i].b;
            
            if (pq.size() < K - 1) {
                pq.push(current_b);
                sum += current_b;
            } else {
                if (pq.size() > 0 && current_b < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(current_b);
                    sum += current_b;
                }
            }
            
            if (pq.size() == K - 1) {
                ans = min(ans, current_a * (sum + current_b));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}