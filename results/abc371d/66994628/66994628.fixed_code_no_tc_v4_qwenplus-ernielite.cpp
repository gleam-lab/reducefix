#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q;
int x[MAXN], p[MAXN];
// 前缀和数组应该和数组 x 的大小保持一致，但为了节省空间，我们可以只分配一半的空间来存储前缀和
// 因为每个 sum[i] 只依赖于 p 的前 i 个元素
int sum[MAXN / 2]; // 假设 n 不是很大以至于这个空间足够使用

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // 读取 x 数组的值
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i]; // 读取 p 数组的值，并计算前缀和
        if (i > 1) { // 只对 i > 1 的情况计算前缀和以避免越界
            sum[i] = sum[i - 1] + p[i];
        } else {
            sum[i] = p[i]; // 当 i 为 1 时直接赋值 p[i] 作为前缀和，因为 sum[i-1] 不存在
        }
    }
    cin >> q;
    while (q--) {
        int l, r; // 读取查询的左右边界值 l 和 r
        cin >> l >> r; // 注意这里不需要再对 l 和 r 进行二分查找的调整了，因为题目要求的是在 x 中的位置区间内求和的差值
        // 使用 lower_bound 来找到 l 在 x 中的位置（注意加一因为 lower_bound 会指向第一个大于等于 l 的位置）
        l = lower_bound(x + 1, x + n + 1, l) - x; // 修改后的二分查找来获取 l 的索引位置
        // r 的值已经在给定的查询中给出，不需要调整（假设查询是合法的）
        // 输出前缀和的差值作为结果（注意这里不需要减一）
        cout << sum[r] - sum[l - 1] << endl; // 修改前缀和数组索引来输出正确的结果
    }
    return 0; // 主函数返回语句通常不需要显式写出来，但在这里写上也没问题
}