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


#ifndef _H_EMBER_SHMEM_ALLTOALL_EVENT
#define _H_EMBER_SHMEM_ALLTOALL_EVENT

#include "emberShmemEvent.h"

namespace SST {
namespace Ember {

class EmberAlltoallShmemEvent : public EmberShmemEvent {

public:
	EmberAlltoallShmemEvent( Shmem::Interface& api, Output* output,
               Hermes::Vaddr dest, Hermes::Vaddr src, size_t nelems,
               int PE_start, int logPE_stride, int PE_size, Hermes::Vaddr pSync,
                    EmberEventTimeStatistic* stat = NULL ) :
            EmberShmemEvent( api, output, stat ),
            m_dest(dest), m_src(src), m_nelems(nelems),
            m_pe_start(PE_start), m_stride( logPE_stride), m_size(PE_size), m_pSync(pSync) {}
	~EmberAlltoallShmemEvent() {}

    std::string getName() { return "Alltoall"; }

    void issue( uint64_t time, Shmem::Callback callback ) {

        EmberEvent::issue( time );
        m_api.alltoall( m_dest, m_src, m_nelems, m_pe_start, m_stride, m_size, m_pSync, callback );
    }
private:
    Hermes::Vaddr m_dest;
    Hermes::Vaddr m_src;
    size_t m_nelems;
    int m_pe_start;
    int m_stride;
    int m_size;
    Hermes::Vaddr m_pSync;
};

}
}

#endif
