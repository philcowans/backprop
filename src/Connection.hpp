#ifndef __CONNECTION_HPP__
#define __CONNECTION_HPP__

#include "Layer.hpp"

class Connection {
public:
  void propagate_forward(gsl_matrix *pInput);
  void propagate_backward(gsl_matrix *pSomething);
  void recursively_apply_deltas();

private:
  Layer *m_pLayerAbove;
  Layer *m_pLayerBelow;

  gsl_matrix *m_pOutput;
};

#endif
