// -*-c++-*-
#ifndef _SIMPLEMCMC_H_
#define _SIMPLEMCMC_H_

#include <R.h>
#include <Rmath.h>
#include <Rcpp.h>

namespace simplemcmc {

template <typename Func>
Rcpp::List mcmc(Func target, std::vector<double> x0, std::vector<double> w,
                int nsteps, std::vector<double> pars) {
  const size_t len(x0.size());
  double p0 = target(x0, pars);
  std::vector<double> x1(len);

  std::vector<double> p(nsteps);
  std::vector<double> x(nsteps * len);

  std::vector<double>::iterator it = x.begin();
  for (int i = 0; i < nsteps; ++i) {
    for (int k = 0; k < len; ++k) {
      x1[k] = x0[k] + R::runif(-w[k], w[k]);
    }

    double p1 = target(x1, pars);
    if (p1 > p0 || unif_rand() < p0 - p1) {
      x0.swap(x1);
      p0 = p1;
    }

    it = std::copy(x1.begin(), x1.end(), it);
    p[i] = p0;
  }

  using  Rcpp::_;
  return Rcpp::List::create(_["x"]=x, _["p"]=p);
}

}

#endif
