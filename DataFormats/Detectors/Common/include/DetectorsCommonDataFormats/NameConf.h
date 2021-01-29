// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#ifndef ALICEO2_NAME_GENERATOR_H_
#define ALICEO2_NAME_GENERATOR_H_

#include "DetectorsCommonDataFormats/DetID.h"
#include "CommonUtils/StringUtils.h"
#include <string_view>

/// \file NameConf.h
/// \brief Definition of the Names Generator class
namespace o2
{
namespace base
{

// Class for standardization of the names for output files and trees
class NameConf
{
  using DId = o2::detectors::DetID;

 public:
  // Check if the path exists
  static bool pathExists(const std::string_view p);

  // Check if the path is a directory
  static bool pathIsDirectory(const std::string_view p);

  // Expand to full path
  static std::string getFullPath(const std::string_view p);

  // The Hits file name are generated by hardcoded schema, only prefix is mutable to allow the embedding
  static std::string getHitsFileName(o2::detectors::DetID d, const std::string_view prefix = STANDARDSIMPREFIX)
  {
    return o2::utils::concat_string(prefix, "_", HITS_STRING, d.getName(), ".root");
  }

  // The Digits file name are generated by hardcoded schema, only prefix is mutable to allow the embedding
  static std::string getDigitsFileName(o2::detectors::DetID d, const std::string_view prefix = STANDARDSIMPREFIX)
  {
    return o2::utils::concat_string(prefix, "_", DIGITS_STRING, d.getName(), ".root");
  }

  // Filename to store kinematics + TrackRefs
  static std::string getGRPFileName(const std::string_view prefix = STANDARDSIMPREFIX)
  {
    return o2::utils::concat_string(prefix, "_", GRP_STRING, ".root");
  }

  // Filename to store kinematics + TrackRefs
  static std::string getMCKinematicsFileName(const std::string_view prefix = STANDARDSIMPREFIX)
  {
    return o2::utils::concat_string(prefix, "_", KINE_STRING, ".root");
  }

  // Filename to store final MC configuration file
  static std::string getMCConfigFileName(const std::string_view prefix = STANDARDSIMPREFIX)
  {
    return o2::utils::concat_string(prefix, "_", CONFIG_STRING, ".ini");
  }

  // Filename to store geometry file
  static std::string getGeomFileName(const std::string_view prefix = "");

  // Filename to for decoding dictionaries
  static std::string getDictionaryFileName(DId det, const std::string_view prefix = "", const std::string_view ext = "");

  // Filename to store material LUT file
  static std::string getMatLUTFileName(const std::string_view prefix = "");

  // Filename to store summary about simulation processes and cut values
  static std::string getCutProcFileName(const std::string_view prefix = "");

  // TGeometry object name
  static constexpr std::string_view GEOMOBJECTNAME = "FAIRGeom"; // hardcoded

  // public standard TTree key (for MC ) -- not a function
  static constexpr std::string_view MCTTREENAME = "o2sim"; // hardcoded

  // standard name for digitization configuration output
  static constexpr std::string_view DIGITIZATIONCONFIGFILE = "o2simdigitizerworkflow_configuration.ini";

  // public standard CTF dictionary
  static constexpr std::string_view CTFDICT = "ctf_dictionary"; // hardcoded

  // Block for ITS/TPC matching
  static constexpr std::string_view TPCITS_TracksBranchName = "TPCITS";              ///< name of branch containing output matched tracks
  static constexpr std::string_view TPCITS_TPCMCTruthBranchName = "MatchTPCMCTruth"; ///< name of branch for output matched tracks TPC MC
  static constexpr std::string_view TPCITS_ITSMCTruthBranchName = "MatchITSMCTruth"; ///< name of branch for output matched tracks ITS MC

  // CTF tree name
  static constexpr std::string_view CTFTREENAME = "ctf"; // hardcoded

  // CTF Filename
  static std::string getCTFFileName(long id, const std::string_view prefix = "o2_ctf");

 private:
  // unmodifiable constants used to construct filenames etc
  static constexpr std::string_view STANDARDSIMPREFIX = "o2sim";
  static constexpr std::string_view HITS_STRING = "Hits";     // hardcoded
  static constexpr std::string_view DIGITS_STRING = "Digits"; // hardcoded
  static constexpr std::string_view GRP_STRING = "grp";       // hardcoded
  static constexpr std::string_view KINE_STRING = "Kine";     // hardcoded
  static constexpr std::string_view GEOM_FILE_STRING = "geometry";
  static constexpr std::string_view CUT_FILE_STRING = "proc-cut";
  static constexpr std::string_view CONFIG_STRING = "configuration";

  static constexpr std::string_view DICTFILENAME = "dictionary";
  static constexpr std::string_view MATBUDLUT = "matbud";
};

} // namespace base
} // namespace o2

#endif
