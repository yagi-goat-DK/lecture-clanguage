/*
課題7-1：以下の機能を満たすプログラムを作成せよ。
　・ある年（例：「1999」など整数4桁）を入力する。（整数4桁のチェック等は不要）　
　・入力された年がうるう年かそうでないかを判断し、表示する。
　・ただし、以下の仕様の関数”isLeapYear”を必ず作成し、使用すること。
　　ー引数として、int型で西暦を渡すと、うるう年かどうかを判定する関数
　　ー戻り値は、int型。戻り値が1ならうるう年、0ならうるう年ではない。

　＊うるう年
　　　－400で割り切れる年はうるう年である。
　　　－4で割り切れる年はうるう年だが、100で割り切れる年はうるう年ではない。
*/

#include <stdio.h>

int isLeapYear(int year){
  if(year%4 == 0){
    if(year%100==0 && year%400!=0){
      return(0);
    }else{
      return(1);
    }
  }else{
    return(0);
  }
}

int main(void){

  int year;

  printf("整数4桁を入力してください");
  scanf("%d", &year);

  if(isLeapYear(year)==1){
    printf("うるう年です");
  }else{
    printf("うるう年ではありません");
  }
}
