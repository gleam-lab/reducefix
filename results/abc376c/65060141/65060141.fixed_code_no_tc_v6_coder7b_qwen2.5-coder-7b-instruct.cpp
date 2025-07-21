#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canPlace(int x, vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> boxes(n, x); // Initialize all boxes with size x
    for(int i = 0; i < n - 1; ++i) {
        if(boxes[b[i] - 1] >= a[i]) {
            boxes[b[i] - 1] -= a[i]; // Place toy i in box b[i]
        } else {
            return false; // Cannot place toy i
        }
    }
    return true;
}

int minBoxSize(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end()); // Sort toy sizes
    sort(b.begin(), b.end()); // Sort box sizes
    int low = *max_element(a.begin(), a.end()); // Minimum toy size
    int high = 1e9; // Maximum possible box size
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canPlace(mid, a, b)) {
            high = mid - 1; // Try smaller box size
        } else {
            low = mid + 1; // Need larger box size
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    int result = minBoxSize(a, b);
    cout << result << endl;
    return 0;
}