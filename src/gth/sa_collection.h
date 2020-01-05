/*
  Copyright (c) 2003-2011 Gordon Gremme <gordon@gremme.org>
  Copyright (c) 2003-2008 Center for Bioinformatics, University of Hamburg

  Permission to use, copy, modify, and distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef SA_COLLECTION_H
#define SA_COLLECTION_H

#include "gth/call_info.h"
#include "gth/input.h"
#include "gth/sa_visitor.h"
#include "gth/stat.h"

typedef struct GthSACollection GthSACollection;

GthSACollection* gth_sa_collection_new(GthDuplicateCheck duplicate_check);
/* Returns true, if <sa> has passed the <sa_filter> and has been inserted into
   <sa_collection>, otherwise false is returned. <stat> is optional. */
bool          gth_sa_collection_insert_sa(GthSACollection*, GthSA *sa,
                                          GthSAFilter *sa_filter,
                                          GthStat *stat);
/* Checks if the given two spliced alignment collections are equal.
   They are equal if they contain exactly the same spliced alignments. */
bool          gth_sa_collections_are_equal(const GthSACollection*,
                                           const GthSACollection*);
/* Returns true if <sa_collection> contains at least on spliced alignment,
   false otherwise. */
bool          gth_sa_collection_contains_sa(const GthSACollection*);
void          gth_sa_collection_traverse(const GthSACollection*, GthSAVisitor*,
                                         GthInput*);
void          gth_sa_collection_set_md5s(GthSACollection*, GthInput*);
void          gth_sa_collection_delete(GthSACollection*);

typedef struct GthSACollectionIterator GthSACollectionIterator;

GthSACollectionIterator* gth_sa_collection_iterator_new(const GthSACollection*);
GthSA*                   gth_sa_collection_iterator_next(
                                                      GthSACollectionIterator*);
void                     gth_sa_collection_iterator_delete(
                                                      GthSACollectionIterator*);

#endif
