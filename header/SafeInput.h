/**
 * * Safe Input Module
 * * Original Work: @Teproanyx
 * * Customed by: @Leomotors
 */

#ifndef TEPROANYX_SAFE_INPUT
#define TEPROANYX_SAFE_INPUT

#ifndef INITIAL_BUFFER
#define INITIAL_BUFFER 8
#endif

#include <string>

namespace tsi
{
    long long getlong(const char *);
    int getInt(const char *);
    double getDouble(const char *);
    std::string getString(const char *);
    void memoryError(const void *);
}

#endif