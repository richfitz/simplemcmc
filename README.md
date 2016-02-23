# simplemcmc

> Simple MCMC With Templates

This is an example of using templates to make a function that needs functions (e.g. an MCMC sampler, optimiser, etc) work easily enough in R + Rcpp.  See the demo package at [tests/testthat/demo](tests/testthat/demo) for use in a package (the important bit is the `LinkingTo` field in the [DESCRIPTION](tests/testthat/demo/DESCRIPTION).  The package also has the same example in `src` and `R` (which would be the model if you had a sampler that you wanted to use multiple times within a single package).

Simple MCMC With Templates

## Installation

```r
devtools::install_github("richfitz/simplemcmc")
```

## Usage

```
n <- 5
x0 <- rnorm(n)
w <- runif(n, 0, 10)
pars <- c(rnorm(n), runif(n))
samples <- simplemcmc::mcmc_example(x0, w, 1000, pars)
matplot(samples$x, type="l", lty=1)
```

## License

MIT + file LICENSE © [Rich FitzJohn](https://github.com/richfitz).
