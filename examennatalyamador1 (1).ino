//Nataly Yoseth Amador Coello
//Microcontroladores
#include <LiquidCrystal.h>
#include <Keypad.h>
const byte filas=4; 
const byte columnas=4;
byte pfilas[filas]={11,10,9,8};
byte pcolumnas [columnas]={7,6,5,4};
LiquidCrystal lcd(14,15,16,17,18,19);

char tecladito[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad teclado = Keypad(makeKeymap(tecladito),pfilas,pcolumnas,filas,columnas);
String clave; 
String pass="1A2B";
int longitud =0;
void setup()
{
  Serial.begin(9600);
 lcd.begin(16,2);
 lcd.print("Bienvenido!");
  lcd.setCursor(0,1);
 lcd.print("Confirmar = A");
 delay(1500);
 lcd.clear(); 
 lcd.print("Ingrese el Pin: ");
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  
  char tecla = teclado.getKey();
  
  if(tecla)
  {
    if(longitud<4){
    	clave += tecla;
      	longitud++;
      	lcd.setCursor(7,1);
       lcd.print(clave);
    }else if (longitud == 4 && tecla =='A'){
      if(clave == pass){
        lcd.clear();
      	lcd.print("Acceso Permitido");
        Acceso();
      }else{
        lcd.clear();
 		lcd.print("Acceso Denegado"); 
        delay(1000);
        lcd.clear();
        clave="";
        Denegado();
        
        
      }}else{
      lcd.clear();
        lcd.print("Pin  de");
        lcd.setCursor(0,1);
        lcd.print("4 Digitos");
      } 
    }   
      
  
}

void Acceso(){
	digitalWrite(12,HIGH);
   delay(1000);
  	tone(13,500,200);
}

void Denegado (){

  	tone(13,220,100);

}