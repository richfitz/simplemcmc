context("simplemcmc")

test_that("simplemcmc works", {
  n <- 10 # number of dimensions
  mu <- runif(n)
  sd <- runif(n, min=1, max=10)
  pars <- c(mu, sd)
  x0 <- rnorm(n)
  w <- rep(1, n)

  samples <- mcmc_example(x0, w, 100, pars)
  ## Not really a test
  expect_equal(names(samples), c("x", "p"))
})

test_that("package works", {
  devtools::load_all("demo")

  n <- 10 # number of dimensions
  mu <- runif(n)
  sd <- runif(n, min=1, max=10)
  pars <- c(mu, sd)
  x0 <- rnorm(n)
  w <- rep(1, n)

  samples <- demo::mcmc_example(x0, w, 100, pars)
  ## Not really a test
  expect_equal(names(samples), c("x", "p"))
})
