#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e8 * 2 + 10;
vector<int> sorted_a;

int binary_search(int target, int k) {
    int left = 0, right = sorted_a.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (sorted_a[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return sorted_a[left] == target ? left : -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    sorted_a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> sorted_a[i];
    }
    sort(sorted_a.begin(), sorted_a.end());
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        int index = binary_search(b, k);
        if (index != -1) {
            cout << abs(sorted_a[index] - b) << endl;
        } else {
            cout << "Invalid" << endl; // Handle the case when kth element does not exist
        }
    }
    return 0;
}