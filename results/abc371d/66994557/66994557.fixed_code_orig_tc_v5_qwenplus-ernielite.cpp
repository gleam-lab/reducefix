#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5; // 根据实际情况调整 MAXN 的值
int n, q, x[MAXN], p[MAXN], idxL, idxR; // 添加 idxL 和 idxR 来存储 L 和 R 的索引值
long long sum[MAXN]; // 使用 long long 以存储可能的较大前缀和值

// ... (其他代码保持不变) ...

int main(){
    // ... (输入和初始化保持不变) ...
    
    // 在主函数中添加代码来处理 L 和 R 的索引值
    cin >> q;
    while(q--){
        int L_val, R_val; // L 和 R 的值
        cin >> L_val >> R_val; // 从输入中读取 L 和 R 的值
        idxL = lower_bound(x + 1, x + n + 1, L_val) - x; // 找到 L 的索引值
        idxR = upper_bound(x + 1, x + n + 1, R_val) - x - 1; // 找到 R 的索引值并减一（因为二分查找会多算一个）
        // 现在 idxL 和 idxR 是正确的索引值，可以计算前缀和的差值并输出结果
        cout << sum[idxR] - sum[idxL - 1] << endl; // 注意 idxL - 1 来计算正确的差值（因为前缀和是从索引 1 开始的）
    }
}