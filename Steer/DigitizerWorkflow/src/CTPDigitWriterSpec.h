// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
#ifndef STEER_DIGITIZERWORKFLOW_CTPDIGITWRITERSPEC_H
#define STEER_DIGITIZERWORKFLOW_CTPDIGITWRITERSPEC_H

#include "Framework/DataProcessorSpec.h"
#include "DPLUtils/MakeRootTreeWriterSpec.h"
#include "Framework/InputSpec.h"
#include "DataFormatsCTP/Digits.h"

namespace o2
{
namespace ctp
{

template <typename T>
using BranchDefinition = framework::MakeRootTreeWriterSpec::BranchDefinition<T>;

o2::framework::DataProcessorSpec getCTPDigitWriterSpec(bool mctruth)
{
  using InputSpec = framework::InputSpec;
  using MakeRootTreeWriterSpec = framework::MakeRootTreeWriterSpec;
  return MakeRootTreeWriterSpec("CTPDigitWriter",
                                "ctpdigits.root",
                                "o2sim",
                                BranchDefinition<std::vector<o2::ctp::CTPDigit>>{InputSpec{"digitBC", "CTP", "DIGITSBC"}, "CTPDIGITSBC"})();
}

} // namespace ctp
} // end namespace o2
#endif //STEER_DIGITIZERWORKFLOW_CTPDIGITWRITERSPEC_H
