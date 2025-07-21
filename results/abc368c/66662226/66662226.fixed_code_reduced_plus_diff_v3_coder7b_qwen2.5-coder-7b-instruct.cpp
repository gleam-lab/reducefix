#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    long long t = 0;
    for(int i = 0; i < n;) {
        if(h[i] <= 0) {
            i++;
            continue;
        }

        t++;
        if(t % 3 == 0)
            h[i] -= 3;
        else
            h[i]--;

        if(h[i] <= 0)
            i++;
    }

    cout << t << endl;
}