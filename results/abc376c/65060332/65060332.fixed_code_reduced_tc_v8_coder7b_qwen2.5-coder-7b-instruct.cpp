#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<ll> a, b;

bool canPlaceAllToys(int boxSize) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int j = 0;
    for (int i = 0; i < b.size(); ++i) {
        while (j < a.size() && a[j] <= b[i]) {
            ++j;
        }
    }
    
    return j == a.size();
}

int main() {
    int n;
    cin >> n;
    
    a.resize(n + 1);
    b.resize(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    // Binary search for the minimum box size
    int low = 1, high = *max_element(a.begin(), a.end()) + 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceAllToys(mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}