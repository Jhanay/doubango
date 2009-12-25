/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsk_time.h
 * @brief Useful datetime functions.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _TINYSAK_TIME_H_
#define _TINYSAK_TIME_H_

#include "tinySAK_config.h"

#ifdef __SYMBIAN32__ /* Forward declaration */
struct timeval;
struct timezone;
#endif

#define TSK_TIME_S_2_MS(S) (S*1000)

TINYSAK_API int tsk_gettimeofday(struct timeval *tv, struct timezone *tz);
TINYSAK_API uint64_t tsk_time_epoch();

/**
* Gets the number of milliseconds since the EPOCH.
*/
#define tsk_time_now() tsk_time_epoch()

//#ifdef _WIN32_WCE
//
//#ifndef TIMEVAL
///* On wince timeval struct is defined in "Winsock2.h" but I don't want to add it */
//struct timeval 
//{
//  long tv_sec;
//  long tv_usec;
//};
//#define TIMEVAL
//#endif TIMEVAL
//
//#endif

#endif /* _TINYSAK_TIME_H_ */
