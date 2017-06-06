 int frente =  13;
int re  = 12 ;
int direita =  11;
int esquerda = 10;
const int pingPin = 7;
const int echoPin = 6;
int entrada;

void setup()
{
  Serial.begin(9600);
}

void funcaoFrente()
{
  pinMode(frente,OUTPUT); 
  digitalWrite(frente,HIGH);
   
}
void funcaoRe()
{
  pinMode(re,OUTPUT);
  digitalWrite(re,HIGH);
}
void funcaoDireita()
{
  pinMode(direita,OUTPUT);
  digitalWrite(direita,HIGH);
}
void funcaoEsquerda()
{
  pinMode(esquerda,OUTPUT); 
  digitalWrite(esquerda,HIGH);
}
void parar()
{
   
   digitalWrite(direita,LOW);
   digitalWrite(esquerda,LOW);
   digitalWrite(frente,LOW);
   digitalWrite(re,LOW);
   
   
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}



long microsecondsToCentimeters(long microseconds)
{
  
  return microseconds / 29 / 2;
}

void loop()
{
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  //inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  if(cm < 10)
  {
     //Serial.println("teste");
     parar();
     funcaoRe();
     funcaoEsquerda();
  }else
  {
   parar();
   funcaoFrente(); 
  }
  delay(100);
}


