#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
#define int long long
const int N = 2e5 + 9;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    vector<int> B(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    set<pair<int, int>> maxHeap; // stores pairs of (B[i], i) to keep track of the sum of B[i] for top k A[i]

    long long ans = LLONG_MAX;
    long long sumB = 0;

    for (int i = 1; i <= n; i++) {
        sumB += B[i];
        maxHeap.insert({B[i], i});

        if (maxHeap.size() > k) {
            sumB -= maxHeap.begin()->first; // remove the smallest B[i] from sumB
            maxHeap.erase(maxHeap.begin());
        }

        if (maxHeap.size() == k) {
            int sumBk = sumB - maxHeap.begin()->first; // sum of B for the current top k elements
            int maxAk = A[maxHeap.begin()->second]; // maximum A[i] for the current top k elements
            ans = min(ans, maxAk * sumBk);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}