#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void description();
int ransuu();
int raderGame(int ans);
int question();

int main(void){
    int ans;
    description();
    ans = ransuu(); // 乱数発生
    raderGame(ans); // レーダーゲーム開始
    question(); // もう1回遊ぶか質問
    return 0;
}

void description(){
    puts("☆レーダー☆");
    puts("----------------------------------------------");
    puts("ターゲットとして 0～100 のうち１つの数が設定されます。\n探索する位置と範囲を入力してターゲットを見つけてください。");
    puts("ターゲットと探索位置の差が探索範囲以下であればヒットです。\n探索範囲より大きければ、はずれです。");
    puts("探索位置とターゲットが一致すれば正解です。");
    puts("----------------------------------------------");
    return;
}

int ransuu(){
    int i;
    srand((unsigned int)time(NULL)); // 乱数発生のおまじない
    i = 0 + rand() % 100; // 乱数発生のおまじない
    return i;
}

int raderGame(int ans){
    int num1,num2,count=1;
    puts("ゲームを開始します。");
    puts("ターゲットが設定されました。");
    
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

    printf("おめでとうございます！\n%d回目で正解です！\n", count);
    return 0;
}

int question() {
    int ans,ques;

    printf("もう1度遊びますか？ はい->0 いいえ->1\n");
    scanf("%d", &ques);

    while(ques==0){
        ans = ransuu();
        printf("%d\n", ans);
        raderGame(ans);
        printf("もう1度遊びますか？ はい->0 いいえ->1\n");
        scanf("%d", &ques);
        if(ques==1) puts("お疲れ様でした！また遊んでね。");
    }
    return 0;
}