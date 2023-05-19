#ifndef TIME_JD_H
#define TIME_JD_H

#define DEBUG

unsigned int to_jd0(int year, int month, int day);

double to_dt(int hours, int minutes, int seconds);

double time_stap(double jnd, int seconds);

double zn(double jnd);

double dr(double jnd);

#endif
