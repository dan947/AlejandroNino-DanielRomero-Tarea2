#include <stdio.h>
#include "struct.h"
#include "init.h"
#include "io.h"
#include "diff.h"
#include "converter.h"

int main(int argc, char **argv){

  float R[3];
  R[0]=5;
  R[1]=30;
  R[2]=60;

  physics_grid * P_state;
  U_grid * U_state;
  F_grid * Fx_state;
  Fx_state= create_F_grid();

  F_grid * Fy_state;
  Fy_state= create_F_grid();
  F_grid * Fz_state;
  Fz_state= create_F_grid();

  P_state = create_physics_grid();
  U_state = create_U_grid();

  init_problem(P_state, U_state, Fx_state,Fy_state,Fz_state, SEDOV);
  initMatrixP(P_state,SEDOV);
  init_Uc(P_state,U_state,SEDOV);

  int j;
  for(j=0;j<28;j++)
  {
    VolumenesFinitos(U_state);
  }

  int o;
  for(o=0;o<3;o++)
    {
      float sum=0;
      float casillas=0;
      int r;
      r=R[o];
      int i;
      int k;
      for(j=64-r;j<64+1+r;j++){
	for(i=64-r;i<64+1+r;i++){
	  sum += U_state->U1[t(i,j,64-r)];
	  sum += U_state->U1[t(i,j,64+r)];
      }
    }

    for(j=64-r;j<64+1+r;j++){
      for(k=64-r+1;k<64+r;k++){
        sum += U_state->U1[t(64-r,j,k)];
        sum += U_state->U1[t(64+r,j,k)];
      }
    }

    for(k=64-r+1;k<64+r;k++){
      for(i=64-r+1;i<64+r;i++){
        sum += U_state->U1[t(i,64-r,k)];
        sum += U_state->U1[t(i,64+r,k)];
      }
    }
   casillas = 2*((2*r)*(2*r)) + 2*((2*(r-2))*(2+r)) + 2*( (2*(r-2))*(2*(r-2)));
   printf("%f %f \n",sum/casillas,0.000001*27);
  }
  return 0;
}

