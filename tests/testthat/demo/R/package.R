##' Simple mcmc example.  In this model the target distribution is an
##' n dimensional multivariate normal with zero correlations.  The
##' sampler will take a step from a uniform distribution with a width
##' \code{w[i] * 2}.
##'
##' @title Simple mcmc example
##' @param x0 Initial point
##' @param w Propopsal widths (uniform distribution)
##' @param nsteps Number of steps
##' @param pars Parameters (means and standard deviations)
##' @export
##' @useDynLib demo
mcmc_example <- function(x0, w, nsteps, pars) {
  if (length(w) != length(x0)) {
    stop("Incorrect length x0")
  }
  if (length(pars) != 2 * length(x0)) {
    stop("Incorrect length pars")
  }
  res <- mcmcexample_rcpp(x0, w, nsteps, pars)
  list(x=matrix(res$x, nsteps, byrow=TRUE), p=res$p)
}
