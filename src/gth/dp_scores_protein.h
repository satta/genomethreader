/*
  Copyright (c) 2009 Gordon Gremme <gordon@gremme.org>

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

#ifndef DP_SCORES_PROTEIN_H
#define DP_SCORES_PROTEIN_H

#include "core/chardef_api.h"
#include "core/score_matrix_api.h"
#include "gth/bssm_param.h"

typedef struct {
  GtUchar ***codon2amino;
  GthFlt **score;
} GthDPScoresProtein;

static inline GthFlt GTHGETSCORE(GthDPScoresProtein *scores,
                                 GtUchar n1, GtUchar n2, GtUchar n3,
                                 GtUchar aa)
{
  if (n1 == DASH || n2 == DASH || n3 == DASH)
    return scores->score[DASH][aa];
  else if (n1 > 3 || n2 > 3 || n3 > 3)
    return scores->score[GT_WILDCARD][aa];
  return scores->score[scores->codon2amino[n1][n2][n3]][aa];
}

GthDPScoresProtein* gth_dp_scores_protein_new(GtUword translationtable,
                                              GtScoreMatrix *score_matrix,
                                              GtAlphabet
                                              *score_matrix_alphabet);
void                gth_dp_scores_protein_delete(GthDPScoresProtein*);

#endif
