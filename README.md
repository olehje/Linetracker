Stasjon 2: Få roboten til å følge en linje på gulvet
På denne stasjon skal du få roboten til å følge en linje på gulvet. Foran på roboten kan du se en sensor med tre LED’er. Disse kan brukes til å måle om en farve er lys eller mørk, og derfor kan vi bruke den til å følge en linje som er i kontrast til baggrunden. Det forventes ikke at du kan lage alle øvelserne selv, men det vil være mentorer tilstede som kan hjelpe med disse.
Al kode er markeret med grøn tekst som du kan kopiere ind i dit program, dersom du ikke vil skrive det selv 😊
På dette link finder du en færdig versjon af koden du skal lave, og du kan hente hjelp her dersom du trenger det. Det vil i hver oppgave også være henvisninger til bestemte linjer kode i denne fil.
Dersom du allerede har gjennemført noen af øvelserne på en tidligere stasjon trenger du ikke å lage disse igjen, men du kan bruke koden fra tidligere. Husk derfor å lagre dit program når du er ferdig.
Bliver du ferdig med øvelserne før tid, kan du enten velge å fortsette med de foreslåtte øvelser eller å lage dit eget program.
Opgaver:
1.	Start med å åpne et tomt Arduino program.
2.	Først skal vi få roboten til å kjøre frem. For å bruke de fire motorer på roboten må vi tilføje disse fem linjer i starten af programmet:

#include <UCMotor.h>
UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

Nå kan du styre hver enkelt motor ved å give den en retning og en hastighed. Hvis du for eksempel vil få venstre motor foran til å kjøre frem må du skrive dette i din loop funksjon:
leftMotor1.run(0x01); 			(“0x02” vil få motoren til å kjøre baglæns)
leftMotor1.setSpeed(200);		(farten sættes her til 200)

3.	For å skabe mere overblik i programmet, kan du lave funksjoner, som indeholder kode. Nu skal du lave en funksjon der får roboten til å kjøre frem (som du gjorde i forrige opgave). Et eksempel på en funksjon er dette:

void minFunksjon() {
    // mellem disse to “{ }” skal du skrive alt det kode, som din funksjon skal udføre.
}

Du kjører din funktion ved å skrive funksjonens navn:
	
void loop() {
minFunksjon();
}

4.	Lav nu funksjoner der får roboten til å:		(SE LINJE 93-131 I FERDIG VERSJON)
a.	Kjøre til venstre
b.	Kjøre til højre
c.	Kjøre tilbake
d.	Stoppe
Husk at du må bruke «delay()» mellem hver funksjon du kjører. Dette får programmet til å vente med å kjøre videre i programmet. Hvis du for eksempel vil kjøre frem i to sekunder, må du skrive:
funksjon_frem();
delay(2000);
funksjon_stop();

5.	Nå er du klar til å hente data fra robotens linje-følger sensor. Denne sensor inneholder tre sensorer, som kan brukes til å måle om en farve er lys eller mørk. For å definere hvilke porte disse sensorer er sluttet til på Arduinoen, skal du skrive disse tre linjer kode i starten af programmet. (SE LINJE 7-9 I FÆRDIG VERSJON)

#define leftSensor    A0
#define middleSensor  A1
#define rightSensor   13
Og denne linje må du sette ind i din setup funksjon (LINJE 17-19 I FERDIG VERSJON):
Serial.begin(9600);
Du kan hente data fra de tre sensorer ved å skrive «digitalRead(pin)». Disse data kan gemmes som tre forskjellige variabler. Du kan printe de to variabler ved å bruke Serial.print(). Se eksemplet herunder:
void loop() {
int left = digitalRead(leftSensor); 
int middle = digitalRead(middleSensor);
int right = digitalRead(rightSensor);

Serial.print("left = "); Serial.println(left);
Serial.print("middle = "); Serial.println(middle);
Serial.print("right = "); Serial.println(right)
Serial.println("");

delay(20);
}
	Prøv å kopiere koden herover og se hvordan de tre sensorer reagerer på svarte og hvite overflater.

6.	For å få roboten til å følge en linje på gulvet må vi bruke verdierne fra alle tre sensorer.  Vi skal ut fra disse data bestemme hvilken af disse fire muligheter den skal vælge:
a.	Kjør ret frem: hvis roboten er i midten af den hvite strek.
b.	Kjør til højre: hvis roboten er til venstre for den hvite strek.
c.	Kjør til venstre: hvis roboten er til højre for den hvite strek.
d.	Kjør tilbake: hvis sensoren ikke kan finde den hvite strek.

Prøv å skrive if/else betingelser, der får roboten til å følge streken, ved å kjøre de funksjoner du skrev  i øvelse 4. Tag en måling af lyset 50 gange i sekundet (delay(20)). (LINJE 34-61 I FERDIG VERSJON):
7.	Du er nå klar til å teste dit ferdige program. Prøv å få roboten til å følge en hvit strek på en svart overflate.

8.	Har du mere tid kan du få roboten til å stoppe hvis der kommer en forhindring. For å bruke afstandssensoren må du tilføje disse linjer før din setup funksjon:

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A2, A3);
	Afstanden kan nu gemmes som variablen ”dist” ved at bruge denne linje kode i dit program:
		  int  dist = ultrasonic.distanceRead();
Du kan nu tilføje en if-statement der får roboten til å stoppe hvis afstanden f.eks. er mindre end 30 (enheden er i centimeter).
9.	Find selv på annet du vil gjøre med roboten. Forslag:
-	Få den til å snu 180 grader og fortsætte å kjøre hvis der kommer en forhindring
-	Start og stop med fjernbetjening
