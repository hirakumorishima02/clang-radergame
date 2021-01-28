#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ransuu();
int raderGame(int ans);

int main(void){
    int ans,count,ques;
    ans = ransuu();
    printf("%d\n", ans);

    count = raderGame(ans);

    printf("もう1度遊びますか？ はい->0 いいえ->1\n");
    scanf("%d", &ques);

    while(ques==0){
        ans = ransuu();
        printf("%d\n", ans);
        count = raderGame(ans);
        printf("もう1度遊びますか？ はい->0 いいえ->1\n");
        scanf("%d", &ques);
    }

    return 0;
}

int ransuu(){
    int i;
    srand((unsigned int)time(NULL));

    i = 0 + rand() % 100;
    return i;
}

int raderGame(int ans){
    int num1,num2,count=1;

    while(num1+num2!=ans||num1-num2!=ans) {
        printf("位置は？");
        scanf("%d", &num1);
        printf("範囲は？");
        scanf("%d", &num2);
        if(num1+num2 >= ans && num1-num2 <= ans) {
            if(num2==0 && (num1+num2 == ans || num1-num2 == ans)) break;
            printf("ヒット\n");
        } else {
            printf("外れ\n");
        }
        count++;
    }
    printf("%d回目で正解です。\n", count);
    return 0;
}