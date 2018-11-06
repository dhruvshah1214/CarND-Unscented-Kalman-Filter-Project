#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations, const vector<VectorXd> &ground_truth) {
    VectorXd rmse(4);
    rmse << 0,0,0,0;
    assert(estimations.size() > 0);
    assert(ground_truth.size() > 0);

    int n = estimations.size();
    assert(n == ground_truth.size());

    for(int i = 0; i < estimations.size(); i++){
      VectorXd d = estimations[i] - ground_truth[i];
      d = d.array()*d.array();
      rmse += d;
    }
    rmse = (rmse / n).array().sqrt();
    return rmse;
}
