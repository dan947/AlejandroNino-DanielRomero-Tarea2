void init_P(physics_grid *P,int problem);
void init_U( U_grid *U,physics_grid *P,int problem);
void init_F(F_grid *F,physics_grid *P,int problem);
physics_grid * create_physics_grid(void);
U_grid * create_U_grid(void);
F_grid * create_F_grid(void);
void initMatrixP(physics_grid *P,int problem);
void init_Uc(physics_grid *P,U_grid *U,int problem);
void init_Fc(physics_grid *P,F_grid *Fx,F_grid *Fy,F_grid *Fz,int problem);
void init_problem(physics_grid *P,U_grid *U,F_grid *Fx,F_grid *Fy,F_grid *Fz,int problem);

