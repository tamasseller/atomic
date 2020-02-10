/*
 * Atomic.h
 *
 *  Created on: 2018.02.28.
 *      Author: tooma
 */

#ifndef ATOMIC_H_
#define ATOMIC_H_

#include "../x86-64-common/AtomicCommon.h"

#include <windows.h>

namespace home {
	
namespace detail {	
	
template<class Data>
bool boolCas(volatile Data *ptr, Data oldval, Data newval) {
	return oldval == (Data)InterlockedCompareExchange((volatile LONG *)ptr, (LONG)newval, (LONG) oldval);
}

}

template<class Data>
using Atomic = IntelArchCommon::Atomic<Data, &detail::boolCas<Data>>;

}

#endif /* ATOMIC_H_ */
