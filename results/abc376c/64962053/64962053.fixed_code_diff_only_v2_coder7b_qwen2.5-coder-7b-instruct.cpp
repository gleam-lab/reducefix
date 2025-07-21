#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.rbegin(), a.rend()); // Sort in descending order for easier processing
    sort(b.rbegin(), b.rend()); // Sort in descending order for easier processing

    long long max_needed = 0; // Variable to keep track of the maximum size needed
    for(int i = 0; i < n - 1; ++i) {
        if(b[i] >= a[i]) // If the current box can hold the current toy
            continue;
        else { // If the current box cannot hold the current toy
            if(i == 0 || b[i - 1] < a[i]) // If we're at the first box or the previous box couldn't hold the previous toy
                max_needed = max(max_needed, a[i]); // Update the maximum size needed
            else // If the previous box could hold the previous toy
                max_needed = max(max_needed, a[i] + b[i - 1] - b[i]); // Calculate the new size needed
        }
    }

    if(max_needed == 0) // If no additional box was needed
        cout << "1"; // We need at least one box of size 1
    else
        cout << max_needed; // Output the minimum size needed

    return 0;
}