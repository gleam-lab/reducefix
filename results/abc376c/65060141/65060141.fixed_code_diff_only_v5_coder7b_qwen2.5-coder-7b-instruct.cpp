#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = n - 2, ans = -1;
    for(int i = n - 1; i >= 0; --i) {
        while(j >= 0 && b[j] < a[i])
            --j;

        if(j >= 0) {
            ans = a[i];
            break;
        }
    }

    cout << ans << endl;
    return 0;
}