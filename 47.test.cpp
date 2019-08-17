/*************************************************************************
	> File Name: 47.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月16日 星期五 19时31分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 1000000
int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 1; // 素数的素因子只有它本身(1不是素数)
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i];//当i和prime[j]有最小公共素因子prime[j]时，i * prime[j]的素因子数量和i的素因子数量相等
                break;
            } else {
                f[i * prime[j]] = f[i] + 1;//当i和prime[j]没有公共素因子时，i * prime[j] 的素因子为 i的素因子为加1
            }
        }
    }
    return;
}

int main() {
    init();
    for (int i = 2; i < max_n; i++) {
        int flag = 1;
        for (int k = 0; k < 4 && flag; k++) {//把flag写到for循环的判断条件中，减少一次循环内部的判断，使代码更简洁
            flag = (prime[i + k] == 4);
        }
        if (flag) {
            cout << i << endl;
            break;   
        }
    }

}
