#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int INF = 1e18;

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
        for (int i = 0; i < N; i++) cin >> elements[i].a;
        for (int i = 0; i < N; i++) cin >> elements[i].b;
        
        sort(elements.begin(), elements.end(), compareA);
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_b = 0;
        vector<int> suffix_sum(N + 1, 0);
        
        for (int i = N - 1; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1];
            if (min_heap.size() < K - 1) {
                min_heap.push(elements[i].b);
                suffix_sum[i] += elements[i].b;
            } else if (!min_heap.empty() && elements[i].b > min_heap.top()) {
                suffix_sum[i] -= min_heap.top();
                min_heap.pop();
                min_heap.push(elements[i].b);
                suffix_sum[i] += elements[i].b;
            }
        }
        
        while (!min_heap.empty()) min_heap.pop();
        sum_b = 0;
        
        int min_product = INF;
        for (int i = 0; i < N; i++) {
            if (i + 1 >= K) {
                int current_max = elements[i].a;
                int current_sum = sum_b + elements[i].b;
                if (K > 1) current_sum += suffix_sum[i + 1];
                min_product = min(min_product, current_max * current_sum);
            }
            
            if (K > 1) {
                if (min_heap.size() < K - 1) {
                    min_heap.push(elements[i].b);
                    sum_b += elements[i].b;
                } else if (!min_heap.empty() && elements[i].b > min_heap.top()) {
                    sum_b -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(elements[i].b);
                    sum_b += elements[i].b;
                }
            }
        }
        
        cout << min_product << '\n';
    }
    return 0;
}