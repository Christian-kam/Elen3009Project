//Authors: Catherine Honegger
//			Christian Kamwangala
//			StopWatch class implementation

#include "StopWatch.h"
#include <ctime>

StopWatch::StopWatch(){
	reset();
}
	
	
//starts the stopwatch timing
void StopWatch::start()
{
	if(stopped==0)
		startTime = getProcessTime();
	else
		pauseTime = getProcessTime()-stopped;
}

//returns the final stopwatch timing
double StopWatch::stop()
{
	stopped = getProcessTime();
	
	if(pauseTime==0)
		runTime = stopped - startTime; //Time that has passed
	else
		runTime = stopped - pauseTime;
			
	return runTime;
}

//resets the stopwatch to zero
void StopWatch::reset()
{
	startTime = 0;
	runTime = 0;
	pauseTime = 0;
	stopped = 0;
}

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
