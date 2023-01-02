int M1 = 9; // M1 será la salida PWM para el control del motor DC
float Velocidad = 0; // Velocidad en valores de 0 a 255 donde 0 es totalmente
// the setup routine runs once when you press reset:
void setup() {
 // declare pin 9 to be an output:
 pinMode(M1, OUTPUT);
 Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
if (Serial.available() > 0) {
  int r = Serial.parseInt();
  Serial.println(r);
  if(r>=0 && r<=255){
    Velocidad = int(r);
    Serial.println(Velocidad);
  }
}
    // say what you got:
 // activa el motor con la velocidad determinada por la intensidad de luz del sensor
 analogWrite(M1, Velocidad);
 Serial.println(Velocidad);
 delay(1000);
}