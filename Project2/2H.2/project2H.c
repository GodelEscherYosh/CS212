#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int compareIntegers(const void *a, const void *b) {
    // Subtracting b from a gives ascending order
    return (*(int *)a - *(int *)b);
}

int *AllocateArray(int N)
{
    /* Allocate an array with N integers.    
     * The value of each element of the array should be a
     * random number between 0 and 10N.    
     * Hint: use the rand() function and a modulo operator.    
     */
	int *nums = (int *)malloc(sizeof(int)*N);
	for(int i = 0; i<N; i++)
	{
		int sampleNum = rand() % (10*N);
		nums[i] = sampleNum;
	}
	return nums;
}

void SortArray(int N, int *A)
{
    qsort(A, N, sizeof(int), compareIntegers);
}

void DeallocateArray(int *A)
{
	free(A);
}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */

    for (int i = 0 ; i < 8 ; i++)
    {
        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;

        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */

	//Allocate Time
	struct timeval startTimeAllocate;
	gettimeofday(&startTimeAllocate,0);
	int *list = AllocateArray(sizes[i]);
	struct timeval endTimeAllocate;
	gettimeofday(&endTimeAllocate,0);
	//tv_sec is seconds, tv_usec is our microseconds (from binary to the seconds)
	alloc_time = (double)((endTimeAllocate.tv_sec-startTimeAllocate.tv_sec))+((double)(endTimeAllocate.tv_usec-startTimeAllocate.tv_usec)/1000000);

	//Sort Time
	struct timeval startTimeSort;
	gettimeofday(&startTimeSort, 0);
	SortArray(i, list);
	struct timeval endTimeSort;
	gettimeofday(&endTimeSort,0);
	//time interval
	sort_time = (double)((endTimeSort.tv_sec-startTimeSort.tv_sec))+((double)(endTimeSort.tv_usec-startTimeSort.tv_usec)/1000000);

	//Deallocate time
	struct timeval startTimeDe;
	gettimeofday(&startTimeDe,0);
	DeallocateArray(list);
	struct timeval endTimeDe;
	gettimeofday(&endTimeDe,0);
	dealloc_time = (double)((endTimeDe.tv_sec - startTimeDe.tv_sec))+((double)(endTimeDe.tv_usec - startTimeDe.tv_usec)/1000000);

	
        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time, alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time, sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time);

	//How do the timings compare with the runs in (5)? How does the output compare with my sample output? (My output had optimizations)
	//Let's take a loot at Runs (5)
	//My Allocation time: 0.00369
	//Hank allocation 0.000112
	//Hanks Time allocation is much faster. Perhaps his time complexity is is better than my code. Perhaps my machine is runing slower.
	//In the later trails, you will see a much more noticable difference in run times from mine and Hanks. This more evidence for
	//the fact that my code has worse time complexity.
	   }
}
