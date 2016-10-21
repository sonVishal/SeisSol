#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

namespace seissol
{

namespace writer
{

class PostProcessor {
private:
    int m_tmp;
public:
    PostProcessor ():m_tmp(-1){
    }
    virtual ~PostProcessor () {
        m_tmp = 0;
    }
    void integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs);
};

}

}

#endif // POST_PROCESSOR_H
