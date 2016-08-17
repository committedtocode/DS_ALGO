#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "sll.h"

int main() {

	list_t *list = create_list();
	assert(list != NULL);

	result_t result;

	result = insert_begin(list, 10);
	assert(result == SUCCESS && is_at_begining(list, 10) == TRUE);

	result = insert_end(list, 40);
	assert(result == SUCCESS && is_at_end(list, 40) == TRUE);

	result = insert_before_data(list, 40, 30);
	assert(result == SUCCESS && is_before(list, 30, 40) == TRUE);

	result = insert_before_data(list, 10, 5);
	assert(result == SUCCESS && is_before(list, 5, 10) == TRUE);

	result = insert_before_data(list, 100, 50);
	assert(result == ERROR && is_before(list, 50, 100) == FALSE);

	result = insert_after_data(list, 40, 50);
	assert(result == SUCCESS && is_after(list, 50, 40) == TRUE);

	exit (EXIT_SUCCESS);
}

