#include "Network.hpp"

Network::Network() {
  m_pInputLayer = new Layer();
  m_pOutputLayer = m_pInputLayer;
  
  m_pOutputLayer = m_pOutputLayer->add_layer_above(new Layer());
  m_pOutputLayer = m_pOutputLayer->add_layer_above(new Layer());
  m_pOutputLayer = m_pOutputLayer->add_layer_above(new Layer());
}

Network::~Network() {
  while(m_pOutputLayer) {
    m_pOutputLayer = m_pOutputLayer->remove_from_above();
  }
}

void Network::train_minbatch(gsl_matrix *pInput, gsl_matrix *pOutput) {
  m_pInputLayer->propagate_forward(pInput);
  
  gsl_matrix *pErrorGradients;
  // Calaculate error gradeient from targets and network output
  m_pOutputLayer->propagate_backward(pErrorGradient);

  m_pInputLayer->recursively_apply_deltas();
}
