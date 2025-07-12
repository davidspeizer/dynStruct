// + Advance
// + Delete
// + DeleteList
// + Find
// + FindPrevious
// + First
// + Header
// + Insert
// + IsEmpty
// + IsLast
// + MakeEmpty
// + PrintList
// + Retrieve
// + list.istr0
// + list.istr1
// + list.istr2
// + list.istr3
// + main
// + testlist.istr0
// + testlist.istr1
// + testlist.istr2
// + testlist.istr3
// + testlist.istr4
#include <stdlib.h>
#include <stdio.h>
#include "print.h"
typedef struct struct1 struct1;
typedef struct struct2 struct2;
struct struct1 {
  int field0;
  struct1* field1;
};
struct struct2 {
  int field0;
  int field1;
};
int First(struct2* x19);
struct1* FindPrevious(int x12,struct1* x13);
char* list_istr3();
char* list_istr2();
char* list_istr1();
char* list_istr0();
int DeleteList(struct1* x17);
int* Find(int x8,struct1* x9);
int Delete(int x10,struct1* x11);
int Insert(int x14,int* x15,struct1* x16);
struct1* MakeEmpty(struct1* x4);
int main(int x2,char** x3);
int IsLast(struct1* x6,int* x7);
int Retrieve(int* x21);
struct1* Advance(struct1* x20);
int IsEmpty(struct1* x5);
struct1* Header(struct1* x18);
int PrintList(struct1* x1);
char* testlist_istr4();
char* testlist_istr3();
char* testlist_istr2();
char* testlist_istr1();
char* testlist_istr0();
int First(struct2* x19) {
  int y152;
  int y153;
  label__BB000:
            y153 = x19->field1;
            y152 = y153;
            return y152;
}
struct1* FindPrevious(int x12,struct1* x13) {
  struct1* y127;
  struct1* y128;
  struct1* y129;
  int* y130;
  int y131;
  int* y132;
  int y133;
  int y134;
  int y135;
  label__BB000:
            y128 = x13;
            goto label__BB11;
  label__BB10:
            y129 = y128->field1;
            y128 = y129;
            y130 = y128->field1;
            if (y130) goto label__BB26;
            y131 = 1;
            goto label__BB27;
  label__BB11:
            y130 = y128->field1;
            if (y130) goto label__BB26;
            y131 = 1;
            goto label__BB27;
  label__BB12:
            y127 = y128;
            return y127;
  label__BB26:
            y131 = 0;
            if (y131) goto label__BB12;
            y132 = y128->field1;
            y133 = *y132;
            y134 = y133 == x12;
            if (y134) goto label__BB28;
            y135 = 1;
            goto label__BB29;
  label__BB27:
            if (y131) goto label__BB12;
            y132 = y128->field1;
            y133 = *y132;
            y134 = y133 == x12;
            if (y134) goto label__BB28;
            y135 = 1;
            goto label__BB29;
  label__BB28:
            y135 = 0;
            if (y135) goto label__BB10;
            y127 = y128;
            return y127;
  label__BB29:
            if (y135) goto label__BB10;
            y127 = y128;
            return y127;
}
char* list_istr3() {
  char* y91;
  int y92;
  char* y93;
  char y94;
  label__BB000:
            y92 = 2;
            y91 = (char*) malloc((sizeof(char)) * y92 * 1);
            y93 = y91;
            y94 = 10;
            y93[0] = y94;
            y93 = y93 + 1;
            y94 = 0;
            y93[0] = y94;
            return y91;
}
char* list_istr2() {
  char* y87;
  int y88;
  char* y89;
  char y90;
  label__BB000:
            y88 = 16;
            y87 = (char*) malloc((sizeof(char)) * y88 * 1);
            y89 = y87;
            y90 = 79;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 117;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 116;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 32;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 111;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 102;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 32;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 115;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 112;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 97;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 99;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 101;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 33;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 33;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 33;
            y89[0] = y90;
            y89 = y89 + 1;
            y90 = 0;
            y89[0] = y90;
            return y87;
}
char* list_istr1() {
  char* y83;
  int y84;
  char* y85;
  char y86;
  label__BB000:
            y84 = 2;
            y83 = (char*) malloc((sizeof(char)) * y84 * 1);
            y85 = y83;
            y86 = 10;
            y85[0] = y86;
            y85 = y85 + 1;
            y86 = 0;
            y85[0] = y86;
            return y83;
}
char* list_istr0() {
  char* y79;
  int y80;
  char* y81;
  char y82;
  label__BB000:
            y80 = 15;
            y79 = (char*) malloc((sizeof(char)) * y80 * 1);
            y81 = y79;
            y82 = 79;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 117;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 116;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 32;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 111;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 102;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 32;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 109;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 101;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 109;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 111;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 114;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 121;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 33;
            y81[0] = y82;
            y81 = y81 + 1;
            y82 = 0;
            y81[0] = y82;
            return y79;
}
int DeleteList(struct1* x17) {
  int y145;
  struct1* y146;
  struct1* y147;
  struct1* y148;
  struct1* y149;
  struct1* y150;
  label__BB000:
            y148 = x17->field1;
            y146 = y148;
            y149 = 0;
            x17->field1 = y149;
            goto label__BB15;
  label__BB14:
            y150 = y146->field1;
            y147 = y150;
            y146 = y147;
            if (y146) goto label__BB14;
            return y145;
  label__BB15:
            if (y146) goto label__BB14;
            return y145;
}
int* Find(int x8,struct1* x9) {
  int* y113;
  struct1* y114;
  struct1* y115;
  struct1* y116;
  int y117;
  int y118;
  int y119;
  int y120;
  label__BB000:
            y115 = x9->field1;
            y114 = y115;
            goto label__BB7;
  label__BB22:
            y117 = 0;
            if (y117) goto label__BB8;
            y118 = y114->field0;
            y119 = y118 == x8;
            if (y119) goto label__BB24;
            y120 = 1;
            goto label__BB25;
  label__BB23:
            if (y117) goto label__BB8;
            y118 = y114->field0;
            y119 = y118 == x8;
            if (y119) goto label__BB24;
            y120 = 1;
            goto label__BB25;
  label__BB24:
            y120 = 0;
            if (y120) goto label__BB6;
            y113 = y114;
            return y113;
  label__BB25:
            if (y120) goto label__BB6;
            y113 = y114;
            return y113;
  label__BB6:
            y116 = y114->field1;
            y114 = y116;
            if (y114) goto label__BB22;
            y117 = 1;
            goto label__BB23;
  label__BB7:
            if (y114) goto label__BB22;
            y117 = 1;
            goto label__BB23;
  label__BB8:
            y113 = y114;
            return y113;
}
int Delete(int x10,struct1* x11) {
  int y121;
  struct1* y122;
  struct1* y123;
  int y124;
  struct1* y125;
  struct1* y126;
  label__BB000:
            y122 = FindPrevious(x10,x11);
            y124 = IsLast(y122,x11);
            if (y124) goto label__BB9;
            y125 = y122->field1;
            y123 = y125;
            y126 = y123->field1;
            y122->field1 = y126;
            return y121;
  label__BB9: return y121;
}
int Insert(int x14,int* x15,struct1* x16) {
  int y136;
  struct1* y137;
  char* y138;
  int y139;
  char* y140;
  int y141;
  int y142;
  int y143;
  struct1* y144;
  label__BB000:
            y137 = (struct1*) malloc(sizeof(struct1));
            if (y137) goto label__BB13;
            y138 = list_istr2();
            y139 = prints(y138);
            y140 = list_istr3();
            y141 = prints(y140);
            y143 = 1;
            y142 = mincexit(y143);
            y137->field0 = x14;
            y144 = x16->field1;
            y137->field1 = y144;
            x16->field1 = y137;
            return y136;
  label__BB13:
            y137->field0 = x14;
            y144 = x16->field1;
            y137->field1 = y144;
            x16->field1 = y137;
            return y136;
}
struct1* MakeEmpty(struct1* x4) {
  struct1* y95;
  int y96;
  int y97;
  char* y98;
  int y99;
  char* y100;
  int y101;
  int y102;
  int y103;
  struct1* y104;
  label__BB000:
            if (x4) goto label__BB16;
            y96 = 1;
            goto label__BB17;
  label__BB0:
            x4 = (struct1*) malloc(sizeof(struct1));
            if (x4) goto label__BB1;
            y98 = list_istr0();
            y99 = prints(y98);
            y100 = list_istr1();
            y101 = prints(y100);
            y103 = 1;
            y102 = mincexit(y103);
            y104 = 0;
            x4->field1 = y104;
            y95 = x4;
            return y95;
  label__BB1:
            y104 = 0;
            x4->field1 = y104;
            y95 = x4;
            return y95;
  label__BB16:
            y96 = 0;
            if (y96) goto label__BB0;
            y97 = DeleteList(x4);
            x4 = (struct1*) malloc(sizeof(struct1));
            if (x4) goto label__BB1;
            y98 = list_istr0();
            y99 = prints(y98);
            y100 = list_istr1();
            y101 = prints(y100);
            y103 = 1;
            y102 = mincexit(y103);
            y104 = 0;
            x4->field1 = y104;
            y95 = x4;
            return y95;
  label__BB17:
            if (y96) goto label__BB0;
            y97 = DeleteList(x4);
            x4 = (struct1*) malloc(sizeof(struct1));
            if (x4) goto label__BB1;
            y98 = list_istr0();
            y99 = prints(y98);
            y100 = list_istr1();
            y101 = prints(y100);
            y103 = 1;
            y102 = mincexit(y103);
            y104 = 0;
            x4->field1 = y104;
            y95 = x4;
            return y95;
}
int main(int x2,char** x3) {
  int y37;
  struct1* y38;
  struct1* y39;
  int y40;
  struct1* y41;
  int y42;
  int y43;
  int y44;
  int y45;
  int y46;
  int y47;
  int y48;
  int y49;
  int y50;
  int y51;
  int y52;
  int y53;
  int y54;
  int y55;
  int y56;
  int y57;
  int y58;
  int y59;
  int y60;
  int y61;
  int y62;
  int* y63;
  int y64;
  int y65;
  int y66;
  char* y67;
  int y68;
  int y69;
  int y70;
  int y71;
  int y72;
  int y73;
  int y74;
  char* y75;
  int y76;
  int y77;
  int y78;
  label__BB000:
            y41 = 0;
            y38 = MakeEmpty(y41);
            y39 = Header(y38);
            y42 = PrintList(y38);
            y40 = 0;
            goto label__BB3;
  label__BB10:
            y65 = y62 == y64;
            if (y65) goto label__BB13;
            y66 = 1;
            goto label__BB14;
  label__BB11:
            y40 = y40 + 1;
            y69 = y40;
            y69 = y69 - 10;
            y70 = y40;
            y72 = y40;
            y70 = y70 | 10;
            y72 = y72 & 10;
            y70 = y70 - y72;
            y71 = y69;
            y73 = y69;
            y71 = y71 | y40;
            y73 = y73 & y40;
            y71 = y71 - y73;
            y70 = y70 & y71;
            y71 = y69;
            y74 = y69;
            y71 = y71 | y70;
            y74 = y74 & y70;
            y71 = y71 - y74;
            y71 = y71 >> 31;
            if (y71) goto label__BB6;
            y75 = testlist_istr4();
            y76 = prints(y75);
            y77 = PrintList(y38);
            y78 = DeleteList(y38);
            y37 = 0;
            return y37;
  label__BB12:
            y69 = y40;
            y69 = y69 - 10;
            y70 = y40;
            y72 = y40;
            y70 = y70 | 10;
            y72 = y72 & 10;
            y70 = y70 - y72;
            y71 = y69;
            y73 = y69;
            y71 = y71 | y40;
            y73 = y73 & y40;
            y71 = y71 - y73;
            y70 = y70 & y71;
            y71 = y69;
            y74 = y69;
            y71 = y71 | y70;
            y74 = y74 & y70;
            y71 = y71 - y74;
            y71 = y71 >> 31;
            if (y71) goto label__BB6;
            y75 = testlist_istr4();
            y76 = prints(y75);
            y77 = PrintList(y38);
            y78 = DeleteList(y38);
            y37 = 0;
            return y37;
  label__BB13:
            y66 = 0;
            if (y66) goto label__BB11;
            y67 = testlist_istr3();
            y68 = prints(y67);
            y40 = y40 + 1;
            y69 = y40;
            y69 = y69 - 10;
            y70 = y40;
            y72 = y40;
            y70 = y70 | 10;
            y72 = y72 & 10;
            y70 = y70 - y72;
            y71 = y69;
            y73 = y69;
            y71 = y71 | y40;
            y73 = y73 & y40;
            y71 = y71 - y73;
            y70 = y70 & y71;
            y71 = y69;
            y74 = y69;
            y71 = y71 | y70;
            y74 = y74 & y70;
            y71 = y71 - y74;
            y71 = y71 >> 31;
            if (y71) goto label__BB6;
            y75 = testlist_istr4();
            y76 = prints(y75);
            y77 = PrintList(y38);
            y78 = DeleteList(y38);
            y37 = 0;
            return y37;
  label__BB14:
            if (y66) goto label__BB11;
            y67 = testlist_istr3();
            y68 = prints(y67);
            y40 = y40 + 1;
            y69 = y40;
            y69 = y69 - 10;
            y70 = y40;
            y72 = y40;
            y70 = y70 | 10;
            y72 = y72 & 10;
            y70 = y70 - y72;
            y71 = y69;
            y73 = y69;
            y71 = y71 | y40;
            y73 = y73 & y40;
            y71 = y71 - y73;
            y70 = y70 & y71;
            y71 = y69;
            y74 = y69;
            y71 = y71 | y70;
            y74 = y74 & y70;
            y71 = y71 - y74;
            y71 = y71 >> 31;
            if (y71) goto label__BB6;
            y75 = testlist_istr4();
            y76 = prints(y75);
            y77 = PrintList(y38);
            y78 = DeleteList(y38);
            y37 = 0;
            return y37;
  label__BB2:
            y43 = Insert(y40,y38,y39);
            y44 = PrintList(y38);
            y39 = Advance(y39);
            y40 = y40 + 1;
            y45 = y40;
            y45 = y45 - 10;
            y46 = y40;
            y48 = y40;
            y46 = y46 | 10;
            y48 = y48 & 10;
            y46 = y46 - y48;
            y47 = y45;
            y49 = y45;
            y47 = y47 | y40;
            y49 = y49 & y40;
            y47 = y47 - y49;
            y46 = y46 & y47;
            y47 = y45;
            y50 = y45;
            y47 = y47 | y46;
            y50 = y50 & y46;
            y47 = y47 - y50;
            y47 = y47 >> 31;
            if (y47) goto label__BB2;
            y40 = 0;
            goto label__BB5;
  label__BB3:
            y45 = y40;
            y45 = y45 - 10;
            y46 = y40;
            y48 = y40;
            y46 = y46 | 10;
            y48 = y48 & 10;
            y46 = y46 - y48;
            y47 = y45;
            y49 = y45;
            y47 = y47 | y40;
            y49 = y49 & y40;
            y47 = y47 - y49;
            y46 = y46 & y47;
            y47 = y45;
            y50 = y45;
            y47 = y47 | y46;
            y50 = y50 & y46;
            y47 = y47 - y50;
            y47 = y47 >> 31;
            if (y47) goto label__BB2;
            y40 = 0;
            goto label__BB5;
  label__BB4:
            y51 = Delete(y40,y38);
            y52 = y40;
            y52 = y52 + 2;
            y40 = y52;
            y53 = y40;
            y53 = y53 - 10;
            y54 = y40;
            y56 = y40;
            y54 = y54 | 10;
            y56 = y56 & 10;
            y54 = y54 - y56;
            y55 = y53;
            y57 = y53;
            y55 = y55 | y40;
            y57 = y57 & y40;
            y55 = y55 - y57;
            y54 = y54 & y55;
            y55 = y53;
            y58 = y53;
            y55 = y55 | y54;
            y58 = y58 & y54;
            y55 = y55 - y58;
            y55 = y55 >> 31;
            if (y55) goto label__BB4;
            y40 = 0;
            goto label__BB12;
  label__BB5:
            y53 = y40;
            y53 = y53 - 10;
            y54 = y40;
            y56 = y40;
            y54 = y54 | 10;
            y56 = y56 & 10;
            y54 = y54 - y56;
            y55 = y53;
            y57 = y53;
            y55 = y55 | y40;
            y57 = y57 & y40;
            y55 = y55 - y57;
            y54 = y54 & y55;
            y55 = y53;
            y58 = y53;
            y55 = y55 | y54;
            y58 = y58 & y54;
            y55 = y55 - y58;
            y55 = y55 >> 31;
            if (y55) goto label__BB4;
            y40 = 0;
            goto label__BB12;
  label__BB6:
            y59 = y40;
            y59 = y59 & 1;
            y60 = y59;
            y60 = y60 - 1;
            y61 = y59;
            y61 = y61 * -1;
            y61 = y61 + -1;
            y60 = y60 & y61;
            y60 = y60 >> 31;
            if (y60) goto label__BB7;
            y62 = 0;
            goto label__BB8;
  label__BB7:
            y62 = 1;
            y63 = Find(y40,y38);
            if (y63) goto label__BB9;
            y64 = 0;
            goto label__BB10;
  label__BB8:
            y63 = Find(y40,y38);
            if (y63) goto label__BB9;
            y64 = 0;
            goto label__BB10;
  label__BB9:
            y64 = 1;
            y65 = y62 == y64;
            if (y65) goto label__BB13;
            y66 = 1;
            goto label__BB14;
}
int IsLast(struct1* x6,int* x7) {
  int y109;
  int* y110;
  int y111;
  int y112;
  label__BB000:
            y110 = x6->field1;
            if (y110) goto label__BB20;
            y111 = 1;
            goto label__BB21;
  label__BB20:
            y111 = 0;
            if (y111) goto label__BB4;
            y112 = 0;
            goto label__BB5;
  label__BB21:
            if (y111) goto label__BB4;
            y112 = 0;
            goto label__BB5;
  label__BB4:
            y112 = 1;
            y109 = y112;
            return y109;
  label__BB5:
            y109 = y112;
            return y109;
}
int Retrieve(int* x21) {
  int y156;
  int y157;
  label__BB000:
            y157 = *x21;
            y156 = y157;
            return y156;
}
struct1* Advance(struct1* x20) {
  struct1* y154;
  struct1* y155;
  label__BB000:
            y155 = x20->field1;
            y154 = y155;
            return y154;
}
int IsEmpty(struct1* x5) {
  int y105;
  int* y106;
  int y107;
  int y108;
  label__BB000:
            y106 = x5->field1;
            if (y106) goto label__BB18;
            y107 = 1;
            goto label__BB19;
  label__BB18:
            y107 = 0;
            if (y107) goto label__BB2;
            y108 = 0;
            goto label__BB3;
  label__BB19:
            if (y107) goto label__BB2;
            y108 = 0;
            goto label__BB3;
  label__BB2:
            y108 = 1;
            y105 = y108;
            return y105;
  label__BB3:
            y105 = y108;
            return y105;
}
struct1* Header(struct1* x18) {
  struct1* y151;
  label__BB000:
            y151 = x18;
            return y151;
}
int PrintList(struct1* x1) {
  int y21;
  struct1* y22;
  int y23;
  int y24;
  int y25;
  char* y26;
  int y27;
  int y28;
  int y29;
  char* y30;
  int y31;
  int y32;
  int y33;
  int y34;
  char* y35;
  int y36;
  label__BB000:
            y22 = Header(x1);
            y23 = IsEmpty(x1);
            y24 = y23;
            y24 = y24 - 1;
            y25 = y23;
            y25 = y25 * -1;
            y25 = y25 + -1;
            y24 = y24 & y25;
            y24 = y24 >> 31;
            if (y24) goto label__BB0;
            y26 = testlist_istr0();
            y27 = prints(y26);
            goto label__BB1;
  label__BB0:
            y22 = Advance(y22);
            y28 = Retrieve(y22);
            y29 = print32(y28);
            y30 = testlist_istr1();
            y31 = prints(y30);
            y32 = IsLast(y22,x1);
            y33 = y32;
            y33 = y33 - 1;
            y34 = y32;
            y34 = y34 * -1;
            y34 = y34 + -1;
            y33 = y33 & y34;
            y33 = y33 >> 31;
            if (y33) goto label__BB0;
            y35 = testlist_istr2();
            y36 = prints(y35);
            return y21;
  label__BB1: return y21;
}
char* testlist_istr4() {
  char* y17;
  int y18;
  char* y19;
  char y20;
  label__BB000:
            y18 = 20;
            y17 = (char*) malloc((sizeof(char)) * y18 * 1);
            y19 = y17;
            y20 = 70;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 105;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 110;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 105;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 115;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 104;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 101;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 100;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 32;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 100;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 101;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 108;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 101;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 116;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 105;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 111;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 110;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 115;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 10;
            y19[0] = y20;
            y19 = y19 + 1;
            y20 = 0;
            y19[0] = y20;
            return y17;
}
char* testlist_istr3() {
  char* y13;
  int y14;
  char* y15;
  char y16;
  label__BB000:
            y14 = 12;
            y13 = (char*) malloc((sizeof(char)) * y14 * 1);
            y15 = y13;
            y16 = 70;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 105;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 110;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 100;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 32;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 102;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 97;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 105;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 108;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 115;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 10;
            y15[0] = y16;
            y15 = y15 + 1;
            y16 = 0;
            y15[0] = y16;
            return y13;
}
char* testlist_istr2() {
  char* y9;
  int y10;
  char* y11;
  char y12;
  label__BB000:
            y10 = 2;
            y9 = (char*) malloc((sizeof(char)) * y10 * 1);
            y11 = y9;
            y12 = 10;
            y11[0] = y12;
            y11 = y11 + 1;
            y12 = 0;
            y11[0] = y12;
            return y9;
}
char* testlist_istr1() {
  char* y5;
  int y6;
  char* y7;
  char y8;
  label__BB000:
            y6 = 2;
            y5 = (char*) malloc((sizeof(char)) * y6 * 1);
            y7 = y5;
            y8 = 32;
            y7[0] = y8;
            y7 = y7 + 1;
            y8 = 0;
            y7[0] = y8;
            return y5;
}
char* testlist_istr0() {
  char* y1;
  int y2;
  char* y3;
  char y4;
  label__BB000:
            y2 = 12;
            y1 = (char*) malloc((sizeof(char)) * y2 * 1);
            y3 = y1;
            y4 = 69;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 109;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 112;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 116;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 121;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 32;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 108;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 105;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 115;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 116;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 10;
            y3[0] = y4;
            y3 = y3 + 1;
            y4 = 0;
            y3[0] = y4;
            return y1;
}
