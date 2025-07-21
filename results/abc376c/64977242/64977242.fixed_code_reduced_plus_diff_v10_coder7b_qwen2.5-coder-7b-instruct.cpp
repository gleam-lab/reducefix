#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

bool canPlaceToys(vector<int>& A, vector<int>& B, int size) {
    int n = A.size();
    vector<bool> used(n, false);

    for(int i = 0; i < n - 1; ++i) {
        auto it = upper_bound(B.begin(), B.end(), A[i], [&](int b, int a){ return b >= a; });
        if(it == B.end()) {
            return false;
        }
        while(it != B.end() && used[it - B.begin()] || *it < A[i]) {
            ++it;
        }
        if(it == B.end()) {
            return false;
        }
        used[it - B.begin()] = true;
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int left = 0, right = INT_MAX;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(canPlaceToys(A, B, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if(left <= A.back()) {
        cout << left << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}