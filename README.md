# 🌱 Smart Greenhouse Monitoring System

An **IoT-based Smart Greenhouse Monitoring System** designed to monitor and control important greenhouse conditions using **ESP32**. The system collects temperature, humidity, light intensity, and soil moisture data and provides automated control of greenhouse devices.

The system uses the **Blynk IoT platform** for remote monitoring and control.

---

## 📌 Project Overview

Maintaining suitable environmental conditions is important for healthy plant growth. Manual monitoring of temperature, humidity, light, and soil moisture can be time-consuming.

This project provides an automated solution using sensors and actuators connected to an ESP32. Based on the monitored conditions, devices such as a **fan, LED, and water pump** can be controlled through relay modules.

---

## 🚀 Features

* 🌡️ Temperature monitoring using DHT11
* 💧 Humidity monitoring using DHT11
* 🌱 Soil moisture monitoring
* ☀️ Light intensity monitoring using LDR
* 🌀 Fan control
* 💡 LED control
* 💦 Automatic water pump control
* 🔌 Relay-based device switching
* 📱 Remote monitoring and control using Blynk
* ⚡ ESP32-based automation

---

## 🧰 Hardware Components

| Component            | Quantity | Purpose                          |
| -------------------- | -------: | -------------------------------- |
| ESP32                |        1 | Main controller                  |
| DHT11                |        1 | Temperature and humidity sensing |
| Soil Moisture Sensor |        1 | Soil moisture monitoring         |
| LDR Sensor           |        1 | Light intensity detection        |
| Relay Module         |        1 | Controls electrical loads        |
| LED                  |        1 | Lighting                         |
| Fan                  |        1 | Temperature/ventilation control  |
| Water Pump           |        1 | Automatic irrigation             |

---

## 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* Blynk IoT
* DHT Sensor Library
* Wi-Fi Library

---

## 🔧 System Architecture

```text
                    🌱 SMART GREENHOUSE
                           │
                           ▼
                    ┌─────────────┐
                    │    ESP32    │
                    │ Controller  │
                    └──────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
      ┌────────┐      ┌──────────┐      ┌────────┐
      │ DHT11  │      │   LDR    │      │ Soil   │
      │ Sensor │      │  Sensor  │      │Moisture│
      └────────┘      └──────────┘      └────────┘
          │                │                │
          └────────────────┼────────────────┘
                           │
                           ▼
                    ┌─────────────┐
                    │    Relay    │
                    │   Module    │
                    └──────┬──────┘
                           │
              ┌────────────┼────────────┐
              │            │            │
              ▼            ▼            ▼
           🌀 Fan        💡 LED       💦 Pump

                           │
                           ▼
                     📱 Blynk IoT
```

---

## ⚙️ Working Principle

1. The **DHT11 sensor** measures the temperature and humidity inside the greenhouse.
2. The **LDR sensor** detects the surrounding light intensity.
3. The **soil moisture sensor** measures the moisture level of the soil.
4. The **ESP32** receives and processes the sensor readings.
5. Based on the programmed conditions, the ESP32 controls the **fan, LED, and water pump** through the relay module.
6. The **Blynk IoT platform** is used to monitor sensor data and control connected devices remotely.
7. The water pump can be activated when the soil requires additional moisture.

---

## 📱 Blynk IoT

The Blynk platform provides an IoT interface for monitoring and controlling the greenhouse.

The dashboard can display:

* 🌡️ Temperature
* 💧 Humidity
* 🌱 Soil moisture
* ☀️ Light intensity
* 🌀 Fan status
* 💡 LED status
* 💦 Water pump status

---

## 🔌 Circuit

The sensors and actuators are connected to the ESP32 according to the project circuit design.

The **relay module** is used to control devices such as the fan, LED, and water pump.

> Add your circuit diagram inside the `circuit` folder.

```text
circuit/
└── circuit_diagram.png
```

---

## 📸 Project Images

Add project photographs and Blynk screenshots to the `images` folder.

```text
images/
├── project_setup.jpg
├── blynk_dashboard.jpg
└── circuit.jpg
```

---

## 📂 Project Structure

```text
smart-greenhouse-monitoring-system/
│
├── README.md
│
├── src/
│   └── smart_greenhouse.ino
│
├── circuit/
│   └── circuit_diagram.png
│
├── images/
│   ├── project_setup.jpg
│   ├── blynk_dashboard.jpg
│   └── circuit.jpg
│
└── docs/
    └── project_report.pdf
```

---

## 🎯 Objectives

* Monitor greenhouse environmental conditions.
* Monitor soil moisture for irrigation.
* Automate greenhouse devices.
* Reduce manual monitoring.
* Provide remote monitoring through IoT.
* Improve efficient use of water and electrical devices.

---

## 🔮 Future Improvements

* 🌐 Web-based monitoring dashboard
* 📊 Data logging and historical graphs
* 🤖 AI-based plant condition analysis
* 🌦️ Weather-based irrigation control
* 📷 Camera-based plant monitoring
* 📈 Cloud-based data analytics
* 🔔 Mobile notifications for abnormal conditions

---

## 🛠️ Applications

* Smart agriculture
* Greenhouse automation
* IoT-based farming
* Plant monitoring
* Automated irrigation
* Agricultural research

---

## 👨‍💻 Author

**Harish Rajoli**

Electronics and Communication Engineering

---

## ⭐ Project

If you find this project useful, consider giving the repository a ⭐ on GitHub.

---
