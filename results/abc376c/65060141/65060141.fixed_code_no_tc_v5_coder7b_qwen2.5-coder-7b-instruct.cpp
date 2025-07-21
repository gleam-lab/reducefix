#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll a[N], b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i)
        cin >> b[i];
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // Find the maximum size of box needed which is greater than or equal to the largest toy size
    int mx_a = *max_element(a + 1, a + n + 1);
    int ans = -1;

    for(int i = 0; i < n - 1; ++i) {
        if(b[i] >= mx_a) {
            ans = b[i];
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}