#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <vector>

namespace seissol
{

namespace writer
{

class PostProcessor {
private:
    bool m_integrationMask[9];
public:
    PostProcessor (){
    }
    virtual ~PostProcessor () {
    }
    void integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs);
    void setIntegrationMask(const int * const i_integrationMask);
};

}

}

#endif // POST_PROCESSOR_H
