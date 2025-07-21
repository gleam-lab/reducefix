#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        vector<ll> distances(N);
        rep(j, N) {
            distances[j] = abs(a[j] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << "\n";
    }

    return 0;
}