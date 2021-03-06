#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sorting.h>
#include <assert.h>

#define VALID_ARGUMENTS 2

/*aux functions*/
void* xcalloc(int, int);

/*framework functions*/
void input(int [], int);
void sort(int[], int);
void test_sorting(int[], int);
void output(int arr[], int num_of_elements);

int main(int argv, char *args[]) 
{

    if(argv != VALID_ARGUMENTS) 
	{
        fprintf(stderr, "Invalid arguments: %s \n", args[1]);
        exit(EXIT_FAILURE);
    }

    int num_of_elements = atoi(args[1]);
    int* arr;
    arr = xcalloc(num_of_elements, sizeof(int));

	// populates array with random numbers
    input(arr, num_of_elements);

    sort(arr, num_of_elements);
	
    test_sorting(arr, num_of_elements);

    free(arr);

    exit(EXIT_SUCCESS);
}

void* xcalloc(int instances, int size) 
{
    void* m_blocks;
    m_blocks = calloc(instances, size);
   
    if(m_blocks == NULL) 
	{
        fprintf(stderr, "Out of memory \n");
        exit(EXIT_FAILURE);
    }

    return m_blocks;
}

void input(int arr[], int num_of_elements) 
{
    int i;
	srand(time(NULL));
    for(i=0; i < num_of_elements; i++) 
	{
        arr[i] = rand();    
    }
}

void sort(int array[], int num_of_elements)
{
	if(num_of_elements < INSERTION_SHORT_SIZE)
	{   
		insertion_sort(array, num_of_elements);
	} 
	else
	{   
		heap_sort(array, num_of_elements);
	}
}

void test_sorting(int arr[], int size) 
{
    int i;
    for(i=1; i < size; i++) 
	{
        assert(arr[i-1] < arr[i]);
    }
}

void output(int arr[], int num_of_elements) 
{
    int i;
    for(i=0; i < num_of_elements; i++) 
	{
        printf("arr[%d] = %d \n", i, arr[i]);
    }
}
