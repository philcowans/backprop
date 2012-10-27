#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "Layer.hpp"

class Network {
  Network();

  void train_minbatch(gsl_matrix *pInput, gsl_matrix *pOutput);

private:
  Layer *m_pInputLayer;
  Layer *m_pOutputLayer;
};

#endif
