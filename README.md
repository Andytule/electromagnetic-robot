# Electromagnetic-Robot
Andy Le, AndyTuLe Febuary 14, 2019

## About
- The robot is programmed using an Arduino, Raspberry Pi, with Python, Java, and C++
- A robot that picks up scrap pieces of metal

## Usage

Python was utilized in two different ways in order for the robot to be controlled remotely:

- A wireless keybaord method which through Pygame; read key press for commands sending serial bits to the Arduino to allow the robot to perform it's desired movements
- A java app method in which the app sent web requests to a Flask server that sent certain seriall bits to the Arduino and in turn allowing the robot to perform it's desired movements

Arduino was utilized by:
- Energzing and de-energizing the electromagnets to pick up the scrap pieces of metal
- Controling the motor control boards that allowed the robot to move
- Activating the servo motors that moved the arms up and down

![Mock](https://user-images.githubusercontent.com/47620000/70858128-b1e42480-1ec9-11ea-87d7-c5e7b632f8f8.png "Mock")
![Picture](https://user-images.githubusercontent.com/47620000/70858137-e3f58680-1ec9-11ea-8950-3b28b316d88e.png "{icture")
