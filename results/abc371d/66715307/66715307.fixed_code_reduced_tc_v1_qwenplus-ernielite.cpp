#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // 计算前缀和
    }
    cin >> q;
    while (q--) { // 对每个查询进行操作
        int l, r;
        cin >> l >> r; // 读取查询的左右边界值l和r
        int l1 = 1, r1 = n, l2 = 0, r2 = n; // 初始化二分查找的左右边界
        // 在x数组中寻找不小于l的第一个元素和不大于r的最后一个元素的位置
        while (l1 < r1) {
            int mid = l1 + (r1 - l1) / 2; // 二分查找左边界，注意除法防溢出
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        l2 = l1 - 1; // 因为l1可能越界，所以取前一个位置作为l2的初始值
        while (l2 > 0 && l2 < r) { // 二分查找右边界，注意范围限制
            int mid = (l2 + r) / 2; // 注意除法防溢出，并处理r在数组边界外的情况
            if (x[mid] <= r) l2 = mid;
            else r = mid - 1; // 注意这里r要更新为mid-1，因为mid可能越界
        }
        // 输出a数组中对应区间的和（注意l2可能为负数）
        if (l2 < 0 || l2 >= n) { // 如果l2不在数组范围内，则输出0（因为无法找到对应的区间）
            cout << "0" << endl;
        } else { // 否则输出a数组中对应区间的和（注意这里使用a数组时不能越界）
            cout << a[l2] << endl; // 这里使用a[l2]而不是a[l2-1]，因为已经保证l2是合法的索引了
        }
    }
    return 0;
}