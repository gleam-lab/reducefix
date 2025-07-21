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
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int currentA = elements[i].a;
            int currentB = elements[i].b;
            
            if (minHeap.size() == K - 1) {
                ans = min(ans, currentA * (sum + currentB));
            }
            
            if (minHeap.size() < K - 1) {
                minHeap.push(currentB);
                sum += currentB;
            } else if (!minHeap.empty() && currentB > minHeap.top()) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(currentB);
                sum += currentB;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}