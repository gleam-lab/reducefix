#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    cin >> n;
    vector<int> coords(n);
    for (int i = 0; i < n; ++i) {
        cin >> coords[i];
        coords[i] -= coords[0]; // Adjusting coordinates to be relative to the first village
    }
    sort(coords.begin(), coords.end());
    unordered_map<int, int> coordIndex;
    for (int i = 0; i < n; ++i) {
        coordIndex[coords[i]] = i;
    }

    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l -= coords[0];
        r -= coords[0];
        int l_index = binarySearch(coords, l);
        int r_index = binarySearch(coords, r);
        if (l_index != -1 && r_index != -1) {
            cout << a[r_index] - a[l_index] << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}