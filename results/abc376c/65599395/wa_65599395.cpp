#include <bits/stdc++.h>

using namespace std;

// #define ls p << 1
// #define rs p << 1 | 1
#define x first
#define y second

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

void solve(){
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i ++) std::cin >> a[i];
    for (int i = 0; i + 1 < n; i ++) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (int i = 0; i + 1 < n; i ++){
        if (a[i] > b[i]){
            std::cout << -1 << '\n';
            return;
        }
    }

    for (int i = n - 1; i >= 1; i --){
        if (a[i] > b[i - 1]){
            std::cout << a[i] << '\n';
            return;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int T = 1;
    // std::cin >> T;

    while (T --){
        solve();
    }

    return 0;
}