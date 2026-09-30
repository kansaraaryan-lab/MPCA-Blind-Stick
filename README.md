# 🦯 OSCAR Blind Stick

### Obstacle Scanning Collision Alert Radar

An Arduino UNO-based smart blind stick prototype designed to detect nearby obstacles and provide real-time audio alerts to improve awareness while walking.

---

## 📌 Overview

**OSCAR (Obstacle Scanning Collision Alert Radar)** is a low-cost assistive technology prototype that combines an **Arduino UNO**, **HC-SR04 ultrasonic sensor**, and **SG90 servo motor** to scan the user's surroundings for obstacles.

The ultrasonic sensor continuously measures the distance to objects while the servo motor rotates the sensor across different angles. When an obstacle is detected within a predefined safety range, a buzzer provides an audio warning.

The project demonstrates the practical use of **embedded systems, ultrasonic sensing, servo control, and real-time obstacle detection**.

---

## 🎯 Objectives

* Detect obstacles in front of the user.
* Scan obstacles across multiple directions instead of detecting only one fixed point.
* Provide an immediate audio warning when an obstacle is nearby.
* Build a low-cost and portable assistive prototype.
* Demonstrate the integration of hardware and embedded programming.

---

## ⚙️ How It Works

The basic working process is:

```text
        ┌──────────────────┐
        │   Ultrasonic     │
        │    HC-SR04       │
        └────────┬─────────┘
                 │
                 ▼
        Measures Distance
                 │
                 ▼
        ┌──────────────────┐
        │    Arduino UNO   │
        │  Processing Unit │
        └────────┬─────────┘
                 │
          Distance Check
                 │
        ┌────────┴─────────┐
        │                  │
    Obstacle            No Obstacle
    Detected             Detected
        │                  │
        ▼                  ▼
     Buzzer             Continue
      Alert               Scan
```

The **SG90 servo motor** rotates the HC-SR04 sensor through different angles. At each position, the Arduino measures the distance to the nearest detected object.

If the measured distance is below the programmed threshold, the buzzer produces an alert.

---

## 🧩 Components Used

| Component                 | Purpose                              |
| ------------------------- | ------------------------------------ |
| Arduino UNO               | Main microcontroller                 |
| HC-SR04 Ultrasonic Sensor | Measures distance to obstacles       |
| SG90 Servo Motor          | Rotates the ultrasonic sensor        |
| Buzzer                    | Provides audio warning               |
| Breadboard                | Circuit prototyping                  |
| Jumper Wires              | Electrical connections               |
| USB Cable                 | Programming and power during testing |
| Walking Stick             | Physical project platform            |

> **Note:** Power requirements should be considered carefully when moving from the prototype stage to a portable battery-powered version.

---

## 🔌 Pin Connections

### HC-SR04 → Arduino UNO

| HC-SR04 Pin | Arduino UNO |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D7          |
| ECHO        | D6          |

### SG90 Servo → Arduino UNO

| Servo Wire | Arduino UNO |
| ---------- | ----------- |
| Signal     | D9          |
| VCC        | 5V*         |
| GND        | GND         |

### Buzzer → Arduino UNO

| Buzzer       | Arduino UNO |
| ------------ | ----------- |
| Positive (+) | D8          |
| Negative (-) | GND         |

*For a final portable version, the servo should have an appropriate power supply rather than relying on the Arduino's regulator if current demand causes instability.

---

## 💻 Software

### Development Environment

* **Arduino IDE**
* **Arduino C/C++**
* Arduino UNO board

### Main Programming Concepts

* Digital input/output
* Ultrasonic distance measurement
* Servo motor control
* Conditional statements
* Loops
* Serial communication
* Real-time sensor processing

---

## 🧠 Detection Logic

The system continuously performs the following sequence:

```text
START
  │
  ▼
Initialize Arduino
  │
  ▼
Move Servo to Scanning Angle
  │
  ▼
Trigger HC-SR04
  │
  ▼
Measure Echo Time
  │
  ▼
Calculate Distance
  │
  ▼
Is obstacle within threshold?
  │
 ┌┴───────────────┐
 │                │
YES              NO
 │                │
 ▼                ▼
Activate        Continue
Buzzer           Scanning
 │                │
 └───────┬────────┘
         ▼
   Next Scanning Angle
         │
         └──────► Repeat
```

---

## 🚀 Features

* 🔊 Real-time audio obstacle alert
* 📡 Ultrasonic distance measurement
* 🔄 Servo-based scanning
* 🧠 Arduino-based control system
* 💰 Low-cost prototype
* 🔧 Simple and modular hardware
* 🦯 Designed around a walking-stick form factor

---

## 📂 Project Structure

```text
OSCAR-Blind-Stick/
│
├── README.md
│
├── Arduino/
│   └── OSCAR_Blind_Stick.ino
│
└──Circuit/
    └── circuit-diagram.png

```

---

## 🛠️ Setup & Installation

### 1. Install Arduino IDE

Download and install the Arduino IDE from the official Arduino website.

### 2. Connect Arduino UNO

Connect the Arduino UNO to your computer using a USB data cable.

### 3. Open the Project

Open:

```text
Arduino/OSCAR_Blind_Stick.ino
```

### 4. Select Board

In Arduino IDE:

```text
Tools → Board → Arduino AVR Boards → Arduino Uno
```

### 5. Select Port

Select the COM port assigned to your Arduino UNO:

```text
Tools → Port → COMx
```

### 6. Upload

Click **Upload** in Arduino IDE.

---

## 📏 Detection Range

The detection threshold can be modified in the Arduino program.

For example:

```cpp
const int detectionDistance = 50;
```

This sets the obstacle alert threshold to approximately **50 cm**.

The value can be adjusted according to the requirements of the prototype.

---

## 🔮 Future Improvements

The current version is a prototype and can be expanded with additional features:

* Multiple ultrasonic sensors for better coverage
* Vibration-based alerts in addition to sound
* Different alert patterns based on obstacle distance
* Rechargeable battery system
* Improved power management
* Water-resistant enclosure
* GPS-based emergency location feature
* SOS/emergency button
* Mobile connectivity
* More advanced obstacle classification
* Improved mechanical mounting for the scanning sensor

---

## ⚠️ Important Disclaimer

OSCAR is an **educational prototype** developed to demonstrate obstacle detection and embedded-system concepts. It should **not be treated as a certified mobility aid or relied upon as the sole means of navigation or personal safety**.

The prototype should be thoroughly tested and professionally validated before any real-world assistive use.

---

## 👩‍💻 Project Team

**Project:** OSCAR Blind Stick — Obstacle Scanning Collision Alert Radar

**Domain:** Microprocessor and Computer Applications / Embedded Systems

**Platform:** Arduino UNO

---

## 📜 License

MIT License.

You are welcome to study, modify, and improve the project while giving appropriate credit to the original project.
