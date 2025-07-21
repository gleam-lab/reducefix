#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<numeric>
#include <iomanip>

using namespace std;
using ll = long long;

const double PI = acos(-1.0);

int main()
{
    int N;
    cin >> N;
    vector<ll>H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    ll T = 0;
    for (int i = 0; i < N; i++)
    {
        T += H[i] / 3;
        T++;
        if (T % 3 == 0)
        {
            if (H[i] % 3 == 2)T++;
        }
        else if (T % 3 == 1)
        {
            if (H[i] % 3 == 1)T++;
        }
        else
        {
            if (H[i] % 3 >= 2)T++;
        }
    }
    cout << T << endl;
}