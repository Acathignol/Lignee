rm(list=ls())

Table<-read.table("/home/acathignol/Lignee/results.txt")

par(mfrow=c(1,1))
#print(Table)
 
ainit<-Table$V1
T_<-Table$V2
results<-Table$V3

plot(T_,ainit,col=results+2, main="Diagramme de phase ! :)\nVert = Exclusion, Rouge = Extinction, Bleu = Cohabitation", pch=19, xlim=c(1,1001), xlab="Temps avant renouvellement", ylab="[Glucose] initiale")


