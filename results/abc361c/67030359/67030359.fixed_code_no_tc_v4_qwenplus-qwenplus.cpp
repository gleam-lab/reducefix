#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// This function checks if we can create a subsequence of length (N-K)
// where the max-min difference is <= target
bool canHaveMaxDiff(vi &A, int K, int target) {
    int n = sz(A);
    // We will use sliding window to find a window [left, right] such that:
    // A[right] - A[left] <= target
    // and there are at least (n - K) elements in this window
    int left = 0;
    for (int right = 0; right < n; ++right) {
        while (A[right] - A[left] > target) {
            left++;
        }
        if (right - left + 1 >= n - K) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(all(A));

    // Binary search on the answer: the minimum possible value of max(B) - min(B)
    int low = 0;
    int high = A.back() - A.front();
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canHaveMaxDiff(A, K, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}