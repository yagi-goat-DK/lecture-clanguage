/*
情報処理演習Ⅱ課題／ロジスティック写像１

ロジスティクス写像のパラメータを設定した上で，datファイルへの出力とgnuplotでのプロットを一括で行うプログラム
*/

#include <stdio.h>

int main(){
    int n,i;
    double a,x0,x;
    a=3.8;  //ロジスティクス写像のパラメータ a ∈ [0,4] 
    x0=0.5;  //初期値条件 x0 ∈ [0,1]

    //-------------------------------------------
    FILE *gp;  // gnuplot用のFILEポインタ
    gp = popen("gnuplot -persist","w");  // -persistオプションでウィンドウを閉じない

    FILE *fp;  // データ出力用のFILEポインタ
    fp = fopen("LM1.dat", "w");  // ファイルを書き込みモードで開く
    //-------------------------------------------

    fprintf(fp, "0 %f\n",x0); //初期値の出力(0回目, 初期値)
    
    n=100; //繰り返し回数の設定

    x=x0; //初期値を設定

    for(i=1;i<=n;i++){
        x=a*x*(1-x);
        fprintf(fp, "%d %f\n",i,x);  // ファイルに出力
    }

    fclose(fp);  // ファイルを閉じる

    //-------------------------------------------
    // gnuplotでデータをプロット
    fprintf(gp, "plot 'LM1.dat' using 1:2 with lines\n");
    fprintf(gp, "replot \n");        // gnuplotにコマンドを送る
    fflush(gp);  // バッファをクリア
    //-------------------------------------------

    pclose(gp);  // gnuplotを閉じる
    return 0;
}