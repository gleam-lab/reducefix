#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, k;
int a[N];
int b[N];
int b_sum[N];
int a_index[N];

void solve() {
    cin >> n >> k;
    long long sum_k_elements = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a_index[i] = i;
        cin >> b[i];
        b_sum[i] = b[i];
    }

    // Sort indices based on A values in descending order
    sort(a_index, a_index + n, [&](int i, int j) {
        return a[i] > a[j];
    });

    // Calculate initial sum of the first k elements in B
    for (int i = 0; i < k; ++i) {
        q.push(b[a_index[i]]);
        sum_k_elements += b[a_index[i]];
    }

    long long min_product = (long long)sum_k_elements * a[a_index[0]];

    // Sliding window over the sorted indices
    for (int i = k; i < n; ++i) {
        sum_k_elements -= q.top();
        q.pop();
        sum_k_elements += b[a_index[i]];
        q.push(b[a_index[i]]);
        min_product = min(min_product, (long long)sum_k_elements * a[a_index[i]]);
    }

    cout << min_product << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}