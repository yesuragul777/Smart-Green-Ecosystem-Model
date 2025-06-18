# 🌱 Smart Green Ecosystem Model – Embedded System Platform

An **IoT-based composting system** designed to automate the drying and grinding of wet kitchen waste into odor-free, fine fertilizer. This project presents a **sensor-driven embedded system** that enhances composting efficiency through real-time monitoring and environmental control.

---

## 📌 Project Description

This project proposes a **smart composting unit** capable of turning household kitchen waste into quality compost using a microcontroller-based embedded platform. The system is designed with real-time sensing, automated mechanical actuation, and energy-efficient waste processing.

---

## ⚙️ Features

- 🌡️ **Temperature & Humidity Monitoring** – Uses DHT11 sensor for environmental analysis.
- 📏 **Ultrasonic Sensing** – Detects compost bin fill-level to prevent overflow.
- 🔄 **Automated Drying & Grinding** – Controlled via a 3-relay system driving fans/motors.
- 🌐 **IoT Integration (optional)** – Real-time data monitoring and notifications.
- ♻️ **Eco-friendly Solution** – Converts waste into usable compost, reducing landfill impact.

---

## 🔧 Hardware Components

| Component               | Quantity | Description                            |
|------------------------|----------|----------------------------------------|
| Arduino Uno / ESP32    | 1        | Microcontroller unit                   |
| DHT11 Sensor           | 1        | Measures temperature & humidity        |
| HC-SR04 Ultrasonic     | 1        | Distance measurement sensor            |
| 3-Channel Relay Module | 1        | Controls fan, grinder, dryer           |
| DC Fan / Motor         | 2-3      | For drying and mixing                  |
| Power Supply Unit      | 1        | For powering motors and controller     |
| Breadboard, Wires      | –        | For prototyping                        |

📄 See [`hardware_components_list.md`](hardware_components_list.md) for detailed specs.

---

## 🔌 Circuit Diagram

- All components are interfaced to the microcontroller as per the diagram.
- The 3-channel relay drives the external motor-based fan and grinder system.
- Sensors feed real-time environmental data to the controller.

📎 [View Circuit Diagram](circuit_diagram.png)

---

## 💻 Code Overview

Arduino code for the composting logic is available in the [`Code/`](Code/) directory.

Key modules:
- `readSensors()`: Gathers temperature, humidity, and bin level.
- `controlRelays()`: Automates relays based on thresholds.
- `loop()`: Runs the continuous composting logic.

```cpp
if (humidity > 70) {
    digitalWrite(fanRelay, HIGH); // Start drying
} else {
    digitalWrite(fanRelay, LOW);
}
