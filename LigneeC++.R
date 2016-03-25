rm(list=ls())

par(mfrow=c(2,2))


Table<-read.table("/home/acathignol/Lignee/ConcentrationsIN.txt")
Table2<-read.table("/home/acathignol/Lignee/ConcentrationsOUT.txt")

#print(Table)

ainit<-Table$V1
T_<-Table$V2
GA<-Table$V3[Table$V1=="15"]
AinA<-Table$V4[Table$V1=="15"]
BinA<-Table$V5[Table$V1=="15"]
CinA<-Table$V6[Table$V1=="15"]
GB<-Table$V7[Table$V1=="15"]
AinB<-Table$V8[Table$V1=="15"]
BinB<-Table$V9[Table$V1=="15"]
CinB<-Table$V10[Table$V1=="15"]
Dead<-Table$V11[Table$V1=="15"]

x= seq(1:1:101)
plot(x,AinA[1:101], type='l',col="black",lwd=2,xlim=c(0,101), ylim=c(0,15000), main = "Concentrations In GA", ylab="Concentrations", xlab="Temps")
lines(x,BinA[1:101], lty=1,col="red")
#lines(x,CinA[1:10001] , lty=1,col="blue")
legend("topright",legend=c("[A]","[B]"), lty=c(1,1), lwd=c(2,1),col=c("black","red"))

plot(x,BinB[1:101], type='l',col="red",xlim=c(0,101), ylim=c(0,15000), main = "Concentrations In GB", ylab="Concentrations", xlab="Temps")
#lines(x,AinB[1:10001], lty=1, col="black")
lines(x,CinB[1:101], lty=1,col="blue")
legend("topright",legend=c("[B]","[C]"), lty=c(1,1), lwd=c(1,1),col=c("red","blue"))

plot(x,GA[1:101], type='l',col="green",xlim=c(0,101), ylim=c(0,1050), main = "Genotypes", ylab="Nombre de Ecoli", xlab="Temps")
lines(x,GB[1:101], lty=1,col="purple")
lines(x,Dead[1:101], lty=1,col="black",lwd=2)
legend("topright",legend=c("GA","GB","Dead"), lty=c(1,1,1), lwd=c(1,1,2),col=c("green","purple","black"))



AoutA<-Table2$V4[Table2$V1=="15"]
BoutA<-Table2$V5[Table2$V1=="15"]
CoutA<-Table2$V6[Table2$V1=="15"]
AoutB<-Table2$V8[Table2$V1=="15"]
BoutB<-Table2$V9[Table2$V1=="15"]
CoutB<-Table2$V10[Table2$V1=="15"]
AoutD<-Table2$V12[Table2$V1=="15"]
BoutD<-Table2$V13[Table2$V1=="15"]
CoutD<-Table2$V14[Table2$V1=="15"]

aout=c()
bout=c()
cout=c()
outT=c()
for(i in 1:1:101){
  aout[i]=AoutA[i]+AoutB[i]+AoutD[i]
  bout[i]=BoutA[i]+BoutB[i]+BoutD[i]
  cout[i]=CoutA[i]+CoutB[i]+CoutD[i]
  outT[i]=aout[i]+bout[i]+cout[i]
}

plot(x,aout, type='l',col="black",lwd=2, ylim=c(0,100),xlim=c(0,20), main = "Concentrations Out", ylab="Concentrations", xlab="Temps")
lines(x,bout, lty=1,col="red")
lines(x,cout,lty=1,col="blue")
legend("topright",legend=c("[A]","[B]","[C]"), lty=c(1,1,1), lwd=c(2,1,1),col=c("black","red","blue"))

MATA=c()
MATB=c()
MATC=c()

MATT=c()
for(i in 1:1:101){
  MATA[i]=AinA[i]+AinB[i]+aout[i]
  MATB[i]=BinA[i]+BinB[i]+bout[i]
  MATC[i]=CinB[i]+CinA[i]+cout[i]
  MATT[i]=MATA[i]+MATB[i]+MATC[i]
}

par(mfrow=c(1,1))

plot(x,MATA, type='l',col="black",lwd=2,xlim=c(0,100),ylim=c(0,40000), main = "Conservation/Création de la matière", ylab="Concentrations (Ainit-[A]in)", xlab="Temps")
lines(x,MATB, lty=1,col="red")
lines(x,MATC, lty=1,col="Blue")
lines(x,MATT, lty=1,col="Green")
legend("topright",legend=c("[A]","[B]","[C]","[Tot]"), lty=c(1,1,1,1), lwd=c(2,1,1,1),col=c("black","red","blue","green"))
