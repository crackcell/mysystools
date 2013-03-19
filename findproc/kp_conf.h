/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _KP_CONF_H_
#define _KP_CONF_H_

/**
 * 
 *
 * @file kp_conf.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Tue Mar 19 12:16:45 2013
 *
 **/

#include <linux/limits.h>

struct kp_conf {
    char file[PATH_MAX];
};

#endif /* _KP_CONF_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
