#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, q;
vector<int> a(N);
vector<pair<int, int>> queries;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }
    
    // Sort points A and queries by the coordinates of B
    sort(a.begin(), a.end());
    sort(queries.begin(), queries.end());
    
    vector<int> answers(q);
    
    // Process each query
    for (int i = 0; i < q; i++) {
        auto& [b, k] = queries[i];
        int lb = lower_bound(a.begin(), a.end(), b) - a.begin(); // 1-based index
        answers[i] = a[lb + k - 1] - b; // k-th closest means lb + k - 1 index in sorted A
    }
    
    // Output all answers
    for (int ans : answers) {
        cout << ans << '\n';
    }
    
    return 0;
}