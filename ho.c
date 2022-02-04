#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
int b1 = -1, b2 = -1, b3 = -1, b4 = -1;
int c1 = -1, c2 = -1, c3 = -1, c4 = -1;
int d1 = -1, d2 = -1, d3 = -1, d4 = -1;
int count;
int tianxing();
int ee, eee, eeee, eeeee;//完成声明
int red = 0, blue = 1, green = 2, yellow = 3;
void sujishu();
void tishi();
int kiki(); //弹性
void outg();
void paixv();//谁
void qifei(void);
void xianshia(void);
void xianshib(void);
void xianshic(void);
void xianshid(void);
int quanzhong();//权重
int first = 0, twe = 0, three = 0, four = 0; // 排名
int chu(int a, int b, int c, int d) {
    if (d == quanzhong()) {
        yellow -= 3;
        red++;
        blue++;
        green++;
    } else if (c == quanzhong()) {
        green -= 3;
        red++;
        blue++;
        yellow++;
        } else if (b == quanzhong()) {
            blue -= 3;
            red++;
            yellow++;
            green++;
        } else {
                red -= 3;
                yellow++;
                green++;
                blue++;
            }
}

void xingdong(void) {
    if (quanzhong() == red && (count == 6 || (a1 >= 0 && a1 !=55) || (a2 >= 0 && a2 != 55) || (a3 >= 0 && a3 != 55) || (a4 >= 0 && a4 != 55))) {
        qifei();
    }
    if (quanzhong() == blue && (count == 6 || (b1 >= 0 && b1 != 55) || (b2 >= 0 && b2 != 55) || (b3 >= 0 && b3 != 55) || (b4 >= 0 && b4 != 55))) {
        qifei();
    }
    if (quanzhong() == green && (count == 6 || (c1 >= 0 && c1 !=55) || (c2 >= 0 && c2 != 55 ) || (c3 >= 0 && c3 != 55) || (c4 >= 0 && c4 != 55))) {
        qifei();
    }
    if (quanzhong() == yellow && (count == 6 || (d1 >= 0 && d1 != 55) || (d2 >= 0 && d2 != 55) || (d3 >= 0 && d3 != 55) || (d4 >= 0 && d4 != 55))) {
        qifei();
    }
}

void win(void) {
    if (a1 == 55 && a2 == 55 && a3 == 55 && a4 == 55 && ee != 1) {
        red = -50000;
        first += 1;
        ee = 1;
        printf("WIN DEST");
    }
    if (b1 == 55 && b2 == 55 && b3 == 55 && b4 == 55 && eee != 1) {
        blue = -50000;
        twe += 1;
        eee = 1;
    }
    if (c1 == 55 && c2 == 55 && c3 == 55 && c4 == 55 && eeee != 1) {
        green = -50000;
        three += 1;
        eeee = 1;
    }
    if (d1 == 55 && d2 == 55 && d3 == 55 && d4 == 55 && eeeee != 1) {
        yellow = -50000;
        four += 1;
        eeeee = 1;
    }
    four += four;
    twe  += twe;
    first += first;
    three += three;
    if (four >= 1 && first >= 1 && three >= 1 && twe >= 1) {
        printf("game over");
    }//名次
}

int main() {
    char y, e, s;
    printf("game start \? \"yes\" or \"no\"\n");
    scanf("%c%c%c", &y, &e, &s);
    if (y == 'n' && e == 'o') {
        printf(" \ngame over\n");
        return 0;
    }
    printf("出发顺序 yellow ->> green ->> blue ->> red\n");
    printf("red           blue\n");
    for (int a=1; a <= 5; a++) {
        printf("  ");
        for (int jk = 3; jk <= 15; jk++) {
            if (a == 5) {
                printf(">");
                } else if (a == 1){
                    printf("<");
                    } else if (jk==15) {
                    printf(" ");
                        } else if (jk == 3) {
                            printf(" ");
                            } else {
                                printf(" ");
                                }
            }
        printf("\n");
    }
    printf("yellow        green\n\n\n");
    do {
        tishi();
    } while (ee != 1 && eee != 1 && eeee != 1 && eeeee !=1);

    return 0;
}

void sujishu(void) {
    char enter;
    paixv(red, blue, green, yellow);
    printf("投掷骰子\n\n");
    scanf("%c", &enter);
    scanf("%c", &enter);//确认
    srand(time(0));
    count = rand()%6+1;
    printf("      点数%d\n\n", count);
    //计算步数
}


void qifei(void) {
     int hao;// 编号
    if (red == 3 && ee != 1) {
        printf("red选择编号");
        do {
            scanf("%d", &hao);
        } while (hao > 4 || hao <= 0);
        switch (hao) {
            case 1:
                if(a1 >= 0 && a1 < 55 && count == 6) {
                    if (a1 + count <= 55) {
                        a1 += count;
                        a1 += kiki(a1);
                        } else {
                            a1 = tianxing(a1);
                            }
                    win();
                    xianshia();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (a1 >= 0 && a1 < 55) {
                    if (a1 + count <= 55) {
                        a1 += count;
                        a1 += kiki(a1);
                        } else {
                            a1 = tianxing(a1);
                            }
                        win();
                        xianshia();
                    }    else if ((a2 == 1 || a3 == 1 || a4 == 1) && count == 6 && a1 < 0 && a1 < 55) {
                            a1 = 0;
                            xianshia();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && a1 < 0 && a1 < 55) {
                                a1 = 1;
                                xianshia();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (a1 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 2:
                 if(a2 >= 0 && a2 < 55 && count == 6) {
                    if (a2 + count <= 55) {
                        a2 += count;
                        a2 += kiki(a2);
                        } else {
                            a2 = tianxing(a2);
                            }
                    win();
                    xianshia();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (a2 >= 0 && a2 < 55) {
                    if (a2 + count < 55) {
                        a2 += count;
                        a2 += kiki(a2);
                        } else {
                            a2 = tianxing(a2);
                            }
                        win();
                        xianshia();
                    }    else if ((a1 == 1 || a3 == 1 || a4 == 1) && count == 6 && a2 < 0 && a2 < 55) {
                            a2 = 0;
                            xianshia();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && a2 < 0 && a2 < 55) {
                                a2 = 1;
                                xianshia();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (a2 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 3:
                 if(a3 >= 0 && a3 < 55 && count == 6) {
                    if (a3 + count <= 55) {
                        a3 += count;
                        a3 += kiki(a3);
                        } else {
                            a3 = tianxing(a3);
                            }
                    win();
                    xianshia();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (a3 >= 0 && a3 < 55) {
                    if (a3 + count <= 55) {
                       a3 += count;
                       a3 += kiki(a3);
                        } else {
                            a3 = tianxing(a3);
                            }
                        win();
                        xianshia();
                    }    else if ((a2 == 1 || a1 == 1 || a4 == 1) && count == 6 && a3 < 0 && a3 < 55) {
                            a3 = 0;
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && a3 < 0 && a3 < 55) {
                                a3 = 1;
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (a3 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 4:
                 if(a4 >= 0 && a4 < 55 && count == 6) {
                    if (a4 + count <= 55) {
                        a4 += count;
                        a4 += kiki(a4);
                        } else {
                            a4 = tianxing(a4);
                            }
                    win();
                    xianshia();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (a4 >= 0 && a4 < 55) {
                    if (a4 + count <= 55) {
                        a4 += count;
                        kiki(a4);
                        } else {
                            a4 = tianxing(a4);
                            }
                        win();
                        xianshia();
                    }    else if ((a2 == 1 || a3 == 1 || a1 == 1) && count == 6 && a4 < 0 && a4 < 55) {
                            a4 = 0;
                            xianshia();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && a4 < 0 && a4 < 55) {
                                a4 = 1;
                                xianshia();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (a4 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
        }
    }
    if (blue == 3 && eee != 1) {
        printf("blue选择编号");
        do {
            scanf("%d", &hao);
        } while (hao > 4 || hao <= 0);
        switch (hao) {
            case 1:
                if(b1 >= 0 && b1 < 55 && count == 6) {
                    if (b1 + count <= 55) {
                        b1 += count;
                        b1 += kiki(b1);
                        } else {
                            b1 = tianxing(b1);
                            }
                    win();
                    xianshib();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (b1 >= 0 && b1 < 55) {
                    if (b1 + count <= 55) {
                        b1 += count;
                        b1 += kiki(b1);
                        } else {
                            b1 = tianxing(b1);
                            }
                        win();
                        xianshib();
                    }    else if ((b2 == 1 || b3 == 1 || b4 == 1) && count == 6 && b1 < 0 && b1 < 55) {
                            b1 = 0;
                            xianshib();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && b1 < 0 && b1 < 55) {
                                b1 = 1;
                                xianshib();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (b1 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 2:
                 if(b2 >= 0 && b2 < 55 && count == 6) {
                    if (b2 + count <= 55) {
                        b2 += count;
                        b2 += kiki(b2);
                        } else {
                            b2 = tianxing(b2);
                            }
                    win();
                    xianshib();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (b2 >= 0 && b2 < 55) {
                    if (b2 + count < 55) {
                        b2 += count;
                        b2 += kiki(b2);
                        } else {
                            b2 = tianxing(b2);
                            }
                        win();
                        xianshib();
                    }    else if ((b1 == 1 || b3 == 1 || b4 == 1) && count == 6 && b2 < 0 && b2 < 55) {
                            b2 = 0;
                            xianshib();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && b2 < 0 && b2 < 55) {
                                b2 = 1;
                                xianshib();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (b2 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 3:
                 if(b3 >= 0 && b3 < 55 && count == 6) {
                    if (b3 + count <= 55) {
                        b3 += count;
                        b3 += kiki(b3);
                        } else {
                            b3 = tianxing(b3);
                            }
                    win();
                    xianshib();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (b3 >= 0 && b3 < 55) {
                    if (b3 + count <= 55) {
                       b3 += count;
                       b3 += kiki(b3);
                        } else {
                            b3 = tianxing(b3);
                            }
                        win();
                        xianshib();
                    }    else if ((b2 == 1 || b1 == 1 || b4 == 1) && count == 6 && b3 < 0 && b3 < 55) {
                            b3 = 0;
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && b3 < 0 && b3 < 55) {
                                b3 = 1;
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (b3 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 4:
                 if(b4 >= 0 && b4 < 55 && count == 6) {
                    if (b4 + count <= 55) {
                        b4 += count;
                        b4 += kiki(b4);
                        } else {
                            b4 = tianxing(b4);
                            }
                    win();
                    xianshib();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (b4 >= 0 && b4 < 55) {
                    if (b4 + count <= 55) {
                        b4 += count;
                        kiki(b4);
                        } else {
                            b4 = tianxing(b4);
                            }
                        win();
                        xianshib();
                    }    else if ((b2 == 1 || b3 == 1 || b1 == 1) && count == 6 && b4 < 0 && b4 < 55) {
                            b4 = 0;
                            xianshib();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && b4 < 0 && b4 < 55) {
                                b4 = 1;
                                xianshib();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (b4 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
        }
    }
    if (yellow == 3 && eeee != 1) {
        printf("yellow选择编号");
        do {
            scanf("%d", &hao);
        } while (hao > 4 || hao <= 0);
        switch (hao) {
            case 1:
                if(d1>= 0 && d1 < 55 && count == 6) {
                    if (d1 + count <= 55) {
                        d1 += count;
                        d1 += kiki(d1);
                        } else {
                            d1 = tianxing(d1);
                            }
                    win();
                    xianshid();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (d1 >= 0 && d1 < 55) {
                    if (d1 + count <= 55) {
                        d1 += count;
                        d1 += kiki(d1);
                        } else {
                            d1 = tianxing(d1);
                            }
                        win();
                        xianshid();
                    }    else if ((d2 == 1 || d3 == 1 || d4 == 1) && count == 6 && d1 < 0 && d1 < 55) {
                            d1 = 0;
                            xianshid();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && d1 < 0 && d1 < 55) {
                                d1 = 1;
                                xianshid();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (d1 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 2:
                 if(d2 >= 0 && d2 < 55 && count == 6) {
                    if (d2 + count <= 55) {
                        d2 += count;
                        d2 += kiki(d2);
                        } else {
                            d2 = tianxing(d2);
                            }
                    win();
                    xianshid();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (d2 >= 0 && d2 < 55) {
                    if (d2 + count < 55) {
                        d2 += count;
                        d2 += kiki(d2);
                        } else {
                            d2 = tianxing(d2);
                            }
                        win();
                        xianshid();
                    }    else if ((d1 == 1 || d3 == 1 || d4 == 1) && count == 6 && d2 < 0 && d2 < 55) {
                            d2 = 0;
                            xianshid();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && d2 < 0 && d2 < 55) {
                                d2 = 1;
                                xianshid();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (d2 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 3:
                 if(d3 >= 0 && d3 < 55 && count == 6) {
                    if (d3 + count <= 55) {
                        d3 += count;
                        d3 += kiki(d3);
                        } else {
                            d3 = tianxing(d3);
                            }
                    win();
                    xianshid();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (d3 >= 0 && d3 < 55) {
                    if (d3 + count <= 55) {
                       d3 += count;
                       d3 += kiki(d3);
                        } else {
                            d3 = tianxing(d3);
                            }
                        win();
                        xianshid();
                    }    else if ((d2 == 1 || d1 == 1 || d4 == 1) && count == 6 && d3 < 0 && d3 < 55) {
                            d3 = 0;
                            xianshid();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && d3 < 0 && 3 < 55) {
                                d3 = 1;
                                xianshid();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (d3 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 4:
                 if(d4 >= 0 && d4 < 55 && count == 6) {
                    if (d4 + count <= 55) {
                        d4 += count;
                        d4 += kiki(d4);
                        } else {
                            d4 = tianxing(d4);
                            }
                    win();
                    xianshid();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (d4 >= 0 && d4 < 55) {
                    if (d4 + count <= 55) {
                        d4 += count;
                        kiki(d4);
                        } else {
                            d4 = tianxing(d4);
                            }
                        win();
                        xianshid();
                    }    else if ((d2 == 1 || d3 == 1 || d1 == 1) && count == 6 && d4 < 0 && d4 < 55) {
                            d4 = 0;
                            xianshid();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && d4 < 0 && d4 < 55) {
                                d4 = 1;
                                xianshid();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (d4 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
        }
    }
    if (green == 3 && eeeee != 1) {
        printf("green选择编号");
        do {
            scanf("%d", &hao);
        } while (hao > 4 || hao <= 0);
        switch (hao) {
            case 1:
                if(c1>= 0 && c1 < 55 && count == 6) {
                    if (c1 + count <= 55) {
                        c1 += count;
                        c1 += kiki(c1);
                        } else {
                            c1 = tianxing(c1);
                            }
                    win();
                    xianshic();
                    outg();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (c1 >= 0 && c1 < 55) {
                    if (c1 + count <= 55) {
                        c1 += count;
                        c1 += kiki(c1);
                        } else {
                            c1 = tianxing(c1);
                            }
                        win();
                        outg();
                        xianshic();
                    }    else if ((c2 == 1 || c3 == 1 || c4 == 1) && count == 6 && c1 < 0 && c1 < 55) {
                            c1 = 0;
                            xianshic();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && c1 < 0 && c1 < 55) {
                                c1 = 1;
                                xianshic();
                                outg();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (c1 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 2:
                 if(c2 >= 0 && c2 < 55 && count == 6) {
                    if (c2 + count <= 55) {
                        c2 += count;
                        c2 += kiki(c2);
                        } else {
                            c2 = tianxing(c2);
                            }
                    win();
                    outg();
                    xianshic();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (c2 >= 0 && c2 < 55) {
                    if (c2 + count < 55) {
                        c2 += count;
                        c2 += kiki(c2);
                        } else {
                            c2 = tianxing(c2);
                            }
                        win();
                        outg();
                        xianshic();
                    }    else if ((c1 == 1 || c3 == 1 || c4 == 1) && count == 6 && c2 < 0 && c2 < 55) {
                            c2 = 0;
                            xianshic();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && c2 < 0 && c2 < 55) {
                                c2 = 1;
                                xianshic();
                                outg();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (c2 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 3:
                 if(c3 >= 0 && c3 < 55 && count == 6) {
                    if (c3 + count <= 55) {
                        c3 += count;
                        c3 += kiki(c3);
                        } else {
                            c3 = tianxing(c3);
                            }
                    win();
                    outg();
                    xianshic();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (c3 >= 0 && c3 < 55) {
                    if (c3 + count <= 55) {
                       c3 += count;
                       c3 += kiki(c3);
                        } else {
                            c3 = tianxing(c3);
                            }
                        win();
                        outg();
                        xianshic();
                    }    else if ((c2 == 1 || d1 == 1 || d4 == 1) && count == 6 && c3 < 0 && c3 < 55) {
                            c3 = 0;
                            xianshic();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && c3 < 0 && c3 < 55) {
                                c3 = 1;
                                 xianshic();
                                 outg();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (c3 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
            case 4:
                 if(c4 >= 0 && c4 < 55 && count == 6) {
                    if (c4 + count <= 55) {
                        c4 += count;
                        c4 += kiki(c4);
                        } else {
                            c4 = tianxing(c4);
                            }
                    win();
                    outg();
                    xianshic();
                    sujishu();//获得机会
                    qifei();//重新选择
                }  else if (c4 >= 0 && c4 < 55) {
                    if (c4 + count <= 55) {
                        c4 += count;
                        kiki(c4);
                        } else {
                            c4 = tianxing(c4);
                            }
                        win();
                        outg();
                        xianshic();
                    }    else if ((c2 == 1 || c3 == 1 || c1 == 1) && count == 6 && c4 < 0 && c4 < 55) {
                            c4 = 0;
                            xianshic();
                            sujishu();//获得机会
                            qifei();//重新选择
                        } else if (count == 6 && c4 < 0 && c4 < 55) {
                                c4 = 1;
                                xianshic();
                                outg();
                                sujishu();//获得机会
                                qifei();//重新选择
                            } else if (c4 == 55){
                                    printf("已经到终点了喔！！\n");
                                    qifei();
                                } else {
                                    printf("不可以w\n");
                                    qifei();
                                    }
                break;
        }
    }
}



void tishi(void) {
    sujishu();//计算步数
    //printf("red %d blue %d green %d yellow %d\n", red, blue, green, yellow);//映出权重
    xingdong();
    win();
    chu(red, blue, green, yellow);//重置权重
    //printf("red %d blue %d green %d yellow %d\n", red, blue, green, yellow);//映出权重
}

int quanzhong(void) {// 最大值
    int max = yellow;
    if (red > max) {
        max = red;
    }
    if (blue > max) {
        max = blue;
    }
    if (green > max) {
        max = green;
    }
    return max;
}

void xianshia(void) {
    printf("red: \n");
    printf("*   目前步数 %d\n", a1);
    printf("**  目前步数 %d\n", a2);
    printf("*** 目前步数 %d\n", a3);
    printf("****目前步数 %d\n", a4);
}

void xianshib(void) {
    printf("blue: \n");
    printf("*   目前步数 %d\n", b1);
    printf("**  目前步数 %d\n", b2);
    printf("*** 目前步数 %d\n", b3);
    printf("****目前步数 %d\n", b4);
}

void xianshic(void) {
    printf("green: \n");
    printf("*   目前步数 %d\n", c1);
    printf("**  目前步数 %d\n", c2);
    printf("*** 目前步数 %d\n", c3);
    printf("****目前步数 %d\n", c4);
}

void xianshid(void) {
    printf("yellow: \n");
    printf("*   目前步数 %d\n", d1);
    printf("**  目前步数 %d\n", d2);
    printf("*** 目前步数 %d\n", d3);
    printf("****目前步数 %d\n", d4);
}

void paixv(int a, int b, int c, int d) {
    if (a == 3) {
        printf("\nred ");
    } else if (b == 3) {
        printf("\nblue");
        } else if (c == 3) {
            printf("\ngreen");
            } else {
                printf("\nyellow");
                }
}

int tianxing(int a) {
    int ccc;
    ccc = a += count - 55;
    a = 55 - ccc;
    return a;//弹性回跳
}


// 快捷区块
int kiki(int ismo) {
    int honode, exeee = 1;
    if (ismo == 13) {
        return 25;
    }
    for (honode = 1; honode <= 11; honode++) {
        exeee += 4;
       // printf("%d", exeee);
        if (exeee == ismo && ismo != 17) {
            printf("+4\n");
            return 4;
            }
        }
    if (ismo == 17) {
        return 25+4;
    }
    return 0;
    }

void outg(int zi) {// green eat
    // eat yellow
    if ((zi - 13 == d1 || d1 - 39 == zi) && d1 <= 49 &&  d1 > 0) {
        d1 = 0;
        printf("eat yellow1 for green\n");
    } else if ((zi - 13 == d2 || d2 - 39 == zi) && d2 <= 49 && d2 > 0) {
                d2 = 0;
                printf("eat yellow2 for green\n");
            } else if ((zi - 13 == d3 || d3 - 39 == zi) && d3 <= 49 && d3 > 0) {
                    d3 = 0;
                    printf("eat yellow3 for green\n");
                    } else if ((zi - 13 == d4 || d4 - 39 == zi) && d4 <= 49 && d4 > 0) {
                            d4 = 0;
                            printf("eat yellow4 for green\n");
                            } //eat red
    if ((zi - 26 == a1 || a1 - 26 == zi) && a1 <= 49 && a1 > 0) {
        a1 = 0;
        printf("eat red1 for green\n");
    } else if ((zi - 26 == a2 || a2 - 39 == zi) && a2 <= 49 && a2 > 0) {
                a2 = 0;
                printf("eat red2 for green\n");
            } else if ((zi - 26 == a3 || a3 - 26 == a3) && a3 <= 49 && a3 > 0) {
                        a3 = 0;
                        printf("eat red3 for green\n");
                    } else if ((zi - 26 == a4 || a4 - 26 == zi) && a4 <= 49 && a4 > 0) {
                            a4 = 0;
                            printf("eat red4 for green\n");
                            }// eat blue
    if ((zi - 39 == b1 || b1 - 13 == zi) && b1 <= 49 && b1 > 0) {
        b1 = 0;
        printf("eat blue1 for green\n");
    } else if ((zi - 39 == b2 || b2 - 13 == zi) && b2 <= 49 && b2 > 0) {
            b2 = 0;
            printf("eat blue2 for green\n");
            } else if ((zi - 39 == b3 || b3 - 13 == zi) && b3 <= 49 && b3 > 0 {
                    b3 = 0;
                    printf("eat blue3 for green\n");
                    } else if ((zi - 39 == b4 || b4 - 16 == zi) && b4 <= 49 && b4 > 0) {
                            b4 = 0;
                            printf("eat blue4 for green\n");
                            }
}
