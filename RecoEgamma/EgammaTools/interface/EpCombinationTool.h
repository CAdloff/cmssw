#ifndef RecoEgamma_EgammaTools_EpCombinationTool_h
#define RecoEgamma_EgammaTools_EpCombinationTool_h

#include "RecoEgamma/EgammaTools/interface/EgammaRegressionContainer.h"

#include <string>
#include <vector>
#include <utility>

namespace edm{
  class ParameterSet;
  class EventSetup;
}
namespace reco{
  class GsfElectron;
}

class EpCombinationTool
{
public:
  EpCombinationTool(const edm::ParameterSet& iConfig);
  ~EpCombinationTool(){}

  void setEventContent(const edm::EventSetup& iSetup);
  std::pair<float, float> combine(const reco::GsfElectron& electron) const;
  
  
private:
  EgammaRegressionContainer ecalTrkEnergyRegress_;
  EgammaRegressionContainer ecalTrkEnergyRegressUncert_;
  float maxEcalEnergyForComb_;
  float minEOverPForComb_;
  float maxEPDiffInSigmaForComb_;
  float maxRelTrkMomErrForComb_;
  
};


#endif
