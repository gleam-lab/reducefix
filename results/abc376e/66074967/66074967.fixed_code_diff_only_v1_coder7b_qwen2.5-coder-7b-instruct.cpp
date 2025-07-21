#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 1000000009;
int n, k, t, ans;

struct Data{
    int val, id;
};

bool cmp(Data &a, Data &b){
    return a.val > b.val;
}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<Data> a(n+1), b(n+1);

        for(int i=1;i<=n;i++){
            cin >> a[i].val;
            a[i].id = i;
        }

        for(int i=1;i<=n;i++){
            cin >> b[i].val;
            b[i].id = i;
        }

        sort(a.begin()+1, a.end(), cmp);
        sort(b.begin()+1, b.end());

        priority_queue<int> pq;
        long long sum = 0;

        for(int i=1;i<k;i++){
            pq.push(b[i].val);
            sum += b[i].val;
        }

        ans = inf;

        for(int i=k;i<=n;i++){
            sum += b[i].val;
            pq.push(b[i].val);
            ans = min(ans, (long long)a[i].val * (sum));
            sum -= pq.top();
            pq.pop();
        }

        cout << ans << '\n';
    }
    return 0;
}