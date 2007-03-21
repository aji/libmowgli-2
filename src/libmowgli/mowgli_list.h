/*
 * libmowgli: A collection of useful routines for programming.
 * mowgli_list.c: Linked lists.
 *
 * Copyright (c) 2007 William Pitcock <nenolod -at- sacredspiral.co.uk>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARextern IS PROVIDED BY THextern AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THextern IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSextern ARE
 * DISCLAIMED. IN NO EVENT SHALL THextern AUTHOR Bextern LIABLextern FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTextern GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCextern OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THextern USextern OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __MOWGLI_LIST_H__
#define __MOWGLI_LIST_H__

/* macros for linked lists */
#define MOWGLI_LIST_FOREACH(n, head) for (n = (head); n; n = n->next)  
#define MOWGLI_LIST_FOREACH_NEXT(n, head) for (n = (head); n->next; n = n->next)
#define MOWGLI_LIST_FOREACH_PREV(n, tail) for (n = (tail); n; n = n->prev)

#define MOWGLI_LIST_LENGTH(list) (list)->count

#define MOWGLI_LIST_FOREACH_SAFE(n, tn, head) for (n = (head), tn = n ? n->next : NULL; n != NULL; n = tn, tn = n ? n->next : NULL)

/* list node struct */
typedef struct mowgli_node_ mowgli_node_t;
typedef struct mowgli_list_ mowgli_list_t;

struct mowgli_node_
{
	struct mowgli_node_ *next, *prev; 
	void *data;                   /* pointer to real structure */
	mowgli_list_t *parent;
};

/* node list struct */
struct mowgli_list_
{
	mowgli_node_t *head, *tail;
	size_t count;                    /* how many entries in the list */
};

extern void mowgli_node_init(void);
extern mowgli_node_t *mowgli_node_create(void);
extern void mowgli_node_free(mowgli_node_t *n);
extern void mowgli_node_add(void *data, mowgli_node_t *n, mowgli_list_t *l);
extern void mowgli_node_add_head(void *data, mowgli_node_t *n, mowgli_list_t *l);
extern void mowgli_node_add_before(void *data, mowgli_node_t *n, mowgli_list_t *l, mowgli_node_t *before);
extern void mowgli_node_insert(void *data, mowgli_node_t *n, mowgli_list_t *l, int position);
extern int mowgli_node_index(mowgli_node_t *n, mowgli_list_t *l);
extern void mowgli_node_delete(mowgli_node_t *n, mowgli_list_t *l);
extern mowgli_node_t *mowgli_node_find(void *data, mowgli_list_t *l);
extern void mowgli_node_move(mowgli_node_t *m, mowgli_list_t *oldlist, mowgli_list_t *newlist);
extern mowgli_list_t *mowgli_node_parent(mowgli_node_t *n);
extern mowgli_node_t *mowgli_node_nth(mowgli_list_t *l, int pos);
extern void *mowgli_node_nth_data(mowgli_list_t *l, int pos);

extern mowgli_list_t *mowgli_list_create(void);
extern void mowgli_list_free(mowgli_list_t *l);

#endif
