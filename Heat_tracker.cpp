#include <OneWire.h>
#include <DallasTemperature.h>

// ds18b20 connected to pin 2
#define one_wire_bus 2
OneWire onewire(one_wire_bus);
DallasTemperature sensors(&onewire);

// led pins
#define led_idle       3   // white
#define led_heating    4   // blue
#define led_stabilize  5   // yellow
#define led_target     6   // green
#define led_overheat   7   // red

// state definitions
#define STATE_IDLE         0
#define STATE_HEATING      1
#define STATE_STABILIZING  2
#define STATE_TARGET       3
#define STATE_OVERHEAT     4

int current_state = STATE_IDLE;

void setup() {
  Serial.begin(9600);
  sensors.begin();

  // set led pins as output
  pinMode(led_idle, OUTPUT);
  pinMode(led_heating, OUTPUT);
  pinMode(led_stabilize, OUTPUT);
  pinMode(led_target, OUTPUT);
  pinMode(led_overheat, OUTPUT);

  // turn off all leds initially
  turn_off_all_leds();

  Serial.println("heat state tracker started...");
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  // determine state based on temperature
  if (temp < 20.0) {
    current_state = STATE_IDLE;
  } else if (temp < 45.0) {
    current_state = STATE_HEATING;
  } else if (temp < 65.0) {
    current_state = STATE_STABILIZING;
  } else if (temp < 90.0) {
    current_state = STATE_TARGET;
  } else {
    current_state = STATE_OVERHEAT;
  }

  // print temperature and state to serial monitor
  Serial.print("temperature: ");
  Serial.print(temp);
  Serial.print(" °c | state: ");
  print_state(current_state);

  // update led based on state
  update_leds(current_state);

  delay(1000); 
}

void update_leds(int state) {
  turn_off_all_leds();
  switch (state) {
    case STATE_IDLE:
      digitalWrite(led_idle, HIGH);
      break;
    case STATE_HEATING:
      digitalWrite(led_heating, HIGH);
      break;
    case STATE_STABILIZING:
      digitalWrite(led_stabilize, HIGH);
      break;
    case STATE_TARGET:
      digitalWrite(led_target, HIGH);
      break;
    case STATE_OVERHEAT:
      digitalWrite(led_overheat, HIGH);
      break;
  }
}

void turn_off_all_leds() {
  digitalWrite(led_idle, LOW);
  digitalWrite(led_heating, LOW);
  digitalWrite(led_stabilize, LOW);
  digitalWrite(led_target, LOW);
  digitalWrite(led_overheat, LOW);
}

void print_state(int state) {
  switch (state) {
    case STATE_IDLE:
      Serial.println("idle");
      break;
    case STATE_HEATING:
      Serial.println("heating");
      break;
    case STATE_STABILIZING:
      Serial.println("stabilizing");
      break;
    case STATE_TARGET:
      Serial.println("target_reached");
      break;
    case STATE_OVERHEAT:
      Serial.println("overheat");
      break;
  }
}
