#include <bits/stdc++.h>

using namespace std;

// #define ls p << 1
// #define rs p << 1 | 1
#define x first
#define y second

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 100010;
const LL inf = 2e18;

void solve(){
    int n;
    std::string s;
    std::cin >> n >> s;

    s = " " + s;
    std::vector dp((n + 1), std::vector<int> (2, 0));

    dp[1][1] = 1, dp[1][0] = 0;
    for (int i = 2; i <= n; i ++){
        if (s[i] == s[i - 1]){

            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1];

        }else {

            if (s[i] == 'R'){

                if (s[i - 1] == 'S'){
                    dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + 1;
                    dp[i][0] = dp[i - 1][0];
                }
                if (s[i - 1] == 'P'){
                    dp[i][1] = dp[i - 1][1] + 1;
                    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                }
            }
            
            if (s[i] == 'S'){

                if (s[i - 1] == 'R'){
                    dp[i][1] = dp[i - 1][1] + 1;
                    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                }
                if (s[i - 1] == 'P'){
                    dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + 1;
                    dp[i][0] = dp[i - 1][0];
                }
            }

            if (s[i] == 'P'){

                if (s[i - 1] == 'R'){
                    dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) + 1;
                    dp[i][0] = dp[i - 1][0];
                }
                if (s[i - 1] == 'S'){
                    dp[i][1] = dp[i - 1][1] + 1;
                    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                }
            }

        }
    }

    // for (int j = 0; j < 2; j ++){
    //     for (int i = 1; i <= n; i ++) std::cout << dp[i][j] << ' ';
    //     std::cout << '\n';
    // }

    std::cout << std::max(dp[n][0], dp[n][1]) << '\n';
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