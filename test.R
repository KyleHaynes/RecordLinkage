# installing
formals(quit)$save <- formals(q)$save <- "no"

setwd("C:\\Users\\Kyle\\Desktop\\RecordLinkage")

remove.packages("RecordLinkage")

devtools::install_local(force = T, upgrade = "never", INSTALL_opts='--no-multiarch')

RecordLinkage::jarowinkler("cat", "kat")


