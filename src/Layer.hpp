#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "Connection.hpp"

class Layer {
public:
  Layer *add_layer_above(Layer *pNewLayer);
  void set_connection_below(Connection *pConnectionBelow);
  void propagate_forward(gsl_matrix *pInput);
  void propagate_backward(gsl_matrix *pInputGradient);
  void recursively_apply_deltas();

private:
  Connection *m_pConnectionAbove;
  Connection *m_pConnectionBelow;

  gsl_matrix *m_pOutput;
};

#endif
