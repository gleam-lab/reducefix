#include <bits/stdc++.h>
using namespace std;

bool canPlaceAllToys(int mid, const vector<int>& A, const vector<int>& B) {
    vector<bool> used(B.size(), false);
    for (int toy : A) {
        bool placed = false;
        for (int i = 0; i < B.size(); ++i) {
            if (!used[i] && B[i] >= toy) {
                used[i] = true;
                placed = true;
                break;
            }
        }
        if (!placed) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int low = 1;
    int high = *max_element(A.begin(), A.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceAllToys(mid, A, B)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low > *max_element(A.begin(), A.end())) {
        cout << "-1" << endl;
    } else {
        cout << low << endl;
    }

    return 0;
}