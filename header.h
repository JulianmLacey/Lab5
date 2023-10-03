#pragma once
#include <locale.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <Windows.h>
#elif __APPLE__
#include <unistd.h>
#else
#error "Unknown compiler"
#endif

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct node {
    int data;
    struct node *next;
} Node;