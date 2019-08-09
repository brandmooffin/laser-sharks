# laser-sharks
Code for HacksterMIA/GDG Miami Laser Sharks Workshop

![image](https://secure.meetupstatic.com/photos/event/5/c/8/7/highres_483743687.jpeg)

# Overview
This project is run on an Arduino UNO and uses IR sensors (receivers & emitter) for the laser tag mechnism. The code detects when IR receivers are hit from any IR emitter and registers that as a "hit". 

The "shark" runs on an autonomous rover that is also controlled by the Arduino UNO and uses a distance sensor to determine oncoming object and attempts to adjust course based on blocking obstacles. (like a roomba!)

There are additional components included, a LED and a buzzer/speaker, which are used to alert that the rover has been hit. The code forces the rover to pause momentarily and once it is clear will resume movement.


# Project Schematic
![image](https://github.com/brandmooffin/laser-sharks/blob/master/laser_shark_sketch_bb.png?raw=true)
