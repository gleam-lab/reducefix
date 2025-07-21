#include <iostream>
#include <algorithm>
using namespace std;

#define INF (long long)(1e18)

long long maxSumTwoNonAdjacent(long long arr[], int n) {
    long long max_sum = 0;
    long long incl = 0; // Sum including the previous element
    long long excl = 0; // Sum excluding the previous element
    
    for (int i = 0; i < n; i++) {
        long long new_excl = max(incl, excl); // New excl sum is max of prev incl and excl
        incl = excl + arr[i]; // Current incl sum is prev excl + current element
        excl = new_excl; // Update excl to new_excl
        max_sum = max(max_sum, incl); // Update max sum
    }
    
    return max(max_sum, excl); // Return max of incl and excl as last element doesn't need to be excluded
}

int main() {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSumTwoNonAdjacent(arr, n) << endl;
    return 0;
}