#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    if (k == 0) {
        int min_val = *min_element(A.begin(), A.end());
        int max_val = *max_element(A.begin(), A.end());
        cout << max_val - min_val << "\n";
        return 0;
    }

    // We need to remove exactly K elements to minimize the difference between max and min in the remaining elements

    // Consider all windows of size (n - k) and find the one with minimal (max - min)
    int window_size = n - k;
    deque<int> max_deque;
    deque<int> min_deque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Remove elements out of the window
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }

        // Add current element to deques
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }

        max_deque.push_back(i);
        min_deque.push_back(i);

        // Once the window is full, update result
        if (i >= window_size - 1) {
            chmin(result, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << result << "\n";
    return 0;
}