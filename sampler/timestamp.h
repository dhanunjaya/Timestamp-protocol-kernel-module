#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

#include <time.h>
#include <sys/time.h>

typedef signed long long s64;

extern struct timespec ns_to_timespec(s64 nsec);
extern s64 timespec_to_ns(const struct timespec ts);
extern s64 timeval_to_ns(const struct timeval tv);
#endif
