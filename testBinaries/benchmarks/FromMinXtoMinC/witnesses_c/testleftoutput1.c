// + DeleteMin1
// + FindMin
// + Initialize
// + Insert1
// + IsEmpty
// + Merge
// + Merge1
// + SwapChildren
// + leftheap.istr0
// + leftheap.istr1
// + leftheap.istr2
// + leftheap.istr3
// + leftheap.istr4
// + leftheap.istr5
// + main
// + testleft.istr0
// + testleft.istr1
// + testleft.istr2
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
typedef struct struct1 struct1;
struct struct1 {
  int field0;
  struct1* field1;
  struct1* field2;
  int field3;
};
int SwapChildren(struct1* x5);
struct1* Merge1(struct1* x6,struct1* x7);
struct1* Merge(struct1* x3,struct1* x4);
char* leftheap_istr5();
char* leftheap_istr4();
char* leftheap_istr3();
char* leftheap_istr2();
char* leftheap_istr1();
char* leftheap_istr0();
int IsEmpty(int* x12);
struct1* DeleteMin1(struct1* x10);
int FindMin(int* x11);
struct1* Insert1(int x8,struct1* x9);
struct1* Initialize();
int main(int x1,char** x2);
char* testleft_istr2();
char* testleft_istr1();
char* testleft_istr0();
int SwapChildren(struct1* x5) {
  int y72;
  struct1* y73;
  struct1* y74;
  struct1* y75;
  label__BB000:
            y74 = x5->field1;
            y73 = y74;
            y75 = x5->field2;
            x5->field1 = y75;
            x5->field2 = y73;
            return y72;
}
struct1* Merge1(struct1* x6,struct1* x7) {
  struct1* y76;
  int* y77;
  struct1* y78;
  struct1* y79;
  struct1* y80;
  int y81;
  struct1* y82;
  int y83;
  int y84;
  int y85;
  int y86;
  int y87;
  struct1* y88;
  int y89;
  int y90;
  label__BB000:
            y77 = x6->field1;
            if (y77) goto label__BB4;
            x6->field1 = x7;
            goto label__BB6;
  label__BB4:
            y78 = x6->field2;
            y79 = Merge(y78,x7);
            x6->field2 = y79;
            y80 = x6->field1;
            y81 = y80->field3;
            y82 = x6->field2;
            y83 = y82->field3;
            y84 = y81;
            y84 = y84 - y83;
            y84 = y84 * -1;
            y84 = y84 + -1;
            y85 = y83;
            y86 = y83;
            y85 = y85 | y81;
            y86 = y86 & y81;
            y85 = y85 - y86;
            y85 = y85 | y84;
            y84 = y81;
            y84 = y84 * -1;
            y84 = y84 + -1;
            y84 = y84 | y83;
            y84 = y84 & y85;
            y84 = y84 >> 31;
            if (y84) goto label__BB5;
            y87 = SwapChildren(x6);
            y88 = x6->field2;
            y89 = y88->field3;
            y90 = y89;
            y90 = y90 + 1;
            x6->field3 = y90;
            y76 = x6;
            return y76;
  label__BB5:
            y88 = x6->field2;
            y89 = y88->field3;
            y90 = y89;
            y90 = y90 + 1;
            x6->field3 = y90;
            y76 = x6;
            return y76;
  label__BB6:
            y76 = x6;
            return y76;
}
struct1* Merge(struct1* x3,struct1* x4) {
  struct1* y64;
  int y65;
  int y66;
  int y67;
  int y68;
  int y69;
  struct1* y70;
  struct1* y71;
  label__BB000:
            if (x3) goto label__BB0;
            y64 = x4;
            goto label__BB3;
  label__BB0:
            if (x4) goto label__BB1;
            y64 = x3;
            goto label__BB3;
  label__BB1:
            y65 = x3->field0;
            y66 = x4->field0;
            y67 = y65;
            y67 = y67 - y66;
            y67 = y67 * -1;
            y67 = y67 + -1;
            y68 = y66;
            y69 = y66;
            y68 = y68 | y65;
            y69 = y69 & y65;
            y68 = y68 - y69;
            y68 = y68 | y67;
            y67 = y65;
            y67 = y67 * -1;
            y67 = y67 + -1;
            y67 = y67 | y66;
            y67 = y67 & y68;
            y67 = y67 >> 31;
            if (y67) goto label__BB2;
            y70 = Merge1(x3,x4);
            y64 = y70;
            goto label__BB3;
  label__BB2:
            y71 = Merge1(x4,x3);
            y64 = y71;
            return y64;
  label__BB3: return y64;
}
char* leftheap_istr5() {
  char* y59;
  int y60;
  char* y61;
  char y62;
  label__BB000:
            y60 = 2;
            y59 = (char*) malloc((sizeof(char)) * y60 * 1);
            y61 = y59;
            y62 = 10;
            y61[0] = y62;
            y61 = y61 + 1;
            y62 = 0;
            y61[0] = y62;
            return y59;
}
char* leftheap_istr4() {
  char* y55;
  int y56;
  char* y57;
  char y58;
  label__BB000:
            y56 = 24;
            y55 = (char*) malloc((sizeof(char)) * y56 * 1);
            y57 = y55;
            y58 = 80;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 114;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 105;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 111;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 114;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 105;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 116;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 121;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 32;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 81;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 117;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 101;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 117;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 101;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 32;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 105;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 115;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 32;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 69;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 109;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 112;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 116;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 121;
            y57[0] = y58;
            y57 = y57 + 1;
            y58 = 0;
            y57[0] = y58;
            return y55;
}
char* leftheap_istr3() {
  char* y51;
  int y52;
  char* y53;
  char y54;
  label__BB000:
            y52 = 2;
            y51 = (char*) malloc((sizeof(char)) * y52 * 1);
            y53 = y51;
            y54 = 10;
            y53[0] = y54;
            y53 = y53 + 1;
            y54 = 0;
            y53[0] = y54;
            return y51;
}
char* leftheap_istr2() {
  char* y47;
  int y48;
  char* y49;
  char y50;
  label__BB000:
            y48 = 24;
            y47 = (char*) malloc((sizeof(char)) * y48 * 1);
            y49 = y47;
            y50 = 80;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 114;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 105;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 111;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 114;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 105;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 116;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 121;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 32;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 113;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 117;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 101;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 117;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 101;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 32;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 105;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 115;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 32;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 101;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 109;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 112;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 116;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 121;
            y49[0] = y50;
            y49 = y49 + 1;
            y50 = 0;
            y49[0] = y50;
            return y47;
}
char* leftheap_istr1() {
  char* y43;
  int y44;
  char* y45;
  char y46;
  label__BB000:
            y44 = 2;
            y43 = (char*) malloc((sizeof(char)) * y44 * 1);
            y45 = y43;
            y46 = 10;
            y45[0] = y46;
            y45 = y45 + 1;
            y46 = 0;
            y45[0] = y46;
            return y43;
}
char* leftheap_istr0() {
  char* y39;
  int y40;
  char* y41;
  char y42;
  label__BB000:
            y40 = 16;
            y39 = (char*) malloc((sizeof(char)) * y40 * 1);
            y41 = y39;
            y42 = 79;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 117;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 116;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 32;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 111;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 102;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 32;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 115;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 112;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 97;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 99;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 101;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 33;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 33;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 33;
            y41[0] = y42;
            y41 = y41 + 1;
            y42 = 0;
            y41[0] = y42;
            return y39;
}
int IsEmpty(int* x12) {
  int y126;
  int y127;
  int y128;
  label__BB000:
            if (x12) goto label__BB15;
            y127 = 1;
            goto label__BB16;
  label__BB13:
            y128 = 1;
            y126 = y128;
            return y126;
  label__BB14:
            y126 = y128;
            return y126;
  label__BB15:
            y127 = 0;
            if (y127) goto label__BB13;
            y128 = 0;
            goto label__BB14;
  label__BB16:
            if (y127) goto label__BB13;
            y128 = 0;
            goto label__BB14;
}
struct1* DeleteMin1(struct1* x10) {
  struct1* y102;
  struct1* y103;
  struct1* y104;
  int y105;
  int y106;
  int y107;
  char* y108;
  int y109;
  char* y110;
  int y111;
  int y112;
  int y113;
  struct1* y114;
  struct1* y115;
  struct1* y116;
  label__BB000:
            y105 = IsEmpty(x10);
            y106 = y105;
            y106 = y106 - 1;
            y107 = y105;
            y107 = y107 * -1;
            y107 = y107 + -1;
            y106 = y106 & y107;
            y106 = y106 >> 31;
            if (y106) goto label__BB9;
            y108 = leftheap_istr2();
            y109 = prints(y108);
            y110 = leftheap_istr3();
            y111 = prints(y110);
            y113 = 1;
            y112 = mincexit(y113);
            y102 = x10;
            goto label__BB10;
  label__BB10: return y102;
  label__BB9:
            y114 = x10->field1;
            y103 = y114;
            y115 = x10->field2;
            y104 = y115;
            y116 = Merge(y103,y104);
            y102 = y116;
            return y102;
}
int FindMin(int* x11) {
  int y117;
  int y118;
  int y119;
  char* y120;
  int y121;
  char* y122;
  int y123;
  int y124;
  int y125;
  label__BB000:
            y118 = IsEmpty(x11);
            if (y118) goto label__BB11;
            y119 = *x11;
            y117 = y119;
            goto label__BB12;
  label__BB11:
            y120 = leftheap_istr4();
            y121 = prints(y120);
            y122 = leftheap_istr5();
            y123 = prints(y122);
            y125 = 1;
            y124 = mincexit(y125);
            y117 = 0;
            return y117;
  label__BB12: return y117;
}
struct1* Insert1(int x8,struct1* x9) {
  struct1* y91;
  struct1* y92;
  char* y93;
  int y94;
  char* y95;
  int y96;
  int y97;
  int y98;
  int y99;
  struct1* y100;
  struct1* y101;
  label__BB000:
            y92 = (struct1*) malloc(sizeof(struct1));
            if (y92) goto label__BB7;
            y93 = leftheap_istr0();
            y94 = prints(y93);
            y95 = leftheap_istr1();
            y96 = prints(y95);
            y98 = 1;
            y97 = mincexit(y98);
            goto label__BB8;
  label__BB7:
            y92->field0 = x8;
            y99 = 0;
            y92->field3 = y99;
            y100 = 0;
            y92->field2 = y100;
            y101 = y92->field2;
            y92->field1 = y101;
            x9 = Merge(y92,x9);
            y91 = x9;
            return y91;
  label__BB8:
            y91 = x9;
            return y91;
}
struct1* Initialize() {
  struct1* y63;
  label__BB000:
            y63 = 0;
            return y63;
}
int main(int x1,char** x2) {
  int y13;
  struct1* y14;
  int y15;
  int y16;
  int y17;
  int y18;
  int y19;
  int y20;
  int y21;
  int y22;
  int y23;
  int y24;
  int y25;
  int y26;
  int y27;
  int y28;
  char* y29;
  int y30;
  int y31;
  char* y32;
  int y33;
  int y34;
  int y35;
  int y36;
  char* y37;
  int y38;
  label__BB000:
            y14 = Initialize();
            y15 = 0;
            y16 = 500;
            goto label__BB1;
  label__BB0:
            y14 = Insert1(y16,y14);
            y15 = y15 + 1;
            y17 = y16;
            y17 = y17 + 17;
            y19 = y17;
            y19 = y19 / 1000;
            y19 = y19 * 1000;
            y18 = y17;
            y18 = y18 - y19;
            y16 = y18;
            y20 = y15;
            y20 = y20 - 1000;
            y21 = y15;
            y23 = y15;
            y21 = y21 | 1000;
            y23 = y23 & 1000;
            y21 = y21 - y23;
            y22 = y20;
            y24 = y20;
            y22 = y22 | y15;
            y24 = y24 & y15;
            y22 = y22 - y24;
            y21 = y21 & y22;
            y22 = y20;
            y25 = y20;
            y22 = y22 | y21;
            y25 = y25 & y21;
            y22 = y22 - y25;
            y22 = y22 >> 31;
            if (y22) goto label__BB0;
            y16 = 0;
            goto label__BB4;
  label__BB1:
            y20 = y15;
            y20 = y20 - 1000;
            y21 = y15;
            y23 = y15;
            y21 = y21 | 1000;
            y23 = y23 & 1000;
            y21 = y21 - y23;
            y22 = y20;
            y24 = y20;
            y22 = y22 | y15;
            y24 = y24 & y15;
            y22 = y22 - y24;
            y21 = y21 & y22;
            y22 = y20;
            y25 = y20;
            y22 = y22 | y21;
            y25 = y25 & y21;
            y22 = y22 - y25;
            y22 = y22 >> 31;
            if (y22) goto label__BB0;
            y16 = 0;
            goto label__BB4;
  label__BB2:
            y26 = FindMin(y14);
            y27 = y16;
            y16 = y16 + 1;
            y28 = y26 == y27;
            if (y28) goto label__BB3;
            y29 = testleft_istr0();
            y30 = prints(y29);
            y31 = print32(y16);
            y32 = testleft_istr1();
            y33 = prints(y32);
            goto label__BB4;
  label__BB3:
            y14 = DeleteMin1(y14);
            y34 = IsEmpty(y14);
            y35 = y34;
            y35 = y35 - 1;
            y36 = y34;
            y36 = y36 * -1;
            y36 = y36 + -1;
            y35 = y35 & y36;
            y35 = y35 >> 31;
            if (y35) goto label__BB2;
            y37 = testleft_istr2();
            y38 = prints(y37);
            y13 = 0;
            return y13;
  label__BB4:
            y34 = IsEmpty(y14);
            y35 = y34;
            y35 = y35 - 1;
            y36 = y34;
            y36 = y36 * -1;
            y36 = y36 + -1;
            y35 = y35 & y36;
            y35 = y35 >> 31;
            if (y35) goto label__BB2;
            y37 = testleft_istr2();
            y38 = prints(y37);
            y13 = 0;
            return y13;
}
char* testleft_istr2() {
  char* y9;
  int y10;
  char* y11;
  char y12;
  label__BB000:
            y10 = 9;
            y9 = (char*) malloc((sizeof(char)) * y10 * 1);
            y11 = y9;
            y12 = 68;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 111;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 110;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 101;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 46;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 46;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 46;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 10;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 0;
            y11[0] = y12;
            return y9;
}
char* testleft_istr1() {
  char* y5;
  int y6;
  char* y7;
  char y8;
  label__BB000:
            y6 = 2;
            y5 = (char*) malloc((sizeof(char)) * y6 * 1);
            y7 = y5;
            y8 = 10;
            y7[0] = y8;
            y7 = y7 + 1;
            y8 = 0;
            y7[0] = y8;
            return y5;
}
char* testleft_istr0() {
  char* y1;
  int y2;
  char* y3;
  char y4;
  label__BB000:
            y2 = 21;
            y1 = (char*) malloc((sizeof(char)) * y2 * 1);
            y3 = y1;
            y4 = 69;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 114;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 114;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 111;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 114;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 32;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 105;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 110;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 32;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 68;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 101;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 108;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 101;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 116;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 101;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 77;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 105;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 110;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 44;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 32;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 0;
            y3[0] = y4;
            return y1;
}
