#include "MergeSort.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/*------------------------------------------------- Merge Sort -----
|  Function Merge Sort
|
|  Purpose:  Merge Sort
|
|  Parameters:
| 	IN:Array
|	OUT:Array
|  Returns:
*-------------------------------------------------------------------*/

//	int up = 1;
//	int down = 0;

void MergeSort(DTYPE IN[SIZE]){
// Write your code here

// Synthesizable with only outermost loop unrolled:

//	DTYPE B[SIZE];
//
//	MergeSort_label0:for (int width = 1; width < SIZE; width = 2 * width) {
//		int loop_boundary = 0;
//		while (loop_boundary < SIZE - loop_boundary * 2 * width + loop_boundary) loop_boundary++;
//
//		int i = 0;
//		for (int x = 0; x < SIZE; x++) {
//			if (x < loop_boundary) {
//			i = x * 2 * width;
//			int this_lower_border = i;
//			int this_upper_border = fmin(i+width, SIZE);
//			int nd_loop_boundary = fmin(i+2*width, SIZE) - i;
//			int j;
//			for (int y = 0; y < SIZE; y++) {
//				if (y < nd_loop_boundary) {
//				j = y + i;
//				if (this_lower_border < fmin(i+width, SIZE)
//					&& (this_upper_border >= fmin(i+2*width, SIZE)
//						|| IN[this_lower_border] <= IN[this_upper_border])) {
//					B[j] = IN[this_lower_border];
//					this_lower_border = this_lower_border + 1;
//				}
//				else {
//					B[j] =IN[this_upper_border];
//					this_upper_border = this_upper_border + 1;
//				}
//				}
//			}
//			for(int i = 0; i < SIZE; i++) IN[i] = B[i];
//		}
//		}
//	}
//	IN = B;

// simpler code, values from cosim

	DTYPE B[SIZE];
	for (int width = 1; width < SIZE; width = 2 * width) {
		for (int y = 0; y < SIZE; y = y + 2 * width) {
			int this_lower_border = y;
			int this_upper_border = fmin(y+width, SIZE);
			for (int j = y; j < fmin(y+2*width, SIZE); j++) {
				if (this_lower_border < fmin(y+width, SIZE)
					&& (this_upper_border >= fmin(y+2*width, SIZE)
						|| IN[this_lower_border] <= IN[this_upper_border])) {
					B[j] = IN[this_lower_border];
					this_lower_border = this_lower_border + 1;
				}
				else {
					B[j] =IN[this_upper_border];
					this_upper_border = this_upper_border + 1;
				}
			}
			for(int i = 0; i < SIZE; i++) IN[i] = B[i];
		}
	}
	IN = B;

// bitonic mergesort - inspired by http://www.sanfoundry.com/c-program-implement-bitonic-sort/

//	recbitonic(0, SIZE, up, IN);

}

//void compare(int i, int j, int dir, DTYPE IN[SIZE])
//{
//    if (dir == (IN[i] > IN[j]))
//    {
//    	int helper = IN[i] ;
//        IN[i] = IN[j];
//        IN[j] = helper;
//    }
//}
//
//void bitonicmerge(int low, int c, int dir, DTYPE IN[SIZE])
//{
//    int k, i;
//
//    if (c > 1)
//    {
//         k = c / 2;
//        for (i = low;i < low+k ;i++)
//            compare(i, i+k, dir, IN);
//        bitonicmerge(low, k, dir, IN);
//        bitonicmerge(low+k, k, dir, IN);
//    }
//}
//
//void recbitonic(int low, int c, int dir, DTYPE IN[SIZE])
//{
//    int k;
//
//    if (c > 1)
//    {
//        k = c / 2;
//        recbitonic(low, k, up, IN);
//        recbitonic(low + k, k, down, IN);
//        bitonicmerge(low, c, dir, IN);
//    }
//}


