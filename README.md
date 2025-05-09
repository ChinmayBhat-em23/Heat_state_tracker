# 🔥 Heat State Tracker using DS18B20 and LED Indicators

This Arduino-based project is a **temperature state tracking system** using the **DS18B20 digital temperature sensor** and a set of LEDs to visually represent different heat states (Idle, Heating, Stabilizing, Target, and Overheat). It can be used for applications such as DIY heating systems, thermal monitoring in embedded labs, or simple industrial prototypes.

---


## 🚀 Project Overview

This project monitors temperature in real-time and classifies it into five states:

1. **Idle**
2. **Heating**
3. **Stabilizing**
4. **Target**
5. **Overheat**

Each state is indicated using a separate **colored LEDs** for intuitive visualization. The DS18B20 sensor continuously measures the ambient temperature, and the corresponding LED turns on based on the current temperature range.

---

## ✨ Features

* Real-time temperature monitoring using **DS18B20** sensor.
* **Visual state feedback** via 5 color-coded LEDs.
* Temperature reading and state updates every second.
* Simple, clean, and readable code architecture.
* Modular functions for easy future extensions.

---

## 🔧 Hardware Requirements

| Component                              | Quantity  |
| -------------------------------------- | --------- |
| Arduino UNO/Nano                       | 1         |
| DS18B20 Temperature Sensor             | 1         |
| 4.7kΩ Resistor (for DS18B20 pull-up)   | 1         |
| LEDs (White, Blue, Yellow, Green, Red) | 5         |
| Resistors (220Ω for LEDs)              | 5         |
| Breadboard & Jumper Wires              | As needed |

---

## 🔌 Circuit Diagram

```
DS18B20:
 - VCC → 5V
 - GND → GND
 - DATA → D2 (with 4.7kΩ pull-up to 5V)

LEDs:
 - White  → D3
 - Blue   → D4
 - Yellow → D5
 - Green  → D6
 - Red    → D7
```

---

## 📥 Installation

1. Connect the circuit as described.
2. Open Arduino IDE.
3. Install the required library:
   Go to **Sketch > Include Library > Manage Libraries**
   Search for **DallasTemperature** and install it.
   It will auto-install the **OneWire** library.
4. Upload the provided code to your Arduino.
5. Open Serial Monitor (9600 baud) to view live temperature and states.

---

## ⚙️ How It Works

* The **DS18B20** sensor measures the current temperature.
* Based on the temperature range, the system determines the **current heat state**.
* The system turns on the **corresponding LED** to represent that state.
* It prints the temperature and current state to the **Serial Monitor** every second.

---

## 🧠 Code Breakdown

* **`setup()`**: Initializes the sensor, serial monitor, and LED pins.
* **`loop()`**:

  * Requests a temperature reading.
  * Calculates the corresponding state.
  * Prints the temperature and state.
  * Lights up the correct LED while turning others off.
* **Helper Functions**:

  * `update_leds(state)` – Lights the LED corresponding to the state.
  * `turn_off_all_leds()` – Ensures only one LED is on at a time.
  * `print_state(state)` – Prints readable state names to Serial Monitor.

---

## 🔁 State Logic

| Temperature Range (°C) | State       | LED Color |
| ---------------------- | ----------- | --------- |
| `< 20.0`               | IDLE        | White     |
| `20.0 – 44.9`          | HEATING     | Blue      |
| `45.0 – 64.9`          | STABILIZING | Yellow    |
| `65.0 – 89.9`          | TARGET      | Green     |
| `>= 90.0`              | OVERHEAT    | Red       |

---

## 🖥️ Serial Monitor Output

Sample output:

```
temperature: 32.5 °c | state: heating
temperature: 47.8 °c | state: stabilizing
temperature: 66.2 °c | state: target_reached
temperature: 91.0 °c | state: overheat
```

---

## 💡 Applications

* DIY home heating system controller
* Thermal monitoring for electronic equipment
* Educational temperature visualization project
* Industrial prototype state indicator
* Safe heating zone alert system

---

