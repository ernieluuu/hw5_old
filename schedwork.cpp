#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#endif

#include "schedwork.h"
using namespace std;

// a constant that can be used to indicate an INVALID
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;

// Add prototypes for any helper functions here
bool checkPossibleSchedule(const AvailabilityMatrix& avail, size_t day, size_t workerIndex);
bool scheduleHelper(const AvailabilityMatrix& avail, size_t dailyNeed, size_t maxShifts,
	DailySchedule& schedule, size_t day, size_t shiftCount, vector<int> shifts, int workerIndex);

// Add your implementation of schedule() and other helper functions here
bool schedule(
	const AvailabilityMatrix& avail,
	const size_t dailyNeed,
	const size_t maxShifts,
	DailySchedule& sched
) 
{
	bool availIsEmpty = (avail.size() == 0U);
	if (availIsEmpty) {
		return false;
	}

	sched.clear();

	// Add your code below
	int workerIndex = 0;
	vector<int> shifts;

	/*initialization*/
	for (int i = 0; i < avail[0].size(); i++) {
		shifts.push_back(0);
	}

	for (int i = 0; i < 10; i++) {
		checkPossibleSchedule(avail, 0, workerIndex);
	}

	// resize the matrix to the same as available size
	sched.resize(avail.size());

	checkPossibleSchedule(avail, 0, 0);

	return scheduleHelper(avail, dailyNeed, maxShifts, sched, 0, 0, shifts, workerIndex);
}

// Helper function to check if a solution is possible given the initializations
bool checkPossibleSchedule(const AvailabilityMatrix& avail, size_t day, size_t workerIndex) {
	// Base case: if all days are processed, return true
	if (day == avail.size()) {
		return true;
	}

	// Recursive case: process the current day and move to the next day
	if (workerIndex < avail[day].size()) {
		// Recursive call to process the next worker
		if (checkPossibleSchedule(avail, day, workerIndex + 1)) {
			return true;
		}
	}
	else {
		// All workers processed for the current day, move to the next day
		// Recursive call to process the next day
		if (checkPossibleSchedule(avail, day + 1, 0)) {
			return true;
		}
	}

	return false;
}

// Helper function to check if a worker has exceeded the maximum number of shifts
bool scheduleHelper(const AvailabilityMatrix& avail, size_t dailyNeed, size_t maxShifts,
	DailySchedule& schedule, size_t day, size_t shiftCount, vector<int> shifts, int workerIndex) 
{

	// if all of the days are filled
	bool allDaysFilled = (day == avail.size());
	if (allDaysFilled) {
		return true;
	}

	bool shiftCountReached = (shiftCount == dailyNeed);
	if (shiftCountReached) {
		return scheduleHelper(avail, dailyNeed, maxShifts, schedule, day + 1, 0, shifts, 0);
	}

	bool lastWorkerReached = (workerIndex == avail[0].size());
	if (lastWorkerReached) {
		return false;
	}

	bool workerAvailable = avail[day][workerIndex];
	bool shiftsRemaining = (shifts[workerIndex] < maxShifts);

	if (workerAvailable && shiftsRemaining) {
		// assigns worker & updates shift
		schedule[day].push_back(workerIndex);
		shiftCount++;
		shifts[workerIndex]++;

		// moves onto next day
		if (scheduleHelper(avail, dailyNeed, maxShifts, schedule, day, shiftCount, shifts, workerIndex + 1)) {
			return true;
		}

		schedule[day].pop_back();
		shiftCount--;
		shifts[workerIndex]--;

		if (scheduleHelper(avail, dailyNeed, maxShifts, schedule, day, shiftCount, shifts, workerIndex + 1)) {
			return true;
		}
	}
	else {
		if (scheduleHelper(avail, dailyNeed, maxShifts, schedule, day, shiftCount, shifts, workerIndex + 1)) {
			return true;
		}
	}

	return false;
}

/*bool schedule_helper(
	const AvailabilityMatrix& avail,
	const size_t dailyNeed,
	const size_t maxShifts,
	DailySchedule& sched,
	unsigned int day = 0
)
{

	// if it's 0, move on
	// if it's one u can schedule or not scheduel
	// if they are 1 you update the sched
	// move on in a backtracing way
	// return true if curr idx is valid and it's the last idx of the matrix.
	// return false if you get to the end of a row and you haven't gotten enough workers
	// chain back through recursive calls to update your answer
	// always assume you can schedule them on that day, and change your answer if you return false

}*/