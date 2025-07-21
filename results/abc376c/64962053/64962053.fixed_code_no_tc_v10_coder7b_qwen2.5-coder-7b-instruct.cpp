#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.rbegin(), a.rend()); // Sort toys in descending order
    sort(b.begin(), b.end()); // Sort boxes in ascending order

    long long sum = 0;
    for(int i = 0; i < n - 1; ++i) {
        sum += b[i]; // Sum up sizes of available boxes
        if(sum >= a[i]) { // Check if current sum of boxes can accommodate the largest toy
            cout << a[i] << '\n'; // The required box size is at least as large as the largest toy
            return 0;
        }
    }

    cout << max(sum + 1, a[n - 1]) << '\n'; // If not, take the maximum of the next box size or the largest toy size
    return 0;
}