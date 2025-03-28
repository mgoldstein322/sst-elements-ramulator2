// Copyright 2009-2025 NTESS. Under the terms
// of Contract DE-NA0003525 with NTESS, the U.S.
// Government retains certain rights in this software.
//
// Copyright (c) 2009-2025, NTESS
// All rights reserved.
//
// Portions are copyright of other developers:
// See the file CONTRIBUTORS.TXT in the top level directory
// of the distribution for more information.
//
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.


#ifndef _H_EMBER_SHMEM_FREE_EVENT
#define _H_EMBER_SHMEM_FREE_EVENT

#include "emberShmemEvent.h"

namespace SST {
namespace Ember {

class EmberFreeShmemEvent : public EmberShmemEvent {

public:
	EmberFreeShmemEvent( Shmem::Interface& api, Output* output, Hermes::MemAddr val,
                    EmberEventTimeStatistic* stat = NULL ) :
            EmberShmemEvent( api, output, stat ), m_val(val) {}
	~EmberFreeShmemEvent() {}

    std::string getName() { return "Free"; }

    void issue( uint64_t time, Shmem::Callback callback ) {

        EmberEvent::issue( time );
        m_api.free( m_val, callback );
    }
private:
    Hermes::MemAddr m_val;
};

}
}

#endif
