// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include <vector>

#include "Framework/DataProcessorSpec.h"
#include "Framework/Task.h"
#include "DataFormatsCTP/Digits.h"
//#include "CPVReconstruction/RawDecoder.h"

namespace o2
{

namespace ctp
{

namespace reco_workflow
{

/// \class RawToDigitConverterSpec
/// \brief Coverter task for Raw data to CTP digits
/// \author Roman Lietava from CPV example
///
class RawToDigitConverterSpec : public framework::Task
{
 public:
  /// \brief Constructor
  /// \param propagateMC If true the MCTruthContainer is propagated to the output
  RawToDigitConverterSpec() : framework::Task(){};

  /// \brief Destructor
  ~RawToDigitConverterSpec() override = default;

  /// \brief Initializing the RawToDigitConverterSpec
  /// \param ctx Init context
  void init(framework::InitContext& ctx) final;

  /// \brief Run conversion of raw data to cells
  /// \param ctx Processing context
  ///
  /// The following branches are linked:
  /// Input RawData: {"ROUT", "RAWDATA", 0, Lifetime::Timeframe}
  /// Output cells: {"CPV", "CELLS", 0, Lifetime::Timeframe}
  /// Output cells trigger record: {"CPV", "CELLSTR", 0, Lifetime::Timeframe}
  /// Output HW errors: {"CPV", "RAWHWERRORS", 0, Lifetime::Timeframe}
  void run(framework::ProcessingContext& ctx) final;

 protected:
  /// \brief simple check of HW address
  char CheckHWAddress(short ddl, short hwAddress, short& fee);

 private:
};

/// \brief Creating DataProcessorSpec for the CPV Cell Converter Spec
///
/// Refer to RawToDigitConverterSpec::run for input and output specs
o2::framework::DataProcessorSpec getRawToDigitConverterSpec();

} // namespace reco_workflow

} // namespace ctp

} // namespace o2
