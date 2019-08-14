/*************************************************************************
	> File Name: 13.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月07日 星期三 18时16分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char num[55];
int ans[55] = {0};

int main() {
    for (int i = 0; i < 100; ++i) {
        scanf("%s", num);
        int len = strlen(num);
        for (int j = 1; j <= len; ++j) {
            ans[j] += (num[len - j] - '0');
        }
        if (len > ans[0]) ans[0] = len;
        for (int j = 1; j <= ans[0]; ++j) {
            if (ans[j] < 10) continue; 
            ans[j + 1] += (ans[j] / 10);
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; --i) {
        printf("%d", ans[i]);
    }

    return 0;
}
