#ifndef SYMPHONY_H_
#define SYMPHONY_H_

#include <stdio.h>
#include "params.h"
#include "fits.h"
#include "integrator/integrate.h"

double j_nu(double nu,
            double magnetic_field,
            double electron_density,
            double observer_angle,
            int distribution,
            int polarization,
            double theta_e,
            double power_law_p,
            double gamma_min,
            double gamma_max,
            double gamma_cutoff,
            double kappa,
            double kappa_width,
            char **error_message);
double alpha_nu(double nu,
                double magnetic_field,
                double electron_density,
                double observer_angle,
                int distribution,
                int polarization,
                double theta_e,
                double power_law_p,
                double gamma_min,
                double gamma_max,
                double gamma_cutoff,
                double kappa,
                double kappa_width,
                char **error_message);
#endif /* SYMPHONY_H_ */
