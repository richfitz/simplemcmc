#include <simplemcmc.h>

// [[Rcpp::export]]
double target(const std::vector<double> &x,
              const std::vector<double> &pars) {
  const size_t len = pars.size() / 2;
  const double* mu = &pars[0];
  const double* sd = mu + len;
  double tot = 0.0;
  for (size_t i = 0; i < len; ++i) {
    tot += R::dnorm(x[i], mu[i], sd[i], 1);
  }
  return tot;
}

// [[Rcpp::export]]
Rcpp::List mcmcexample_rcpp(std::vector<double> x0, std::vector<double> w,
                       int nsteps, std::vector<double> pars) {
  return simplemcmc::mcmc(target, x0, w, nsteps, pars);
}
