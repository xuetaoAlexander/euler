/*************************************************************************
	> File Name: 2.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年07月31日 星期三 15时30分37秒
 ************************************************************************/

#include<stdio.h>
#define max_n 4000000

int fib[45];
int main() {
    fib[1] = 1, fib[2] = 2;
    int n = 2;
    while (fib[n] < max_n) {
        n++;
        fib[n] = fib[n - 1] + fib[n - 2];
    }
    long long int sum = 0;
    for(int i = 1; i <= n; ++i) {
        if (fib[i] & 1) continue;
        sum += fib[i];
    }
    printf("%lld\n", sum);

    return 0;
}
