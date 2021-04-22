/**
 * * Safe Input Module
 * * Original Work: @Teproanyx
 * * Customed by: @Leomotors
 */

#include "SafeInput.hpp"

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>

namespace tsi
{
    using namespace std;
    long getLong(const char *prompt)
    {
        const char *buffer = getString(prompt).c_str();
        ;
        if (buffer[0] == '\0')
        {
            printf("Input error, please try again!\n");
            return getLong(prompt);
        }

        char *end = NULL;
        errno = 0;

        long n = strtol(buffer, &end, 10);
        if (errno || *end != '\0')
        {
            fprintf(stderr, "Value conversion error\n");
            printf("Input error, please try again!\n");
            return getLong(prompt);
        }
        return n;
    }

    int getInt(const char *prompt)
    {
        long n = getLong(prompt);
        if (n > INT_MAX || n < INT_MIN)
        {
            printf("Input error, please try again!\n");
            return getInt(prompt);
        }
        return (int)n;
    }

    double getDouble(const char *prompt)
    {
        const char *buffer = getString(prompt).c_str();
        if (buffer[0] == '\0')
        {
            printf("Input error, please try again!\n");
            return getLong(prompt);
        }

        char *end = NULL;
        errno = 0;

        double n = strtod(buffer, &end);
        if (errno || *end != '\0')
        {
            fprintf(stderr, "Value conversion error\n");
            printf("Input error, please try again!\n");
            return getDouble(prompt);
        }

        return n;
    }

    std::string getString(const char *prompt)
    {
        size_t size = INITIAL_BUFFER;
        printf("%s", prompt);
        char *buffer = (char *)malloc((size + 1) * sizeof(*buffer));
        memoryError(buffer);
        if (fgets(buffer, size + 1, stdin) == NULL)
        {
            free(buffer);
            printf("Error, try again!\n");
            return getString(prompt);
        }
        while (buffer[strlen(buffer) - 1] != '\n')
        {
            char *subBuffer = (char *)malloc((size + 1) * sizeof(*subBuffer));
            memoryError(subBuffer);

            if (fgets(subBuffer, size + 1, stdin) == NULL)
            {
                free(buffer);
                free(subBuffer);
                printf("Read Error(WTF HOW), try again MTFKER!\n");
                return getString(prompt);
            }

            size *= 2;
            buffer = (char *)realloc(buffer, size + 1);
            memoryError(buffer);

            strncat(buffer, subBuffer, size / 2);
            free(subBuffer);
        }
        buffer[strlen(buffer) - 1] = '\0';
        buffer = (char *)realloc(buffer, strlen(buffer) + 1);
        memoryError(buffer);

        std::string iString = buffer;
        free(buffer);
        return iString;
    }

    void memoryError(const void *pointer)
    {
        if (pointer == NULL)
        {
            printf("Not enough RAM. Terminating program...\n");
            exit(EXIT_FAILURE);
        }
    }
}