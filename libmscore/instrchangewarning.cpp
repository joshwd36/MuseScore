//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2008-2011 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#include "score.h"
#include "stafftext.h"
#include "system.h"
#include "staff.h"
#include "xml.h"
#include "measure.h"
#include "instrchange.h"

namespace Ms {

//---------------------------------------------------------
//   staffStyle
//---------------------------------------------------------

static const ElementStyle InstrumentChangeWarningStyle {
      { Sid::instrumentChangePlacement,          Pid::PLACEMENT              },
      { Sid::instrumentChangeMinDistance,        Pid::MIN_DISTANCE           },
};

//---------------------------------------------------------
//   InstrumentChangeWarning
//---------------------------------------------------------

InstrumentChangeWarning::InstrumentChangeWarning(InstrumentChange* ic, Score* s, Tid tid)
   : StaffTextBase(s, tid, ElementFlag::MOVABLE | ElementFlag::ON_STAFF), _ic(ic)
      {
      initElementStyle(&InstrumentChangeWarningStyle);
      }

//---------------------------------------------------------
//   layout
//---------------------------------------------------------

void InstrumentChangeWarning::layout()
      {
      TextBase::layout();
      autoplaceSegmentElement();
      }

//---------------------------------------------------------
//   propertyDefault
//---------------------------------------------------------

QVariant InstrumentChangeWarning::propertyDefault(Pid id) const
      {
      switch (id) {
            case Pid::SUB_STYLE:
                  return int(Tid::STAFF);
            default:
                  return StaffTextBase::propertyDefault(id);
            }
      }

//---------------------------------------------------------
//   getPropertyStyle
//---------------------------------------------------------

Sid InstrumentChangeWarning::getPropertyStyle(Pid pid) const
      {
      if (pid == Pid::OFFSET)
            return placeAbove() ? Sid::staffTextPosAbove : Sid::staffTextPosBelow;
      return TextBase::getPropertyStyle(pid);
      }

}