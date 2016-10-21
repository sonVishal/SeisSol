#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

namespace seissol
{

namespace writer
{

class PostProcessor {
private:
    int m_integrationMask[9];
public:
    PostProcessor (){
    }
    virtual ~PostProcessor () {
    }
    void integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs);
};

}

}

#endif // POST_PROCESSOR_H
