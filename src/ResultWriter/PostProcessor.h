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
    int m_numberOfVariables;
public:
    PostProcessor (): m_numberOfVariables(0) {
        for (size_t i = 0; i < 9; i++) {
            m_integrationMask[i] = false;
        }
    }
    virtual ~PostProcessor () {
    }
    void integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs);
    void setIntegrationMask(const int * const i_integrationMask);
    int getNumberOfVariables();
    const bool* getIntegrationMask();
};

}

}

#endif // POST_PROCESSOR_H
