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
 * @file main.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 15:42:00 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>
#include <ctype.h>

#include "kp_global.h"
#include "kp_main.h"
#include "version.h"

void getopts(int argc, char *argv[]) {
    char c;
    while ((c = getopt(argc, argv, "hv")) != -1) {
        switch (c) {
        case 'h':
            show_help();
            exit(0);
        case 'v':
            show_version();
            exit(0);
        default:
            break;
        }
    }

    if (1 == argc) {
        show_help();
        exit(1);
    }

    snprintf(g_conf.file, sizeof(g_conf.file), "%s", argv[1]);
    g_conf.file[sizeof(g_conf.file) - 1] = '\0';
}

int main(int argc, char *argv[]) {
    bzero(&g_conf, sizeof(g_conf));
    getopts(argc, argv);

    signal(SIGPIPE, SIG_IGN);

    return kp_main();
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
