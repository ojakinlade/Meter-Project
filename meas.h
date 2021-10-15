#ifndef MEAS_H
#define MEAS_H

#define NUMBER_OF_SAMPLES		2000

extern void voltage_CurrentMeasurement_Init(void);

extern double getVoltage(uint16_t* maxim);
extern double getCurrent(uint16_t* maxim);



#endif /* MEAS_H */