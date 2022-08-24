// ---------------------------------------------------------------- //
// Arduino Ultrasonic Sensor HC-SR04
// Traducido y modificado a partir de  código de Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.15
// Using HC-SR04 Module
// Código para enviar un botón y sensor ultrasónico a PureDara por puerto serial.
// ---------------------------------------------------------------- //

#define echoPin 2 // D2 a Echo del HC-SR04
#define trigPin 3 // D3 a Trigger del HC-SR04


// Definición de variables
long dur; // Duración de el recorrido de onda sonora
int dist; // Variable para medición de distancia

void setup() {
  pinMode(trigPin, OUTPUT); // Pin de Trigger como Output
  pinMode(echoPin, INPUT); // Pin de Echo como Input
  pinMode(buttonPin,INPUT); //Pin de botón como Input
  Serial.begin(9600); // // Comienza comunicación serial
  
}
void loop() {
  
  // Reinicia condiciones del sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Se lanza un pulso
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Se lee el resultado con la duración del recorrido que tuvo el pulso sonoro
  dur = pulseIn(echoPin, HIGH);
  // Calculamos distancia usando la velocidad del sonido y dividimos entre dos
  dist= dur * 0.034 / 2; 
  // Enviamos el dato por puerto serial
 
  Serial.println(dist);
  
}
