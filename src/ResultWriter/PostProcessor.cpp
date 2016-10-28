#include "PostProcessor.h"
#include "SeisSol.h"

void seissol::writer::PostProcessor::integrateQuantities(const double i_timestep, double* io_integrals, double* i_dofs) {
	unsigned int nextId = 0;
	for( unsigned int i = 0; i < 9; i++ ) {
		if (m_integrationMask[i]) {
			io_integrals[nextId] += i_dofs[NUMBER_OF_ALIGNED_BASIS_FUNCTIONS*i]*i_timestep;
			nextId++;
		}
	}
}

void seissol::writer::PostProcessor::setIntegrationMask(const int * const i_integrationMask) {
	for (unsigned int i = 0; i < 9; i++) {
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
	return m_integrationMask;
}
