#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.c"

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )
#define calloc( x , y ) mycalloc( x, y, __FILE__, __LINE__ )
#define realloc( x , y ) myrealloc( x, y, __FILE__, __LINE__ )

struct node {
	struct node *next;
	int data;
};

int main(int argc, char** argv) {

	// Test Case 1 - free()ing pointers that were never allocated
	int x;
	free(&x);

	// Test Case 2 - free()ing pointers to dynamic memory that were not returned from malloc()
/*	char *p;
	p = (char*)malloc(5);
	free(p+20);
*/

	// Test Case 3 - redundant free()ing of the same pointer
/*	char *p;
	p = (char*)malloc(5);
	free(p);
	free(p);
*/

	// Test Case 4 - malloc()ing a variable of size 0
/*	char *p;
	p = (char*)malloc(0);
	free(p);
*/

	// Test Case 5 - free()ing a pointer that points to NULL
/*	char *null = (char*)malloc(10);
	null = NULL;
	free((void*)null);
*/

	// Test Case 6 - calloc()ing
/*	char *str = (char *) calloc(1, 6);
	
	str[0] = 'h';
	str[1] = 'i';
	str[2] = '\0';
	
	int i;
	for(i = 0; i < 6; i++){
		printf("str[%d]: %c\n", i, str[i]);
	}
*/

	// Test Case 7 - Saturation/using SBRK() to extend heap
/*	char *str = (char*)malloc(1025);
*/
	
	// Test Case 8 - free()ing ptr not in heap
/*	int *ptr;
	free(ptr);
*/

	// Test Case 9 - realloc() to something with less memory
/*	char *str = (char *) calloc(1, 6);
	
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';
	
	int i;
	for(i = 0; i < 6; i++){
		printf("str[%d]: %c\n", i, str[i]);
	}
	
	str = (char*) realloc(str, 4);
	for(i = 0; i < 4; i++){
		printf("str[%d]: %c\n", i, str[i]);
	}
*/

	// Test Case 10 - successful output
/*	char *str = (char *) malloc(6);
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';
	
	printf("str: %s\n", str);
	
	free(str);
*/

	return 0;
}
