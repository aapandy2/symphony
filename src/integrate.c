#include "integrate.h"

/*derivative: wrapper for the GSL derivative gsl_deriv_central(); used to
 *help speed up the integration over harmonic number n
 *@param n_start: Input, value of n at which the derivative is to be performed
 *@param nu: Input, frequency of absorption/emission
 */
double derivative_of_n(double n_start, struct parameters * params)
{
  gsl_function F;
  double result;
  double abserr;
  F.function = gamma_integration_result;
  F.params = params;
  gsl_deriv_central(&F, n_start, 1e-8, &result, &abserr);
  return result;

  return 0.;
}

/*normalize_f: normalizes the distribution function (power-law with cutoff
 * or kappa) using GSL's QAGIU integrator.
 *@returns: 1 over the normalization constant for the chosen distribution
 */
double normalize_f(struct parameters * params)
{
  static double ans = 0;
  if (ans != 0) return ans;
  gsl_integration_workspace * w = gsl_integration_workspace_alloc (5000);
  double result, error;
  gsl_function F;
  
  if(params->distribution == params->POWER_LAW)
  {
    F.function = &power_law_to_be_normalized;
  }
  else if(params->distribution == params->KAPPA_DIST)
  {
    F.function = &kappa_to_be_normalized;
    //TODO: Debug mode 
    //printf("SHOULD NOT GET HERE");
  }
  else
  {
    return 0;
  }

  F.params = params;
  // TODO: Remove hard coded limits
  gsl_integration_qagiu(&F, 1, 0, 1e-8, 1000,
                         w, &result, &error
                       );
  gsl_integration_workspace_free (w);
  ans = result;
  //TODO: Debug mode 
  //printf("\nRESULT of NORM = %e\n", result);
  return result;
}

//evaluates gamma integral; TODO: write more here
double gamma_integral(double min, 
                      double max, 
                      double n,
                      struct parameters * params)
{
  double nu_c = get_nu_c(*params);

  struct parametersGSL paramsGSL;
  paramsGSL.params = *params;
  paramsGSL.n      = n;

  if(params->nu/nu_c >= 1.e6)
  {
     gsl_set_error_handler_off();//trying this
  }

  double result, error;

  gsl_function F;
  F.function = &gamma_integrand;
  F.params = &paramsGSL;

  gsl_integration_workspace * w = gsl_integration_workspace_alloc (5000);

  // TODO: Remove hard coded limits
  gsl_integration_qag(&F, min, max, 0., 1.e-3, 1000,
                         3,  w, &result, &error); 

  gsl_integration_workspace_free (w);

  return result;
}

double n_integral(double min,
                  double max, 
                  double n,
                  struct parameters * params)
{
  double nu_c = get_nu_c(*params);

  if(params->nu/nu_c >= 1.e6)
  {
  gsl_set_error_handler_off();//trying this
  }

  double result, error;

  gsl_function F;
  F.function = &gamma_integration_result;
  F.params = params;

  gsl_integration_workspace * w = gsl_integration_workspace_alloc (5000);

  // TODO: Remove hard coded limits
  gsl_integration_qag(&F, min, max, 0., 1.e-3, 1000,
                         3,  w, &result, &error);

  gsl_integration_workspace_free (w);

  return result;
}
