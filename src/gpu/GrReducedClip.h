/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrReducedClip_DEFINED
#define GrReducedClip_DEFINED

#include "SkClipStack.h"
#include "SkTLList.h"

class SK_API GrReducedClip {
public:
    typedef SkTLList<SkClipStack::Element, 16> ElementList;

    enum InitialState {
        kAllIn_InitialState,
        kAllOut_InitialState,
    };

    /**
     * This function takes a clip stack and a query rectangle and it produces a
     * reduced set of SkClipStack::Elements that are equivalent to applying the
     * full stack to the rectangle. The clip stack generation id that represents
     * the list of elements is returned in resultGenID. The initial state of the
     * query rectangle before the first clip element is applied is returned via
     * initialState. The reducer output tighterBounds is a tighter bounds on the
     * clip. tighterBounds will always be contained by queryBounds after return.
     * It is assumed that the caller will not draw outside of tighterBounds.
     * The requiresAA output will indicate whether anti-aliasing is required to
     * process any of the elements in the element list result.
     */
    static void ReduceClipStack(const SkClipStack& stack,
                                const SkIRect& queryBounds,
                                ElementList* result,
                                int32_t* resultGenID,
                                InitialState* initialState,
                                SkIRect* tighterBounds,
                                bool* requiresAA);
};

#endif
