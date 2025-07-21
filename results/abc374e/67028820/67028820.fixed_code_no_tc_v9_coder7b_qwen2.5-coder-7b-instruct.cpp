#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

// Function to check if we can make at least 'mid' items within budget 'x'
bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate the number of items we can produce with 'a[i]' cost per item
        int x = mid / a[i];
        total_cost += x * p[i]; // Add the cost of producing these items
        mid -= x * a[i]; // Decrease the remaining items we need to produce
        
        // If there are still items left, calculate how many more we can produce with 'b[i]' cost per item
        if (mid > 0) {
            x = mid / b[i];
            total_cost += x * q[i]; // Add the cost of producing these additional items
            mid -= x * b[i]; // Decrease the remaining items we need to produce
        }
    }
    
    // Check if the total cost is within the budget
    return (int)(ceil(total_cost)) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}