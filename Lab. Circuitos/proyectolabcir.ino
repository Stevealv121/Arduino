int enA = 9;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(enA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //flowControl();
  accelerate();
}

void flowControl(){
  int sensorValue = analogRead(A2);
  float voltage = sensorValue * (5.0 / 1023.0);
  //Serial.println(voltage);
  if (voltage > 0.72){
    accelerate();    
  }else{
    decelerate();    
  }  
}

void accelerate() {
// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
	}  
}

void decelerate(){
// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
	}
}