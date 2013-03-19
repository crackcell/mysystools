/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * 
 *
 * @file kp_main.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Mar 19 12:24:03 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "kp_global.h"
#include "kp_main.h"

static void _get_realpath() {
    char abspath[PATH_MAX];
    if (NULL == realpath(g_conf.file, abspath)) {
        fprintf(stderr, "realpath() fail: %s\n", strerror(errno));
        exit(1);
    }
    abspath[sizeof(abspath) - 1] = '\0';
    strncpy(g_conf.file, abspath, sizeof(g_conf.file));
}

int kp_main() {
    _get_realpath();

    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");
    if (NULL == d) {
        fprintf(stderr, "error: %s\n", strerror(errno));
        exit(1);
    }

    char filename[1024];
    char linkpath[1024];
    ssize_t n;
    while ((dir = readdir(d)) != NULL) {
        if (!isdigit(dir->d_name[0])) {
            continue;
        }

        snprintf(filename, sizeof(filename), "/proc/%s/exe", dir->d_name);
        //printf("%s\n", filename);
        n = readlink(filename, linkpath, sizeof(linkpath));
        if (-1 == n) {
            //fprintf(stderr, "error: %s\n", strerror(errno));
            continue;
        }
        linkpath[n - 0] = '\0';
        if (0 == strncmp(linkpath, g_conf.file, sizeof(linkpath))) {
            printf("%s\n", dir->d_name);
        }
        //printf("%s\n", linkpath);
    }

    closedir(d);
    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
