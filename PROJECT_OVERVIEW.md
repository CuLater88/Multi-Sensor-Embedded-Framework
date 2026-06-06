# Multi-Sensor Environmental Monitoring System

## Project Overview

This project was developed to create a centralized sensor monitoring system using an Arduino microcontroller. The system collects environmental data from multiple sensors and displays the results through the serial monitor.

The project integrates the following sensors:

* Photoresistors (Light Detection)
* Soil Moisture Sensors
* Temperature Sensor
* Ultrasonic Distance Sensor

The primary objective was to gain practical experience with:

* Embedded systems development
* Sensor integration
* Hardware design
* Analog and digital signal processing
* C++ Object-Oriented Programming
* Reading and interpreting component datasheets
* System-level engineering design


## Problem Statement

Many embedded systems require data from multiple sensors simultaneously. As the number of sensors increases, software complexity also increases.

The goal of this project was to design a modular framework capable of collecting data from multiple sensors while maintaining organized and scalable code.

Rather than writing individual functions for every sensor, a reusable C++ class structure was implemented to simplify future expansion.

---

## Engineering Process

### 1. Requirements and Planning

Before any hardware or software development began, the project requirements were defined.

Questions considered:

* What information should the system collect?
* Which sensors are required?
* How will sensor data be displayed?
* How can the software remain scalable as more sensors are added?

The decision was made to build a sensor monitoring platform capable of measuring:

* Ambient light levels
* Soil moisture levels
* Temperature
* Distance to nearby objects

---

### 2. Datasheet Research

The first technical step was obtaining and reviewing the datasheets for each component.

This process was used to determine:

* Operating voltages
* Current requirements
* Input and output behavior
* Triggering requirements
* Sensor conversion equations

Examples include:

* Understanding the ultrasonic sensor trigger pulse requirements
* Determining the temperature conversion equation
* Understanding analog sensor voltage outputs

Datasheet review was critical for ensuring proper circuit design and software implementation.

---

### 3. System Design

A complete wiring diagram was drafted by hand before assembly.

This provided a visual reference for:

* Sensor placement
* Power distribution
* Arduino pin assignments
* Signal routing

Designing the circuit beforehand helped reduce wiring errors during assembly.

---

### 4. Simulation and Verification

Before building the physical circuit, the design was recreated in Tinkercad.

The simulation was used to verify:

* Wiring correctness
* Sensor functionality
* Voltage levels
* Current paths

Because a physical multimeter was not available during development, simulation provided an additional layer of validation prior to hardware assembly.

---

### 5. Hardware Assembly

All sensors were connected in parallel to the Arduino power supply.

This approach was chosen so that each sensor would receive approximately 5V from the Arduino.

Additional consideration was given to the photoresistor circuits.

Testing and analysis showed that the photoresistors exhibited very low resistance under bright light conditions.

To limit current flow and prevent potential short-circuit conditions, a 1 kΩ resistor was placed in series with each photoresistor.

This improved circuit protection and ensured safer operation.

---

### 6. Software Architecture

Once the hardware was operational, software development began.

Because the system uses multiple sensors, a class-based architecture was selected rather than creating separate standalone functions.

A custom C++ class called:

```cpp
analog_Sensors
```

was created to encapsulate sensor functionality.

The class provides:

* Analog sensor voltage reading
* Ultrasonic sensor distance measurement
* Sensor data averaging

This approach improves:

* Code readability
* Maintainability
* Reusability
* Future scalability

---

## Sensor Processing

### Analog Sensors

Several sensors output analog voltages that are read using the Arduino ADC.

The Arduino converts these voltages into values ranging from:

```text
0 - 1023
```

These values are converted back into voltage measurements for processing.

---

### Light Sensors

Three photoresistors are sampled.

The readings are averaged to reduce the impact of individual sensor variations and provide a more representative measurement of ambient light conditions.

---

### Soil Moisture Sensors

Two soil moisture sensors are sampled.

The readings are averaged to improve measurement consistency.

---

### Temperature Sensor

The temperature sensor output voltage is converted into temperature measurements using the sensor's conversion equation.

The resulting value is converted from Celsius to Fahrenheit before display.

---

### Ultrasonic Sensor

The ultrasonic sensor uses a trigger pulse to initiate a distance measurement.

The echo pulse duration is measured and converted into distance using the formula provided in the sensor datasheet.

Distance is displayed in inches.

---

## Results

The completed system successfully:

* Collected data from six analog sensors
* Measured object distance using ultrasonic ranging
* Converted raw ADC values into engineering units
* Displayed environmental data through the serial monitor
* Demonstrated modular C++ software architecture

The project provided hands-on experience with both hardware integration and embedded software development.

---

## Lessons Learned

This project reinforced several engineering concepts:

### Hardware Design

* Importance of reviewing datasheets before implementation
* Benefits of validating circuits through simulation
* Proper resistor selection and current limiting

### Embedded Software

* ADC conversion and signal processing
* Class-based software architecture
* Sensor abstraction through reusable interfaces

### Systems Engineering

* Planning before implementation
* Hardware-software integration
* Debugging across multiple system layers

---

## Future Improvements

Potential future enhancements include:

* Splitting class definitions into separate header and source files
* Creating dedicated sensor classes for each sensor type
* Data logging to CSV or SD card
* LCD or OLED display integration
* Wireless telemetry using Bluetooth or Wi-Fi
* ROS2 integration for robotics applications

---

## Technologies Used

* Arduino
* C++
* Tinkercad
* Serial Communication
* Analog-to-Digital Conversion (ADC)
* Object-Oriented Programming (OOP)
* Embedded Systems Development
* Sensor Integration
