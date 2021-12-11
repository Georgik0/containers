//
// Created by Stephane Kitsch on 12/11/21.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    auto it = a.begin();
    std::reverse_iterator<int> it1;
//    std::iterator<std::vector<int> > it = a.begin();
//    std::cout << *it << std::endl;
//    std::reverse_iterator<std::vector<int>()> it = a.begin();
    std::cout << *it << std::endl;
}
