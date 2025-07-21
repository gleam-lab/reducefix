#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (q--) {
        ll b, k;
        cin >> b >> k;
        
        // Binary search for the k-th closest point
        auto left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (a[mid] >= b - k && a[mid] <= b + k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        // Calculate the distance of the k-th closest point
        ll distance = abs(a[left] - b);
        cout << distance << endl;
    }
    
    return 0;
}