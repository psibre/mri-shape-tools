#ifndef __REGISTERED_EMA_DATA_H__
#define __REGISTERED_EMA_DATA_H__

#include <vector>

#include <armadillo>

class RegisteredEmaData{

public:

  std::vector<arma::vec> speakerWeights;
  std::vector<arma::vec> phonemeWeights;

  std::vector<double> timeStamps;

  double samplingFrequency;
  int boundarySize = 0;

};
#endif
