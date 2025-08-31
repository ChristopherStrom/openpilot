#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8319977481415482502) {
   out_8319977481415482502[0] = delta_x[0] + nom_x[0];
   out_8319977481415482502[1] = delta_x[1] + nom_x[1];
   out_8319977481415482502[2] = delta_x[2] + nom_x[2];
   out_8319977481415482502[3] = delta_x[3] + nom_x[3];
   out_8319977481415482502[4] = delta_x[4] + nom_x[4];
   out_8319977481415482502[5] = delta_x[5] + nom_x[5];
   out_8319977481415482502[6] = delta_x[6] + nom_x[6];
   out_8319977481415482502[7] = delta_x[7] + nom_x[7];
   out_8319977481415482502[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7856058601514848039) {
   out_7856058601514848039[0] = -nom_x[0] + true_x[0];
   out_7856058601514848039[1] = -nom_x[1] + true_x[1];
   out_7856058601514848039[2] = -nom_x[2] + true_x[2];
   out_7856058601514848039[3] = -nom_x[3] + true_x[3];
   out_7856058601514848039[4] = -nom_x[4] + true_x[4];
   out_7856058601514848039[5] = -nom_x[5] + true_x[5];
   out_7856058601514848039[6] = -nom_x[6] + true_x[6];
   out_7856058601514848039[7] = -nom_x[7] + true_x[7];
   out_7856058601514848039[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7751681295769521417) {
   out_7751681295769521417[0] = 1.0;
   out_7751681295769521417[1] = 0.0;
   out_7751681295769521417[2] = 0.0;
   out_7751681295769521417[3] = 0.0;
   out_7751681295769521417[4] = 0.0;
   out_7751681295769521417[5] = 0.0;
   out_7751681295769521417[6] = 0.0;
   out_7751681295769521417[7] = 0.0;
   out_7751681295769521417[8] = 0.0;
   out_7751681295769521417[9] = 0.0;
   out_7751681295769521417[10] = 1.0;
   out_7751681295769521417[11] = 0.0;
   out_7751681295769521417[12] = 0.0;
   out_7751681295769521417[13] = 0.0;
   out_7751681295769521417[14] = 0.0;
   out_7751681295769521417[15] = 0.0;
   out_7751681295769521417[16] = 0.0;
   out_7751681295769521417[17] = 0.0;
   out_7751681295769521417[18] = 0.0;
   out_7751681295769521417[19] = 0.0;
   out_7751681295769521417[20] = 1.0;
   out_7751681295769521417[21] = 0.0;
   out_7751681295769521417[22] = 0.0;
   out_7751681295769521417[23] = 0.0;
   out_7751681295769521417[24] = 0.0;
   out_7751681295769521417[25] = 0.0;
   out_7751681295769521417[26] = 0.0;
   out_7751681295769521417[27] = 0.0;
   out_7751681295769521417[28] = 0.0;
   out_7751681295769521417[29] = 0.0;
   out_7751681295769521417[30] = 1.0;
   out_7751681295769521417[31] = 0.0;
   out_7751681295769521417[32] = 0.0;
   out_7751681295769521417[33] = 0.0;
   out_7751681295769521417[34] = 0.0;
   out_7751681295769521417[35] = 0.0;
   out_7751681295769521417[36] = 0.0;
   out_7751681295769521417[37] = 0.0;
   out_7751681295769521417[38] = 0.0;
   out_7751681295769521417[39] = 0.0;
   out_7751681295769521417[40] = 1.0;
   out_7751681295769521417[41] = 0.0;
   out_7751681295769521417[42] = 0.0;
   out_7751681295769521417[43] = 0.0;
   out_7751681295769521417[44] = 0.0;
   out_7751681295769521417[45] = 0.0;
   out_7751681295769521417[46] = 0.0;
   out_7751681295769521417[47] = 0.0;
   out_7751681295769521417[48] = 0.0;
   out_7751681295769521417[49] = 0.0;
   out_7751681295769521417[50] = 1.0;
   out_7751681295769521417[51] = 0.0;
   out_7751681295769521417[52] = 0.0;
   out_7751681295769521417[53] = 0.0;
   out_7751681295769521417[54] = 0.0;
   out_7751681295769521417[55] = 0.0;
   out_7751681295769521417[56] = 0.0;
   out_7751681295769521417[57] = 0.0;
   out_7751681295769521417[58] = 0.0;
   out_7751681295769521417[59] = 0.0;
   out_7751681295769521417[60] = 1.0;
   out_7751681295769521417[61] = 0.0;
   out_7751681295769521417[62] = 0.0;
   out_7751681295769521417[63] = 0.0;
   out_7751681295769521417[64] = 0.0;
   out_7751681295769521417[65] = 0.0;
   out_7751681295769521417[66] = 0.0;
   out_7751681295769521417[67] = 0.0;
   out_7751681295769521417[68] = 0.0;
   out_7751681295769521417[69] = 0.0;
   out_7751681295769521417[70] = 1.0;
   out_7751681295769521417[71] = 0.0;
   out_7751681295769521417[72] = 0.0;
   out_7751681295769521417[73] = 0.0;
   out_7751681295769521417[74] = 0.0;
   out_7751681295769521417[75] = 0.0;
   out_7751681295769521417[76] = 0.0;
   out_7751681295769521417[77] = 0.0;
   out_7751681295769521417[78] = 0.0;
   out_7751681295769521417[79] = 0.0;
   out_7751681295769521417[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8580266784932828914) {
   out_8580266784932828914[0] = state[0];
   out_8580266784932828914[1] = state[1];
   out_8580266784932828914[2] = state[2];
   out_8580266784932828914[3] = state[3];
   out_8580266784932828914[4] = state[4];
   out_8580266784932828914[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8580266784932828914[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8580266784932828914[7] = state[7];
   out_8580266784932828914[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5223163587251609359) {
   out_5223163587251609359[0] = 1;
   out_5223163587251609359[1] = 0;
   out_5223163587251609359[2] = 0;
   out_5223163587251609359[3] = 0;
   out_5223163587251609359[4] = 0;
   out_5223163587251609359[5] = 0;
   out_5223163587251609359[6] = 0;
   out_5223163587251609359[7] = 0;
   out_5223163587251609359[8] = 0;
   out_5223163587251609359[9] = 0;
   out_5223163587251609359[10] = 1;
   out_5223163587251609359[11] = 0;
   out_5223163587251609359[12] = 0;
   out_5223163587251609359[13] = 0;
   out_5223163587251609359[14] = 0;
   out_5223163587251609359[15] = 0;
   out_5223163587251609359[16] = 0;
   out_5223163587251609359[17] = 0;
   out_5223163587251609359[18] = 0;
   out_5223163587251609359[19] = 0;
   out_5223163587251609359[20] = 1;
   out_5223163587251609359[21] = 0;
   out_5223163587251609359[22] = 0;
   out_5223163587251609359[23] = 0;
   out_5223163587251609359[24] = 0;
   out_5223163587251609359[25] = 0;
   out_5223163587251609359[26] = 0;
   out_5223163587251609359[27] = 0;
   out_5223163587251609359[28] = 0;
   out_5223163587251609359[29] = 0;
   out_5223163587251609359[30] = 1;
   out_5223163587251609359[31] = 0;
   out_5223163587251609359[32] = 0;
   out_5223163587251609359[33] = 0;
   out_5223163587251609359[34] = 0;
   out_5223163587251609359[35] = 0;
   out_5223163587251609359[36] = 0;
   out_5223163587251609359[37] = 0;
   out_5223163587251609359[38] = 0;
   out_5223163587251609359[39] = 0;
   out_5223163587251609359[40] = 1;
   out_5223163587251609359[41] = 0;
   out_5223163587251609359[42] = 0;
   out_5223163587251609359[43] = 0;
   out_5223163587251609359[44] = 0;
   out_5223163587251609359[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5223163587251609359[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5223163587251609359[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5223163587251609359[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5223163587251609359[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5223163587251609359[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5223163587251609359[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5223163587251609359[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5223163587251609359[53] = -9.8100000000000005*dt;
   out_5223163587251609359[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5223163587251609359[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5223163587251609359[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5223163587251609359[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5223163587251609359[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5223163587251609359[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5223163587251609359[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5223163587251609359[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5223163587251609359[62] = 0;
   out_5223163587251609359[63] = 0;
   out_5223163587251609359[64] = 0;
   out_5223163587251609359[65] = 0;
   out_5223163587251609359[66] = 0;
   out_5223163587251609359[67] = 0;
   out_5223163587251609359[68] = 0;
   out_5223163587251609359[69] = 0;
   out_5223163587251609359[70] = 1;
   out_5223163587251609359[71] = 0;
   out_5223163587251609359[72] = 0;
   out_5223163587251609359[73] = 0;
   out_5223163587251609359[74] = 0;
   out_5223163587251609359[75] = 0;
   out_5223163587251609359[76] = 0;
   out_5223163587251609359[77] = 0;
   out_5223163587251609359[78] = 0;
   out_5223163587251609359[79] = 0;
   out_5223163587251609359[80] = 1;
}
void h_25(double *state, double *unused, double *out_1671475450152858479) {
   out_1671475450152858479[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1501874552027792962) {
   out_1501874552027792962[0] = 0;
   out_1501874552027792962[1] = 0;
   out_1501874552027792962[2] = 0;
   out_1501874552027792962[3] = 0;
   out_1501874552027792962[4] = 0;
   out_1501874552027792962[5] = 0;
   out_1501874552027792962[6] = 1;
   out_1501874552027792962[7] = 0;
   out_1501874552027792962[8] = 0;
}
void h_24(double *state, double *unused, double *out_540195808638615030) {
   out_540195808638615030[0] = state[4];
   out_540195808638615030[1] = state[5];
}
void H_24(double *state, double *unused, double *out_670775046977706604) {
   out_670775046977706604[0] = 0;
   out_670775046977706604[1] = 0;
   out_670775046977706604[2] = 0;
   out_670775046977706604[3] = 0;
   out_670775046977706604[4] = 1;
   out_670775046977706604[5] = 0;
   out_670775046977706604[6] = 0;
   out_670775046977706604[7] = 0;
   out_670775046977706604[8] = 0;
   out_670775046977706604[9] = 0;
   out_670775046977706604[10] = 0;
   out_670775046977706604[11] = 0;
   out_670775046977706604[12] = 0;
   out_670775046977706604[13] = 0;
   out_670775046977706604[14] = 1;
   out_670775046977706604[15] = 0;
   out_670775046977706604[16] = 0;
   out_670775046977706604[17] = 0;
}
void h_30(double *state, double *unused, double *out_5533158926581360131) {
   out_5533158926581360131[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4020207510535041589) {
   out_4020207510535041589[0] = 0;
   out_4020207510535041589[1] = 0;
   out_4020207510535041589[2] = 0;
   out_4020207510535041589[3] = 0;
   out_4020207510535041589[4] = 1;
   out_4020207510535041589[5] = 0;
   out_4020207510535041589[6] = 0;
   out_4020207510535041589[7] = 0;
   out_4020207510535041589[8] = 0;
}
void h_26(double *state, double *unused, double *out_5978828971517713268) {
   out_5978828971517713268[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4806400521788593563) {
   out_4806400521788593563[0] = 0;
   out_4806400521788593563[1] = 0;
   out_4806400521788593563[2] = 0;
   out_4806400521788593563[3] = 0;
   out_4806400521788593563[4] = 0;
   out_4806400521788593563[5] = 0;
   out_4806400521788593563[6] = 0;
   out_4806400521788593563[7] = 1;
   out_4806400521788593563[8] = 0;
}
void h_27(double *state, double *unused, double *out_2653559543488156591) {
   out_2653559543488156591[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6243801581718984806) {
   out_6243801581718984806[0] = 0;
   out_6243801581718984806[1] = 0;
   out_6243801581718984806[2] = 0;
   out_6243801581718984806[3] = 1;
   out_6243801581718984806[4] = 0;
   out_6243801581718984806[5] = 0;
   out_6243801581718984806[6] = 0;
   out_6243801581718984806[7] = 0;
   out_6243801581718984806[8] = 0;
}
void h_29(double *state, double *unused, double *out_7911911879467345840) {
   out_7911911879467345840[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4530438854849433773) {
   out_4530438854849433773[0] = 0;
   out_4530438854849433773[1] = 1;
   out_4530438854849433773[2] = 0;
   out_4530438854849433773[3] = 0;
   out_4530438854849433773[4] = 0;
   out_4530438854849433773[5] = 0;
   out_4530438854849433773[6] = 0;
   out_4530438854849433773[7] = 0;
   out_4530438854849433773[8] = 0;
}
void h_28(double *state, double *unused, double *out_3553598243992464464) {
   out_3553598243992464464[0] = state[0];
}
void H_28(double *state, double *unused, double *out_551960162220096801) {
   out_551960162220096801[0] = 1;
   out_551960162220096801[1] = 0;
   out_551960162220096801[2] = 0;
   out_551960162220096801[3] = 0;
   out_551960162220096801[4] = 0;
   out_551960162220096801[5] = 0;
   out_551960162220096801[6] = 0;
   out_551960162220096801[7] = 0;
   out_551960162220096801[8] = 0;
}
void h_31(double *state, double *unused, double *out_5295839714528174015) {
   out_5295839714528174015[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4180192419555242087) {
   out_4180192419555242087[0] = 0;
   out_4180192419555242087[1] = 0;
   out_4180192419555242087[2] = 0;
   out_4180192419555242087[3] = 0;
   out_4180192419555242087[4] = 0;
   out_4180192419555242087[5] = 0;
   out_4180192419555242087[6] = 0;
   out_4180192419555242087[7] = 0;
   out_4180192419555242087[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8319977481415482502) {
  err_fun(nom_x, delta_x, out_8319977481415482502);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7856058601514848039) {
  inv_err_fun(nom_x, true_x, out_7856058601514848039);
}
void car_H_mod_fun(double *state, double *out_7751681295769521417) {
  H_mod_fun(state, out_7751681295769521417);
}
void car_f_fun(double *state, double dt, double *out_8580266784932828914) {
  f_fun(state,  dt, out_8580266784932828914);
}
void car_F_fun(double *state, double dt, double *out_5223163587251609359) {
  F_fun(state,  dt, out_5223163587251609359);
}
void car_h_25(double *state, double *unused, double *out_1671475450152858479) {
  h_25(state, unused, out_1671475450152858479);
}
void car_H_25(double *state, double *unused, double *out_1501874552027792962) {
  H_25(state, unused, out_1501874552027792962);
}
void car_h_24(double *state, double *unused, double *out_540195808638615030) {
  h_24(state, unused, out_540195808638615030);
}
void car_H_24(double *state, double *unused, double *out_670775046977706604) {
  H_24(state, unused, out_670775046977706604);
}
void car_h_30(double *state, double *unused, double *out_5533158926581360131) {
  h_30(state, unused, out_5533158926581360131);
}
void car_H_30(double *state, double *unused, double *out_4020207510535041589) {
  H_30(state, unused, out_4020207510535041589);
}
void car_h_26(double *state, double *unused, double *out_5978828971517713268) {
  h_26(state, unused, out_5978828971517713268);
}
void car_H_26(double *state, double *unused, double *out_4806400521788593563) {
  H_26(state, unused, out_4806400521788593563);
}
void car_h_27(double *state, double *unused, double *out_2653559543488156591) {
  h_27(state, unused, out_2653559543488156591);
}
void car_H_27(double *state, double *unused, double *out_6243801581718984806) {
  H_27(state, unused, out_6243801581718984806);
}
void car_h_29(double *state, double *unused, double *out_7911911879467345840) {
  h_29(state, unused, out_7911911879467345840);
}
void car_H_29(double *state, double *unused, double *out_4530438854849433773) {
  H_29(state, unused, out_4530438854849433773);
}
void car_h_28(double *state, double *unused, double *out_3553598243992464464) {
  h_28(state, unused, out_3553598243992464464);
}
void car_H_28(double *state, double *unused, double *out_551960162220096801) {
  H_28(state, unused, out_551960162220096801);
}
void car_h_31(double *state, double *unused, double *out_5295839714528174015) {
  h_31(state, unused, out_5295839714528174015);
}
void car_H_31(double *state, double *unused, double *out_4180192419555242087) {
  H_31(state, unused, out_4180192419555242087);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
