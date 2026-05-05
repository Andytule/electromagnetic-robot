# 🤖 Electromagnetic Scrap-Collection Robot

> An Arduino + Raspberry Pi robot that autonomously navigates a surface, uses electromagnets to attract and collect metal scrap pieces, and supports both keyboard and Android app remote control.

![Robot Mockup](https://user-images.githubusercontent.com/47620000/70858128-b1e42480-1ec9-11ea-87d7-c5e7b632f8f8.png)
![Robot Photo](https://user-images.githubusercontent.com/47620000/70858137-e3f58680-1ec9-11ea-8950-3b28b316d88e.png)

---

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Architecture](#architecture)
- [Project Structure](#project-structure)
- [Setup & Usage](#setup--usage)
- [Control Methods](#control-methods)
- [License](#license)

---

## Overview

This robot was built to drive around a surface and pick up scrap metal pieces using electromagnets. When energized, the electromagnetic arms attract metal fragments; the arms then lift and deposit the pieces into an on-board storage bin. The robot can be controlled remotely via a wireless keyboard or an Android app over a local network.

---

## Features

- **Electromagnetic pickup** — arms energize/de-energize on command to attract and release metal pieces
- **Servo-driven arms** — servo motors raise and lower the collection arms
- **Dual remote control** — supports both a Pygame keyboard interface and an Android app via HTTP
- **Serial communication** — Python scripts on the Raspberry Pi communicate with the Arduino over serial
- **PWM motor speed control** — adjustable drive speed via motor control boards

---

## Tech Stack

| Layer | Technology |
|---|---|
| Microcontroller firmware | Arduino (C/C++) |
| Host computer | Raspberry Pi |
| Keyboard control | Python, Pygame |
| Android app control | Python, Flask |
| Hardware | Servo motors, DC motors, motor control boards, electromagnets |

---

## Architecture

```
Android App
    │  HTTP requests
    ▼
Flask Server (Raspberry Pi)
    │  Serial (USB)
    ▼
Arduino
    ├── Motor control boards → DC drive motors
    ├── Servo motors → arm up/down
    └── Electromagnets → attract/release metal

— OR —

Pygame Keyboard (PC/Raspberry Pi)
    │  Serial (USB/COM)
    ▼
Arduino  (same as above)
```

---

## Project Structure

```
electromagnetic-robot/
├── EM_Robot_Arduino.ino       # Arduino firmware — motors, servos, electromagnets
├── Flask Server Controls.py   # Raspberry Pi Flask server for Android app control
├── Pygame Controls.py         # Keyboard control interface via Pygame + serial
├── Project Writeup.xlsx       # Design documentation and project writeup
└── README.md
```

---

## Setup & Usage

### Hardware requirements
- Arduino (Uno or compatible)
- Raspberry Pi (any model with USB)
- DC motor control boards (×2)
- Servo motors (for arms)
- Electromagnets
- USB cable (Arduino ↔ Raspberry Pi)

### Arduino
1. Open `EM_Robot_Arduino.ino` in the Arduino IDE.
2. Upload to your Arduino board.

### Keyboard control (Pygame)
```bash
pip install pygame pyserial
```
Edit the serial port in `Pygame Controls.py`:
```python
ser = serial.Serial("COM5", 9600)   # Windows
# ser = serial.Serial('/dev/ttyUSB0', 9600)  # Linux/Raspberry Pi
```
Then run:
```bash
python "Pygame Controls.py"
```

### Android app / Flask server
```bash
pip install flask pyserial
```
Ensure the serial port in `Flask Server Controls.py` matches your setup:
```python
ser = serial.Serial('/dev/ttyUSB0', 9600)
```
Start the server on the Raspberry Pi:
```bash
python "Flask Server Controls.py"
```
The server runs at `http://<raspberry-pi-ip>:5000`. Your Android app can send HTTP requests to the endpoints below.

---

## Control Methods

### Keyboard controls (Pygame)
| Key | Action |
|---|---|
| `W` / `↑` | Move forward |
| `S` / `↓` | Move backward |
| `A` / `←` | Turn left |
| `D` / `→` | Turn right |
| `Z` | Raise/lower arms |
| `C` | Energize / de-energize electromagnets |
| `+` / `-` | Increase / decrease motor speed |

### Flask API endpoints (Android app)
| Endpoint | Action |
|---|---|
| `GET /forward` | Move forward |
| `GET /backward` | Move backward |
| `GET /left` | Turn left |
| `GET /right` | Turn right |
| `GET /arms` | Toggle arm position |
| `GET /energize` | Toggle electromagnets |
| `GET /add` | Increase PWM speed |
| `GET /subract` | Decrease PWM speed |

---

## License

This project is licensed under the terms in the [LICENSE](LICENSE) file.
