#ifndef SYMPHONY_PARAMS_H_
#define SYMPHONY_PARAMS_H_

#include <math.h>

struct parameters
{
  //parameters of calculation
  //we use Gaussian CGS units
  double pi;        
  double mass_electron;
  double plancks_constant;
  double speed_light;
  double electron_charge;
  double n_max;
  int    C;       
  // Keys for the distributions
  int    THERMAL;
  int    POWER_LAW;
  int    KAPPA_DIST;
  // Keys for the polarization modes
  int    STOKES_I;
  int    STOKES_Q;
  int    STOKES_U;
  int    STOKES_V;
  // Keys for the mode: absorptivity or emmisivity
  int    ABSORPTIVITY;
  int    EMISSIVITY;

  // USER PARAMS:
  double nu;               // GHz
  double magnetic_field;   // Gauss
  double electron_density; // g/cc
  double observer_angle;   // rad  
  int    distribution;     
  int    polarization; 
  int    mode;             // Emissivity or Absorptivity
  double gamma_cutoff;

  // Thermal distribution parameters
  double theta_e;

  //power law parameters
  double power_law_p;
  double gamma_min;
  double gamma_max;

  //kappa distribution parameters
  double kappa;
  double kappa_width;

  int stokes_v_switch;
};

struct parametersGSL
{
  struct parameters params;
  double n;
};

void setConstParams(struct parameters *params);
void setUserParams(struct parameters *params);

#endif /* SYMPHONY_PARAMS_H_ */