/*
  Originally coded by Zen Lian @2018-11-08 just for fun.
  Don't see <https://github.com/ZenLian>, nothing there.
*/

#ifndef LOGGING_H
#define LOGGING_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stdarg.h>

#define __DEBUG   0
#define __INFO    1
#define __WARNING 2
#define __ERROR   3

#define LOGGING_LEVEL   __DEBUG
#define LOGGING_RAW

static inline int LOG_COMMON(char* file, int line, const char *fmt, ...)
{
    char logbuf[256];
    int ret;
    va_list ap;

#ifndef LOGGING_RAW
    fprintf(stderr, "%s(%d): ", file, line);
#endif

    va_start(ap, fmt);
    ret = vsprintf(logbuf, fmt, ap);
    va_end(ap);

    fprintf(stderr, logbuf);

    return ret;
}

#if LOGGING_LEVEL <= __DEBUG
#define LOG_DEBUG(fmt, ...)\
    do {\
        fprintf(stderr, "DEBUG: ");\
        LOG_COMMON(__FILE__, __LINE__, fmt, ##__VA_ARGS__);\
    } while (0)
    
#else
#define LOG_DEBUG(fmt, ...)
#endif

#if LOGGING_LEVEL <= __INFO
#define LOG_INFO(fmt, ...)\
    do {\
        fprintf(stderr, "INFO: ");\
        LOG_COMMON(__FILE__, __LINE__, fmt, ##__VA_ARGS__);\
    } while (0)
#else
#define LOG_INFO(fmt, ...)
#endif

#if LOGGING_LEVEL <= __WARNING
#define LOG_WARNING(fmt, ...)\
    do {\
        fprintf(stderr, "WARNING: ");\
        LOG_COMMON(__FILE__, __LINE__, fmt, ##__VA_ARGS__);\
    } while (0)
#else
#define LOG_WARNING(fmt, ...)
#endif

#if LOGGING_LEVEL <= __ERROR
#define LOG_ERROR(fmt, ...)\
    do {\
        fprintf(stderr, "ERROR: ");\
        LOG_COMMON(__FILE__, __LINE__, fmt, ##__VA_ARGS__);\
    } while (0)
#else
#define LOG_ERROR(fmt, ...)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LOGGING_H */