#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];

bool canPlaceAllToys(int x, int n, vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j = 0; // Index for boxes
    for (int i = 0; i < n; ++i) {
        while (j < n - 1 && B[j] < A[i]) {
            j++;
        }
        if (j == n - 1) return false; // No suitable box found for this toy
        j++; // Move to the next box
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i + 1];
    }

    int left = 1, right = 1e9, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceAllToys(mid, n, a, b)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}