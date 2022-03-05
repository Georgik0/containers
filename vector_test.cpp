#include "vector.hpp"


void vector_test() {
    std::vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> b {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int>::iterator  ita = a.begin();
    std::vector<int>::iterator  itb = b.begin();

    std::vector<int> sum(a.end(), b.begin());
    for (auto i : sum) {
        std::cout << i << "\n";
    }
    std::cout << "dist: " << a.begin() - a.end() << "\n";
    std::cout << "dist: " << a.end() - a.begin() << "\n";
    std::cout << "dist: " << a.end() - b.begin() << "\n";
    std::cout << "dist: " << a.begin() - b.end() << "\n";

    int first = 20, last = 1;
    int _len = first < last ? last - first : first - last;
    std::cout << _len << "\n";

    /* error vector
    std::vector<int> vec_err(a.end(), a.begin());
    for (auto i : vec_err) {
        std::cout << i << "\n";
    }
    */
   std::cout << "\nTest allocator\n";
   std::allocator<int>  alloc;
   int n = 10;
   int *ptr = alloc.allocate(n);
   alloc.allocate(n, ptr + n);
   for (size_t i = 0; i < 2*n; i++) {
       alloc.construct(ptr + i, i);
       std::cout << *(ptr + i) << "\n";
   }

   {
       std::vector<int> a {1, 2, 3, 4, 5};
       std::cout << "size = " << a.size() << "\n";
       int t = a.at(20);
       std::cout << "test at(pos), pos > _len   t = " << t << "\n";
   }

}