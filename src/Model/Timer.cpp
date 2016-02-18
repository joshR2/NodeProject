/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: jrob2049
 */

#include "timer.h"
#include <iomanip> //make output look nicer
#include <iostream>
Timer ::Timer()
{
	executionTime= 0;
}

Timer ::~Timer()
{

}

void Timer ::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " (microseconds) for the code" << endl;
	cout << "which is" << float(executionTime)/CLOCKS_PER_SEC << "Seconds" << endl;
}

void Timer::startTimer()
{
	executionTime = clock();
}
void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}
void Timer::resetTimer()
{
	executionTime = 0;
}
long Timer::getExecutionTimeInMicroseconds()
{
	return executionTime;
}
