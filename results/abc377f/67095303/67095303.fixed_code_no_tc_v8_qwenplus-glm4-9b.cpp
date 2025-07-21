#include<bits/stdc++.h>
#define long long int
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long total_squares = n * n;
    long long occupied = 0;

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        occupied += (n - (a - 1)) * (n - b) * 4;
    }

    // Subtract the corners since they are counted four times
    occupied -= 4ll * (n - 2);

    // The remaining squares are the total squares minus the occupied squares
    cout << total_squares - occupied << endl;
    return 0;
}