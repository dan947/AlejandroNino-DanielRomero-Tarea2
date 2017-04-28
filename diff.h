void CalFx(U_grid *U, F_grid *Fx);
void CalFy( U_grid *U, F_grid *Fy);
void CalFz( U_grid *U, F_grid *Fz);
void CalculateF( U_grid *U, F_grid *Fx,F_grid *Fy,F_grid *Fz);
void CalculateFG( physics_grid *P,U_grid *U,F_grid *Fx1,F_grid *Fx2,F_grid *Fy1,F_grid *Fy2,F_grid *Fz1,F_grid *Fz2 );
void VolumenesFinitos( U_grid *U);
FLOAT E(FLOAT rho,FLOAT e,FLOAT u,FLOAT v,FLOAT w);
FLOAT e(FLOAT p,FLOAT rho);
FLOAT PR(FLOAT U1,FLOAT U2,FLOAT U3,FLOAT U4,FLOAT U5);

