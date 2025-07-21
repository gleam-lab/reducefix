#include<bits/stdc++.h>
using namespace std;

int n, m, a[400005], an;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];  // This line is correct as it's supposed to copy the element i times forward.
    }
    for (int i = 1; i < 2 * n; i++) {
        an += a[i];  // Directly add a[i] to an without handling the t and w arrays.
    }
    cout << an;
    return 0;
}