# Meter-Project
The aim of this project is to measure the voltage, current and phase difference between voltage and current in a room.
Voltage measurement is done by passing 220volts to a volatage divider network of 470k and 1K ohms resistor. The voltage across the 1K ohms resistor is passed to the analog input
of the microcontroller.
Current is measured using the ACS712 current sensor which gives a DC voltage output proportional to the current flowing.
The phase difference between the current and voltage waveforms is determined using operational amplifiers as zero crossing detectors. Thus, the AC sinusoids are converted into square waveforms
which is then passed into the microcontroller. A rising edge pulse triggers an interrupt and the timestamp at which the interrupt occurs is stored for both waves, the difference in the 
timestamps gives the phase difference.

For more information about this project, contact me at ojakinlade@gmail.com.
