#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5332570688472365038) {
   out_5332570688472365038[0] = delta_x[0] + nom_x[0];
   out_5332570688472365038[1] = delta_x[1] + nom_x[1];
   out_5332570688472365038[2] = delta_x[2] + nom_x[2];
   out_5332570688472365038[3] = delta_x[3] + nom_x[3];
   out_5332570688472365038[4] = delta_x[4] + nom_x[4];
   out_5332570688472365038[5] = delta_x[5] + nom_x[5];
   out_5332570688472365038[6] = delta_x[6] + nom_x[6];
   out_5332570688472365038[7] = delta_x[7] + nom_x[7];
   out_5332570688472365038[8] = delta_x[8] + nom_x[8];
   out_5332570688472365038[9] = delta_x[9] + nom_x[9];
   out_5332570688472365038[10] = delta_x[10] + nom_x[10];
   out_5332570688472365038[11] = delta_x[11] + nom_x[11];
   out_5332570688472365038[12] = delta_x[12] + nom_x[12];
   out_5332570688472365038[13] = delta_x[13] + nom_x[13];
   out_5332570688472365038[14] = delta_x[14] + nom_x[14];
   out_5332570688472365038[15] = delta_x[15] + nom_x[15];
   out_5332570688472365038[16] = delta_x[16] + nom_x[16];
   out_5332570688472365038[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1837874623875687063) {
   out_1837874623875687063[0] = -nom_x[0] + true_x[0];
   out_1837874623875687063[1] = -nom_x[1] + true_x[1];
   out_1837874623875687063[2] = -nom_x[2] + true_x[2];
   out_1837874623875687063[3] = -nom_x[3] + true_x[3];
   out_1837874623875687063[4] = -nom_x[4] + true_x[4];
   out_1837874623875687063[5] = -nom_x[5] + true_x[5];
   out_1837874623875687063[6] = -nom_x[6] + true_x[6];
   out_1837874623875687063[7] = -nom_x[7] + true_x[7];
   out_1837874623875687063[8] = -nom_x[8] + true_x[8];
   out_1837874623875687063[9] = -nom_x[9] + true_x[9];
   out_1837874623875687063[10] = -nom_x[10] + true_x[10];
   out_1837874623875687063[11] = -nom_x[11] + true_x[11];
   out_1837874623875687063[12] = -nom_x[12] + true_x[12];
   out_1837874623875687063[13] = -nom_x[13] + true_x[13];
   out_1837874623875687063[14] = -nom_x[14] + true_x[14];
   out_1837874623875687063[15] = -nom_x[15] + true_x[15];
   out_1837874623875687063[16] = -nom_x[16] + true_x[16];
   out_1837874623875687063[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1304869096128896257) {
   out_1304869096128896257[0] = 1.0;
   out_1304869096128896257[1] = 0.0;
   out_1304869096128896257[2] = 0.0;
   out_1304869096128896257[3] = 0.0;
   out_1304869096128896257[4] = 0.0;
   out_1304869096128896257[5] = 0.0;
   out_1304869096128896257[6] = 0.0;
   out_1304869096128896257[7] = 0.0;
   out_1304869096128896257[8] = 0.0;
   out_1304869096128896257[9] = 0.0;
   out_1304869096128896257[10] = 0.0;
   out_1304869096128896257[11] = 0.0;
   out_1304869096128896257[12] = 0.0;
   out_1304869096128896257[13] = 0.0;
   out_1304869096128896257[14] = 0.0;
   out_1304869096128896257[15] = 0.0;
   out_1304869096128896257[16] = 0.0;
   out_1304869096128896257[17] = 0.0;
   out_1304869096128896257[18] = 0.0;
   out_1304869096128896257[19] = 1.0;
   out_1304869096128896257[20] = 0.0;
   out_1304869096128896257[21] = 0.0;
   out_1304869096128896257[22] = 0.0;
   out_1304869096128896257[23] = 0.0;
   out_1304869096128896257[24] = 0.0;
   out_1304869096128896257[25] = 0.0;
   out_1304869096128896257[26] = 0.0;
   out_1304869096128896257[27] = 0.0;
   out_1304869096128896257[28] = 0.0;
   out_1304869096128896257[29] = 0.0;
   out_1304869096128896257[30] = 0.0;
   out_1304869096128896257[31] = 0.0;
   out_1304869096128896257[32] = 0.0;
   out_1304869096128896257[33] = 0.0;
   out_1304869096128896257[34] = 0.0;
   out_1304869096128896257[35] = 0.0;
   out_1304869096128896257[36] = 0.0;
   out_1304869096128896257[37] = 0.0;
   out_1304869096128896257[38] = 1.0;
   out_1304869096128896257[39] = 0.0;
   out_1304869096128896257[40] = 0.0;
   out_1304869096128896257[41] = 0.0;
   out_1304869096128896257[42] = 0.0;
   out_1304869096128896257[43] = 0.0;
   out_1304869096128896257[44] = 0.0;
   out_1304869096128896257[45] = 0.0;
   out_1304869096128896257[46] = 0.0;
   out_1304869096128896257[47] = 0.0;
   out_1304869096128896257[48] = 0.0;
   out_1304869096128896257[49] = 0.0;
   out_1304869096128896257[50] = 0.0;
   out_1304869096128896257[51] = 0.0;
   out_1304869096128896257[52] = 0.0;
   out_1304869096128896257[53] = 0.0;
   out_1304869096128896257[54] = 0.0;
   out_1304869096128896257[55] = 0.0;
   out_1304869096128896257[56] = 0.0;
   out_1304869096128896257[57] = 1.0;
   out_1304869096128896257[58] = 0.0;
   out_1304869096128896257[59] = 0.0;
   out_1304869096128896257[60] = 0.0;
   out_1304869096128896257[61] = 0.0;
   out_1304869096128896257[62] = 0.0;
   out_1304869096128896257[63] = 0.0;
   out_1304869096128896257[64] = 0.0;
   out_1304869096128896257[65] = 0.0;
   out_1304869096128896257[66] = 0.0;
   out_1304869096128896257[67] = 0.0;
   out_1304869096128896257[68] = 0.0;
   out_1304869096128896257[69] = 0.0;
   out_1304869096128896257[70] = 0.0;
   out_1304869096128896257[71] = 0.0;
   out_1304869096128896257[72] = 0.0;
   out_1304869096128896257[73] = 0.0;
   out_1304869096128896257[74] = 0.0;
   out_1304869096128896257[75] = 0.0;
   out_1304869096128896257[76] = 1.0;
   out_1304869096128896257[77] = 0.0;
   out_1304869096128896257[78] = 0.0;
   out_1304869096128896257[79] = 0.0;
   out_1304869096128896257[80] = 0.0;
   out_1304869096128896257[81] = 0.0;
   out_1304869096128896257[82] = 0.0;
   out_1304869096128896257[83] = 0.0;
   out_1304869096128896257[84] = 0.0;
   out_1304869096128896257[85] = 0.0;
   out_1304869096128896257[86] = 0.0;
   out_1304869096128896257[87] = 0.0;
   out_1304869096128896257[88] = 0.0;
   out_1304869096128896257[89] = 0.0;
   out_1304869096128896257[90] = 0.0;
   out_1304869096128896257[91] = 0.0;
   out_1304869096128896257[92] = 0.0;
   out_1304869096128896257[93] = 0.0;
   out_1304869096128896257[94] = 0.0;
   out_1304869096128896257[95] = 1.0;
   out_1304869096128896257[96] = 0.0;
   out_1304869096128896257[97] = 0.0;
   out_1304869096128896257[98] = 0.0;
   out_1304869096128896257[99] = 0.0;
   out_1304869096128896257[100] = 0.0;
   out_1304869096128896257[101] = 0.0;
   out_1304869096128896257[102] = 0.0;
   out_1304869096128896257[103] = 0.0;
   out_1304869096128896257[104] = 0.0;
   out_1304869096128896257[105] = 0.0;
   out_1304869096128896257[106] = 0.0;
   out_1304869096128896257[107] = 0.0;
   out_1304869096128896257[108] = 0.0;
   out_1304869096128896257[109] = 0.0;
   out_1304869096128896257[110] = 0.0;
   out_1304869096128896257[111] = 0.0;
   out_1304869096128896257[112] = 0.0;
   out_1304869096128896257[113] = 0.0;
   out_1304869096128896257[114] = 1.0;
   out_1304869096128896257[115] = 0.0;
   out_1304869096128896257[116] = 0.0;
   out_1304869096128896257[117] = 0.0;
   out_1304869096128896257[118] = 0.0;
   out_1304869096128896257[119] = 0.0;
   out_1304869096128896257[120] = 0.0;
   out_1304869096128896257[121] = 0.0;
   out_1304869096128896257[122] = 0.0;
   out_1304869096128896257[123] = 0.0;
   out_1304869096128896257[124] = 0.0;
   out_1304869096128896257[125] = 0.0;
   out_1304869096128896257[126] = 0.0;
   out_1304869096128896257[127] = 0.0;
   out_1304869096128896257[128] = 0.0;
   out_1304869096128896257[129] = 0.0;
   out_1304869096128896257[130] = 0.0;
   out_1304869096128896257[131] = 0.0;
   out_1304869096128896257[132] = 0.0;
   out_1304869096128896257[133] = 1.0;
   out_1304869096128896257[134] = 0.0;
   out_1304869096128896257[135] = 0.0;
   out_1304869096128896257[136] = 0.0;
   out_1304869096128896257[137] = 0.0;
   out_1304869096128896257[138] = 0.0;
   out_1304869096128896257[139] = 0.0;
   out_1304869096128896257[140] = 0.0;
   out_1304869096128896257[141] = 0.0;
   out_1304869096128896257[142] = 0.0;
   out_1304869096128896257[143] = 0.0;
   out_1304869096128896257[144] = 0.0;
   out_1304869096128896257[145] = 0.0;
   out_1304869096128896257[146] = 0.0;
   out_1304869096128896257[147] = 0.0;
   out_1304869096128896257[148] = 0.0;
   out_1304869096128896257[149] = 0.0;
   out_1304869096128896257[150] = 0.0;
   out_1304869096128896257[151] = 0.0;
   out_1304869096128896257[152] = 1.0;
   out_1304869096128896257[153] = 0.0;
   out_1304869096128896257[154] = 0.0;
   out_1304869096128896257[155] = 0.0;
   out_1304869096128896257[156] = 0.0;
   out_1304869096128896257[157] = 0.0;
   out_1304869096128896257[158] = 0.0;
   out_1304869096128896257[159] = 0.0;
   out_1304869096128896257[160] = 0.0;
   out_1304869096128896257[161] = 0.0;
   out_1304869096128896257[162] = 0.0;
   out_1304869096128896257[163] = 0.0;
   out_1304869096128896257[164] = 0.0;
   out_1304869096128896257[165] = 0.0;
   out_1304869096128896257[166] = 0.0;
   out_1304869096128896257[167] = 0.0;
   out_1304869096128896257[168] = 0.0;
   out_1304869096128896257[169] = 0.0;
   out_1304869096128896257[170] = 0.0;
   out_1304869096128896257[171] = 1.0;
   out_1304869096128896257[172] = 0.0;
   out_1304869096128896257[173] = 0.0;
   out_1304869096128896257[174] = 0.0;
   out_1304869096128896257[175] = 0.0;
   out_1304869096128896257[176] = 0.0;
   out_1304869096128896257[177] = 0.0;
   out_1304869096128896257[178] = 0.0;
   out_1304869096128896257[179] = 0.0;
   out_1304869096128896257[180] = 0.0;
   out_1304869096128896257[181] = 0.0;
   out_1304869096128896257[182] = 0.0;
   out_1304869096128896257[183] = 0.0;
   out_1304869096128896257[184] = 0.0;
   out_1304869096128896257[185] = 0.0;
   out_1304869096128896257[186] = 0.0;
   out_1304869096128896257[187] = 0.0;
   out_1304869096128896257[188] = 0.0;
   out_1304869096128896257[189] = 0.0;
   out_1304869096128896257[190] = 1.0;
   out_1304869096128896257[191] = 0.0;
   out_1304869096128896257[192] = 0.0;
   out_1304869096128896257[193] = 0.0;
   out_1304869096128896257[194] = 0.0;
   out_1304869096128896257[195] = 0.0;
   out_1304869096128896257[196] = 0.0;
   out_1304869096128896257[197] = 0.0;
   out_1304869096128896257[198] = 0.0;
   out_1304869096128896257[199] = 0.0;
   out_1304869096128896257[200] = 0.0;
   out_1304869096128896257[201] = 0.0;
   out_1304869096128896257[202] = 0.0;
   out_1304869096128896257[203] = 0.0;
   out_1304869096128896257[204] = 0.0;
   out_1304869096128896257[205] = 0.0;
   out_1304869096128896257[206] = 0.0;
   out_1304869096128896257[207] = 0.0;
   out_1304869096128896257[208] = 0.0;
   out_1304869096128896257[209] = 1.0;
   out_1304869096128896257[210] = 0.0;
   out_1304869096128896257[211] = 0.0;
   out_1304869096128896257[212] = 0.0;
   out_1304869096128896257[213] = 0.0;
   out_1304869096128896257[214] = 0.0;
   out_1304869096128896257[215] = 0.0;
   out_1304869096128896257[216] = 0.0;
   out_1304869096128896257[217] = 0.0;
   out_1304869096128896257[218] = 0.0;
   out_1304869096128896257[219] = 0.0;
   out_1304869096128896257[220] = 0.0;
   out_1304869096128896257[221] = 0.0;
   out_1304869096128896257[222] = 0.0;
   out_1304869096128896257[223] = 0.0;
   out_1304869096128896257[224] = 0.0;
   out_1304869096128896257[225] = 0.0;
   out_1304869096128896257[226] = 0.0;
   out_1304869096128896257[227] = 0.0;
   out_1304869096128896257[228] = 1.0;
   out_1304869096128896257[229] = 0.0;
   out_1304869096128896257[230] = 0.0;
   out_1304869096128896257[231] = 0.0;
   out_1304869096128896257[232] = 0.0;
   out_1304869096128896257[233] = 0.0;
   out_1304869096128896257[234] = 0.0;
   out_1304869096128896257[235] = 0.0;
   out_1304869096128896257[236] = 0.0;
   out_1304869096128896257[237] = 0.0;
   out_1304869096128896257[238] = 0.0;
   out_1304869096128896257[239] = 0.0;
   out_1304869096128896257[240] = 0.0;
   out_1304869096128896257[241] = 0.0;
   out_1304869096128896257[242] = 0.0;
   out_1304869096128896257[243] = 0.0;
   out_1304869096128896257[244] = 0.0;
   out_1304869096128896257[245] = 0.0;
   out_1304869096128896257[246] = 0.0;
   out_1304869096128896257[247] = 1.0;
   out_1304869096128896257[248] = 0.0;
   out_1304869096128896257[249] = 0.0;
   out_1304869096128896257[250] = 0.0;
   out_1304869096128896257[251] = 0.0;
   out_1304869096128896257[252] = 0.0;
   out_1304869096128896257[253] = 0.0;
   out_1304869096128896257[254] = 0.0;
   out_1304869096128896257[255] = 0.0;
   out_1304869096128896257[256] = 0.0;
   out_1304869096128896257[257] = 0.0;
   out_1304869096128896257[258] = 0.0;
   out_1304869096128896257[259] = 0.0;
   out_1304869096128896257[260] = 0.0;
   out_1304869096128896257[261] = 0.0;
   out_1304869096128896257[262] = 0.0;
   out_1304869096128896257[263] = 0.0;
   out_1304869096128896257[264] = 0.0;
   out_1304869096128896257[265] = 0.0;
   out_1304869096128896257[266] = 1.0;
   out_1304869096128896257[267] = 0.0;
   out_1304869096128896257[268] = 0.0;
   out_1304869096128896257[269] = 0.0;
   out_1304869096128896257[270] = 0.0;
   out_1304869096128896257[271] = 0.0;
   out_1304869096128896257[272] = 0.0;
   out_1304869096128896257[273] = 0.0;
   out_1304869096128896257[274] = 0.0;
   out_1304869096128896257[275] = 0.0;
   out_1304869096128896257[276] = 0.0;
   out_1304869096128896257[277] = 0.0;
   out_1304869096128896257[278] = 0.0;
   out_1304869096128896257[279] = 0.0;
   out_1304869096128896257[280] = 0.0;
   out_1304869096128896257[281] = 0.0;
   out_1304869096128896257[282] = 0.0;
   out_1304869096128896257[283] = 0.0;
   out_1304869096128896257[284] = 0.0;
   out_1304869096128896257[285] = 1.0;
   out_1304869096128896257[286] = 0.0;
   out_1304869096128896257[287] = 0.0;
   out_1304869096128896257[288] = 0.0;
   out_1304869096128896257[289] = 0.0;
   out_1304869096128896257[290] = 0.0;
   out_1304869096128896257[291] = 0.0;
   out_1304869096128896257[292] = 0.0;
   out_1304869096128896257[293] = 0.0;
   out_1304869096128896257[294] = 0.0;
   out_1304869096128896257[295] = 0.0;
   out_1304869096128896257[296] = 0.0;
   out_1304869096128896257[297] = 0.0;
   out_1304869096128896257[298] = 0.0;
   out_1304869096128896257[299] = 0.0;
   out_1304869096128896257[300] = 0.0;
   out_1304869096128896257[301] = 0.0;
   out_1304869096128896257[302] = 0.0;
   out_1304869096128896257[303] = 0.0;
   out_1304869096128896257[304] = 1.0;
   out_1304869096128896257[305] = 0.0;
   out_1304869096128896257[306] = 0.0;
   out_1304869096128896257[307] = 0.0;
   out_1304869096128896257[308] = 0.0;
   out_1304869096128896257[309] = 0.0;
   out_1304869096128896257[310] = 0.0;
   out_1304869096128896257[311] = 0.0;
   out_1304869096128896257[312] = 0.0;
   out_1304869096128896257[313] = 0.0;
   out_1304869096128896257[314] = 0.0;
   out_1304869096128896257[315] = 0.0;
   out_1304869096128896257[316] = 0.0;
   out_1304869096128896257[317] = 0.0;
   out_1304869096128896257[318] = 0.0;
   out_1304869096128896257[319] = 0.0;
   out_1304869096128896257[320] = 0.0;
   out_1304869096128896257[321] = 0.0;
   out_1304869096128896257[322] = 0.0;
   out_1304869096128896257[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7297543761639843564) {
   out_7297543761639843564[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7297543761639843564[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7297543761639843564[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7297543761639843564[3] = dt*state[12] + state[3];
   out_7297543761639843564[4] = dt*state[13] + state[4];
   out_7297543761639843564[5] = dt*state[14] + state[5];
   out_7297543761639843564[6] = state[6];
   out_7297543761639843564[7] = state[7];
   out_7297543761639843564[8] = state[8];
   out_7297543761639843564[9] = state[9];
   out_7297543761639843564[10] = state[10];
   out_7297543761639843564[11] = state[11];
   out_7297543761639843564[12] = state[12];
   out_7297543761639843564[13] = state[13];
   out_7297543761639843564[14] = state[14];
   out_7297543761639843564[15] = state[15];
   out_7297543761639843564[16] = state[16];
   out_7297543761639843564[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8980341081238898912) {
   out_8980341081238898912[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8980341081238898912[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8980341081238898912[2] = 0;
   out_8980341081238898912[3] = 0;
   out_8980341081238898912[4] = 0;
   out_8980341081238898912[5] = 0;
   out_8980341081238898912[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8980341081238898912[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8980341081238898912[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8980341081238898912[9] = 0;
   out_8980341081238898912[10] = 0;
   out_8980341081238898912[11] = 0;
   out_8980341081238898912[12] = 0;
   out_8980341081238898912[13] = 0;
   out_8980341081238898912[14] = 0;
   out_8980341081238898912[15] = 0;
   out_8980341081238898912[16] = 0;
   out_8980341081238898912[17] = 0;
   out_8980341081238898912[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8980341081238898912[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8980341081238898912[20] = 0;
   out_8980341081238898912[21] = 0;
   out_8980341081238898912[22] = 0;
   out_8980341081238898912[23] = 0;
   out_8980341081238898912[24] = 0;
   out_8980341081238898912[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8980341081238898912[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8980341081238898912[27] = 0;
   out_8980341081238898912[28] = 0;
   out_8980341081238898912[29] = 0;
   out_8980341081238898912[30] = 0;
   out_8980341081238898912[31] = 0;
   out_8980341081238898912[32] = 0;
   out_8980341081238898912[33] = 0;
   out_8980341081238898912[34] = 0;
   out_8980341081238898912[35] = 0;
   out_8980341081238898912[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8980341081238898912[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8980341081238898912[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8980341081238898912[39] = 0;
   out_8980341081238898912[40] = 0;
   out_8980341081238898912[41] = 0;
   out_8980341081238898912[42] = 0;
   out_8980341081238898912[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8980341081238898912[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8980341081238898912[45] = 0;
   out_8980341081238898912[46] = 0;
   out_8980341081238898912[47] = 0;
   out_8980341081238898912[48] = 0;
   out_8980341081238898912[49] = 0;
   out_8980341081238898912[50] = 0;
   out_8980341081238898912[51] = 0;
   out_8980341081238898912[52] = 0;
   out_8980341081238898912[53] = 0;
   out_8980341081238898912[54] = 0;
   out_8980341081238898912[55] = 0;
   out_8980341081238898912[56] = 0;
   out_8980341081238898912[57] = 1;
   out_8980341081238898912[58] = 0;
   out_8980341081238898912[59] = 0;
   out_8980341081238898912[60] = 0;
   out_8980341081238898912[61] = 0;
   out_8980341081238898912[62] = 0;
   out_8980341081238898912[63] = 0;
   out_8980341081238898912[64] = 0;
   out_8980341081238898912[65] = 0;
   out_8980341081238898912[66] = dt;
   out_8980341081238898912[67] = 0;
   out_8980341081238898912[68] = 0;
   out_8980341081238898912[69] = 0;
   out_8980341081238898912[70] = 0;
   out_8980341081238898912[71] = 0;
   out_8980341081238898912[72] = 0;
   out_8980341081238898912[73] = 0;
   out_8980341081238898912[74] = 0;
   out_8980341081238898912[75] = 0;
   out_8980341081238898912[76] = 1;
   out_8980341081238898912[77] = 0;
   out_8980341081238898912[78] = 0;
   out_8980341081238898912[79] = 0;
   out_8980341081238898912[80] = 0;
   out_8980341081238898912[81] = 0;
   out_8980341081238898912[82] = 0;
   out_8980341081238898912[83] = 0;
   out_8980341081238898912[84] = 0;
   out_8980341081238898912[85] = dt;
   out_8980341081238898912[86] = 0;
   out_8980341081238898912[87] = 0;
   out_8980341081238898912[88] = 0;
   out_8980341081238898912[89] = 0;
   out_8980341081238898912[90] = 0;
   out_8980341081238898912[91] = 0;
   out_8980341081238898912[92] = 0;
   out_8980341081238898912[93] = 0;
   out_8980341081238898912[94] = 0;
   out_8980341081238898912[95] = 1;
   out_8980341081238898912[96] = 0;
   out_8980341081238898912[97] = 0;
   out_8980341081238898912[98] = 0;
   out_8980341081238898912[99] = 0;
   out_8980341081238898912[100] = 0;
   out_8980341081238898912[101] = 0;
   out_8980341081238898912[102] = 0;
   out_8980341081238898912[103] = 0;
   out_8980341081238898912[104] = dt;
   out_8980341081238898912[105] = 0;
   out_8980341081238898912[106] = 0;
   out_8980341081238898912[107] = 0;
   out_8980341081238898912[108] = 0;
   out_8980341081238898912[109] = 0;
   out_8980341081238898912[110] = 0;
   out_8980341081238898912[111] = 0;
   out_8980341081238898912[112] = 0;
   out_8980341081238898912[113] = 0;
   out_8980341081238898912[114] = 1;
   out_8980341081238898912[115] = 0;
   out_8980341081238898912[116] = 0;
   out_8980341081238898912[117] = 0;
   out_8980341081238898912[118] = 0;
   out_8980341081238898912[119] = 0;
   out_8980341081238898912[120] = 0;
   out_8980341081238898912[121] = 0;
   out_8980341081238898912[122] = 0;
   out_8980341081238898912[123] = 0;
   out_8980341081238898912[124] = 0;
   out_8980341081238898912[125] = 0;
   out_8980341081238898912[126] = 0;
   out_8980341081238898912[127] = 0;
   out_8980341081238898912[128] = 0;
   out_8980341081238898912[129] = 0;
   out_8980341081238898912[130] = 0;
   out_8980341081238898912[131] = 0;
   out_8980341081238898912[132] = 0;
   out_8980341081238898912[133] = 1;
   out_8980341081238898912[134] = 0;
   out_8980341081238898912[135] = 0;
   out_8980341081238898912[136] = 0;
   out_8980341081238898912[137] = 0;
   out_8980341081238898912[138] = 0;
   out_8980341081238898912[139] = 0;
   out_8980341081238898912[140] = 0;
   out_8980341081238898912[141] = 0;
   out_8980341081238898912[142] = 0;
   out_8980341081238898912[143] = 0;
   out_8980341081238898912[144] = 0;
   out_8980341081238898912[145] = 0;
   out_8980341081238898912[146] = 0;
   out_8980341081238898912[147] = 0;
   out_8980341081238898912[148] = 0;
   out_8980341081238898912[149] = 0;
   out_8980341081238898912[150] = 0;
   out_8980341081238898912[151] = 0;
   out_8980341081238898912[152] = 1;
   out_8980341081238898912[153] = 0;
   out_8980341081238898912[154] = 0;
   out_8980341081238898912[155] = 0;
   out_8980341081238898912[156] = 0;
   out_8980341081238898912[157] = 0;
   out_8980341081238898912[158] = 0;
   out_8980341081238898912[159] = 0;
   out_8980341081238898912[160] = 0;
   out_8980341081238898912[161] = 0;
   out_8980341081238898912[162] = 0;
   out_8980341081238898912[163] = 0;
   out_8980341081238898912[164] = 0;
   out_8980341081238898912[165] = 0;
   out_8980341081238898912[166] = 0;
   out_8980341081238898912[167] = 0;
   out_8980341081238898912[168] = 0;
   out_8980341081238898912[169] = 0;
   out_8980341081238898912[170] = 0;
   out_8980341081238898912[171] = 1;
   out_8980341081238898912[172] = 0;
   out_8980341081238898912[173] = 0;
   out_8980341081238898912[174] = 0;
   out_8980341081238898912[175] = 0;
   out_8980341081238898912[176] = 0;
   out_8980341081238898912[177] = 0;
   out_8980341081238898912[178] = 0;
   out_8980341081238898912[179] = 0;
   out_8980341081238898912[180] = 0;
   out_8980341081238898912[181] = 0;
   out_8980341081238898912[182] = 0;
   out_8980341081238898912[183] = 0;
   out_8980341081238898912[184] = 0;
   out_8980341081238898912[185] = 0;
   out_8980341081238898912[186] = 0;
   out_8980341081238898912[187] = 0;
   out_8980341081238898912[188] = 0;
   out_8980341081238898912[189] = 0;
   out_8980341081238898912[190] = 1;
   out_8980341081238898912[191] = 0;
   out_8980341081238898912[192] = 0;
   out_8980341081238898912[193] = 0;
   out_8980341081238898912[194] = 0;
   out_8980341081238898912[195] = 0;
   out_8980341081238898912[196] = 0;
   out_8980341081238898912[197] = 0;
   out_8980341081238898912[198] = 0;
   out_8980341081238898912[199] = 0;
   out_8980341081238898912[200] = 0;
   out_8980341081238898912[201] = 0;
   out_8980341081238898912[202] = 0;
   out_8980341081238898912[203] = 0;
   out_8980341081238898912[204] = 0;
   out_8980341081238898912[205] = 0;
   out_8980341081238898912[206] = 0;
   out_8980341081238898912[207] = 0;
   out_8980341081238898912[208] = 0;
   out_8980341081238898912[209] = 1;
   out_8980341081238898912[210] = 0;
   out_8980341081238898912[211] = 0;
   out_8980341081238898912[212] = 0;
   out_8980341081238898912[213] = 0;
   out_8980341081238898912[214] = 0;
   out_8980341081238898912[215] = 0;
   out_8980341081238898912[216] = 0;
   out_8980341081238898912[217] = 0;
   out_8980341081238898912[218] = 0;
   out_8980341081238898912[219] = 0;
   out_8980341081238898912[220] = 0;
   out_8980341081238898912[221] = 0;
   out_8980341081238898912[222] = 0;
   out_8980341081238898912[223] = 0;
   out_8980341081238898912[224] = 0;
   out_8980341081238898912[225] = 0;
   out_8980341081238898912[226] = 0;
   out_8980341081238898912[227] = 0;
   out_8980341081238898912[228] = 1;
   out_8980341081238898912[229] = 0;
   out_8980341081238898912[230] = 0;
   out_8980341081238898912[231] = 0;
   out_8980341081238898912[232] = 0;
   out_8980341081238898912[233] = 0;
   out_8980341081238898912[234] = 0;
   out_8980341081238898912[235] = 0;
   out_8980341081238898912[236] = 0;
   out_8980341081238898912[237] = 0;
   out_8980341081238898912[238] = 0;
   out_8980341081238898912[239] = 0;
   out_8980341081238898912[240] = 0;
   out_8980341081238898912[241] = 0;
   out_8980341081238898912[242] = 0;
   out_8980341081238898912[243] = 0;
   out_8980341081238898912[244] = 0;
   out_8980341081238898912[245] = 0;
   out_8980341081238898912[246] = 0;
   out_8980341081238898912[247] = 1;
   out_8980341081238898912[248] = 0;
   out_8980341081238898912[249] = 0;
   out_8980341081238898912[250] = 0;
   out_8980341081238898912[251] = 0;
   out_8980341081238898912[252] = 0;
   out_8980341081238898912[253] = 0;
   out_8980341081238898912[254] = 0;
   out_8980341081238898912[255] = 0;
   out_8980341081238898912[256] = 0;
   out_8980341081238898912[257] = 0;
   out_8980341081238898912[258] = 0;
   out_8980341081238898912[259] = 0;
   out_8980341081238898912[260] = 0;
   out_8980341081238898912[261] = 0;
   out_8980341081238898912[262] = 0;
   out_8980341081238898912[263] = 0;
   out_8980341081238898912[264] = 0;
   out_8980341081238898912[265] = 0;
   out_8980341081238898912[266] = 1;
   out_8980341081238898912[267] = 0;
   out_8980341081238898912[268] = 0;
   out_8980341081238898912[269] = 0;
   out_8980341081238898912[270] = 0;
   out_8980341081238898912[271] = 0;
   out_8980341081238898912[272] = 0;
   out_8980341081238898912[273] = 0;
   out_8980341081238898912[274] = 0;
   out_8980341081238898912[275] = 0;
   out_8980341081238898912[276] = 0;
   out_8980341081238898912[277] = 0;
   out_8980341081238898912[278] = 0;
   out_8980341081238898912[279] = 0;
   out_8980341081238898912[280] = 0;
   out_8980341081238898912[281] = 0;
   out_8980341081238898912[282] = 0;
   out_8980341081238898912[283] = 0;
   out_8980341081238898912[284] = 0;
   out_8980341081238898912[285] = 1;
   out_8980341081238898912[286] = 0;
   out_8980341081238898912[287] = 0;
   out_8980341081238898912[288] = 0;
   out_8980341081238898912[289] = 0;
   out_8980341081238898912[290] = 0;
   out_8980341081238898912[291] = 0;
   out_8980341081238898912[292] = 0;
   out_8980341081238898912[293] = 0;
   out_8980341081238898912[294] = 0;
   out_8980341081238898912[295] = 0;
   out_8980341081238898912[296] = 0;
   out_8980341081238898912[297] = 0;
   out_8980341081238898912[298] = 0;
   out_8980341081238898912[299] = 0;
   out_8980341081238898912[300] = 0;
   out_8980341081238898912[301] = 0;
   out_8980341081238898912[302] = 0;
   out_8980341081238898912[303] = 0;
   out_8980341081238898912[304] = 1;
   out_8980341081238898912[305] = 0;
   out_8980341081238898912[306] = 0;
   out_8980341081238898912[307] = 0;
   out_8980341081238898912[308] = 0;
   out_8980341081238898912[309] = 0;
   out_8980341081238898912[310] = 0;
   out_8980341081238898912[311] = 0;
   out_8980341081238898912[312] = 0;
   out_8980341081238898912[313] = 0;
   out_8980341081238898912[314] = 0;
   out_8980341081238898912[315] = 0;
   out_8980341081238898912[316] = 0;
   out_8980341081238898912[317] = 0;
   out_8980341081238898912[318] = 0;
   out_8980341081238898912[319] = 0;
   out_8980341081238898912[320] = 0;
   out_8980341081238898912[321] = 0;
   out_8980341081238898912[322] = 0;
   out_8980341081238898912[323] = 1;
}
void h_4(double *state, double *unused, double *out_1770650768809846521) {
   out_1770650768809846521[0] = state[6] + state[9];
   out_1770650768809846521[1] = state[7] + state[10];
   out_1770650768809846521[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6796672742843516293) {
   out_6796672742843516293[0] = 0;
   out_6796672742843516293[1] = 0;
   out_6796672742843516293[2] = 0;
   out_6796672742843516293[3] = 0;
   out_6796672742843516293[4] = 0;
   out_6796672742843516293[5] = 0;
   out_6796672742843516293[6] = 1;
   out_6796672742843516293[7] = 0;
   out_6796672742843516293[8] = 0;
   out_6796672742843516293[9] = 1;
   out_6796672742843516293[10] = 0;
   out_6796672742843516293[11] = 0;
   out_6796672742843516293[12] = 0;
   out_6796672742843516293[13] = 0;
   out_6796672742843516293[14] = 0;
   out_6796672742843516293[15] = 0;
   out_6796672742843516293[16] = 0;
   out_6796672742843516293[17] = 0;
   out_6796672742843516293[18] = 0;
   out_6796672742843516293[19] = 0;
   out_6796672742843516293[20] = 0;
   out_6796672742843516293[21] = 0;
   out_6796672742843516293[22] = 0;
   out_6796672742843516293[23] = 0;
   out_6796672742843516293[24] = 0;
   out_6796672742843516293[25] = 1;
   out_6796672742843516293[26] = 0;
   out_6796672742843516293[27] = 0;
   out_6796672742843516293[28] = 1;
   out_6796672742843516293[29] = 0;
   out_6796672742843516293[30] = 0;
   out_6796672742843516293[31] = 0;
   out_6796672742843516293[32] = 0;
   out_6796672742843516293[33] = 0;
   out_6796672742843516293[34] = 0;
   out_6796672742843516293[35] = 0;
   out_6796672742843516293[36] = 0;
   out_6796672742843516293[37] = 0;
   out_6796672742843516293[38] = 0;
   out_6796672742843516293[39] = 0;
   out_6796672742843516293[40] = 0;
   out_6796672742843516293[41] = 0;
   out_6796672742843516293[42] = 0;
   out_6796672742843516293[43] = 0;
   out_6796672742843516293[44] = 1;
   out_6796672742843516293[45] = 0;
   out_6796672742843516293[46] = 0;
   out_6796672742843516293[47] = 1;
   out_6796672742843516293[48] = 0;
   out_6796672742843516293[49] = 0;
   out_6796672742843516293[50] = 0;
   out_6796672742843516293[51] = 0;
   out_6796672742843516293[52] = 0;
   out_6796672742843516293[53] = 0;
}
void h_10(double *state, double *unused, double *out_1491379942459163146) {
   out_1491379942459163146[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1491379942459163146[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1491379942459163146[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7969231596219131792) {
   out_7969231596219131792[0] = 0;
   out_7969231596219131792[1] = 9.8100000000000005*cos(state[1]);
   out_7969231596219131792[2] = 0;
   out_7969231596219131792[3] = 0;
   out_7969231596219131792[4] = -state[8];
   out_7969231596219131792[5] = state[7];
   out_7969231596219131792[6] = 0;
   out_7969231596219131792[7] = state[5];
   out_7969231596219131792[8] = -state[4];
   out_7969231596219131792[9] = 0;
   out_7969231596219131792[10] = 0;
   out_7969231596219131792[11] = 0;
   out_7969231596219131792[12] = 1;
   out_7969231596219131792[13] = 0;
   out_7969231596219131792[14] = 0;
   out_7969231596219131792[15] = 1;
   out_7969231596219131792[16] = 0;
   out_7969231596219131792[17] = 0;
   out_7969231596219131792[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7969231596219131792[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7969231596219131792[20] = 0;
   out_7969231596219131792[21] = state[8];
   out_7969231596219131792[22] = 0;
   out_7969231596219131792[23] = -state[6];
   out_7969231596219131792[24] = -state[5];
   out_7969231596219131792[25] = 0;
   out_7969231596219131792[26] = state[3];
   out_7969231596219131792[27] = 0;
   out_7969231596219131792[28] = 0;
   out_7969231596219131792[29] = 0;
   out_7969231596219131792[30] = 0;
   out_7969231596219131792[31] = 1;
   out_7969231596219131792[32] = 0;
   out_7969231596219131792[33] = 0;
   out_7969231596219131792[34] = 1;
   out_7969231596219131792[35] = 0;
   out_7969231596219131792[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7969231596219131792[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7969231596219131792[38] = 0;
   out_7969231596219131792[39] = -state[7];
   out_7969231596219131792[40] = state[6];
   out_7969231596219131792[41] = 0;
   out_7969231596219131792[42] = state[4];
   out_7969231596219131792[43] = -state[3];
   out_7969231596219131792[44] = 0;
   out_7969231596219131792[45] = 0;
   out_7969231596219131792[46] = 0;
   out_7969231596219131792[47] = 0;
   out_7969231596219131792[48] = 0;
   out_7969231596219131792[49] = 0;
   out_7969231596219131792[50] = 1;
   out_7969231596219131792[51] = 0;
   out_7969231596219131792[52] = 0;
   out_7969231596219131792[53] = 1;
}
void h_13(double *state, double *unused, double *out_5097430592298169449) {
   out_5097430592298169449[0] = state[3];
   out_5097430592298169449[1] = state[4];
   out_5097430592298169449[2] = state[5];
}
void H_13(double *state, double *unused, double *out_813958465473184636) {
   out_813958465473184636[0] = 0;
   out_813958465473184636[1] = 0;
   out_813958465473184636[2] = 0;
   out_813958465473184636[3] = 1;
   out_813958465473184636[4] = 0;
   out_813958465473184636[5] = 0;
   out_813958465473184636[6] = 0;
   out_813958465473184636[7] = 0;
   out_813958465473184636[8] = 0;
   out_813958465473184636[9] = 0;
   out_813958465473184636[10] = 0;
   out_813958465473184636[11] = 0;
   out_813958465473184636[12] = 0;
   out_813958465473184636[13] = 0;
   out_813958465473184636[14] = 0;
   out_813958465473184636[15] = 0;
   out_813958465473184636[16] = 0;
   out_813958465473184636[17] = 0;
   out_813958465473184636[18] = 0;
   out_813958465473184636[19] = 0;
   out_813958465473184636[20] = 0;
   out_813958465473184636[21] = 0;
   out_813958465473184636[22] = 1;
   out_813958465473184636[23] = 0;
   out_813958465473184636[24] = 0;
   out_813958465473184636[25] = 0;
   out_813958465473184636[26] = 0;
   out_813958465473184636[27] = 0;
   out_813958465473184636[28] = 0;
   out_813958465473184636[29] = 0;
   out_813958465473184636[30] = 0;
   out_813958465473184636[31] = 0;
   out_813958465473184636[32] = 0;
   out_813958465473184636[33] = 0;
   out_813958465473184636[34] = 0;
   out_813958465473184636[35] = 0;
   out_813958465473184636[36] = 0;
   out_813958465473184636[37] = 0;
   out_813958465473184636[38] = 0;
   out_813958465473184636[39] = 0;
   out_813958465473184636[40] = 0;
   out_813958465473184636[41] = 1;
   out_813958465473184636[42] = 0;
   out_813958465473184636[43] = 0;
   out_813958465473184636[44] = 0;
   out_813958465473184636[45] = 0;
   out_813958465473184636[46] = 0;
   out_813958465473184636[47] = 0;
   out_813958465473184636[48] = 0;
   out_813958465473184636[49] = 0;
   out_813958465473184636[50] = 0;
   out_813958465473184636[51] = 0;
   out_813958465473184636[52] = 0;
   out_813958465473184636[53] = 0;
}
void h_14(double *state, double *unused, double *out_4255816150626229956) {
   out_4255816150626229956[0] = state[6];
   out_4255816150626229956[1] = state[7];
   out_4255816150626229956[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2833431886504031764) {
   out_2833431886504031764[0] = 0;
   out_2833431886504031764[1] = 0;
   out_2833431886504031764[2] = 0;
   out_2833431886504031764[3] = 0;
   out_2833431886504031764[4] = 0;
   out_2833431886504031764[5] = 0;
   out_2833431886504031764[6] = 1;
   out_2833431886504031764[7] = 0;
   out_2833431886504031764[8] = 0;
   out_2833431886504031764[9] = 0;
   out_2833431886504031764[10] = 0;
   out_2833431886504031764[11] = 0;
   out_2833431886504031764[12] = 0;
   out_2833431886504031764[13] = 0;
   out_2833431886504031764[14] = 0;
   out_2833431886504031764[15] = 0;
   out_2833431886504031764[16] = 0;
   out_2833431886504031764[17] = 0;
   out_2833431886504031764[18] = 0;
   out_2833431886504031764[19] = 0;
   out_2833431886504031764[20] = 0;
   out_2833431886504031764[21] = 0;
   out_2833431886504031764[22] = 0;
   out_2833431886504031764[23] = 0;
   out_2833431886504031764[24] = 0;
   out_2833431886504031764[25] = 1;
   out_2833431886504031764[26] = 0;
   out_2833431886504031764[27] = 0;
   out_2833431886504031764[28] = 0;
   out_2833431886504031764[29] = 0;
   out_2833431886504031764[30] = 0;
   out_2833431886504031764[31] = 0;
   out_2833431886504031764[32] = 0;
   out_2833431886504031764[33] = 0;
   out_2833431886504031764[34] = 0;
   out_2833431886504031764[35] = 0;
   out_2833431886504031764[36] = 0;
   out_2833431886504031764[37] = 0;
   out_2833431886504031764[38] = 0;
   out_2833431886504031764[39] = 0;
   out_2833431886504031764[40] = 0;
   out_2833431886504031764[41] = 0;
   out_2833431886504031764[42] = 0;
   out_2833431886504031764[43] = 0;
   out_2833431886504031764[44] = 1;
   out_2833431886504031764[45] = 0;
   out_2833431886504031764[46] = 0;
   out_2833431886504031764[47] = 0;
   out_2833431886504031764[48] = 0;
   out_2833431886504031764[49] = 0;
   out_2833431886504031764[50] = 0;
   out_2833431886504031764[51] = 0;
   out_2833431886504031764[52] = 0;
   out_2833431886504031764[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_5332570688472365038) {
  err_fun(nom_x, delta_x, out_5332570688472365038);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1837874623875687063) {
  inv_err_fun(nom_x, true_x, out_1837874623875687063);
}
void pose_H_mod_fun(double *state, double *out_1304869096128896257) {
  H_mod_fun(state, out_1304869096128896257);
}
void pose_f_fun(double *state, double dt, double *out_7297543761639843564) {
  f_fun(state,  dt, out_7297543761639843564);
}
void pose_F_fun(double *state, double dt, double *out_8980341081238898912) {
  F_fun(state,  dt, out_8980341081238898912);
}
void pose_h_4(double *state, double *unused, double *out_1770650768809846521) {
  h_4(state, unused, out_1770650768809846521);
}
void pose_H_4(double *state, double *unused, double *out_6796672742843516293) {
  H_4(state, unused, out_6796672742843516293);
}
void pose_h_10(double *state, double *unused, double *out_1491379942459163146) {
  h_10(state, unused, out_1491379942459163146);
}
void pose_H_10(double *state, double *unused, double *out_7969231596219131792) {
  H_10(state, unused, out_7969231596219131792);
}
void pose_h_13(double *state, double *unused, double *out_5097430592298169449) {
  h_13(state, unused, out_5097430592298169449);
}
void pose_H_13(double *state, double *unused, double *out_813958465473184636) {
  H_13(state, unused, out_813958465473184636);
}
void pose_h_14(double *state, double *unused, double *out_4255816150626229956) {
  h_14(state, unused, out_4255816150626229956);
}
void pose_H_14(double *state, double *unused, double *out_2833431886504031764) {
  H_14(state, unused, out_2833431886504031764);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
