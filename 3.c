/*************************************************************************
	> File Name: 3.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年07月31日 星期三 16时45分51秒
 ************************************************************************/

#include<stdio.h>
#define N 600851475143LL

int main() {
    long long i = 2, ans = 0, num = 48;
    while (i * i <= num) {
        if (num % i == 0) ans = i;
        while (num % i == 0) num /= i;
        i += 1;
    }

    if (num != 1) ans = num;
    printf("%lld\n", ans);
    return 0;
}
