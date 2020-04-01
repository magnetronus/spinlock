#pragma once
#include <stdatomic.h>
#include <stdbool.h>

typedef atomic_flag spinlock_t;

void spinlock_init(spinlock_t *lock);

void spinlock_lock(spinlock_t *lock);

bool spinlock_trylock(spinlock_t *lock);

void spinlock_unlock(spinlock_t *lock);
