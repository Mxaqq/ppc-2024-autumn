// Golovkin Maksim
#pragma once

#include <boost/mpi/communicator.hpp>
#include <memory>
#include <vector>

#include "core/task/include/task.hpp"

namespace golovkin_integration_rectangular_method {

class MPIIntegralCalculator : public ppc::core::Task {
 public:
  explicit MPIIntegralCalculator(std::shared_ptr<ppc::core::TaskData> taskData);

  bool validation() override;      // �������� ������� ������
  bool pre_processing() override;  // ��������������� ��������� ������
  bool run() override;             // ���������� ���������� � �������������� MPI
  bool post_processing() override;  // ����-��������� ����������� � ������ ��������� ��������

 private:
  boost::mpi::communicator world;  
  std::shared_ptr<ppc::core::TaskData> taskData;
  double a, b, epsilon;  
  int cnt_of_splits;
  double h;
  double local_res;   // ��������� ��������� ��� ������� ��������
  double global_res;  // ���������� ���������, ���������� �� �������� 0

  double function_square(double x);  // ������� ��� ��������������
};

}  // namespace golovkin_integration_rectangular_method