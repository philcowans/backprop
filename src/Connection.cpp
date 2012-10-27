#include "Connection.hpp"

void Connection::propagate_forward(gsl_matrix *pInput) {
  // Assign transformed input to output

  m_pLayerAbove->propagate_forward(m_pOutput);
}

void Coonection:propagate_backward(gsl_matrix *pSomething) {
  // Transform here (just linear?)

  m_pLayerBelow->propagate_backward(...);
}

void Connection:recursively_apply_deltas() {
  // Perform update (weigts this time)

  m_pLayerAbove->recursively_apply_deltas();
}

