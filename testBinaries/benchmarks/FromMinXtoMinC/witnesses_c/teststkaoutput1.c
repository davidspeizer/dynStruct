// + CreateStack
// + DisposeStack
// + IsEmpty
// + IsFull
// + MakeEmpty
// + Pop
// + Push
// + Top
// + TopAndPop
// + main
// + stackar.istr0
// + stackar.istr1
// + stackar.istr10
// + stackar.istr11
// + stackar.istr12
// + stackar.istr13
// + stackar.istr2
// + stackar.istr3
// + stackar.istr4
// + stackar.istr5
// + stackar.istr6
// + stackar.istr7
// + stackar.istr8
// + stackar.istr9
// + teststka.istr0
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
typedef struct struct1 struct1;
struct struct1 {
  int field0;
  int field1;
  int* field2;
};
int TopAndPop(struct1* x12);
int MakeEmpty(struct1* x6);
int IsFull(struct1* x4);
char* stackar_istr13();
char* stackar_istr12();
char* stackar_istr11();
char* stackar_istr10();
char* stackar_istr9();
char* stackar_istr8();
char* stackar_istr7();
char* stackar_istr6();
char* stackar_istr5();
char* stackar_istr4();
char* stackar_istr3();
char* stackar_istr2();
char* stackar_istr1();
char* stackar_istr0();
int DisposeStack(int* x7);
int IsEmpty(struct1* x3);
int Pop(struct1* x11);
int Top(struct1* x10);
int Push(int x8,struct1* x9);
struct1* CreateStack(int x5);
int main(int x1,char** x2);
char* teststka_istr0();
int TopAndPop(struct1* x12) {
  int y160;
  int y161;
  int y162;
  int y163;
  int* y164;
  int* y165;
  int y166;
  char* y167;
  int y168;
  char* y169;
  int y170;
  int y171;
  int y172;
  label__BB000:
            y161 = IsEmpty(x12);
            if (y161) goto label__BB13;
            y162 = x12->field1;
            y163 = y162;
            y163 = y163 + -1;
            x12->field1 = y163;
            y164 = x12->field2;
            y165 = y164;
            y165 = y165 + y162 * 1;
            y166 = y165[0];
            y160 = y166;
            goto label__BB14;
  label__BB13:
            y167 = stackar_istr12();
            y168 = prints(y167);
            y169 = stackar_istr13();
            y170 = prints(y169);
            y172 = 1;
            y171 = mincexit(y172);
            y160 = 0;
            return y160;
  label__BB14: return y160;
}
int MakeEmpty(struct1* x6) {
  int y118;
  int y119;
  label__BB000:
            y119 = -1;
            x6->field1 = y119;
            return y118;
}
int IsFull(struct1* x4) {
  int y86;
  int y87;
  int y88;
  int y89;
  int y90;
  int y91;
  label__BB000:
            y87 = x4->field1;
            y88 = x4->field0;
            y89 = y88;
            y89 = y89 + -1;
            y90 = y87 == y89;
            if (y90) goto label__BB2;
            y91 = 0;
            goto label__BB3;
  label__BB2:
            y91 = 1;
            y86 = y91;
            return y86;
  label__BB3:
            y86 = y91;
            return y86;
}
char* stackar_istr13() {
  char* y77;
  int y78;
  char* y79;
  char y80;
  label__BB000:
            y78 = 2;
            y77 = (char*) malloc((sizeof(char)) * y78 * 1);
            y79 = y77;
            y80 = 10;
            y79[0] = y80;
            y79 = y79 + 1;
            y80 = 0;
            y79[0] = y80;
            return y77;
}
char* stackar_istr12() {
  char* y73;
  int y74;
  char* y75;
  char y76;
  label__BB000:
            y74 = 12;
            y73 = (char*) malloc((sizeof(char)) * y74 * 1);
            y75 = y73;
            y76 = 69;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 109;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 112;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 116;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 121;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 32;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 115;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 116;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 97;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 99;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 107;
            y75[0] = y76;
            y75 = y75 + 1;
            y76 = 0;
            y75[0] = y76;
            return y73;
}
char* stackar_istr11() {
  char* y69;
  int y70;
  char* y71;
  char y72;
  label__BB000:
            y70 = 2;
            y69 = (char*) malloc((sizeof(char)) * y70 * 1);
            y71 = y69;
            y72 = 10;
            y71[0] = y72;
            y71 = y71 + 1;
            y72 = 0;
            y71[0] = y72;
            return y69;
}
char* stackar_istr10() {
  char* y65;
  int y66;
  char* y67;
  char y68;
  label__BB000:
            y66 = 12;
            y65 = (char*) malloc((sizeof(char)) * y66 * 1);
            y67 = y65;
            y68 = 69;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 109;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 112;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 116;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 121;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 32;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 115;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 116;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 97;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 99;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 107;
            y67[0] = y68;
            y67 = y67 + 1;
            y68 = 0;
            y67[0] = y68;
            return y65;
}
char* stackar_istr9() {
  char* y61;
  int y62;
  char* y63;
  char y64;
  label__BB000:
            y62 = 2;
            y61 = (char*) malloc((sizeof(char)) * y62 * 1);
            y63 = y61;
            y64 = 10;
            y63[0] = y64;
            y63 = y63 + 1;
            y64 = 0;
            y63[0] = y64;
            return y61;
}
char* stackar_istr8() {
  char* y57;
  int y58;
  char* y59;
  char y60;
  label__BB000:
            y58 = 12;
            y57 = (char*) malloc((sizeof(char)) * y58 * 1);
            y59 = y57;
            y60 = 69;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 109;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 112;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 116;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 121;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 32;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 115;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 116;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 97;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 99;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 107;
            y59[0] = y60;
            y59 = y59 + 1;
            y60 = 0;
            y59[0] = y60;
            return y57;
}
char* stackar_istr7() {
  char* y53;
  int y54;
  char* y55;
  char y56;
  label__BB000:
            y54 = 2;
            y53 = (char*) malloc((sizeof(char)) * y54 * 1);
            y55 = y53;
            y56 = 10;
            y55[0] = y56;
            y55 = y55 + 1;
            y56 = 0;
            y55[0] = y56;
            return y53;
}
char* stackar_istr6() {
  char* y49;
  int y50;
  char* y51;
  char y52;
  label__BB000:
            y50 = 11;
            y49 = (char*) malloc((sizeof(char)) * y50 * 1);
            y51 = y49;
            y52 = 70;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 117;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 108;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 108;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 32;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 115;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 116;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 97;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 99;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 107;
            y51[0] = y52;
            y51 = y51 + 1;
            y52 = 0;
            y51[0] = y52;
            return y49;
}
char* stackar_istr5() {
  char* y45;
  int y46;
  char* y47;
  char y48;
  label__BB000:
            y46 = 2;
            y45 = (char*) malloc((sizeof(char)) * y46 * 1);
            y47 = y45;
            y48 = 10;
            y47[0] = y48;
            y47 = y47 + 1;
            y48 = 0;
            y47[0] = y48;
            return y45;
}
char* stackar_istr4() {
  char* y41;
  int y42;
  char* y43;
  char y44;
  label__BB000:
            y42 = 16;
            y41 = (char*) malloc((sizeof(char)) * y42 * 1);
            y43 = y41;
            y44 = 79;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 117;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 116;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 32;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 111;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 102;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 32;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 115;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 112;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 97;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 99;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 101;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 33;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 33;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 33;
            y43[0] = y44;
            y43 = y43 + 1;
            y44 = 0;
            y43[0] = y44;
            return y41;
}
char* stackar_istr3() {
  char* y37;
  int y38;
  char* y39;
  char y40;
  label__BB000:
            y38 = 2;
            y37 = (char*) malloc((sizeof(char)) * y38 * 1);
            y39 = y37;
            y40 = 10;
            y39[0] = y40;
            y39 = y39 + 1;
            y40 = 0;
            y39[0] = y40;
            return y37;
}
char* stackar_istr2() {
  char* y33;
  int y34;
  char* y35;
  char y36;
  label__BB000:
            y34 = 16;
            y33 = (char*) malloc((sizeof(char)) * y34 * 1);
            y35 = y33;
            y36 = 79;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 117;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 116;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 32;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 111;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 102;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 32;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 115;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 112;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 97;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 99;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 101;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 33;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 33;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 33;
            y35[0] = y36;
            y35 = y35 + 1;
            y36 = 0;
            y35[0] = y36;
            return y33;
}
char* stackar_istr1() {
  char* y29;
  int y30;
  char* y31;
  char y32;
  label__BB000:
            y30 = 2;
            y29 = (char*) malloc((sizeof(char)) * y30 * 1);
            y31 = y29;
            y32 = 10;
            y31[0] = y32;
            y31 = y31 + 1;
            y32 = 0;
            y31[0] = y32;
            return y29;
}
char* stackar_istr0() {
  char* y25;
  int y26;
  char* y27;
  char y28;
  label__BB000:
            y26 = 24;
            y25 = (char*) malloc((sizeof(char)) * y26 * 1);
            y27 = y25;
            y28 = 83;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 116;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 97;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 99;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 107;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 32;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 115;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 105;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 122;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 101;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 32;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 105;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 115;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 32;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 116;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 111;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 111;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 32;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 115;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 109;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 97;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 108;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 108;
            y27[0] = y28;
            y27 = y27 + 1;
            y28 = 0;
            y27[0] = y28;
            return y25;
}
int DisposeStack(int* x7) {
  int y120;
  label__BB000: return y120;
}
int IsEmpty(struct1* x3) {
  int y81;
  int y82;
  int y83;
  int y84;
  int y85;
  label__BB000:
            y82 = x3->field1;
            y84 = -1;
            y83 = y82 == y84;
            if (y83) goto label__BB0;
            y85 = 0;
            goto label__BB1;
  label__BB0:
            y85 = 1;
            y81 = y85;
            return y81;
  label__BB1:
            y81 = y85;
            return y81;
}
int Pop(struct1* x11) {
  int y148;
  int y149;
  int y150;
  int y151;
  char* y152;
  int y153;
  char* y154;
  int y155;
  int y156;
  int y157;
  int y158;
  int y159;
  label__BB000:
            y149 = IsEmpty(x11);
            y150 = y149;
            y150 = y150 - 1;
            y151 = y149;
            y151 = y151 * -1;
            y151 = y151 + -1;
            y150 = y150 & y151;
            y150 = y150 >> 31;
            if (y150) goto label__BB11;
            y152 = stackar_istr10();
            y153 = prints(y152);
            y154 = stackar_istr11();
            y155 = prints(y154);
            y157 = 1;
            y156 = mincexit(y157);
            goto label__BB12;
  label__BB11:
            y158 = x11->field1;
            y159 = y158;
            y159 = y159 + -1;
            x11->field1 = y159;
            return y148;
  label__BB12: return y148;
}
int Top(struct1* x10) {
  int y136;
  int y137;
  int y138;
  int* y139;
  int* y140;
  int y141;
  char* y142;
  int y143;
  char* y144;
  int y145;
  int y146;
  int y147;
  label__BB000:
            y137 = IsEmpty(x10);
            if (y137) goto label__BB9;
            y138 = x10->field1;
            y139 = x10->field2;
            y140 = y139;
            y140 = y140 + y138 * 1;
            y141 = y140[0];
            y136 = y141;
            goto label__BB10;
  label__BB10: return y136;
  label__BB9:
            y142 = stackar_istr8();
            y143 = prints(y142);
            y144 = stackar_istr9();
            y145 = prints(y144);
            y147 = 1;
            y146 = mincexit(y147);
            y136 = 0;
            return y136;
}
int Push(int x8,struct1* x9) {
  int y121;
  int y122;
  int y123;
  int y124;
  char* y125;
  int y126;
  char* y127;
  int y128;
  int y129;
  int y130;
  int y131;
  int y132;
  int y133;
  int* y134;
  int* y135;
  label__BB000:
            y122 = IsFull(x9);
            y123 = y122;
            y123 = y123 - 1;
            y124 = y122;
            y124 = y124 * -1;
            y124 = y124 + -1;
            y123 = y123 & y124;
            y123 = y123 >> 31;
            if (y123) goto label__BB7;
            y125 = stackar_istr6();
            y126 = prints(y125);
            y127 = stackar_istr7();
            y128 = prints(y127);
            y130 = 1;
            y129 = mincexit(y130);
            goto label__BB8;
  label__BB7:
            y131 = x9->field1;
            y132 = y131;
            y132 = y132 + 1;
            x9->field1 = y132;
            y133 = x9->field1;
            y134 = x9->field2;
            y135 = y134;
            y135 = y135 + y133 * 1;
            y135[0] = x8;
            return y121;
  label__BB8: return y121;
}
struct1* CreateStack(int x5) {
  struct1* y92;
  struct1* y93;
  int y94;
  int y95;
  int y96;
  char* y97;
  int y98;
  char* y99;
  int y100;
  int y101;
  int y102;
  char* y103;
  int y104;
  char* y105;
  int y106;
  int y107;
  int y108;
  int* y109;
  int* y110;
  char* y111;
  int y112;
  char* y113;
  int y114;
  int y115;
  int y116;
  int y117;
  label__BB000:
            y94 = x5;
            y94 = y94 - 5;
            y94 = y94 * -1;
            y94 = y94 + -1;
            y95 = 5;
            y96 = 5;
            y95 = y95 | x5;
            y96 = y96 & x5;
            y95 = y95 - y96;
            y95 = y95 | y94;
            y94 = x5;
            y94 = y94 * -1;
            y94 = y94 + -1;
            y94 = y94 | 5;
            y94 = y94 & y95;
            y94 = y94 >> 31;
            if (y94) goto label__BB4;
            y97 = stackar_istr0();
            y98 = prints(y97);
            y99 = stackar_istr1();
            y100 = prints(y99);
            y102 = 1;
            y101 = mincexit(y102);
            y93 = (struct1*) malloc(sizeof(struct1));
            if (y93) goto label__BB5;
            y103 = stackar_istr2();
            y104 = prints(y103);
            y105 = stackar_istr3();
            y106 = prints(y105);
            y108 = 1;
            y107 = mincexit(y108);
            y109 = (int*) malloc((sizeof(int)) * x5 * 1);
            y93->field2 = y109;
            y110 = y93->field2;
            if (y110) goto label__BB6;
            y111 = stackar_istr4();
            y112 = prints(y111);
            y113 = stackar_istr5();
            y114 = prints(y113);
            y116 = 1;
            y115 = mincexit(y116);
            y93->field0 = x5;
            y117 = MakeEmpty(y93);
            y92 = y93;
            return y92;
  label__BB4:
            y93 = (struct1*) malloc(sizeof(struct1));
            if (y93) goto label__BB5;
            y103 = stackar_istr2();
            y104 = prints(y103);
            y105 = stackar_istr3();
            y106 = prints(y105);
            y108 = 1;
            y107 = mincexit(y108);
            y109 = (int*) malloc((sizeof(int)) * x5 * 1);
            y93->field2 = y109;
            y110 = y93->field2;
            if (y110) goto label__BB6;
            y111 = stackar_istr4();
            y112 = prints(y111);
            y113 = stackar_istr5();
            y114 = prints(y113);
            y116 = 1;
            y115 = mincexit(y116);
            y93->field0 = x5;
            y117 = MakeEmpty(y93);
            y92 = y93;
            return y92;
  label__BB5:
            y109 = (int*) malloc((sizeof(int)) * x5 * 1);
            y93->field2 = y109;
            y110 = y93->field2;
            if (y110) goto label__BB6;
            y111 = stackar_istr4();
            y112 = prints(y111);
            y113 = stackar_istr5();
            y114 = prints(y113);
            y116 = 1;
            y115 = mincexit(y116);
            y93->field0 = x5;
            y117 = MakeEmpty(y93);
            y92 = y93;
            return y92;
  label__BB6:
            y93->field0 = x5;
            y117 = MakeEmpty(y93);
            y92 = y93;
            return y92;
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
  int y17;
  char* y18;
  int y19;
  int y20;
  int y21;
  int y22;
  int y23;
  int y24;
  label__BB000:
            y8 = 12;
            y6 = CreateStack(y8);
            y7 = 0;
            goto label__BB1;
  label__BB0:
            y9 = Push(y7,y6);
            y7 = y7 + 1;
            y10 = y7;
            y10 = y10 - 10;
            y11 = y7;
            y13 = y7;
            y11 = y11 | 10;
            y13 = y13 & 10;
            y11 = y11 - y13;
            y12 = y10;
            y14 = y10;
            y12 = y12 | y7;
            y14 = y14 & y7;
            y12 = y12 - y14;
            y11 = y11 & y12;
            y12 = y10;
            y15 = y10;
            y12 = y12 | y11;
            y15 = y15 & y11;
            y12 = y12 - y15;
            y12 = y12 >> 31;
            if (y12) goto label__BB0;
            goto label__BB3;
  label__BB1:
            y10 = y7;
            y10 = y10 - 10;
            y11 = y7;
            y13 = y7;
            y11 = y11 | 10;
            y13 = y13 & 10;
            y11 = y11 - y13;
            y12 = y10;
            y14 = y10;
            y12 = y12 | y7;
            y14 = y14 & y7;
            y12 = y12 - y14;
            y11 = y11 & y12;
            y12 = y10;
            y15 = y10;
            y12 = y12 | y11;
            y15 = y15 & y11;
            y12 = y12 - y15;
            y12 = y12 >> 31;
            if (y12) goto label__BB0;
            goto label__BB3;
  label__BB2:
            y16 = Top(y6);
            y17 = print32(y16);
            y18 = teststka_istr0();
            y19 = prints(y18);
            y20 = Pop(y6);
            y21 = IsEmpty(y6);
            y22 = y21;
            y22 = y22 - 1;
            y23 = y21;
            y23 = y23 * -1;
            y23 = y23 + -1;
            y22 = y22 & y23;
            y22 = y22 >> 31;
            if (y22) goto label__BB2;
            y24 = DisposeStack(y6);
            y5 = 0;
            return y5;
  label__BB3:
            y21 = IsEmpty(y6);
            y22 = y21;
            y22 = y22 - 1;
            y23 = y21;
            y23 = y23 * -1;
            y23 = y23 + -1;
            y22 = y22 & y23;
            y22 = y22 >> 31;
            if (y22) goto label__BB2;
            y24 = DisposeStack(y6);
            y5 = 0;
            return y5;
}
char* teststka_istr0() {
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
