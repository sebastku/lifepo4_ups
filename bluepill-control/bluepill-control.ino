/* 
   This program monitors the charge of a 4 cell configuration of LiFePO4 batteries as well as
   controls a load inside the UPS designed in this project. 
   
   created by Sebastian Kuempel 2024
 */

// the rate at which the current reading loop operates ()
const int sampleTime = 100;

/* 
   the capacity values used in this program are obtained by multiplying the taget
   capacity measured in Ah by 11170909 for the sample rate of 100.
 */
const int maxCapacity = 40215272;
const int initialCharge = 32172218;
const int lowThreshold = maxCapacity * 0.3;
int charge = initialCharge;

char command;
String commandValue;

bool power;

void setup() {
  Serial.begin(115200);
  // pins PA1 and PA2 are used to monitor the current going into and out of the BMS board
  pinMode(PA1, INPUT_ANALOG);
  pinMode(PA2, INPUT_ANALOG);
  // pin PA3 controls whether Q3 connects or disconnects the load from power
  pinMode(PA3, OUTPUT);
  digitalWrite(PA3, HIGH);
  power = true;
}

void loop() {
  charge = charge + analogRead(PA1) - analogRead(PA2);
  Serial.println(charge);
  // process commands over serial
  if (Serial.available()){
    command = Serial.read();
    commandValue = Serial.readStringUntil('\n');
    // the command s sets charge to the given value
    if (command == 's') {
      charge = commandValue.toInt();
    }
    // the command l returns lowThreshold
    else if (command == 'l') {
      Serial.print("l");
      Serial.println(lowThreshold);
    }
  }
  // disconnect the load from the battery to prevent deep discharge
  if (charge <= lowThreshold && power == true){
    digitalWrite(PA3, LOW);
    power = false;
  }
  // reconnect the load once the battery is recharged sufficiently
  else if (charge > lowThreshold && power == false){
    digitalWrite(PA3, HIGH);
    power = true;
  }
  delay(sampleTime);
}
