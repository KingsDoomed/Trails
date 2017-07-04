#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {

	int* sol = NULL;
	
	//--- Search
    for (int i = 0; i < numsSize - 1; i++) {
    	for (int j = i + 1; j < numsSize; j++) {
			//--- debug Ouput
			printf("nums[%d] + nums[%d] = %d", i, j, (nums[i] + nums[j]));
			if ((nums[i] + nums[j]) == target)
				printf("\tgot it!!!");
			printf("\n");
			
			if ((nums[i] + nums[j]) == target) {
				sol = (int*)malloc(sizeof(int)*2);
				sol[0] = i; sol[1] = j; break;
			}
		}
    }
    
    return sol;
}

int main() {
	const int target = 223;
	const int arrLen = 4;
	int arr[arrLen] = {0, 2, 6, 16};
	int* sol = NULL;
	
	sol = twoSum(arr, arrLen, target);
	
	if (sol != NULL) {
		printf("%d, %d\n", sol[0], sol[1]);
		free(sol);
	}
	else {
		printf("No Solution.\n");
	}
	system("pause");
	return 0;
}
