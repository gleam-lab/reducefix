#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    rep(i, q) {
        int b, k;
        cin >> b >> k;
        vector<int> distances;
        for(int ai : a) {
            distances.push_back(abs(ai - b));
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k-1] << "\n";
    }
    return 0;
}