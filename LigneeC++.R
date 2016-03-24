rm(list=ls())

par(mfrow=c(2,2))


Table<-read.table("/home/acathignol/Lignee/ConcentrationsIN.txt")
Table2<-read.table("/home/acathignol/Lignee/ConcentrationsOUT.txt")



#print(Table)

ainit<-Table$V1
T_<-Table$V2
GA<-Table$V3[Table$V1=="5"][1:10001]
AinA<-Table$V4[Table$V1=="5"][1:10001]
BinA<-Table$V5[Table$V1=="5"][1:10001]
GB<-Table$V7[Table$V1=="5"][1:10001]
BinB<-Table$V9[Table$V1=="5"][1:10001]
CinB<-Table$V10[Table$V1=="5"][1:10001]
Dead<-Table$V11[Table$V1=="5"][1:10001]

x= seq(1:1:10001)
plot(x,AinA, type='l',col="black",lwd=2, ylim=c(0,3.5),xlim=c(0,5000), main = "Concentrations In GA", ylab="Concentrations", xlab="Temps")
lines(x,BinA, lty=1,col="red")
#lines(x,CinA[1:10001] , lty=1,col="blue")
legend("topright",legend=c("[A]","[B]"), lty=c(1,1), lwd=c(2,1),col=c("black","red"))

plot(x,BinB, type='l',col="red", ylim=c(0,0.5),xlim=c(0,5000), main = "Concentrations In GB", ylab="Concentrations", xlab="Temps")
#lines(x,AinB[1:10001], lty=1, col="black")
lines(x,CinB, lty=1,col="blue")
legend("topright",legend=c("[B]","[C]"), lty=c(1,1), lwd=c(1,1),col=c("red","blue"))

plot(x,GA, type='l',col="green", ylim=c(0,1000),xlim=c(0,5000), main = "Genotypes", ylab="Nombre de Ecoli", xlab="Temps")
lines(x,GB, lty=1,col="purple")
lines(x,Dead, lty=1,col="black",lwd=2)
legend("topright",legend=c("GA","GB","Dead"), lty=c(1,1,1), lwd=c(1,1,2),col=c("green","purple","black"))



AoutA<-Table2$V4[Table2$V1=="5"]
BoutA<-Table2$V5[Table2$V1=="5"]
CoutA<-Table2$V6[Table2$V1=="5"]
AoutB<-Table2$V8[Table2$V1=="5"]
BoutB<-Table2$V9[Table2$V1=="5"]
CoutB<-Table2$V10[Table2$V1=="5"]
AoutD<-Table2$V4[Table2$V1=="5"]
BoutD<-Table2$V5[Table2$V1=="5"]
CoutD<-Table2$V6[Table2$V1=="5"]

aout=c()
bout=c()
cout=c()
for(i in 1:1:10001){
  aout[i]=AoutA[i]+AoutB[i]+AoutD[i]
  bout[i]=BoutA[i]+BoutB[i]+BoutD[i]
  cout[i]=CoutA[i]+CoutB[i]+CoutD[i]
}

x= seq(1:1:10001)
plot(x,aout, type='l',col="black",lwd=2, ylim=c(0,20),xlim=c(0,5000), main = "Concentrations Out", ylab="Concentrations", xlab="Temps")
lines(x,bout, lty=1,col="red")
lines(x,cout,lty=1,col="blue")
legend("topright",legend=c("[A]","[B]","[C]"), lty=c(1,1,1), lwd=c(2,1,1),col=c("black","red","blue"))

MATA=c()
MATB=c()
for(i in 1:1:10001){
  MATA[i]=5-AinA[i]
  MATB[i]=5-(BinA[i])
}

plot(x,MATA, type='l',col="black",lwd=2, ylim=c(0,20),xlim=c(0,5000), main = "Conservation/Création de la matière", ylab="Concentrations (Ainit-[A]in)", xlab="Temps")
lines(x,MATB, lty=1,col="red")
legend("topright",legend=c("[A]","[B]"), lty=c(1,1), lwd=c(2,1),col=c("black","red")
