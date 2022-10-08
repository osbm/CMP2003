#include <iostream>
#include <cassert>
#include <time.h>

using namespace std;

int main() {
    // to get different random number everytime
    srand(time(NULL));

    // generate random number between 0 and 1
    double random_number = (double) rand() / RAND_MAX;


    cout << "Random number: " << random_number << endl;
    assert (random_number < 0.5);
    return 0;
}
