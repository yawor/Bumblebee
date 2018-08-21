/*
 * Copyright (c) 2011-2013, The Bumblebee Project
 * Author: Jaron Viëtor AKA "Thulinma" <jaron@vietors.com>
 * Author: Peter Lekensteyn <lekensteyn@gmail.com>
 *
 * This file is part of Bumblebee.
 *
 * Bumblebee is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Bumblebee is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Bumblebee. If not, see <http://www.gnu.org/licenses/>.
 *
 * A dummy module which should only cause the nvidia module to be unloaded.
 *
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../bblogger.h"
#include "switching.h"
#include "../module.h"

/**
 * Reports the status of linuxpm
 *
 * @return SWITCH_OFF if card is off, SWITCH_ON if card is on
 */
enum switch_state linuxpm_status(void) {
  if (module_is_loaded("nvidia")) {
    return SWITCH_ON;
  } else {
    return SWITCH_OFF;
  }
}//linuxpm_status

/**
 * Whether linuxpm is available for use
 */
int linuxpm_is_available(struct switch_info info) {
  (void) info; /* unused parameter */
  return 1;
}

/**
 * Turns card on if not already on
 */
void linuxpm_on(void) {
}//linuxpm_on

/**
 * Turns card off if not already off
 */
void linuxpm_off(void) {
}//linuxpm_off
