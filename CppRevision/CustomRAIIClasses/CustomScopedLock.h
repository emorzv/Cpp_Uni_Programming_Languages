#ifndef CUSTOM_SCOPED_LOCK_H
#define CUSTOM_SCOPED_LOCK_H

#include <mutex>

class CustomScopedLock
{
private:
	std::mutex &_m;

public:
	/* Constructors to acquire the resources */
	CustomScopedLock() = delete;
	CustomScopedLock(std::mutex&&) = delete;
	CustomScopedLock(std::mutex& mutex);

	/* Destructors to release the previously acquired resources */
	~CustomScopedLock();
};

#endif // !CUSTOM_SCOPED_LOCK_H

