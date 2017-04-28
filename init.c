#include "struct.h"
#include "converter.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void init_to_zero(FLOAT *p, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    p[i] = 0.0;
  }
}


physics_grid * create_physics_grid(void){
  physics_grid *G;
  if(!(G = malloc(sizeof(physics_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  }

  G->L_x=0.0;
  G->L_y=0.0;
  G->L_z=0.0;
  G->delta_x=0.0;
  G->delta_y=0.0;
  G->delta_z=0.0;
  G->N_x=0;
  G->N_y=0;
  G->N_z=0;
  G->N_cells=0;
  G->P=NULL;
  G->rho=NULL;
  G->vx=NULL;
  G->vy=NULL;
  G->vz=NULL;

  return G;
}

U_grid * create_U_grid(void){
  U_grid *G;
  if(!(G = malloc(sizeof(U_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  }
  G->N_x=0.0;
  G->N_y=0.0;
  G->N_z=0.0;
  G->N_cells=0.0;
  G->U1=NULL;
  G->U2=NULL;
  G->U3=NULL;
  G->U4=NULL;
  G->U5=NULL;
  G->vx_MAX=0.0;
  G->vy_MAX=0.0;
  G->vz_MAX=0.0;
  G->px_MAX=101325;
  G->rhox_MAX=1.1768;
  G->py_MAX=101325;
  G->rhoy_MAX=1.1768;
  G->pz_MAX=101325;
  G->rhoz_MAX=1.1768;
  G->Ex=101325/(GAMMA-1);
  G->Ey=101325/(GAMMA-1);
  G->Ez=101325/(GAMMA-1);
  return G;
}

F_grid * create_F_grid(void){
  F_grid *G;
  if(!(G = malloc(sizeof(F_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  }
  G->N_x=0.0;
  G->N_y=0.0;
  G->N_z=0.0;
  G->N_cells=0.0;
  G->F1=NULL;
  G->F2=NULL;
  G->F3=NULL;
  G->F4=NULL;
  G->F5=NULL;

  return G;
}

void init_P(physics_grid *P, int problem){

  P->L_x = 256.0;
  P->L_y = 256.0;
  P->L_z = 256.0;
  P->delta_x = 2.0;
  P->delta_y = 2.0;
  P->delta_z = 2.0;
  P->N_x = (int)(P->L_x/P->delta_x);
  P->N_y = (int)(P->L_y/P->delta_y);
  P->N_z = (int)(P->L_z/P->delta_z);
  P->N_cells = P->N_x * P->N_y * P->N_z;

  if(!(P->P=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with pressure allocation");
    exit(1);
  }
  init_to_zero(P->P, P->N_cells);

  if(!(P->rho=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with pressure allocation");
    exit(1);
  }
  init_to_zero(P->rho, P->N_cells);

  if(!(P->vx=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vx allocation");
    exit(1);
  }
  init_to_zero(P->vx, P->N_cells);

  if(!(P->vy=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vy allocation");
    exit(1);
  }
  init_to_zero(P->vy, P->N_cells);
  
  if(!(P->vz=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vz allocation");
    exit(1);
  }
  init_to_zero(P->vz, P->N_cells);
}

void init_U(U_grid *U,physics_grid *P,int problem)
{

  U->N_x = P->N_x;
  U->N_y = P->N_y;
  U->N_z = P->N_z;
  U->N_cells = P->N_cells;


  if(!(U->U1=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_1 allocation");
    exit(1);
  }
  init_to_zero(U->U1, U->N_cells);

  if(!(U->U2=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U2, U->N_cells);

  if(!(U->U3=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U3, U->N_cells);

  if(!(U->U4=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U4, U->N_cells);

  if(!(U->U5=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U5, U->N_cells);
}

void init_F(F_grid *F,physics_grid *P,int problem){
  F->N_x = P->N_x;
  F->N_y = P->N_y;
  F->N_z = P->N_z;
  F->N_cells = P->N_cells;


  if(!(F->F1=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_1_X allocation");
    exit(1);
  }
  init_to_zero(F->F1, F->N_cells);

  if(!(F->F2=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_2_X allocation");
    exit(1);
  }
  init_to_zero(F->F2, F->N_cells);

  if(!(F->F3=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_3_X allocation");
    exit(1);
  }
  init_to_zero(F->F3, F->N_cells);

  if(!(F->F4=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_4_X allocation");
    exit(1);
  }
  init_to_zero(F->F4, F->N_cells);

  if(!(F->F5=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_5_X allocation");
    exit(1);
  }
  init_to_zero(F->F5, F->N_cells);
}


void init_problem(physics_grid *P,U_grid *U,F_grid *Fx,F_grid *Fy,F_grid *Fz,int problem)
{
  init_P(P,problem);
  init_U(U,P,problem);
  init_F(Fx,P,problem);
  init_F(Fy,P,problem);
  init_F(Fz,P,problem);
}

void initMatrixP(physics_grid *P,int problem)
{
  int i;

  int N=P->N_cells;
  for(i=0;i<N;i++)
  {
    P->P[i]=101325;
    P->rho[i]=1.176;
   }
}

void init_Uc(physics_grid *P,U_grid *U,int problem)
{
  FLOAT Rho;
  FLOAT pr;
  FLOAT u;
  FLOAT v;
  FLOAT w;
  FLOAT E;
  int i;
  int N=P->N_cells;
  for(i=0;i<N;i++)
  {

    Rho=P->rho[i];
    pr=P->P[i];
    u=P->vx[i];
    v=P->vy[i];
    w=P->vz[i];
    if(i==t(64,64,64))
      {
       	E=1e10;
      }
    else
      {
       	E=pr/(Rho*(GAMMA-1));
      }
    U->U1[i]=Rho;
    U->U2[i]=Rho*u;
    U->U3[i]=Rho*v;
    U->U4[i]=Rho*w;
    U->U5[i]=Rho*E;
  }
}

void init_Fc(physics_grid *P,F_grid *Fx,F_grid *Fy,F_grid *Fz,int problem)
{
  FLOAT Rho;
  FLOAT pr;
  FLOAT u;
  FLOAT v;
  FLOAT w;
  FLOAT E;
  int i;
  int N=P->N_cells;
  for(i=0;i<N;i++)
  {

    Rho=P->rho[i];
    pr=P->P[i];
    u=P->vx[i];
    v=P->vy[i];
    w=P->vz[i];
    if(i==t(64,64,64))
      {
       	E=1e10;
      }
    else
      {
       	E=pr/(Rho*(GAMMA-1));
      }

    Fx->F1[i]=Rho*u;
    Fx->F2[i]=Rho*pow(u,2)+pr;
    Fx->F3[i]=Rho*u*v;
    Fx->F4[i]=Rho*u*w;
    Fx->F5[i]=u*(Rho*E+pr);

    Fy->F1[i]=Rho*v;
    Fy->F2[i]=Rho*u*v;
    Fy->F3[i]=Rho*pow(v,2)+pr;
    Fy->F4[i]=Rho*w*v;
    Fy->F5[i]=v*(Rho*E+pr);

    Fz->F1[i]=Rho*w;
    Fz->F2[i]=Rho*u*w;
    Fz->F3[i]=Rho*v*w;
    Fz->F4[i]=Rho*pow(w,2)+pr;
    Fz->F5[i]=w*(Rho*E+pr);
  }
}



