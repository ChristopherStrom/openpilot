#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5332570688472365038);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1837874623875687063);
void pose_H_mod_fun(double *state, double *out_1304869096128896257);
void pose_f_fun(double *state, double dt, double *out_7297543761639843564);
void pose_F_fun(double *state, double dt, double *out_8980341081238898912);
void pose_h_4(double *state, double *unused, double *out_1770650768809846521);
void pose_H_4(double *state, double *unused, double *out_6796672742843516293);
void pose_h_10(double *state, double *unused, double *out_1491379942459163146);
void pose_H_10(double *state, double *unused, double *out_7969231596219131792);
void pose_h_13(double *state, double *unused, double *out_5097430592298169449);
void pose_H_13(double *state, double *unused, double *out_813958465473184636);
void pose_h_14(double *state, double *unused, double *out_4255816150626229956);
void pose_H_14(double *state, double *unused, double *out_2833431886504031764);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}