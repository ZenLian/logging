# logging

Simple logging module for c/c++, with only one single header file `logging.h`.

## LOGGING_LEVEL

There are 4 logging levels:

    #define __DEBUG   0
    #define __INFO    1
    #define __WARNING 2
    #define __ERROR   3

logging level is default set to DEBUG, which means message in any level will be displayed.

    #define LOGGING_LEVEL   __DEBUG

## LOGGING_RAW

    #define LOGGING_RAW

Undefine it to output logging message with information about file name and line number.

## Todo List

* output logging message not only to stderr but to a file alternatively.
