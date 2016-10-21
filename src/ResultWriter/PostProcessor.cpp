#include "PostProcessor.h"
#include "SeisSol.h"

void integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs) {
	for( int i = 0; i < 9; i++ ) {
		io_integrals[i] += i_dofs[NUMBER_OF_ALIGNED_BASIS_FUNCTIONS*i]*i_timestep;
	}
}

void setIntegrationMask(const int * const i_integrationMask) {
	for (size_t i = 0; i < 9; i++) {
		m_integrationMask[i] = (bool)i_integrationMask[i];
	}
}
