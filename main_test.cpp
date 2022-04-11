#include <unistd.h>
#include <iostream>
#include <time.h>

void reverse_iterator_test();
void vector_test();
void rb_tree_insert_test();
void rb_tree_delete_test();
void rb_tree_construct_test();
void map_test();
void test_set();
void crash_test();

int main() {

    clock_t start = clock();

    reverse_iterator_test();
    vector_test();
    rb_tree_insert_test();
    rb_tree_delete_test();
    rb_tree_construct_test();
    map_test();
    test_set();
    crash_test();

    clock_t end = clock();
    double sec = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time = " << sec << std::endl;

    // pause();
}