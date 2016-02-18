//GSL libraries
#include <gsl/gsl_integration.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_deriv.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sf.h>

//other C header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <ctype.h>

#include "params.h"
#include "calc.h"
#include "integrate.h"
#include "fits.h"

//function declarations
//double n_peak(double nu);
//double polarization_term(double gamma, double n, double nu);
//double my_Bessel_J(double n, double x);
//double my_Bessel_dJ(double n, double x);
//double maxwell_juttner_f(double gamma);
//double integrand_without_extra_factor(double gamma, double n, double nu);
//double gamma_integrand(double gamma, void * params);
//double gamma_integration_result(double n, void * params);
//double n_summation(void * params);
//double n_integration(double n_minus, double nu);
//double gsl_integrate(double min, double max, double n, double nu);
//double normalize_f(int dist);
//double power_law_to_be_normalized(double gamma, void * params);
//double power_law_f(double gamma);
//double kappa_to_be_normalized(double gamma, void * params);
//double kappa_f(double gamma);
//double derivative(double n_start, double nu);
//double differential_of_f(double gamma, double nu);
//double j_nu(double nu, double B_temp, double n_e_temp, double obs_angl_temp, int dist, int pol);
//double check_for_errors(double nu, double B, double n_e, double obs_angle);
//double alpha_nu(double nu, double B_temp, double n_e_temp, 
//                double obs_angl_temp, int dist, int pol);
//double j_nu_fit(double nu, double B_temp, double n_e_temp, 
//                double obs_angl_temp, int dist, int pol);
//double alpha_nu_fit(double nu, double B_temp, double n_e_temp, 
//                    double obs_angl_temp, int dist, int pol);
//
////fitting formulae
//double thermal_I(double nu);
//double thermal_Q(double nu);
//double thermal_V(double nu);
//double planck_func(double nu);
//double thermal_I_abs(double nu);
//double thermal_Q_abs(double nu);
//double thermal_V_abs(double nu);
//double kappa_I(double nu);
//double kappa_Q(double nu);
//double kappa_V(double nu);
//double kappa_I_abs(double nu);
//double kappa_Q_abs(double nu);
//double kappa_V_abs(double nu);
//double power_law_I(double nu);
//double power_law_Q(double nu);
//double power_law_V(double nu);
//double power_law_I_abs(double nu);
//double power_law_Q_abs(double nu);
//double power_law_V_abs(double nu);