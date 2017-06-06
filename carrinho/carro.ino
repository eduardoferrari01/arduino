int frente =  13;
int re  = 12 ;
int direita =  11;
int esquerda = 10;
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

//funçao que para tudo
void parar()
{
   digitalWrite(direita,LOW);
   digitalWrite(esquerda,LOW);
   digitalWrite(frente,LOW);
   digitalWrite(re,LOW);
}
void loop()
{
    
   if (Serial.available() > 0)   
   {
       
      Serial.println("w - Frente");
      Serial.println("s - Re");
      
      Serial.println("d - Direita");
      Serial.println("a - Esquerda");
      
      Serial.println("wd - Direita Frente");
      Serial.println("wa - Esquerda Frente");
      
      Serial.println("sd - Re Direita");
      Serial.println("sa - Re Esquerda");
      Serial.println("z - Parar");
      entrada = Serial.read();
       Serial.println(entrada);
      switch(entrada)
      {
           case 'w':
          
           funcaoFrente();
           break;
           case 's':
           funcaoRe();
           break;
           case 'd':
           funcaoDireita();
           break;
           case 'a':
           funcaoEsquerda();
           break; 
           case 'z':
           parar();
           break;
           case 'wa':
           funcaoEsquerda();
           funcaoFrente();
           break;
           case 'wd':
           funcaoDireita();
           funcaoFrente();
           break;
           case 'sa':
           funcaoRe();
           funcaoEsquerda();
           break;
           case 'sd':
           funcaoRe();
           funcaoDireita();
           break;
           default:
           Serial.println("Erro:");
           break;
      }
   }  
   
}

