/*
 * deschidere poarta dubla
 * sketch original scris de Nicu FLORICA (niq_ro)
 * versiune initiala, 23.7.2019, Craiova
 */

#define deschidere 2   // pin pentru comanda deschidere
#define inchidere 3    // pin pentru comanda inchidere
#define deschiderestanga 4       // pin de comanda poarta stanga
#define deschideredreapta 5       // pin de comanda poarta dreapta
#define inchiderestanga 6       // pin de comanda poarta stanga
#define inchideredreapta 7       // pin de comanda poarta dreapta

int timpscurt = 500;
int timplung = 300;  // se imparte la 100 sa dea numarul de secunde (3000 = 30 x 100)
byte sens = 0;

void setup() {
Serial.begin(9600);  // monitorizare seriala
pinMode(deschidere, INPUT);
pinMode(inchidere, INPUT);
pinMode(deschiderestanga, OUTPUT);
pinMode(deschideredreapta, OUTPUT);
pinMode(inchiderestanga, OUTPUT);
pinMode(inchideredreapta, OUTPUT);
digitalWrite(deschiderestanga, LOW); 
digitalWrite(deschideredreapta, LOW);
digitalWrite(inchiderestanga, LOW); 
digitalWrite(inchideredreapta, LOW);

//digitalWrite(inchidere, HIGH); 
//digitalWrite(deschidere, HIGH);

}

void loop() {

if (digitalRead(deschidere) == HIGH)
{
 Serial.println("primit comanda de deschidere");
 sens = 1; 
}
else
if (digitalRead(inchidere) == HIGH)
{
 sens = 2;
 Serial.println("primit comanda de inchidere");
}

else
  sens = 0;

if (sens == 1)
{
digitalWrite(deschiderestanga, HIGH);  // deschid usa stanga
Serial.println("deschid usa stanga");
delay(timpscurt);  // astept puutin
digitalWrite(deschideredreapta, HIGH);  // deschid si usa dreapta
Serial.println("deschid usa dreapta");
delay(timpscurt);  // astept putin
Serial.println("pauza..."); 
for (int i=0; i <= timplung; i++)
{
if ((digitalRead(deschidere) == HIGH) or (digitalRead(inchidere) == HIGH))
{
  i = timplung+1;
  Serial.println("oprire de urgenta..."); 
  sens = 0;
  digitalWrite(deschiderestanga, LOW); 
  digitalWrite(deschideredreapta, LOW);
  delay(200);
}
delay(50);
//Serial.print(".");
}
sens = 0;
digitalWrite(deschiderestanga, LOW); 
digitalWrite(deschideredreapta, LOW);
Serial.println("depasire timp..."); 
}

if (sens == 2)
{
digitalWrite(inchideredreapta, HIGH);  // inchid usa dreapta
Serial.println("inchid usa dreapta");
delay(timpscurt);  // astept putin
digitalWrite(inchiderestanga, HIGH);  // inchid si usa stanga
Serial.println("inchid usa stanga");
//delay(timplung);delay(timpscurt);  // astept puutin
Serial.println("pauza..."); 
for (int i=0; i <= timplung; i++)
{
if ((digitalRead(deschidere) == HIGH) or (digitalRead(inchidere) == HIGH))
{
  i = timplung+1;
  Serial.println("oprire de urgenta..."); 
  sens = 0;
  digitalWrite(inchiderestanga, LOW); 
  digitalWrite(inchideredreapta, LOW);  
  delay(200); 
}
delay(50);
//Serial.print(".");
}
sens = 0;
digitalWrite(inchiderestanga, LOW); 
digitalWrite(inchideredreapta, LOW);
Serial.println("depasire timp..."); 
}


} // end
