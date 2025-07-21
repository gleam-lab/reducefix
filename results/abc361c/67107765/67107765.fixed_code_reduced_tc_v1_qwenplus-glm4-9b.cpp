#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    
    // Calculate the number of elements to take from each part
    int leftPart = (k + 1) / 2; // Elements to take from the lower part
    int rightPart = k / 2;     // Elements to take from the higher part

    // Calculate the range of indices for the left and right parts
    int leftBoundary = n - rightPart;
    int rightBoundary = n - leftPart;

    // Calculate the maximum difference
    int maxDiff = num[rightBoundary - 1] - num[leftBoundary];

    // Check for edge cases where we might need to adjust the boundary
    if (leftBoundary - 1 >= 0 && rightBoundary >= 0) {
        maxDiff = min(maxDiff, num[rightBoundary - 1] - num[leftBoundary - 1]);
    }
    if (leftBoundary > 0 && rightBoundary + 1 < n) {
        maxDiff = min(maxDiff, num[rightBoundary] - num[leftBoundary]);
    }

    cout << maxDiff << endl;
    return 0;
}