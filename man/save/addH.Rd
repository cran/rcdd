\name{addH}
\alias{addH}
\title{add rows to H-representation of convex polyhedron}
\usage{
addH(x, a, b, equality = TRUE)
}
\description{
Add new rows to H-representation of convex polyhedron.
See \code{\link{scdd}} for description of valid representations.
See \code{\link{makeH}} for construction of valid representations.
}
\arguments{
  \item{x}{an already valid H-representation.}
  \item{a}{numerical matrix for constraints.  If vector, treated
      as matrix with one row.}
  \item{b}{numerical right hand side vector for constraints.}
  \item{equality}{If \code{TRUE} added constraints are equality constraints
      \code{a \%*\% x == b}, otherwise inequality constraints
      \code{a \%*\% x <= b}.}
}
\value{
  a cdd object that can be handed to \code{\link{scdd}}.
}
\seealso{\code{\link{scdd}}, \code{\link{makeH}}}
\examples{
d <- 4
# unit simplex in H-representation
qux <- makeH(- diag(d), rep(0, d), rep(1, d), 1)
print(qux)
# add an equality constraint
qux <- addH(qux, 1:d, (d + 1) / 2)
print(qux)
# add an inequality constraint
qux <- addH(qux, c(1, -1, 0, 0), 0, FALSE)
print(qux)
# drop a constraint
qux <- qux[- 3, ]
print(qux)
}
\keyword{misc}

