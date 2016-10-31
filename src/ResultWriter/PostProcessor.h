#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <vector>
#include <Initializer/tree/Layer.hpp>
#include <Initializer/tree/LTSTree.hpp>

namespace seissol
{

namespace writer
{

class PostProcessor {
private:
    bool m_integrationMask[9];
    int m_numberOfVariables;
    std::vector<int> m_integerMap;
    Variable<real> m_integrals;
public:
    PostProcessor (): m_numberOfVariables(0), m_integerMap(0L) {
        for (size_t i = 0; i < 9; i++) {
            m_integrationMask[i] = false;
        }
    }
    virtual ~PostProcessor () {
        // TODO: Take care of cleaning up m_integrals
    }
    void integrateQuantities(const double i_timestep,
    	seissol::initializers::Layer& i_layerData, const unsigned int l_cell,
    	const double * const i_dofs);
    void setIntegrationMask(const int * const i_integrationMask);
    int getNumberOfVariables();
    bool* getIntegrationMask();
    void allocateMemory(LTSTree* ltsTree);
    const double* getIntegrals(LTSTree* ltsTree);
};

}

}

#endif // POST_PROCESSOR_H
