#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        int pos = lower_bound(a, a + N, b) - a;
        
        vector<int> distances;
        int i = pos - 1, j = pos;
        while (distances.size() < N) {
            if (i >= 0 && (j >= N || b - a[i] <= a[j] - b)) {
                distances.push_back(b - a[i]);
                --i;
            } else {
                distances.push_back(a[j] - b);
                ++j;
            }
        }
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}