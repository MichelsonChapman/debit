#ifndef __BITARRAY_H__
#define __BITARRAY_H__ 1
/*
   Copyright (C) 2003 rzyjontko
   Copyright (C) 2006 Jean-Baptiste Note <jean-baptiste.note@m4x.org>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/

/*
 * This will evolve. We'll need more subtle stack structure for Altera's
 * unaligned shit.
 */

#include <glib.h>

typedef unsigned char array_storage_t;

typedef struct bitarray {
  array_storage_t *array;
  int       size;
  int       bits;
} bitarray_t;

extern bitarray_t *bitarray_create (int bits);
extern bitarray_t *bitarray_create_data (char *data, int bits);
extern bitarray_t *bitarray_reverse (bitarray_t *b);
extern void        bitarray_destroy (bitarray_t *a);
extern unsigned char *bitarray_free (bitarray_t *a, gboolean keep_data);
extern void        bitarray_remove (bitarray_t *a, int index);
extern void        bitarray_zeros (bitarray_t *a);
extern void        bitarray_ones (bitarray_t *a);
extern void        bitarray_set (bitarray_t *a, int bit);
extern void        bitarray_unset (bitarray_t *a, int bit);
extern void        bitarray_change_bit (bitarray_t *a, int bit);
extern void        bitarray_neg (bitarray_t *a);
extern void        bitarray_sum (bitarray_t *a, const bitarray_t *b);
extern void        bitarray_intersect (bitarray_t *a, const bitarray_t *b);
extern void        bitarray_subtract (bitarray_t *a, const bitarray_t *b);
extern void        bitarray_diffsym (bitarray_t *a, const bitarray_t *b);
extern int         bitarray_equal (const bitarray_t *a, const bitarray_t *b);
extern void        bitarray_copy (bitarray_t *to, const bitarray_t *from);
extern int         bitarray_is_set (const bitarray_t *a, int bit);
extern void        bitarray_for_ones (bitarray_t *a, void (*fun)(int,void *), void* dat);
extern void        bitarray_print (const bitarray_t *a);
extern void        bitarray_print2D (unsigned width, const bitarray_t *a);
extern int         bitarray_ones_count (const bitarray_t *a);
extern int         bitarray_true_for_all (bitarray_t *a, int (*fun)(int));
extern int         bitarray_first_set (const bitarray_t *a);
extern int         bitarray_none_is_set (const bitarray_t *a);

#endif
