// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file Digits2Raw.h
/// \brief Digits  tw Raw translation
/// \author Roman Lietava

#ifndef ALICEO2_CTP_DIGITS2RAW_H_
#define ALICEO2_CTP_DIGITS2RAW_H_

#include "DetectorsRaw/RawFileWriter.h"
#include "DataFormatsCTP/Configuration.h"
#include "DataFormatsCTP/Digits.h"
#include "TRandom.h"
#include "DetectorsRaw/RawFileWriter.h"
#include "DetectorsRaw/RDHUtils.h"
#include "DetectorsRaw/HBFUtils.h"
#include "CCDB/BasicCCDBManager.h"


namespace o2
{
namespace ctp
{
class Digits2Raw
{
 public:
  static constexpr uint32_t NGBT=80;
  Digits2Raw() = default;
  ~Digits2Raw() = default;
  void init();
  void setCCDBServer(const std::string& server) {mCCDBServer = server;}
  void setVerbosity(int v) { mVerbosity = v; }
  void setFilePerLink(bool v) { mOutputPerLink = v; }
  bool getFilePerLink() const { return mOutputPerLink; }
  void setOutDir(const std::string& outDir){mOutDir = outDir;}
  void processDigits(const std::string& fileDigitsName);
  void emptyHBFMethod(const header::RDHAny* rdh, std::vector<char>& toAdd) const;
  std::vector<char> digits2HBTPayload(const gsl::span<std::bitset<NGBT>> digits, uint32_t Npld) const; 
  bool makeGBTWord(const std::bitset<NGBT> &pld,std::bitset<NGBT> &gbtword, uint32_t& size_gbt, uint32_t Npld) const;
  int digit2GBTdigit(std::bitset<NGBT>& gbtdigit, const CTPDigit& digit);
 private:  
  // CTP configuration 
  std::string mCCDBServer="http://ccdb-test.cern.ch:8080";  
  CTPConfiguration* mCTPConfiguration = nullptr; 
  //std::vector<CTPInput> *mInputs = nullptr;
  // Raw Writer
  o2::raw::RawFileWriter mWriter{"CTP"};
  int mVerbosity = 0;
  bool mOutputPerLink = false;
  uint16_t mCruID = 0;
  uint32_t mEndPointID = 0;
  uint64_t mFeeID = 0;
  std::string mOutDir;
  uint32_t mActiveLink = -1;
  // CTP specific
  const int mNLinks=2;
  const uint32_t CRULinkIDIntRec = 0;
  const uint32_t NIntRecPayload = 48+12;
  bool mZeroSuppressedIntRec = false;
  const uint32_t CRULinkIDClassRec = 1;
  const uint32_t NClassPayload = 64+12;
  bool mZeroSuppressedClassRec = true;
  //constexpr uint32_t CTPCRULinkIDMisc = 2;
  ClassDefNV(Digits2Raw, 1);
};
} // namespace ctp
} // namespace o2   
#endif //_CTP_DIGITS2RAW_H_
