#include<stdio.h>
#include"list.h"


int main(int argv, char *args[]) {
    list_t *list;
    list = create_list();

    insert_beginning(list, 10);
    insert-after_data(list, 10, 20);
    insert_before_data(list, 20, 30);
    insert_end(list, 40);
}
