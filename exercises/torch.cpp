#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
  // Load the dataset
  MatrixXd X(4, 2);
  X << 1, 1, 1, 2, 2, 2, 2, 3;

  MatrixXd y(4, 1);
  y << 6, 9, 12, 15;

  // Train the linear regression model
  MatrixXd X_transpose = X.transpose();
  MatrixXd XTX = X_transpose * X;
  MatrixXd XTX_inv = XTX.inverse();
  MatrixXd theta = XTX_inv * X_transpose * y;

  // Print the learned parameters
  std::cout << "Learned parameters:" << std::endl;
  std::cout << "theta0 = " << theta(0) << std::endl;
  std::cout << "theta1 = " << theta(1) << std::endl;

  return 0;
}
