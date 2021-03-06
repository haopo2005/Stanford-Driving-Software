/********************************************************
  Stanford Driving Software
  Copyright (c) 2011 Stanford University
  All rights reserved.

  Redistribution and use in source and binary forms, with 
  or without modification, are permitted provided that the 
  following conditions are met:

* Redistributions of source code must retain the above 
  copyright notice, this list of conditions and the 
  following disclaimer.
* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the 
  following disclaimer in the documentation and/or other
  materials provided with the distribution.
* The names of the contributors may not be used to endorse
  or promote products derived from this software
  without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
  DAMAGE.
 ********************************************************/


/*--------------------------------------------------------------------
 * project ....: Darpa Urban Challenge 2007
 * authors ....: Team vlr
 * organization: Transregional Collaborative Research Center 28 /
 *               Cognitive Automobiles
 * creation ...: xx/xx/2007
 * revisions ..: $Id:$
---------------------------------------------------------------------*/
#include <iostream>
#include "aw_roadNetwork.h"

using namespace std;

namespace vlr {

namespace rndf {
Exit::Exit(uint32_t id, const string& strName) : NetElement(id, strName), m_exitFromWayPoint(NULL),
                                                     m_exitToWayPoint(NULL), m_exitFromPerimeterPoint(NULL),
                                                     m_exitToPerimeterPoint(NULL), m_exitType(LaneToLane) {
}

Exit::~Exit(void) {
}

void Exit::dump() const {
  cout << "  Exit " << name() << " ";
  if (m_exitType == LaneToLane)
    cout << m_exitFromWayPoint->name() << " " << m_exitToWayPoint->name();
  else if (m_exitType == LaneToPerimeter)
    cout << m_exitFromWayPoint->name() << " " << m_exitToPerimeterPoint->name();
  else if (m_exitType == PerimeterToLane)
    cout << m_exitFromPerimeterPoint->name() << " " << m_exitToWayPoint->name();
  else if (m_exitType == PerimeterToPerimeter) cout << m_exitFromPerimeterPoint->name() << " "
      << m_exitToPerimeterPoint->name();
  cout << endl;
}

// ASCII stream IO
std::ostream& operator<<(std::ostream& os, const Exit& e) {
  os << RNDF_EXIT << " ";
  if (e.m_exitType == Exit::LaneToLane)
    os << e.m_exitFromWayPoint->name() << " " << e.m_exitToWayPoint->name();
  else if (e.m_exitType == Exit::LaneToPerimeter)
    os << e.m_exitFromWayPoint->name() << " " << e.m_exitToPerimeterPoint->name();
  else if (e.m_exitType == Exit::PerimeterToLane)
    os << e.m_exitFromPerimeterPoint->name() << " " << e.m_exitToWayPoint->name();
  else if (e.m_exitType == Exit::PerimeterToPerimeter) os << e.m_exitFromPerimeterPoint->name() << " "
      << e.m_exitToPerimeterPoint->name();
  os << endl;
  return os;
}
}

} // namespace vlr

