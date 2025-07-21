#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n, m;
    cin >> n >> m;

    set<pair<long long, long long>> pieces;

    for(long long i=0; i<m; i++) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        if(a+2<=n && b+1<=n) pieces.insert({a+2, b+1});
        if(a+1<=n && b+2<=n) pieces.insert({a+1, b+2});
        if(a-1>=1   && b+2<=n) pieces.insert({a-1, b+2});
        if(a-2>=1   && b+1<=n) pieces.insert({a-2, b+1});
        if(a-2>=1   && b-1>=1) pieces.insert({a-2, b-1});
        if(a-1>=1   && b-2>=1) pieces.insert({a-1, b-2});
        if(a+1<=n   && b-2>=1) pieces.insert({a+1, b-2});
        if(a+2<=n   && b-1>=1) pieces.insert({a+2, b-1});
    }

    long long ans = n*n - pieces.size();
    cout << ans << endl;

    return 0;
}