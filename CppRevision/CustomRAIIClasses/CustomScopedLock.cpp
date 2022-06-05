#include <iostream>
#include "CustomScopedLock.h"

using std::cout;
using std::endl;
using std::string;

/* Global, not RAII, mutex */
std::mutex original_mutex;

CustomScopedLock::CustomScopedLock(std::mutex& mutex) : _m(mutex)
{
    _m.lock();
    cout << "Custom mutex locked\n";
}

CustomScopedLock::~CustomScopedLock()
{
    _m.unlock();
    cout << "Custom mutex unlocked\n";
}

int main_not()
{
    {
        CustomScopedLock custom_mutex(original_mutex);
        cout << "Do some stuff with shared between processes resources\n";
    }
     
    /* Mutex is released by this point */
    cout << "Test ending\n";

    return 0;
}
