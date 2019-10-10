/*************************************************************************
	> File Name: 12.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月14日 星期三 14时20分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 100000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2; // 素数的约数只有两个
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int a = i, cnt = 0;
                while (a % prime[j] == 0) a /= prime[j], cnt++; //cnt为旧合数的prime[j]因子的幂次
                f[i * prime[j]] = f[i] / (cnt + 1) * (cnt + 2); //新标记的合数和旧合数之间的因子满足这种关系
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]]; // i和prime[j]互素
            }
        }
    }
    return;
}

int main() {
    init();
    long long f_max = 0, n = 1;
    while (1) {
        if (n & 1) {
            f_max = f[n] * f[(n + 1) >> 1];
        } else {
            f_max = f[n >> 1] * f[n + 1];
        }
        if (f_max > 500) break;
        n += 1;
    }
    cout << n * (n + 1) / 2 << " = " << n;

    return 0;
}
