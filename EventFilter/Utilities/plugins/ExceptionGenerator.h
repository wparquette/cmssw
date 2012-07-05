#include "TH1D.h"

#include <FWCore/Framework/interface/MakerMacros.h>
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <FWCore/Framework/interface/Event.h>
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "EventFilter/Utilities/interface/ModuleWeb.h"

#include <vector>
#include <string>

namespace xgi{
  class Input;
  class Output;
}

#include <string>

namespace evf{
    class ExceptionGenerator : public edm::EDAnalyzer, public evf::ModuleWeb
    {
    public:
      static const int menu_items = 14;
      static const std::string menu[menu_items];
						   
      explicit ExceptionGenerator( const edm::ParameterSet& );
      ~ExceptionGenerator(){};
      void beginJob();
      void beginRun(edm::Run& r, const edm::EventSetup& iSetup);
      void analyze(const edm::Event & e, const edm::EventSetup& c);
      void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      void defaultWebPage(xgi::Input *in, xgi::Output *out); 
      void publish(xdata::InfoSpace *);
      virtual void publishForkInfo(moduleweb::ForkInfoObj *forkInfoObj);
      
    private:
      int actionId_;
      unsigned int intqualifier_;
      std::string qualifier_;
      bool actionRequired_;
      std::string original_referrer_;
      TH1D* timingHisto_;
      timeval tv_start_;
    };
  }

