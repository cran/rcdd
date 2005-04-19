addH <- function(x, a, b, equality = TRUE) {

    fred <- attr(x, "representation")
    if (! is.null(fred))
        if (fred != "H")
            error("argument x must be H-representation")

    validcdd(x)

    if (! is.matrix(a))
        a <- matrix(a, nrow = 1)
    if (nrow(a) != length(b))
        stop("nrow(a) != length(b)")

    if (! is.logical(equality))
        stop("argument equality must be logical")
    if (length(equality) != 1)
        stop("argument equality must be scalar")

    foo <- cbind(as.numeric(equality), b, - a)
    if (ncol(foo) != ncol(x))
        stop("matrices not of conforming dimension")
    foo <- rbind(x, foo)
    dimnames(foo) <- NULL
    attr(foo, "representation") <- "H"
    validcdd(foo)
    return(foo)
}
