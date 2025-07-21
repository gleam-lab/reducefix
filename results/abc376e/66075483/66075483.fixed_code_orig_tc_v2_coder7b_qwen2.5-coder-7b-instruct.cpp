#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

struct Element {
    ll value, index;
};

bool compare(Element a, Element b) {
    return a.value > b.value;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<Element> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].value;
            A[i].index = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i].value;
            B[i].index = i;
        }

        // Sort A based on values in descending order
        sort(A.begin(), A.end(), compare);

        // Sort B based on indices of elements in A
        sort(B.begin(), B.end(), [&](Element a, Element b) {
            return A[a.index].index < A[b.index].index;
        });

        // Initialize variables
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll currentSum = 0;
        ll ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            pq.push(B[i].value);
            currentSum += B[i].value;

            // Maintain the size of the queue as k
            if (pq.size() > k) {
                currentSum -= pq.top();
                pq.pop();
            }

            // Calculate the result if we have at least k elements
            if (pq.size() == k) {
                ans = min(ans, A[i].value * currentSum);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}