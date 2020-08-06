# IOT-project

'OFFICE CARE' is an IOT solution for office sectors due to the pandemic which is prevailing in people's life.
The automation ensures contactless entry and safety of office personnel.
The PoC is simulated on Tinkercad simulation platform, following is the link which will direct you to it :
https://www.tinkercad.com/things/96yHY6BDLFz-office-care/editel?sharecode=VvuE1IZl70fuNRQSmaHdGOqRAYPN71Bebzdp8Bix5fs.

Arduino UNO is the microcontroller board used for this project. The coding language employed is embedded C and and is compiled in Arduino IDE. Servo motors have been utilized as the actuators for various purposes. In order to contain the servos, a Servo library has to be imported from the list of C libraries as #include<Servo.h>.

Path to servo library:
Open the arduino IDE, Go to Sketch-> Include Library-> Manage libraries, search for 'Servo' and install the suitable version. Else, here is the link for downloading the zip folder of Servo Library:
https://www.arduinolibraries.info/libraries/servo.

Briefing about the automation:
When people come to the office, the glass door opens automatically as a sign of welcoming them. But when they pass the glass door and come inside, 
there is a pass gate. The pass gate will be opened only if they are sanitized. There are automatic sanitizer dispensers for this purpose. 
When the person stretches hands towards the dispenser, it will dispense the liquid. In a couple of seconds, the pass gates will be opened for 3 seconds
along with a green light which blinks thrice in this period. Finally, with a long beep sound the red light turns on denoting the closure of gate.

Note:

1)While starting the simulation on tinker cad, messages will pop up on the Serial monitor as and when a particular task happens.

2)For sanitizer to dispense, the distance from the ultrasonic distance sensor must be roughly 6 inches.

3)Project details like Program, project design, simulation wiring, list of components have been uploaded in this repository.
