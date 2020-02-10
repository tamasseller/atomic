/*
 * Atomic.h
 *
 *  Created on: 2018.02.28.
 *      Author: tooma
 */

#ifndef ATOMIC_H_
#define ATOMIC_H_

#include "../x86-64-common/AtomicCommon.h"

namespace home {

template<class Data>
using Atomic = IntelArchCommon::Atomic<Data, &__sync_bool_compare_and_swap>;

}

#endif /* ATOMIC_H_ */
