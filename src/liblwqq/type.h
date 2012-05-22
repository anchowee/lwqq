/**
 * @file   type.h
 * @author mathslinux <riegamaths@gmail.com>
 * @date   Sun May 20 22:24:30 2012
 * 
 * @brief  Linux WebQQ Data Struct API
 * 
 * 
 */

#ifndef LWQQ_TYPE_H
#define LWQQ_TYPE_H

#include "queue.h"


/************************************************************************/
/* Lwqq Error Code */
typedef enum {
    LWQQ_OK,
    LWQQ_ERROR,
} LwqqErrorCode;

/************************************************************************/
/* LwqqBuddy API  */

/* QQ buddy */
typedef struct LwqqBuddy {
    LIST_ENTRY(LwqqBuddy) entries;
} LwqqBuddy;

/** 
 * 
 * Create a new buddy
 * 
 * @return A LwqqBuddy instance
 */
LwqqBuddy *lwqq_buddy_new();

/** 
 * Free a LwqqBuddy instance
 * 
 * @param buddy 
 */
void lwqq_buddy_free(LwqqBuddy *buddy);

/************************************************************************/
/* LwqqClient API  */
typedef struct LwqqClient {
    char *username;             /**< Username */
    char *password;             /**< Password */
    LwqqBuddy *myself;          /**< Myself */
    LIST_HEAD(, LwqqBuddy) friends; /**< QQ friends */
    
} LwqqClient;

/** 
 * Create a new lwqq client
 * 
 * @param username QQ username
 * @param password QQ password
 * 
 * @return A new LwqqClient instance, or NULL failed
 */
LwqqClient *lwqq_client_new(const char *username, const char *password);

/** 
 * Free LwqqClient instance
 * 
 * @param client LwqqClient instance
 */
void lwqq_client_free(LwqqClient *client);

#endif  /* LWQQ_TYPE_H */
