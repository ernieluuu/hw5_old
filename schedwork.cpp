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
// bool is_valid(/*arguments*/);
bool schedule_helper(
	const AvailabilityMatrix& avail,
	const size_t dailyNeed,
	const size_t maxShifts,
	DailySchedule& sched,
	unsigned int day = 0,
	std::vector<size_t> shiftsAssigned = {}
);

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

	// calls schedule_helper
	return schedule_helper(avail, dailyNeed, maxShifts, sched);

	/*
	
	iterate through avail using a for loop + iterator
	if condition,
	backtrack


	sets worker 1 day 1 to working, continues through algo
	with setting to working first and then backtracking (are they default to non working?
	or do we have to manually set it to non working?)
	and continue through the algorithm.


	
	*/


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

bool schedule_helper(
	const AvailabilityMatrix& avail,
	const size_t dailyNeed,
	const size_t maxShifts,
	DailySchedule& sched,
	unsigned int day,
	std::vector<size_t> shiftsAssigned
) {
	const size_t numDays = avail[0].size();
	const size_t numWorkers = avail.size();

	if (shiftsAssigned.empty()) {
		shiftsAssigned.assign(numWorkers, 0);
	}

	if (day == numDays) {
		return true;  // All days scheduled successfully
	}

	if (sched.size() <= day) {
		sched.emplace_back(dailyNeed, INVALID_ID);
	}

	for (Worker_T worker = 0; worker < numWorkers; ++worker) {
		if (avail[worker][day] && shiftsAssigned[worker] < maxShifts) {
			sched[day][sched[day].size() - dailyNeed] = worker;
			shiftsAssigned[worker]++;

			if (schedule_helper(avail, dailyNeed, maxShifts, sched, day + 1, shiftsAssigned)) {
				return true;
			}

			sched[day][sched[day].size() - dailyNeed] = INVALID_ID;
			shiftsAssigned[worker]--;
		}
	}

	return false;  // No valid schedule found for this day
}

/*




*/