// Golovkin Maksim
#pragma once

#include <boost/mpi/collectives.hpp>
#include <boost/mpi/communicator.hpp>
#include <functional>
#include <memory>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#include "core/task/include/task.hpp"

namespace golovkin_rowwise_matrix_partitioning {

class MPIMatrixMultiplicationTask : public ppc::core::Task {
 public:
  explicit MPIMatrixMultiplicationTask(std::shared_ptr<ppc::core::TaskData> inputData) : Task(std::move(inputData)) {};

  bool validation() override;
  bool pre_processing() override;
  bool run() override;
  bool post_processing() override;
  void gather_result();

 private:
  boost::mpi::communicator world;
  double* A = nullptr;
  double* B = nullptr;
  double* result = nullptr;
  int rows_A;
  int cols_A;
  int rows_B;
  int cols_B;

  void multiply_matrices();
};

}  // namespace golovkin_rowwise_matrix_partitioning