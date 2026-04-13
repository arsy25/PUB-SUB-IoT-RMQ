# PUB-SUB-IoT-RMQ

<p align="center">
  <img src="https://img.shields.io/badge/ESP8266-IoT-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/MQTT-RabbitMQ-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" />
</p>

<p align="center">
  A modular publish-subscribe IoT system using ESP32/ESP8266 and RabbitMQ for sending and receiving sensor data.
</p>

---

## ✨ Overview

**PUB-SUB-IoT-RMQ** is an IoT project built with a **publish-subscribe architecture** using **ESP32/ESP8266**, **MQTT**, and **RabbitMQ**.  
The project is designed in a **modular way**, so each sensor can be separated into its own file for easier development, testing, and maintenance.

This project is suitable for:
- IoT learning and experimentation.
- Modular sensor-based monitoring systems.
- MQTT and RabbitMQ communication practice.
- Future expansion with multiple sensors.

---

## 🔧 Features

- ESP8266 or ESP32 as the main IoT device.
- MQTT communication with RabbitMQ broker.
- Modular sensor structure.
- Separate files for each sensor module.
- Easy to expand for new sensors.
- Lightweight and simple to maintain.

---

## 🧩 Project Concept

The idea behind this project is simple:

1. Each sensor works in its own file or module.
2. ESP8266/ESP32 reads sensor data.
3. Data is published through MQTT.
4. Can receive data from MQTT too.
5. RabbitMQ receives and manages the messages.
6. The system can be expanded without rewriting everything.

Think of it like a tiny smart team:
- one sensor = one worker,
- RabbitMQ = the message station,
- ESP8266/ESP32 = the delivery guy.

---

## 📦 Planned Sensor Modules

This repository is designed to support multiple sensor files such as:

- Temperature sensor
- Smoke sensor
- Flame sensor
- Motion sensor
- Emergency button
- Other future sensors

Each sensor can be added as a separate module when needed.

---

## 🛠️ Technologies Used

- **ESP8266**
- **ESP32**
- **MULTIPLE SENSORS**
- **MQTT**
- **RabbitMQ**
- **WiFiManager**
- **Arduino IDE / PlatformIO**

---

## 📁 Repository Structure

```bash
PUB-SUB-IoT-RMQ/
├── sensor/
├── README.md
└── .gitignore
```

---

## 🚀 How It Works

- Connect ESP8266 to Wi-Fi.
- Read data from the active sensor module.
- Publish sensor value to RabbitMQ using MQTT.
- Keep the code separated by sensor for easier management.

---

## 🧪 Example Data Flow

```text
Sensor -> ESP8266 -> MQTT -> RabbitMQ -> Receiver / Dashboard
RabbitMQ -> MQTT -> ESP8266 -> Actuator
```

---

## 🌱 Future Development

This project will continue to grow with:
- More sensor modules.
- Better message formatting.
- Dashboard integration.
- Alert system.
- Data logging and visualization.

---

## 💡 Notes

This repository is intentionally designed to be **modular**.  
That means every sensor can have its own file, so the code stays clean and easy to update.

No spaghetti code here — just neat little sensor noodles. 🍜

---

## 📜 License

This project is open for educational and development purposes.
