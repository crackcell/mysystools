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
 * @file version.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sat Mar  2 00:17:33 2013
 *
 **/

#include <stdio.h>
#include "version.h"

#ifdef __VERSION_ID__
const char *version_id = __VERSION_ID__;
#else
const char *version_id = "unknown";
#endif
#if defined(__DATE__) && defined(__TIME__)
const char server_built[] = __DATE__ " " __TIME__;
#else
const char server_built[] = "unknown";
#endif

void show_version() {
    printf("Revision    : %s\n", version_id);
    printf("Build date  : %s\n", server_built);
}

void show_help() {
    printf("Usage: killproc [OPTION] PID\n"
           "Kill process with given executable file.\n\n"
           "Options:\n"
           " -h     display this help and exit\n"
           " -v     display version info and exit\n");
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
