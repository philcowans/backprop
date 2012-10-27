#include <cassert>

#include "Layer.hpp"

Layer *Layer::add_layer_above(Layer *pNewLayer) {
  assert(m_pConnectionAbove == NULL); // Currently only support adding to the top of the stack.

  m_pConnectionAbove = new Connection(this, pNewLayer);
  pNewLayer->set_connection_below(m_pConnectionAbove);

  return pNewLayer;
}

void Layer::set_connection_below(Connection *pConnectionBelow) {
  m_pConnectionBelow = pConnectionBelow;
}

void Layer::propagate_forward(gsl_matrix *pInput) {
  // Assign transformed input to outputs

  if(m_pConnectionAbove) {
    m_pConnectionAbove->propagate_forward(m_pOutput);
  }
}

void Layer::propagate_backward(gsl_matrix *pInputGradient) {
  // Need maths here

  if(m_pConnectionBelow) {
    m_pConnectionBelow->propagate_backward(...);
  }
}

void Layer::recursively_apply_deltas() {
  // Actually apply deltas here (update biases?)

  if(m_pConnectionAbove) {
    m_pConnectionAbove->recursively_apply_deltas();
  }
}

