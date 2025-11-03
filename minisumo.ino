
#define LEFT_MOTOR_PWM1  3
#define LEFT_MOTOR_PWM2  11
#define RIGHT_MOTOR_PWM1 10
#define RIGHT_MOTOR_PWM2 9

// Sensör pinleri
#define LINE_SENSOR_PIN A5
#define OBJECT_SENSOR_PIN 4

void setup() {
  // Motor pinleri çıkış
  pinMode(LEFT_MOTOR_PWM1, OUTPUT);
  pinMode(LEFT_MOTOR_PWM2, OUTPUT);

  pinMode(RIGHT_MOTOR_PWM1, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM2, OUTPUT);

  // Sensör pinleri
  pinMode(LINE_SENSOR_PIN, INPUT);
  pinMode(OBJECT_SENSOR_PIN, INPUT);


 

  Serial.begin(9600);
}

void loop() {
   int lineSensor = analogRead(LINE_SENSOR_PIN); // A5
  int objectSensor = digitalRead(OBJECT_SENSOR_PIN); // D5

  Serial.print("Line Sensor: ");
  Serial.print(lineSensor);
  Serial.print(" | Object Sensor: ");
  Serial.println(objectSensor);


   
  //if (objectSensor == HIGH) {
    // Engel algılandı → ileri saldır
 goForward();
  delay(2000);
stop();
    goBackward();

    // Ne çizgi ne engel → rastgele sağa dön
    //turnRight();
 

  delay(2000);
  stop();
}
void goForward() {
  digitalWrite(LEFT_MOTOR_PWM1, HIGH);
  digitalWrite(LEFT_MOTOR_PWM2, LOW);

  digitalWrite(RIGHT_MOTOR_PWM1, LOW);
  digitalWrite(RIGHT_MOTOR_PWM2, HIGH);
}

void goBackward() {
  digitalWrite(LEFT_MOTOR_PWM1, LOW);
  digitalWrite(LEFT_MOTOR_PWM2, HIGH);
  digitalWrite(RIGHT_MOTOR_PWM1, HIGH);
  digitalWrite(RIGHT_MOTOR_PWM2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_PWM1, HIGH);
  digitalWrite(LEFT_MOTOR_PWM2, LOW);

  digitalWrite(RIGHT_MOTOR_PWM1, HIGH);
  digitalWrite(RIGHT_MOTOR_PWM2, LOW);
}

void stop() {
  digitalWrite(LEFT_MOTOR_PWM1, LOW);
  digitalWrite(LEFT_MOTOR_PWM2, LOW);

  digitalWrite(RIGHT_MOTOR_PWM1, LOW);
  digitalWrite(RIGHT_MOTOR_PWM2, LOW);
}




