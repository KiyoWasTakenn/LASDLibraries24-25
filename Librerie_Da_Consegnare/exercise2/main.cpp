
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "LASD Libraries 2025" << std::endl;

  unsigned int choice;

  while(1)
  {
    std::cout << "Inserire una scelta:\n\t0: lasdtest()\n\t1: mytest()\n\tQualsiasi altro numero per uscire\nScelta: ";
    std::cin >> choice; 

    if(choice > 1) break;

    switch(choice)
    {
      case 0: 
        lasdtest();
        break;
      case 1:
        mytest();
        break;
    }
  }
  
  return 0;
}
