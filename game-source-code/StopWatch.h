/**
 * @class StopWatch
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file StopWatch.h
 * @brief This class captures the abstraction of a timer object.
 */
#ifndef STOPWATCH_H
#define STOPWATCH_H



class StopWatch {
public:

	/**
	 * @brief Default constructor.
	 * @details Creates an instance of StopWatch and initialises all relevant data members.
	 */
	StopWatch();
	
	/**
	 * @brief Start.
	 * @details This function starts the stopwatch timing
	 */
	void start();
	
	/**
	 * @brief Stop.
	 * @details This function stops the stopwatch and returns the time elapsed.
	 * @return Time elapsed.
	 */
	double stop();
	
	/**
	 * @brief Reset.
	 * @details This function puts back the timer to zero.
	 */
	void reset();
	
private:

	double getProcessTime();
	double startTime;
	double runTime;
	double pauseTime;
	double stopped;
};

#endif
