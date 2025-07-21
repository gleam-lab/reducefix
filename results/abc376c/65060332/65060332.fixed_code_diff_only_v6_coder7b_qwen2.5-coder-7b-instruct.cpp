#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll a[N], b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    int j = n - 1;
    for(int i = n; i >= 1; i--) {
        if(j < 1 || b[j] < a[i]) {
            cout << -1 << endl;
            return 0;
        } else {
            j--;
        }
    }

    cout << a[n] << endl;

    return 0;
}