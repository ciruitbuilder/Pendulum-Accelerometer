# Pendulum-Accelerometer
DESCRIPTION:

A single dimensional  which uses the angle made by a pendulum with the vertical/accelerometer axis(defined as the direction of acceleration due to gravity according to the design) to find the acceleration of the sensor. This uses a potentiometer salvaged from a hobby servo motor to measure angles made by the pendulum connected to it, by changing its resistance with respect to angles. The potentiometer is used as a variable resistor as a part of a voltage divider with a 10k resistor. 

ACCELEROMETER DESIGN:

This design involves a freely hanging pendulum with a pencil eraser as a mass connected to a potentiometer through a relatively rigid metal wire. The potentiometer is mounted on a chasis built using matchsticks and superglue(fevikwik). 

<img width="942" height="703" alt="Screenshot 2026-04-26 082919" src="https://github.com/user-attachments/assets/5096eadb-b36b-47ed-b4a1-d973a0cb838f" />

[added extra mass to counter frictional opposition of potentiometer using a appropriately heavy, small screw]

MECHANICS OF ACCELEROMETER:

<img width="716" height="573" alt="diagram" src="https://github.com/user-attachments/assets/fd719220-3809-42b6-8230-4087e812a608" />

when the pendulum chasis(the one made out of matchsticks) is accelerated with acceleration a in the frame of a observer in relative rest, in the frame of the pendulum chasis, a pseudo acceleration a' acts on the pendulum such that:

        a = a'
        
this creates a pseudo force(F) :

        F = ma' = ma

this makes the pendulum to swing and make a angle (x) with the accelerometer axis and in case of constantly accelerating frame, it reaches a equilibrium due to a gravitational pull. After resolving the tension, gravitation and pseudo force vectors along and perpendicular to accelerometer axis, balancing them:

        Tcos(x) = mg ----->1
        
        Tsin(x) = ma ----->2 (as ma' = ma)
dividing 2 by 1:

         tan(x) = a/g
                         
FINAL EXPRESSION:        | a = g*tan(x) |

SCHEMATIC:

<img width="894" height="573" alt="accelerometer circuit" src="https://github.com/user-attachments/assets/3ae3ba18-a348-40f4-af16-b9c5cbbb0bdb" />


