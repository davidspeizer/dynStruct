// + CreateStack
// + DisposeStack
// + IsEmpty
// + MakeEmpty
// + Pop
// + Push
// + Top
// + main
// + stackli.istr0
// + stackli.istr1
// + stackli.istr2
// + stackli.istr3
// + stackli.istr4
// + stackli.istr5
// + stackli.istr6
// + stackli.istr7
// + stackli.istr8
// + stackli.istr9
// + teststkl.istr0
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
typedef struct struct1 struct1;
typedef struct struct2 struct2;
struct struct1 {
  int field0;
  struct2* field1;
};
struct struct2 {
  int field0;
  struct2* field1;
};
int MakeEmpty(struct1* x4);
char* stackli_istr9();
char* stackli_istr8();
char* stackli_istr7();
char* stackli_istr6();
char* stackli_istr5();
char* stackli_istr4();
char* stackli_istr3();
char* stackli_istr2();
char* stackli_istr1();
char* stackli_istr0();
int DisposeStack(struct1* x5);
int IsEmpty(struct1* x3);
int Pop(struct1* x9);
int Top(struct1* x8);
int Push(int x6,struct1* x7);
struct1* CreateStack();
int main(int x1,char** x2);
char* teststkl_istr0();
int MakeEmpty(struct1* x4) {
  int y78;
  char* y79;
  int y80;
  char* y81;
  int y82;
  int y83;
  int y84;
  int y85;
  int y86;
  int y87;
  int y88;
  label__BB000:
            if (x4) goto label__BB4;
            y79 = stackli_istr2();
            y80 = prints(y79);
            y81 = stackli_istr3();
            y82 = prints(y81);
            y84 = 1;
            y83 = mincexit(y84);
            goto label__BB5;
  label__BB3:
            y85 = Pop(x4);
            y86 = IsEmpty(x4);
            y87 = y86;
            y87 = y87 - 1;
            y88 = y86;
            y88 = y88 * -1;
            y88 = y88 + -1;
            y87 = y87 & y88;
            y87 = y87 >> 31;
            if (y87) goto label__BB3;
            return y78;
  label__BB4:
            y86 = IsEmpty(x4);
            y87 = y86;
            y87 = y87 - 1;
            y88 = y86;
            y88 = y88 * -1;
            y88 = y88 + -1;
            y87 = y87 & y88;
            y87 = y87 >> 31;
            if (y87) goto label__BB3;
            return y78;
  label__BB5: return y78;
}
char* stackli_istr9() {
  char* y60;
  int y61;
  char* y62;
  char y63;
  label__BB000:
            y61 = 2;
            y60 = (char*) malloc((sizeof(char)) * y61 * 1);
            y62 = y60;
            y63 = 10;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 0;
            y62[0] = y63;
            return y60;
}
char* stackli_istr8() {
  char* y56;
  int y57;
  char* y58;
  char y59;
  label__BB000:
            y57 = 12;
            y56 = (char*) malloc((sizeof(char)) * y57 * 1);
            y58 = y56;
            y59 = 69;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 109;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 112;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 116;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 121;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 32;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 115;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 116;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 97;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 99;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 107;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 0;
            y58[0] = y59;
            return y56;
}
char* stackli_istr7() {
  char* y52;
  int y53;
  char* y54;
  char y55;
  label__BB000:
            y53 = 2;
            y52 = (char*) malloc((sizeof(char)) * y53 * 1);
            y54 = y52;
            y55 = 10;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 0;
            y54[0] = y55;
            return y52;
}
char* stackli_istr6() {
  char* y48;
  int y49;
  char* y50;
  char y51;
  label__BB000:
            y49 = 12;
            y48 = (char*) malloc((sizeof(char)) * y49 * 1);
            y50 = y48;
            y51 = 69;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 109;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 112;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 116;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 121;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 32;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 115;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 116;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 97;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 99;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 107;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 0;
            y50[0] = y51;
            return y48;
}
char* stackli_istr5() {
  char* y44;
  int y45;
  char* y46;
  char y47;
  label__BB000:
            y45 = 2;
            y44 = (char*) malloc((sizeof(char)) * y45 * 1);
            y46 = y44;
            y47 = 10;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 0;
            y46[0] = y47;
            return y44;
}
char* stackli_istr4() {
  char* y40;
  int y41;
  char* y42;
  char y43;
  label__BB000:
            y41 = 16;
            y40 = (char*) malloc((sizeof(char)) * y41 * 1);
            y42 = y40;
            y43 = 79;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 117;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 116;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 32;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 111;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 102;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 32;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 115;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 112;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 97;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 99;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 101;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 33;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 33;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 33;
            y42[0] = y43;
            y42 = y42 + 1;
            y43 = 0;
            y42[0] = y43;
            return y40;
}
char* stackli_istr3() {
  char* y36;
  int y37;
  char* y38;
  char y39;
  label__BB000:
            y37 = 2;
            y36 = (char*) malloc((sizeof(char)) * y37 * 1);
            y38 = y36;
            y39 = 10;
            y38[0] = y39;
            y38 = y38 + 1;
            y39 = 0;
            y38[0] = y39;
            return y36;
}
char* stackli_istr2() {
  char* y32;
  int y33;
  char* y34;
  char y35;
  label__BB000:
            y33 = 27;
            y32 = (char*) malloc((sizeof(char)) * y33 * 1);
            y34 = y32;
            y35 = 77;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 117;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 115;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 116;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 32;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 117;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 115;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 101;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 32;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 67;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 114;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 101;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 97;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 116;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 101;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 83;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 116;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 97;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 99;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 107;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 32;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 102;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 105;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 114;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 115;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 116;
            y34[0] = y35;
            y34 = y34 + 1;
            y35 = 0;
            y34[0] = y35;
            return y32;
}
char* stackli_istr1() {
  char* y28;
  int y29;
  char* y30;
  char y31;
  label__BB000:
            y29 = 2;
            y28 = (char*) malloc((sizeof(char)) * y29 * 1);
            y30 = y28;
            y31 = 10;
            y30[0] = y31;
            y30 = y30 + 1;
            y31 = 0;
            y30[0] = y31;
            return y28;
}
char* stackli_istr0() {
  char* y24;
  int y25;
  char* y26;
  char y27;
  label__BB000:
            y25 = 16;
            y24 = (char*) malloc((sizeof(char)) * y25 * 1);
            y26 = y24;
            y27 = 79;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 117;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 116;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 32;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 111;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 102;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 32;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 115;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 112;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 97;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 99;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 101;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 33;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 33;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 33;
            y26[0] = y27;
            y26 = y26 + 1;
            y27 = 0;
            y26[0] = y27;
            return y24;
}
int DisposeStack(struct1* x5) {
  int y89;
  int y90;
  label__BB000:
            y90 = MakeEmpty(x5);
            return y89;
}
int IsEmpty(struct1* x3) {
  int y64;
  int* y65;
  int y66;
  int y67;
  label__BB000:
            y65 = x3->field1;
            if (y65) goto label__BB12;
            y66 = 1;
            goto label__BB13;
  label__BB0:
            y67 = 1;
            y64 = y67;
            return y64;
  label__BB1:
            y64 = y67;
            return y64;
  label__BB12:
            y66 = 0;
            if (y66) goto label__BB0;
            y67 = 0;
            goto label__BB1;
  label__BB13:
            if (y66) goto label__BB0;
            y67 = 0;
            goto label__BB1;
}
int Pop(struct1* x9) {
  int y110;
  int* y111;
  int y112;
  int y113;
  int y114;
  char* y115;
  int y116;
  char* y117;
  int y118;
  int y119;
  int y120;
  int* y121;
  struct2* y122;
  struct2* y123;
  label__BB000:
            y112 = IsEmpty(x9);
            y113 = y112;
            y113 = y113 - 1;
            y114 = y112;
            y114 = y114 * -1;
            y114 = y114 + -1;
            y113 = y113 & y114;
            y113 = y113 >> 31;
            if (y113) goto label__BB10;
            y115 = stackli_istr8();
            y116 = prints(y115);
            y117 = stackli_istr9();
            y118 = prints(y117);
            y120 = 1;
            y119 = mincexit(y120);
            goto label__BB11;
  label__BB10:
            y121 = x9->field1;
            y111 = y121;
            y122 = x9->field1;
            y123 = y122->field1;
            x9->field1 = y123;
            return y110;
  label__BB11: return y110;
}
int Top(struct1* x8) {
  int y100;
  int y101;
  int* y102;
  int y103;
  char* y104;
  int y105;
  char* y106;
  int y107;
  int y108;
  int y109;
  label__BB000:
            y101 = IsEmpty(x8);
            if (y101) goto label__BB8;
            y102 = x8->field1;
            y103 = *y102;
            y100 = y103;
            goto label__BB9;
  label__BB8:
            y104 = stackli_istr6();
            y105 = prints(y104);
            y106 = stackli_istr7();
            y107 = prints(y106);
            y109 = 1;
            y108 = mincexit(y109);
            y100 = 0;
            return y100;
  label__BB9: return y100;
}
int Push(int x6,struct1* x7) {
  int y91;
  struct2* y92;
  char* y93;
  int y94;
  char* y95;
  int y96;
  int y97;
  int y98;
  struct2* y99;
  label__BB000:
            y92 = (struct2*) malloc(sizeof(struct2));
            if (y92) goto label__BB6;
            y93 = stackli_istr4();
            y94 = prints(y93);
            y95 = stackli_istr5();
            y96 = prints(y95);
            y98 = 1;
            y97 = mincexit(y98);
            goto label__BB7;
  label__BB6:
            y92->field0 = x6;
            y99 = x7->field1;
            y92->field1 = y99;
            x7->field1 = y92;
            return y91;
  label__BB7: return y91;
}
struct1* CreateStack() {
  struct1* y68;
  struct1* y69;
  char* y70;
  int y71;
  char* y72;
  int y73;
  int y74;
  int y75;
  struct2* y76;
  int y77;
  label__BB000:
            y69 = (struct1*) malloc(sizeof(struct1));
            if (y69) goto label__BB2;
            y70 = stackli_istr0();
            y71 = prints(y70);
            y72 = stackli_istr1();
            y73 = prints(y72);
            y75 = 1;
            y74 = mincexit(y75);
            y76 = 0;
            y69->field1 = y76;
            y77 = MakeEmpty(y69);
            y68 = y69;
            return y68;
  label__BB2:
            y76 = 0;
            y69->field1 = y76;
            y77 = MakeEmpty(y69);
            y68 = y69;
            return y68;
}
int main(int x1,char** x2) {
  int y5;
  struct1* y6;
  int y7;
  int y8;
  int y9;
  int y10;
  int y11;
  int y12;
  int y13;
  int y14;
  int y15;
  int y16;
  char* y17;
  int y18;
  int y19;
  int y20;
  int y21;
  int y22;
  int y23;
  label__BB000:
            y6 = CreateStack();
            y7 = 0;
            goto label__BB1;
  label__BB0:
            y8 = Push(y7,y6);
            y7 = y7 + 1;
            y9 = y7;
            y9 = y9 - 10;
            y10 = y7;
            y12 = y7;
            y10 = y10 | 10;
            y12 = y12 & 10;
            y10 = y10 - y12;
            y11 = y9;
            y13 = y9;
            y11 = y11 | y7;
            y13 = y13 & y7;
            y11 = y11 - y13;
            y10 = y10 & y11;
            y11 = y9;
            y14 = y9;
            y11 = y11 | y10;
            y14 = y14 & y10;
            y11 = y11 - y14;
            y11 = y11 >> 31;
            if (y11) goto label__BB0;
            goto label__BB3;
  label__BB1:
            y9 = y7;
            y9 = y9 - 10;
            y10 = y7;
            y12 = y7;
            y10 = y10 | 10;
            y12 = y12 & 10;
            y10 = y10 - y12;
            y11 = y9;
            y13 = y9;
            y11 = y11 | y7;
            y13 = y13 & y7;
            y11 = y11 - y13;
            y10 = y10 & y11;
            y11 = y9;
            y14 = y9;
            y11 = y11 | y10;
            y14 = y14 & y10;
            y11 = y11 - y14;
            y11 = y11 >> 31;
            if (y11) goto label__BB0;
            goto label__BB3;
  label__BB2:
            y15 = Top(y6);
            y16 = print32(y15);
            y17 = teststkl_istr0();
            y18 = prints(y17);
            y19 = Pop(y6);
            y20 = IsEmpty(y6);
            y21 = y20;
            y21 = y21 - 1;
            y22 = y20;
            y22 = y22 * -1;
            y22 = y22 + -1;
            y21 = y21 & y22;
            y21 = y21 >> 31;
            if (y21) goto label__BB2;
            y23 = DisposeStack(y6);
            y5 = 0;
            return y5;
  label__BB3:
            y20 = IsEmpty(y6);
            y21 = y20;
            y21 = y21 - 1;
            y22 = y20;
            y22 = y22 * -1;
            y22 = y22 + -1;
            y21 = y21 & y22;
            y21 = y21 >> 31;
            if (y21) goto label__BB2;
            y23 = DisposeStack(y6);
            y5 = 0;
            return y5;
}
char* teststkl_istr0() {
  char* y1;
  int y2;
  char* y3;
  char y4;
  label__BB000:
            y2 = 2;
            y1 = (char*) malloc((sizeof(char)) * y2 * 1);
            y3 = y1;
            y4 = 10;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 0;
            y3[0] = y4;
            return y1;
}
