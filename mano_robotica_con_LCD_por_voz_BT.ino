//codigo mejorado 
// se debe espaerar e tiempo al finalzar, son se pued superponer una con otra
#include <SoftwareSerial.h> // Incluye la libreria para puerto serie nuevo
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

SoftwareSerial mySerial(A0, A1); // Crea puerto serie para bluetooth; pin A5 (TX HC-06),  pin A4 (RX HC-06)

// Inicializa el LCD con los pines de conexión
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD de 16 columnas y 2 filas

// Inicializa los servos
Servo servo1, servo2, servo3, servo4, servo5, servo6;
int led = 2;
// Variable para guardar el estado actual
char estado = 0;


void setup() {
  // Configura los pines de los servos
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(8);
  servo5.attach(10);
  servo6.attach(11);
  pinMode(led,OUTPUT);
// Inicializa el LCD
  lcd.begin();
  lcd.backlight();  // Enciende la luz de fondo del LCD
  lcd.clear();  // Limpia la pantalla del LCD
  lcd.setCursor(0, 0);
  lcd.print("Esperando...");
  // Inicializa los servos en una posición neutral
  libre();
  
  // Configura el puerto serie para recibir datos
  Serial.begin(9600);
}

void loop() {
  // Lee el estado del puerto serie
 if(mySerial.available()>0){
 estado = mySerial.read();

    
    
    // Maneja el estado recibido
    handleState(estado);
  }
}


// Maneja el estado y muestra la palabra en el LCD
void handleState(char estado) {
  lcd.clear();
  switch (estado) {
    case 'a':
      lcd.setCursor(0, 0); lcd.print("D");
      d(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("De");
      e(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Ded");
      d(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Dedo");
      o(); delay(1000); libre();
      break;
    case 'b':
      lcd.setCursor(0, 0); lcd.print("C");
      c(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Co");
      o(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Com");
      m(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Comi");
      i(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Comid");
      d(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Comida");
      a(); delay(1000); libre();
      break;
    case 'c':
      lcd.setCursor(0, 0); lcd.print("S");
      s(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Se");
      e(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Sed");
      d(); delay(1000); libre();
      break;
    case 'd':
      lcd.setCursor(0, 0); lcd.print("A");
      a(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Au");
      u(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Aut");
      t(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Auto");
      o(); delay(1000); libre();
      break;
    case 'e':
      lcd.setCursor(0, 0); lcd.print("H");
      h(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Ho");
      o(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Hol");
      l(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Hola");
      a(); delay(1000); libre();
      break;
    case 'f':
      lcd.setCursor(0, 0); lcd.print("C");
      c(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Ch");
      h(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Cha");
      a(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("Chau");
      u(); delay(1000); libre();
      break;
    case 'g':
      lcd.setCursor(0, 0); lcd.print("0");
      n0(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("01");
      n1(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("012");
      n2(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("0123");
      n3(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("01234");
      n4(); delay(1000); libre();
      break;
    case 'h':
      lcd.setCursor(0, 0); lcd.print("5");
      n5(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("56");
      n6(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("567");
      n7(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("5678");
      n8(); delay(1000); libre(); lcd.setCursor(0, 0); lcd.print("56789");
      n9(); delay(1000); libre();
      break;

    case 'q':  //all off
      digitalWrite(led, HIGH); // Enciende el LED
      delay(1000);
      break;
    case 'r':  //all off
      break;
    case 's':  //all off
      break;
    case 't':  //all off
      break;
    case 'u':  //all off
      break;
    case 'v':  //all off
      break;
     
    default:
      lcd.clear(); lcd.setCursor(0, 0); lcd.print("Caracter no");
      lcd.setCursor(0, 1); lcd.print("reconocido");
      break;
  }
  estado = 0;
  digitalWrite(led, LOW); // Apaga el LED

}


// Funcion que pone a todos los sevos a 90 grados
void libre(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(90); servo6.write(90);
}

// letra 'a'
void a(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(45);
}
// letra 'b'
void b(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'c'
void c(){
  servo2.write(135); servo3.write(55); delay(500); servo4.write(130); servo5.write(50); delay(500); servo1.write(60);servo6.write(145);
// letra 'd'
}
void d(){
  servo2.write(90); servo3.write(20); servo4.write(155); delay(500); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'e'
void e(){
  servo2.write(170); servo3.write(30); delay(500); servo4.write(140); servo5.write(30); delay(500); servo1.write(34);
}
// letra 'f'
void f(){
  servo2.write(150); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(35);servo6.write(60);
}
// letra 'g'
void g(){
servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(40); servo6.write(145);
}
// letra 'h'
void h(){
  servo2.write(110); servo3.write(70); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(40); servo6.write(5);
}
// letra 'i'
void i(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'k'
void k(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(140); servo5.write(30); delay(500); servo1.write(26);
}
// letra 'l'
void l(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(90);
}
// letra 'm'
void m(){
  servo1.write(40); delay(500); servo2.write(170); servo3.write(20); delay(500); servo4.write(155); servo5.write(25);
}
// letra 'o'
void o(){
  servo2.write(165); servo3.write(40); delay(500); servo4.write(145); servo5.write(35); delay(500); servo1.write(37);servo6.write(145);
}
// letra 's'
void s(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(30);
}
// letra 't'
void t(){
  servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(35);servo6.write(25);
}
// letra 'u'
void u(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'v'
void v(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'w'
void w(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'x'
void x(){ 
  servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(35);
}
// letra 'y'
void y(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(90);
}
// munero '0'
void n0(){
servo2.write(165); servo3.write(40); delay(500); servo4.write(145); servo5.write(35); delay(500); servo1.write(37); servo6.write(145);
}
//munero '1'
void n1(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// munero '2'
void n2(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// munero '3'
void n3(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(90);
}
// munero '4'
void n4(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// munero '5'
void n5(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(65);
}
// munero '6'
void n6(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(25); delay(500); servo1.write(26);
}
// munero '7'
void n7(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// munero '8'
void n8(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// munero '9'
void n9(){
  servo2.write(165); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(40);
}


/* //codigo anterior 
#include <SoftwareSerial.h> // Incluye la libreria para puerto serie nuevo
#include <Servo.h> // Incluye la libreria para Servo motor y seleccionar posicion entre 0 y 180 grados

SoftwareSerial mySerial(A4, A5); // Crea puerto serie para bluetooth; pin A5 (TX HC-06),  pin A4 (RX HC-06)
Servo servo1;  // Crea objetos para los servos
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

byte estado = 0; //define variable 'estado' para que reciba un caracter y le pone valor cero

void setup() {
mySerial.begin(9600); // fija la velocidad del puerto serie del bluetooth
servo1.attach(3);  // asigna los pines 3,5,6,9,10,y 11 para los servos 1,2,3,4,5 y 6
servo2.attach(5);
servo3.attach(6);
servo4.attach(9);
servo5.attach(10);
servo6.attach(11);
}

void loop() {
/// LAS LETRAS QUE NO SE PUEDEN REPRESENTAR SON: ( j, n, ñ, p, q, r, z )

/// Espera de ordenes de bluetooth
 if(mySerial.available()>0){
 estado = mySerial.read();
 }

// deletrea 'dedo' al recibir la letra 'a' del bluetooh
  if (estado == 'a'){
    d();delay(1000); libre(); //muestra letra d, espera 1000 milisegundos y hace que los dedos regresen a su posicion inicial
    e();delay(1000); libre();
    d();delay(1000); libre();
    o();delay(1000); libre();
    estado = 0; // pone la variable 'estado' en cero para esperar otra letra del bluetooth
  }
// deletrea 'comida' al recibir la letra 'b' del bluetooh
  if (estado == 'b'){
    c();delay(1000); libre();
    o();delay(1000); libre();
    m();delay(1000); libre();
    i();delay(1000); libre();
    d();delay(1000); libre();
    a();delay(1000); libre();
    estado = 0;
  }
// deletrea 'sed' al recibir la letra 'c' del bluetooh  
  if (estado == 'c'){
    s();delay(1000); libre();
    e();delay(1000); libre();
    d();delay(1000); libre();
    estado = 0;
  }
// deletrea 'auto' al recibir la letra 'd' del bluetooh  
  if (estado == 'd'){
    a();delay(1000); libre();
    u();delay(1000); libre();
    t();delay(1000); libre();
    o();delay(1000); libre();
    estado = 0;
  }
// deletrea 'hola' al recibir la letra 'e' del bluetooh
  if (estado == 'e'){
    h();delay(1000); libre();
    o();delay(1000); libre();
    l();delay(1000); libre();
    a();delay(1000); libre();
    estado = 0;
  }
// deletrea 'chau' al recibir la letra 'f' del bluetooh
  if (estado == 'f'){
    c();delay(1000); libre();
    h();delay(1000); libre();
    a();delay(1000); libre();
    u();delay(1000); libre();
    estado = 0;
  }
// muestra numeros del 0 al 4 al recibir la letra 'g' del bluetooh
  if (estado == 'g'){
    n0();delay(1000); libre();
    n1();delay(1000); libre();
    n2();delay(1000); libre();
    n3();delay(1000); libre();
    n4();delay(1000); libre();
    estado = 0;
  }
// muestra numeros del 5 al 9 al recibir la letra 'h' del bluetooh
  if (estado == 'h'){
    n5();delay(1000); libre();
    n6();delay(1000); libre();
    n7();delay(1000); libre();
    n8();delay(1000); libre();
    n9();delay(1000); libre();
    estado = 0;
  }
  
}//final de loop

// Funcion que pone a todos los sevos a 90 grados
void libre(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(90); servo6.write(90);
}

// Funciones de cada letra y numero

// letra 'a'
void a(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(45);
}
// letra 'b'
void b(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'c'
void c(){
  servo2.write(135); servo3.write(55); delay(500); servo4.write(130); servo5.write(50); delay(500); servo1.write(60);servo6.write(145);
// letra 'd'
}
void d(){
  servo2.write(90); servo3.write(20); servo4.write(155); delay(500); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'e'
void e(){
  servo2.write(170); servo3.write(30); delay(500); servo4.write(140); servo5.write(30); delay(500); servo1.write(34);
}
// letra 'f'
void f(){
  servo2.write(150); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(35);servo6.write(60);
}
// letra 'g'
void g(){
servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(40); servo6.write(145);
}
// letra 'h'
void h(){
  servo2.write(110); servo3.write(70); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(40); servo6.write(5);
}
// letra 'i'
void i(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'k'
void k(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(140); servo5.write(30); delay(500); servo1.write(26);
}
// letra 'l'
void l(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(90);
}
// letra 'm'
void m(){
  servo1.write(40); delay(500); servo2.write(170); servo3.write(20); delay(500); servo4.write(155); servo5.write(25);
}
// letra 'o'
void o(){
  servo2.write(165); servo3.write(40); delay(500); servo4.write(145); servo5.write(35); delay(500); servo1.write(37);servo6.write(145);
}
// letra 's'
void s(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(30);
}
// letra 't'
void t(){
  servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(35);servo6.write(25);
}
// letra 'u'
void u(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// letra 'v'
void v(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'w'
void w(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(25); delay(500); servo1.write(26);
}
// letra 'x'
void x(){ 
  servo2.write(140); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(35);
}
// letra 'y'
void y(){
  servo2.write(180); servo3.write(20); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(90);
}
// munero '0'
void n0(){
servo2.write(165); servo3.write(40); delay(500); servo4.write(145); servo5.write(35); delay(500); servo1.write(37); servo6.write(145);
}
//munero '1'
void n1(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// munero '2'
void n2(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(26);
}
// munero '3'
void n3(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(25); delay(500); servo1.write(90);
}
// munero '4'
void n4(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// munero '5'
void n5(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(65);
}
// munero '6'
void n6(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(90); servo5.write(25); delay(500); servo1.write(26);
}
// munero '7'
void n7(){
  servo2.write(90); servo3.write(90); delay(500); servo4.write(155); servo5.write(90); delay(500); servo1.write(26);
}
// munero '8'
void n8(){
  servo2.write(90); servo3.write(20); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(26);
}
// munero '9'
void n9(){
  servo2.write(165); servo3.write(90); delay(500); servo4.write(90); servo5.write(90); delay(500); servo1.write(40);
}
*/
