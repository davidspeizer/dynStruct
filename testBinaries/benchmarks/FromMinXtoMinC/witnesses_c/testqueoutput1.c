// + CreateQueue
// + Dequeue
// + DisposeQueue
// + Enqueue
// + Front
// + FrontAndDequeue
// + IsEmpty
// + IsFull
// + MakeEmpty
// + Succ
// + main
// + queue.istr0
// + queue.istr1
// + queue.istr10
// + queue.istr11
// + queue.istr12
// + queue.istr13
// + queue.istr2
// + queue.istr3
// + queue.istr4
// + queue.istr5
// + queue.istr6
// + queue.istr7
// + queue.istr8
// + queue.istr9
// + testque.istr0
// + testque.istr1
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
typedef struct struct1 struct1;
struct struct1 {
  int field0;
  int field1;
  int field2;
  int field3;
  int* field4;
};
int FrontAndDequeue(struct1* x14);
int Succ(int x8,int* x9);
int MakeEmpty(struct1* x6);
int IsFull(struct1* x4);
char* queue_istr13();
char* queue_istr12();
char* queue_istr11();
char* queue_istr10();
char* queue_istr9();
char* queue_istr8();
char* queue_istr7();
char* queue_istr6();
char* queue_istr5();
char* queue_istr4();
char* queue_istr3();
char* queue_istr2();
char* queue_istr1();
char* queue_istr0();
int DisposeQueue(int* x7);
int IsEmpty(struct1* x3);
int Dequeue(struct1* x13);
int Front(struct1* x12);
int Enqueue(int x10,struct1* x11);
struct1* CreateQueue(int x5);
int main(int x1,char** x2);
char* testque_istr1();
char* testque_istr0();
int FrontAndDequeue(struct1* x14) {
  int y188;
  int y189;
  int y190;
  int y191;
  int y192;
  char* y193;
  int y194;
  char* y195;
  int y196;
  int y197;
  int y198;
  int y199;
  int y200;
  int y201;
  int* y202;
  int* y203;
  int y204;
  int y205;
  int y206;
  label__BB000:
            y189 = 0;
            y190 = IsEmpty(x14);
            y191 = y190;
            y191 = y191 - 1;
            y192 = y190;
            y192 = y192 * -1;
            y192 = y192 + -1;
            y191 = y191 & y192;
            y191 = y191 >> 31;
            if (y191) goto label__BB14;
            y193 = queue_istr12();
            y194 = prints(y193);
            y195 = queue_istr13();
            y196 = prints(y195);
            y198 = 1;
            y197 = mincexit(y198);
            goto label__BB15;
  label__BB14:
            y199 = x14->field3;
            y200 = y199;
            y200 = y200 + -1;
            x14->field3 = y200;
            y201 = x14->field1;
            y202 = x14->field4;
            y203 = y202;
            y203 = y203 + y201 * 1;
            y204 = y203[0];
            y189 = y204;
            y205 = x14->field1;
            y206 = Succ(y205,x14);
            x14->field1 = y206;
            y188 = y189;
            return y188;
  label__BB15:
            y188 = y189;
            return y188;
}
int Succ(int x8,int* x9) {
  int y141;
  int y142;
  int y143;
  int y144;
  label__BB000:
            x8 = x8 + 1;
            y142 = *x9;
            y143 = x8 == y142;
            if (y143) goto label__BB16;
            y144 = 1;
            goto label__BB17;
  label__BB16:
            y144 = 0;
            if (y144) goto label__BB7;
            x8 = 0;
            y141 = x8;
            return y141;
  label__BB17:
            if (y144) goto label__BB7;
            x8 = 0;
            y141 = x8;
            return y141;
  label__BB7:
            y141 = x8;
            return y141;
}
int MakeEmpty(struct1* x6) {
  int y136;
  int y137;
  int y138;
  int y139;
  label__BB000:
            y137 = 0;
            x6->field3 = y137;
            y138 = 1;
            x6->field1 = y138;
            y139 = 0;
            x6->field2 = y139;
            return y136;
}
int IsFull(struct1* x4) {
  int y105;
  int y106;
  int y107;
  int y108;
  int y109;
  label__BB000:
            y106 = x4->field3;
            y107 = x4->field0;
            y108 = y106 == y107;
            if (y108) goto label__BB2;
            y109 = 0;
            goto label__BB3;
  label__BB2:
            y109 = 1;
            y105 = y109;
            return y105;
  label__BB3:
            y105 = y109;
            return y105;
}
char* queue_istr13() {
  char* y96;
  int y97;
  char* y98;
  char y99;
  label__BB000:
            y97 = 2;
            y96 = (char*) malloc((sizeof(char)) * y97 * 1);
            y98 = y96;
            y99 = 10;
            y98[0] = y99;
            y98 = y98 + 1;
            y99 = 0;
            y98[0] = y99;
            return y96;
}
char* queue_istr12() {
  char* y92;
  int y93;
  char* y94;
  char y95;
  label__BB000:
            y93 = 12;
            y92 = (char*) malloc((sizeof(char)) * y93 * 1);
            y94 = y92;
            y95 = 69;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 109;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 112;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 116;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 121;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 32;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 113;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 117;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 101;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 117;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 101;
            y94[0] = y95;
            y94 = y94 + 1;
            y95 = 0;
            y94[0] = y95;
            return y92;
}
char* queue_istr11() {
  char* y88;
  int y89;
  char* y90;
  char y91;
  label__BB000:
            y89 = 2;
            y88 = (char*) malloc((sizeof(char)) * y89 * 1);
            y90 = y88;
            y91 = 10;
            y90[0] = y91;
            y90 = y90 + 1;
            y91 = 0;
            y90[0] = y91;
            return y88;
}
char* queue_istr10() {
  char* y84;
  int y85;
  char* y86;
  char y87;
  label__BB000:
            y85 = 12;
            y84 = (char*) malloc((sizeof(char)) * y85 * 1);
            y86 = y84;
            y87 = 69;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 109;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 112;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 116;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 121;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 32;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 113;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 117;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 101;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 117;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 101;
            y86[0] = y87;
            y86 = y86 + 1;
            y87 = 0;
            y86[0] = y87;
            return y84;
}
char* queue_istr9() {
  char* y80;
  int y81;
  char* y82;
  char y83;
  label__BB000:
            y81 = 2;
            y80 = (char*) malloc((sizeof(char)) * y81 * 1);
            y82 = y80;
            y83 = 10;
            y82[0] = y83;
            y82 = y82 + 1;
            y83 = 0;
            y82[0] = y83;
            return y80;
}
char* queue_istr8() {
  char* y76;
  int y77;
  char* y78;
  char y79;
  label__BB000:
            y77 = 12;
            y76 = (char*) malloc((sizeof(char)) * y77 * 1);
            y78 = y76;
            y79 = 69;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 109;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 112;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 116;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 121;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 32;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 113;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 117;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 101;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 117;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 101;
            y78[0] = y79;
            y78 = y78 + 1;
            y79 = 0;
            y78[0] = y79;
            return y76;
}
char* queue_istr7() {
  char* y72;
  int y73;
  char* y74;
  char y75;
  label__BB000:
            y73 = 2;
            y72 = (char*) malloc((sizeof(char)) * y73 * 1);
            y74 = y72;
            y75 = 10;
            y74[0] = y75;
            y74 = y74 + 1;
            y75 = 0;
            y74[0] = y75;
            return y72;
}
char* queue_istr6() {
  char* y68;
  int y69;
  char* y70;
  char y71;
  label__BB000:
            y69 = 11;
            y68 = (char*) malloc((sizeof(char)) * y69 * 1);
            y70 = y68;
            y71 = 70;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 117;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 108;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 108;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 32;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 113;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 117;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 101;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 117;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 101;
            y70[0] = y71;
            y70 = y70 + 1;
            y71 = 0;
            y70[0] = y71;
            return y68;
}
char* queue_istr5() {
  char* y64;
  int y65;
  char* y66;
  char y67;
  label__BB000:
            y65 = 2;
            y64 = (char*) malloc((sizeof(char)) * y65 * 1);
            y66 = y64;
            y67 = 10;
            y66[0] = y67;
            y66 = y66 + 1;
            y67 = 0;
            y66[0] = y67;
            return y64;
}
char* queue_istr4() {
  char* y60;
  int y61;
  char* y62;
  char y63;
  label__BB000:
            y61 = 16;
            y60 = (char*) malloc((sizeof(char)) * y61 * 1);
            y62 = y60;
            y63 = 79;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 117;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 116;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 32;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 111;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 102;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 32;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 115;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 112;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 97;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 99;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 101;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 33;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 33;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 33;
            y62[0] = y63;
            y62 = y62 + 1;
            y63 = 0;
            y62[0] = y63;
            return y60;
}
char* queue_istr3() {
  char* y56;
  int y57;
  char* y58;
  char y59;
  label__BB000:
            y57 = 2;
            y56 = (char*) malloc((sizeof(char)) * y57 * 1);
            y58 = y56;
            y59 = 10;
            y58[0] = y59;
            y58 = y58 + 1;
            y59 = 0;
            y58[0] = y59;
            return y56;
}
char* queue_istr2() {
  char* y52;
  int y53;
  char* y54;
  char y55;
  label__BB000:
            y53 = 16;
            y52 = (char*) malloc((sizeof(char)) * y53 * 1);
            y54 = y52;
            y55 = 79;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 117;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 116;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 32;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 111;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 102;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 32;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 115;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 112;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 97;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 99;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 101;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 33;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 33;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 33;
            y54[0] = y55;
            y54 = y54 + 1;
            y55 = 0;
            y54[0] = y55;
            return y52;
}
char* queue_istr1() {
  char* y48;
  int y49;
  char* y50;
  char y51;
  label__BB000:
            y49 = 2;
            y48 = (char*) malloc((sizeof(char)) * y49 * 1);
            y50 = y48;
            y51 = 10;
            y50[0] = y51;
            y50 = y50 + 1;
            y51 = 0;
            y50[0] = y51;
            return y48;
}
char* queue_istr0() {
  char* y44;
  int y45;
  char* y46;
  char y47;
  label__BB000:
            y45 = 24;
            y44 = (char*) malloc((sizeof(char)) * y45 * 1);
            y46 = y44;
            y47 = 81;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 117;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 101;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 117;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 101;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 32;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 115;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 105;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 122;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 101;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 32;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 105;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 115;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 32;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 116;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 111;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 111;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 32;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 115;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 109;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 97;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 108;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 108;
            y46[0] = y47;
            y46 = y46 + 1;
            y47 = 0;
            y46[0] = y47;
            return y44;
}
int DisposeQueue(int* x7) {
  int y140;
  label__BB000: return y140;
}
int IsEmpty(struct1* x3) {
  int y100;
  int y101;
  int y102;
  int y103;
  int y104;
  label__BB000:
            y101 = x3->field3;
            y102 = y101;
            y102 = y102 - 1;
            y103 = y101;
            y103 = y103 * -1;
            y103 = y103 + -1;
            y102 = y102 & y103;
            y102 = y102 >> 31;
            if (y102) goto label__BB0;
            y104 = 0;
            goto label__BB1;
  label__BB0:
            y104 = 1;
            y100 = y104;
            return y100;
  label__BB1:
            y100 = y104;
            return y100;
}
int Dequeue(struct1* x13) {
  int y174;
  int y175;
  int y176;
  int y177;
  char* y178;
  int y179;
  char* y180;
  int y181;
  int y182;
  int y183;
  int y184;
  int y185;
  int y186;
  int y187;
  label__BB000:
            y175 = IsEmpty(x13);
            y176 = y175;
            y176 = y176 - 1;
            y177 = y175;
            y177 = y177 * -1;
            y177 = y177 + -1;
            y176 = y176 & y177;
            y176 = y176 >> 31;
            if (y176) goto label__BB12;
            y178 = queue_istr10();
            y179 = prints(y178);
            y180 = queue_istr11();
            y181 = prints(y180);
            y183 = 1;
            y182 = mincexit(y183);
            goto label__BB13;
  label__BB12:
            y184 = x13->field3;
            y185 = y184;
            y185 = y185 + -1;
            x13->field3 = y185;
            y186 = x13->field1;
            y187 = Succ(y186,x13);
            x13->field1 = y187;
            return y174;
  label__BB13: return y174;
}
int Front(struct1* x12) {
  int y162;
  int y163;
  int y164;
  int* y165;
  int* y166;
  int y167;
  char* y168;
  int y169;
  char* y170;
  int y171;
  int y172;
  int y173;
  label__BB000:
            y163 = IsEmpty(x12);
            if (y163) goto label__BB10;
            y164 = x12->field1;
            y165 = x12->field4;
            y166 = y165;
            y166 = y166 + y164 * 1;
            y167 = y166[0];
            y162 = y167;
            goto label__BB11;
  label__BB10:
            y168 = queue_istr8();
            y169 = prints(y168);
            y170 = queue_istr9();
            y171 = prints(y170);
            y173 = 1;
            y172 = mincexit(y173);
            y162 = 0;
            return y162;
  label__BB11: return y162;
}
int Enqueue(int x10,struct1* x11) {
  int y145;
  int y146;
  int y147;
  int y148;
  char* y149;
  int y150;
  char* y151;
  int y152;
  int y153;
  int y154;
  int y155;
  int y156;
  int y157;
  int y158;
  int y159;
  int* y160;
  int* y161;
  label__BB000:
            y146 = IsFull(x11);
            y147 = y146;
            y147 = y147 - 1;
            y148 = y146;
            y148 = y148 * -1;
            y148 = y148 + -1;
            y147 = y147 & y148;
            y147 = y147 >> 31;
            if (y147) goto label__BB8;
            y149 = queue_istr6();
            y150 = prints(y149);
            y151 = queue_istr7();
            y152 = prints(y151);
            y154 = 1;
            y153 = mincexit(y154);
            goto label__BB9;
  label__BB8:
            y155 = x11->field3;
            y156 = y155;
            y156 = y156 + 1;
            x11->field3 = y156;
            y157 = x11->field2;
            y158 = Succ(y157,x11);
            x11->field2 = y158;
            y159 = x11->field2;
            y160 = x11->field4;
            y161 = y160;
            y161 = y161 + y159 * 1;
            y161[0] = x10;
            return y145;
  label__BB9: return y145;
}
struct1* CreateQueue(int x5) {
  struct1* y110;
  struct1* y111;
  int y112;
  int y113;
  int y114;
  char* y115;
  int y116;
  char* y117;
  int y118;
  int y119;
  int y120;
  char* y121;
  int y122;
  char* y123;
  int y124;
  int y125;
  int y126;
  int* y127;
  int* y128;
  char* y129;
  int y130;
  char* y131;
  int y132;
  int y133;
  int y134;
  int y135;
  label__BB000:
            y112 = x5;
            y112 = y112 - 5;
            y112 = y112 * -1;
            y112 = y112 + -1;
            y113 = 5;
            y114 = 5;
            y113 = y113 | x5;
            y114 = y114 & x5;
            y113 = y113 - y114;
            y113 = y113 | y112;
            y112 = x5;
            y112 = y112 * -1;
            y112 = y112 + -1;
            y112 = y112 | 5;
            y112 = y112 & y113;
            y112 = y112 >> 31;
            if (y112) goto label__BB4;
            y115 = queue_istr0();
            y116 = prints(y115);
            y117 = queue_istr1();
            y118 = prints(y117);
            y120 = 1;
            y119 = mincexit(y120);
            y111 = (struct1*) malloc(sizeof(struct1));
            if (y111) goto label__BB5;
            y121 = queue_istr2();
            y122 = prints(y121);
            y123 = queue_istr3();
            y124 = prints(y123);
            y126 = 1;
            y125 = mincexit(y126);
            y127 = (int*) malloc((sizeof(int)) * x5 * 1);
            y111->field4 = y127;
            y128 = y111->field4;
            if (y128) goto label__BB6;
            y129 = queue_istr4();
            y130 = prints(y129);
            y131 = queue_istr5();
            y132 = prints(y131);
            y134 = 1;
            y133 = mincexit(y134);
            y111->field0 = x5;
            y135 = MakeEmpty(y111);
            y110 = y111;
            return y110;
  label__BB4:
            y111 = (struct1*) malloc(sizeof(struct1));
            if (y111) goto label__BB5;
            y121 = queue_istr2();
            y122 = prints(y121);
            y123 = queue_istr3();
            y124 = prints(y123);
            y126 = 1;
            y125 = mincexit(y126);
            y127 = (int*) malloc((sizeof(int)) * x5 * 1);
            y111->field4 = y127;
            y128 = y111->field4;
            if (y128) goto label__BB6;
            y129 = queue_istr4();
            y130 = prints(y129);
            y131 = queue_istr5();
            y132 = prints(y131);
            y134 = 1;
            y133 = mincexit(y134);
            y111->field0 = x5;
            y135 = MakeEmpty(y111);
            y110 = y111;
            return y110;
  label__BB5:
            y127 = (int*) malloc((sizeof(int)) * x5 * 1);
            y111->field4 = y127;
            y128 = y111->field4;
            if (y128) goto label__BB6;
            y129 = queue_istr4();
            y130 = prints(y129);
            y131 = queue_istr5();
            y132 = prints(y131);
            y134 = 1;
            y133 = mincexit(y134);
            y111->field0 = x5;
            y135 = MakeEmpty(y111);
            y110 = y111;
            return y110;
  label__BB6:
            y111->field0 = x5;
            y135 = MakeEmpty(y111);
            y110 = y111;
            return y110;
}
int main(int x1,char** x2) {
  int y9;
  struct1* y10;
  int y11;
  int y12;
  int y13;
  int y14;
  int y15;
  int y16;
  int y17;
  int y18;
  int y19;
  int y20;
  int y21;
  char* y22;
  int y23;
  int y24;
  int y25;
  int y26;
  int y27;
  int y28;
  int y29;
  int y30;
  int y31;
  int y32;
  int y33;
  int y34;
  int y35;
  int y36;
  char* y37;
  int y38;
  int y39;
  int y40;
  int y41;
  int y42;
  int y43;
  label__BB000:
            y12 = 12;
            y10 = CreateQueue(y12);
            y11 = 0;
            goto label__BB1;
  label__BB0:
            y13 = Enqueue(y11,y10);
            y11 = y11 + 1;
            y14 = y11;
            y14 = y14 - 10;
            y15 = y11;
            y17 = y11;
            y15 = y15 | 10;
            y17 = y17 & 10;
            y15 = y15 - y17;
            y16 = y14;
            y18 = y14;
            y16 = y16 | y11;
            y18 = y18 & y11;
            y16 = y16 - y18;
            y15 = y15 & y16;
            y16 = y14;
            y19 = y14;
            y16 = y16 | y15;
            y19 = y19 & y15;
            y16 = y16 - y19;
            y16 = y16 >> 31;
            if (y16) goto label__BB0;
            goto label__BB3;
  label__BB1:
            y14 = y11;
            y14 = y14 - 10;
            y15 = y11;
            y17 = y11;
            y15 = y15 | 10;
            y17 = y17 & 10;
            y15 = y15 - y17;
            y16 = y14;
            y18 = y14;
            y16 = y16 | y11;
            y18 = y18 & y11;
            y16 = y16 - y18;
            y15 = y15 & y16;
            y16 = y14;
            y19 = y14;
            y16 = y16 | y15;
            y19 = y19 & y15;
            y16 = y16 - y19;
            y16 = y16 >> 31;
            if (y16) goto label__BB0;
            goto label__BB3;
  label__BB2:
            y20 = Front(y10);
            y21 = print32(y20);
            y22 = testque_istr0();
            y23 = prints(y22);
            y24 = Dequeue(y10);
            y25 = IsEmpty(y10);
            y26 = y25;
            y26 = y26 - 1;
            y27 = y25;
            y27 = y27 * -1;
            y27 = y27 + -1;
            y26 = y26 & y27;
            y26 = y26 >> 31;
            if (y26) goto label__BB2;
            y11 = 0;
            goto label__BB5;
  label__BB3:
            y25 = IsEmpty(y10);
            y26 = y25;
            y26 = y26 - 1;
            y27 = y25;
            y27 = y27 * -1;
            y27 = y27 + -1;
            y26 = y26 & y27;
            y26 = y26 >> 31;
            if (y26) goto label__BB2;
            y11 = 0;
            goto label__BB5;
  label__BB4:
            y28 = Enqueue(y11,y10);
            y11 = y11 + 1;
            y29 = y11;
            y29 = y29 - 10;
            y30 = y11;
            y32 = y11;
            y30 = y30 | 10;
            y32 = y32 & 10;
            y30 = y30 - y32;
            y31 = y29;
            y33 = y29;
            y31 = y31 | y11;
            y33 = y33 & y11;
            y31 = y31 - y33;
            y30 = y30 & y31;
            y31 = y29;
            y34 = y29;
            y31 = y31 | y30;
            y34 = y34 & y30;
            y31 = y31 - y34;
            y31 = y31 >> 31;
            if (y31) goto label__BB4;
            goto label__BB7;
  label__BB5:
            y29 = y11;
            y29 = y29 - 10;
            y30 = y11;
            y32 = y11;
            y30 = y30 | 10;
            y32 = y32 & 10;
            y30 = y30 - y32;
            y31 = y29;
            y33 = y29;
            y31 = y31 | y11;
            y33 = y33 & y11;
            y31 = y31 - y33;
            y30 = y30 & y31;
            y31 = y29;
            y34 = y29;
            y31 = y31 | y30;
            y34 = y34 & y30;
            y31 = y31 - y34;
            y31 = y31 >> 31;
            if (y31) goto label__BB4;
            goto label__BB7;
  label__BB6:
            y35 = Front(y10);
            y36 = print32(y35);
            y37 = testque_istr1();
            y38 = prints(y37);
            y39 = Dequeue(y10);
            y40 = IsEmpty(y10);
            y41 = y40;
            y41 = y41 - 1;
            y42 = y40;
            y42 = y42 * -1;
            y42 = y42 + -1;
            y41 = y41 & y42;
            y41 = y41 >> 31;
            if (y41) goto label__BB6;
            y43 = DisposeQueue(y10);
            y9 = 0;
            return y9;
  label__BB7:
            y40 = IsEmpty(y10);
            y41 = y40;
            y41 = y41 - 1;
            y42 = y40;
            y42 = y42 * -1;
            y42 = y42 + -1;
            y41 = y41 & y42;
            y41 = y41 >> 31;
            if (y41) goto label__BB6;
            y43 = DisposeQueue(y10);
            y9 = 0;
            return y9;
}
char* testque_istr1() {
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
char* testque_istr0() {
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
