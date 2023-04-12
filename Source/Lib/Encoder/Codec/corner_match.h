/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
 */
#ifndef AOM_AV1_ENCODER_CORNER_MATCH_H_
#define AOM_AV1_ENCODER_CORNER_MATCH_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "EbDebugMacros.h"
#include "EbDefinitions.h"

#if OPT_GM_WD
#else
#define MATCH_SZ 13
#define MATCH_SZ_BY2 ((MATCH_SZ - 1) / 2)
#define MATCH_SZ_SQ (MATCH_SZ * MATCH_SZ)
#endif

typedef struct {
    int x, y;
    int rx, ry;
} Correspondence;

int svt_av1_determine_correspondence(unsigned char *frm, int *frm_corners, int num_frm_corners,
                                     unsigned char *ref, int *ref_corners, int num_ref_corners,
                                     int width, int height, int frm_stride, int ref_stride,
#if OPT_GM_WD
                                     int *correspondence_pts, uint8_t match_sz);
#else
                                     int *correspondence_pts);
#endif

DECLARE_ALIGNED(16, extern const uint8_t, svt_aom_compute_cross_byte_mask[8][16]);

#endif // AOM_AV1_ENCODER_CORNER_MATCH_H_
