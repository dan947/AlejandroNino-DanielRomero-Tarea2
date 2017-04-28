#ifndef STRUCT_H
#define STRUCT_H

#define GAMMA 1.4
#define dx 2
#define SEDOV 1
#define L 128

#define FLOAT double
typedef struct physics_grid_str
{
  FLOAT L_x;
  FLOAT L_y;
  FLOAT L_z;
  FLOAT delta_x;
  FLOAT delta_y;
  FLOAT delta_z;
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *P;
  FLOAT *rho;
  FLOAT *vx;
  FLOAT *vy;
  FLOAT *vz;

} physics_grid;

typedef struct U_grid_str{
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *U1;
  FLOAT *U2;
  FLOAT *U3;
  FLOAT *U4;
  FLOAT *U5;
  FLOAT vx_MAX;
  FLOAT vy_MAX;
  FLOAT vz_MAX;
  FLOAT px_MAX;
  FLOAT rhox_MAX;
  FLOAT py_MAX;
  FLOAT rhoy_MAX;
  FLOAT pz_MAX;
  FLOAT rhoz_MAX;
  FLOAT Ex;
  FLOAT Ey;
  FLOAT Ez;
} U_grid;


typedef struct G_grid_str{
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *F1;
  FLOAT *F2;
  FLOAT *F3;
  FLOAT *F4;
  FLOAT *F5;

} F_grid;


#endif

