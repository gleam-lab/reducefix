#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
const int inf = 1e18;

struct Element {
    int A, B;
};

bool compareA(const Element &x, const Element &y) {
    return x.A < y.A;
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
            cin >> elements[i].A;
        }
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].B;
        }
        
        sort(elements.begin(), elements.end(), compareA);
        
        priority_queue<int> max_heap;
        int sum_B = 0;
        int min_result = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = elements[i].A;
            int current_B = elements[i].B;
            
            int current_sum = sum_B + current_B;
            if (max_heap.size() == K - 1) {
                min_result = min(min_result, current_A * current_sum);
            }
            
            max_heap.push(current_B);
            sum_B += current_B;
            
            if (max_heap.size() > K - 1) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }
        }
        
        cout << min_result << '\n';
    }
    return 0;
}