#Andy Le
#Unit 16 Flask Server Controls
#ICS4U
#Mr. Trink
#Date Submitted: 15/06/2017

#imports the flask and serial libraries
from flask import Flask, render_template
import serial

#opens up the serial port
ser = serial.Serial('/dev/ttyUSB0',9600)

#intialize the server
app = Flask(__name__)

#print (ser.readline())

#the default web address
@app.route('/')
def index():
    return render_template('index.html')


#used as test web addresses
@app.route('/a')
def a():
    #ser.write(b"32\n")
    return "Toggles LED"

#used as test web addresses
@app.route('/b')
def b():
    ser.write(b"32\n")
    return "Toggles LED"

#web address that moves the arms up and down
@app.route('/arms')
def arms():
    #send serial code 32 to the arduino
    ser.write(b"122\n")
    return "Arms moved"

#web address that energizes and de energizes the arms
@app.route('/energize')
def energize():
    #sends serial code 99 to the arduino
        ser.write(b"99\n")
        return "Energize"

#web address that moves the robot left
@app.route('/left')
def left():

    #send serial code 276 to the arduino
    ser.write(b"276\n")
    return "Moving left"

#web address the moves the robot right
@app.route('/right')
def right():
    #sends serial code 275 to the arduino
    ser.write(b"275\n")
    return "Moving right"

#web address that moves the robot forward
@app.route('/forward')
def forward():
    #send serial code 273 to the arduino
    ser.write(b"273\n")
    return "Moving forward"

#web address that moves the robot backwards
@app.route('/backward')
def backward():

    #sends serial code 274 to the arduino
    ser.write(b"274\n")
    return "Moving backward"

#web address that adds values to the PWN motors
@app.route('/add')
def add():

    #sends serial code 97 to the arduino
    ser.write(b"97\n")
    return "Adding to PWN"

#web address that subtracts values from the PWN motors
@app.route('/subract')
def subtract():
    #send the serial code 98 to the arduino
    ser.write(b"98\n")
    return "Subtracting from PWN"
    

#Allows the server to keep running until close the server
if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')



 
