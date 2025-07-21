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
        
        priority_queue<int> maxHeap;
        int sum = 0;
        int minProduct = inf;
        
        for (int i = 0; i < N; ++i) {
            int currentA = elements[i].a;
            int currentB = elements[i].b;
            
            if (maxHeap.size() < K - 1) {
                maxHeap.push(currentB);
                sum += currentB;
            } else {
                if (K == 1) {
                    minProduct = min(minProduct, currentA * currentB);
                } else {
                    minProduct = min(minProduct, currentA * (sum + currentB));
                }
                
                if (!maxHeap.empty() && currentB < maxHeap.top()) {
                    sum -= maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(currentB);
                    sum += currentB;
                }
            }
        }
        
        cout << minProduct << '\n';
    }
    return 0;
}