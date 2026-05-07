# Pendulum-Accelerometer
DESCRIPTION:

A single dimensional  which uses the angle made by a pendulum with the vertical/accelerometer axis(defined as the direction of acceleration due to gravity according to the design) to find the acceleration of the sensor. This uses a potentiometer salvaged from a hobby servo motor to measure angles made by the pendulum connected to it, by changing its resistance with respect to angles. The potentiometer is used as a variable resistor as a part of a voltage divider with a 10k resistor. 

ACCELEROMETER DESIGN:

This design involves a freely hanging pendulum with a pencil eraser as a mass connected to a potentiometer through a relatively rigid metal wire. The potentiometer is mounted on a chasis built using matchsticks and superglue(fevikwik). 

<img width="942" height="703" alt="Screenshot 2026-04-26 082919" src="https://github.com/user-attachments/assets/5096eadb-b36b-47ed-b4a1-d973a0cb838f" />

[later added extra mass to counter frictional opposition of potentiometer using a appropriately heavy, small screw]

MECHANICS OF THE ACCELEROMETER:

<img width="716" height="573" alt="diagram" src="https://github.com/user-attachments/assets/fd719220-3809-42b6-8230-4087e812a608" />

When the pendulum chasis(the one made out of matchsticks) is accelerated with acceleration a in the frame of a observer in relative rest, in the frame of the pendulum chasis, a pseudo acceleration a' acts on the pendulum such that:

        a = a'
        
This creates a pseudo force(F) :

        F = ma' = ma

This makes the pendulum to swing and make a angle (x) with the accelerometer axis and in case of constantly accelerating frame, it reaches a equilibrium due to a gravitational pull. After resolving the tension, gravitation and pseudo force vectors along and perpendicular to accelerometer axis, balancing them:

        Tcos(x) = mg ----->1
        
        Tsin(x) = ma ----->2 (as ma' = ma)
dividing 2 by 1:

         tan(x) = a/g
                         
final expression --- >  | a = g*tan(x) |

SCHEMATIC:

<img width="894" height="573" alt="accelerometer circuit" src="https://github.com/user-attachments/assets/3ae3ba18-a348-40f4-af16-b9c5cbbb0bdb" />

explanation: 

The potentiometer/variable resistance is connected in series with a 10k ohm resistor accross the 5v and gnd terminals of the arduino nano. As the resistance of variable resistance changes the potential of the point to which pin A2 is connected changes almost linearly, proof:

  Rv ---> variable resistance
  
  Rc ---> constant 10k ohm resistance
  
  V  ---> potential difference accorss the potential divider = 5v-0v = 5v
  
  I = current in the potential divider for a given Rv
  
  Vv ---> potential difference accross the variable resistor

  Vx ---> potential difference between gnd and point to which A2 is connected [arduino ADC input]
  
  using ohm's law:
  
     I = V/(Rv+Rc)
     
     Vv = IRv 
     
     Vv = (V*Rv)/(Rv+Rc) 
     
     Vx = V-Vv

     Vx = V - (V*Rv)/(Rv+Rc)

     Vx = -(V*Rv)/(Rv+Rc) + V

     since Rv << Rc (larger 10k ohm resistance) , Rv+Rc = ~ constant

     Vx = k*Rv + V
     
     which is of the form 
     
     y = m*x + c ----> linear

DATA PROCESSING:

These Vx values are measured by the ADC as values between 0 and 1023(lets call it ADCout). The arduino ADCout values are then measured(through serial monitor while an example analog read sketch is running on arduino) for each extreme pendulum positions, at 0 radians with the accelerometer axis and π/2 radians with the accelerometer axis, while the pendulum connected to the variable resistors is connected to the main circuit. These values are noted for mapping. then in the main code these values are used as lower and upper limits to map the ADCout values to 0 to 90 range[angles in degree]. The main code is a standard AnalogRead example sketch found in Arduino IDE examples(under files), modified to perform additional trigonometric and arithmetic calculations. These mapped out values are then converted to radian form and then substituted into the main expression in the code assigned to the acceleration float variable 'a' which is then displayed in serial monitor and also can be plotted through serial plotter. 

OPERATION OF ACCELEROMETER:

https://github.com/user-attachments/assets/5880ba18-84e8-4991-bf81-ed034f726edc

image of serial plotter during another test run



LIMITATIONS:

1. Inaccuracies due to mechanical and electrical noise

2. One dimensional

3. Difficult to test and check for errors
