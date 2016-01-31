#ifndef JOBS_H
#define JOBS_H

#include "util.h"

using namespace std;

/* The data structure that stores information about job operations.*/
struct JobStep
{
	int fromJob, fromMach;    // The job and machine this operation belongs to
	int head, body, tail;     // Time information: head, tail, and process time(body)
	JobStep *jsucc;           // Next operation from the same job
	JobStep *jpred;           // Previous operation from the same job
	JobStep *next;            
	JobStep *next2;
};

class JobShopData
{
public:
	//Initializor of JobShop instance
	JobShopData(const char* filename);
private:
	vector< vector<JobStep> > mJobsData;         // Store the jobshop data
	int numJobs, numMachines;                    // Number of jobs and machines
	vector<Machine*> mMachines;                  // Store machine instances
	vector<Job*> mJobs;                          // Store job instances
};

class Job
{
public:
	Job(int id);
private:
	int mJobId;
	vector<JobStep*> mJobSteps;
	JobStep *mJobHead;
};

class Machine
{
public:
	Machine(int numJobs);
private:
	int mMachineId;
	vector<JobStep*> mMachJobs;
	vector<JobStep*> mJobsOrdered;
};

#endif