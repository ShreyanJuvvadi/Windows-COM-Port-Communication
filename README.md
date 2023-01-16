# Windows-COM-Port-Communication
A program designed to read data from the COM port of a Windows PC

Associated with https://github.com/ShreyanJuvvadi/Arduino-Bluetooth-and-Serial-Communication

***

Function

1. Read the variable for the com port and attempt to conenct to it, throw out an error if it did not connect and close
2. Initiate the read function and hangs on the reaad till data is recieved
    1. If data is recieved then read the data and compare the data to a string
        1. If the input matches a string then execute the command the string is associated with, else ignore
            1. If the function has an output, send the output back to the com port
                1. Repeat

***

Tools needed <br />

* Visual studio, program has only been tested on visual studio

***

Features include 

* Serial Connect
* Serial Read
* Serial Write
* Easily expandable functions (only need to add an if statement)
* Easy access to a config file

***

Files

* Main file (.sln) is for visual studio
* COM Port Communication.cpp
* Config.h
* Custom Serial.cpp
* Custom Serial.h
* Handlers.cpp
* Handlers.h

***

Bugs and Issues

* Uses an input buffer rather than a string for finer control of data
* a semicolon, ";", clears the input buffer, must clear this before every input
