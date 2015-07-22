/* Copyright (C) 2000 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef _list_h_
#define _list_h_

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct st_list {
  struct st_list *prev,*next;
  void *data;
} myLIST;

typedef int (*list_walk_action)(void *,void *);

extern myLIST *list_add(myLIST *root,myLIST *element);
extern myLIST *list_delete(myLIST *root,myLIST *element);
extern myLIST *list_cons(void *data,myLIST *root);
extern myLIST *list_reverse(myLIST *root);
extern void list_free(myLIST *root,unsigned int free_data);
extern unsigned int list_length(myLIST *);
extern int list_walk(myLIST *,list_walk_action action,unsigned char * argument);

#define list_rest(a) ((a)->next)
#define list_push(a,b) (a)=list_cons((b),(a))
#define list_pop(A) {myLIST *old=(A); (A)=list_delete(old,old) ; my_free((unsigned char *) old,MYF(MY_FAE)); }

#ifdef	__cplusplus
}
#endif
#endif
