#include "PostProcessor.h"
#include "SeisSol.h"

void seissol::writer::PostProcessor::integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs) {
	int count = 0;
	for(size_t i = 0; i < 9; i++) {
		if (m_integrationMask[i]) {
			io_integrals[count] += i_dofs[NUMBER_OF_ALIGNED_BASIS_FUNCTIONS*i]*i_timestep;
			count++;
		}
	}
}

void seissol::writer::PostProcessor::setIntegrationMask(const int * const i_integrationMask) {
	for (size_t i = 0; i < 9; i++) {
		m_integrationMask[i] = (bool)i_integrationMask[i];
		if (m_integrationMask[i]) {
			m_numberOfVariables++;
		}
	}
}

int seissol::writer::PostProcessor::getNumberOfVariables() {
	return m_numberOfVariables;
}

bool* seissol::writer::PostProcessor::getIntegrationMask() {
	return &m_integrationMask[0];
}
