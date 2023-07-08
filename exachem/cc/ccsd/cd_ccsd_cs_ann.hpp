/*
 * ExaChem: Open Source Exascale Computational Chemistry Software.
 *
 * Copyright 2023 NWChemEx-Project.
 * Copyright 2023 Pacific Northwest National Laboratory, Battelle Memorial Institute.
 *
 * See LICENSE.txt for details
 */

#pragma once

#include "ccsd_util.hpp"

using namespace tamm;

void cd_ccsd(std::string filename, OptionsMap options_map);

template<typename T>
void ccsd_e_cs(Scheduler& sch, const TiledIndexSpace& MO, const TiledIndexSpace& CI, Tensor<T>& de,
               const Tensor<T>& t1_aa, const Tensor<T>& t2_abab, const Tensor<T>& t2_aaaa,
               std::vector<CCSE_Tensors<T>>& f1_se, std::vector<CCSE_Tensors<T>>& chol3d_se);

template<typename T>
void ccsd_t1_cs(Scheduler& sch, const TiledIndexSpace& MO, const TiledIndexSpace& CI,
                Tensor<T>& i0_aa, const Tensor<T>& t1_aa, const Tensor<T>& t2_abab,
                std::vector<CCSE_Tensors<T>>& f1_se, std::vector<CCSE_Tensors<T>>& chol3d_se);

template<typename T>
void ccsd_t2_cs(Scheduler& sch, const TiledIndexSpace& MO, const TiledIndexSpace& CI,
                Tensor<T>& i0_abab, const Tensor<T>& t1_aa, Tensor<T>& t2_abab, Tensor<T>& t2_aaaa,
                std::vector<CCSE_Tensors<T>>& f1_se, std::vector<CCSE_Tensors<T>>& chol3d_se);

template<typename T>
std::tuple<double, double>
cd_ccsd_cs_driver(SystemData& sys_data, ExecutionContext& ec, const TiledIndexSpace& MO,
                  const TiledIndexSpace& CI, Tensor<T>& t1_aa, Tensor<T>& t2_abab, Tensor<T>& d_f1,
                  Tensor<T>& r1_aa, Tensor<T>& r2_abab, std::vector<Tensor<T>>& d_r1s,
                  std::vector<Tensor<T>>& d_r2s, std::vector<Tensor<T>>& d_t1s,
                  std::vector<Tensor<T>>& d_t2s, std::vector<T>& p_evl_sorted, Tensor<T>& cv3d,
                  Tensor<T> dt1_full, Tensor<T> dt2_full, bool ccsd_restart = false,
                  std::string out_fp = "", bool computeTData = false);