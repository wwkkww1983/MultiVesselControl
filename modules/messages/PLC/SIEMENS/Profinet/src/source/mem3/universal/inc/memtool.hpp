/*****************************************************************************/
/*  Copyright (C) 2015 Siemens Aktiengesellschaft. All rights reserved.      */
/*****************************************************************************/
/*  This program is protected by German copyright law and international      */
/*  treaties. The use of this software including but not limited to its      */
/*  Source Code is subject to restrictions as agreed in the license          */
/*  agreement between you and Siemens.                                       */
/*  Copying or distribution is not allowed unless expressly permitted        */
/*  according to your license agreement with Siemens.                        */
/*****************************************************************************/
/*                                                                           */
/*  P r o j e c t         &P: PROFINET IO Runtime Software              :P&  */
/*                                                                           */
/*  P a c k a g e         &W: PROFINET IO Runtime Software              :W&  */
/*                                                                           */
/*  C o m p o n e n t     &C: pcIOX (PNIO Controler, Device and more)   :C&  */
/*                                                                           */
/*  F i l e               &F: memtool.hpp                               :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P05.04.00.00_00.02.00.40         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2015-07-28                                :D&  */
/*                                                                           */
/*****************************************************************************/
/*                                                                           */
/*  D e s c r i p t i o n :                                                  */
/*                                                                           */
/*  MEM3 memory management                                                   */
/*                                                                           */
/*****************************************************************************/

#ifndef MEMTOOL_HPP
#define MEMTOOL_HPP

extern ORDHW  const   BitSetARR [32];
extern ORDHW  const   BitResARR [32];

extern ORDHW          LdDown (ORDHW  Num);
extern ORDHW          LdUp   (ORDHW  Num);

inline
void
SetFlag (ORDHW *  BitSetPTR, ORDHW  BitNum)
  {
    BitSetPTR [BitNum >> 5] |= BitSetARR [BitNum & 0x0000001F];
  }

inline
void
ResFlag (ORDHW *  BitSetPTR, ORDHW  BitNum)
  {
    BitSetPTR [BitNum >> 5] &= BitResARR [BitNum & 0x0000001F];
  }

inline
bool
GetFlag (ORDHW *  BitSetPTR, ORDHW  BitNum)
  {
    ORDHW const  BitNumInTag = BitNum & 0x0000001F;

    return static_cast <bool> ((BitSetPTR [BitNum >> 5] & BitSetARR [BitNumInTag]) >> BitNumInTag);
  }

#endif

/*****************************************************************************/
/*  Copyright (C) 2015 Siemens Aktiengesellschaft. All rights reserved.      */
/*****************************************************************************/
