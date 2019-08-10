/*************************************************************************
	> File Name: 2.advanced.2.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年07月31日 星期三 16时16分52秒
 ************************************************************************/

#include<stdio.h>
#define max_n 4000000

int fib[3] = {0,1};

int main() {
    int sum = 0, n = 1;

    while (fib[n % 3] + fib[(n - 1) % 3] < max_n) {
        n++;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
    }
    printf("%d\n", sum);

    return 0;
}
