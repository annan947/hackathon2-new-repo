#include <ctime>
#include "MainHelperList.h"

void wait(double seconds) {
    double start_time = clock();
    while(clock() - start_time < seconds * CLOCKS_PER_SEC){
        
    }
}