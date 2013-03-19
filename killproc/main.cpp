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
#include <limits.h>

#include "kp_global.h"
#include "kp_main.h"
#include "version.h"

struct signal_table {
    const char *name;
    int value;
} stable[] = {{"HUP", 1},
              {"INT", 2},
              {"QUIT", 3},
              {"ILL", 4},
              {"TRAP", 5},
              {"ABRT", 6},
              {"BUS", 7},
              {"FPE", 8},
              {"KILL", 9},
              {"USR1", 10},
              {"SEGV", 11},
              {"USR2", 12},
              {"PIPE", 13},
              {"ALRM", 14}};

void show_signal_table() {
    unsigned int i;
    for (i = 0; i < sizeof(stable) / sizeof(struct signal_table); i++) {
        printf("%s\t%d\n", stable[i].name, stable[i].value);
    }
}

int lookup_signal_table(const char *name) {
    unsigned int i;
    for (i = 0; i < sizeof(stable) / sizeof(struct signal_table); i++) {
        if (0 == strncmp(stable[i].name, name, strlen(stable[i].name))) {
            return stable[i].value;
        }
    }
    return -1;
}

void getopts(int argc, char *argv[]) {
    g_conf.signal_value = 9;
    char *endptr;
    char c;
    while ((c = getopt(argc, argv, "hvls:")) != -1) {
        switch (c) {
        case 'l':
            show_signal_table();
            exit(0);
        case 's':
            if (isdigit(optarg[0])) {
                g_conf.signal_value = strtol(optarg, &endptr, 10);
                if (LONG_MAX == g_conf.signal_value) {
                    fprintf(stderr, "invalid signal value: %s\n", optarg);
                    exit(1);
                }
            } else {
                g_conf.signal_value = lookup_signal_table(optarg);
                if (-1 == g_conf.signal_value) {
                    fprintf(stderr, "invalid signal value: %s\n", optarg);
                    exit(1);
                }
            }
            break;
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

    if (argc == optind) {
        show_help();
        exit(1);
    }

    snprintf(g_conf.file, sizeof(g_conf.file), "%s", argv[optind]);
    g_conf.file[sizeof(g_conf.file) - 1] = '\0';
}

int main(int argc, char *argv[]) {
    bzero(&g_conf, sizeof(g_conf));
    getopts(argc, argv);

    signal(SIGPIPE, SIG_IGN);

    return kp_main();
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
