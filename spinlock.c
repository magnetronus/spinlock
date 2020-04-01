#include <stdint.h>

#include "spinlock.h"

void spinlock_init(spinlock_t *lock)
{
	atomic_flag_clear(lock);
}

void spinlock_lock(spinlock_t *lock)
{
	while(atomic_flag_test_and_set(lock));
}

bool spinlock_trylock(spinlock_t *lock)
{
	return !atomic_flag_test_and_set(lock);
}

void spinlock_unlock(spinlock_t *lock)
{
	atomic_flag_clear(lock);
}
