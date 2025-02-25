# TelloPlusPlus
a easy to learn, lightweight library to interact with Tello drone using C++. Supports both SDK 1.3 and SDK 2.0

# how to compile?
g++ -o exename filename.cpp -lFrogTello
or modify build.cpp file provided in examples

# tutorial
open main.cpp file in the examples and read header file
or read user guide from both SDKs, functions in the library are similiar to them

# known bugs
well there must be bugs because nothing was tested by me, i know that get() functions dont return value that you get for example getBattery() should return a value of your battery but it doesnt
i will fix these when i get able to test everything

# why
this library supports every function from both SDKs, for C++. Provides even custom message sending for the drone
