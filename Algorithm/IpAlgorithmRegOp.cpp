// Copyright (C) 2005, 2008 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Carl Laird, Andreas Waechter     IBM    2005-08-16

#include "IpAlgorithmRegOp.hpp"
#include "IpRegOptions.hpp"

#include "IpAdaptiveMuUpdate.hpp"
#include "IpAlgBuilder.hpp"
#include "IpDefaultIterateInitializer.hpp"
#include "IpBacktrackingLineSearch.hpp"
#include "IpFilterLSAcceptor.hpp"
#include "IpGradientScaling.hpp"
#include "IpEquilibrationScaling.hpp"
#include "IpIpoptAlg.hpp"
#include "IpIpoptCalculatedQuantities.hpp"
#include "IpIpoptData.hpp"
#include "IpMonotoneMuUpdate.hpp"
#include "IpNLPScaling.hpp"
#include "IpOptErrorConvCheck.hpp"
#include "IpOrigIpoptNLP.hpp"
#include "IpOrigIterationOutput.hpp"
#include "IpLimMemQuasiNewtonUpdater.hpp"
#include "IpPDFullSpaceSolver.hpp"
#include "IpPDPerturbationHandler.hpp"
#include "IpPDSearchDirCalc.hpp"
#include "IpPenaltyLSAcceptor.hpp"
#include "IpProbingMuOracle.hpp"
#include "IpQualityFunctionMuOracle.hpp"
#include "IpRestoConvCheck.hpp"
#include "IpRestoFilterConvCheck.hpp"
#include "IpRestoIpoptNLP.hpp"
#include "IpRestoMinC_1Nrm.hpp"
#include "IpRestoPenaltyConvCheck.hpp"
#include "IpWarmStartIterateInitializer.hpp"
// zhangduo added
#include "IpHomotopyUpdate.hpp"

namespace Ipopt
{

void RegisterOptions_Algorithm(
   const SmartPtr<RegisteredOptions>& roptions
)
{
   roptions->SetRegisteringCategory("Barrier Parameter Update");
   AdaptiveMuUpdate::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Initialization");
   DefaultIterateInitializer::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("");
   AlgorithmBuilder::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Line Search");
   BacktrackingLineSearch::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Line Search");
   FilterLSAcceptor::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Line Search");
   PenaltyLSAcceptor::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("NLP Scaling");
   StandardScalingBase::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("NLP Scaling");
   GradientScaling::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("NLP Scaling");
   EquilibrationScaling::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("");
   IpoptAlgorithm::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("");
   IpoptData::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("");
   IpoptCalculatedQuantities::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Hessian Approximation");
   LimMemQuasiNewtonUpdater::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Barrier Parameter Update");
   MonotoneMuUpdate::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Termination");
   OptimalityErrorConvergenceCheck::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("NLP");
   OrigIpoptNLP::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Output");
   OrigIterationOutput::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Step Calculation");
   PDSearchDirCalculator::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Step Calculation");
   PDFullSpaceSolver::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Step Calculation");
   PDPerturbationHandler::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Barrier Parameter Update");
   ProbingMuOracle::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Barrier Parameter Update");
   QualityFunctionMuOracle::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Restoration Phase");
   RestoConvergenceCheck::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Restoration Phase");
   RestoFilterConvergenceCheck::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Restoration Phase");
   RestoIpoptNLP::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Restoration Phase");
   RestoPenaltyConvergenceCheck::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Restoration Phase");
   MinC_1NrmRestorationPhase::RegisterOptions(roptions);
   roptions->SetRegisteringCategory("Warm Start");
   WarmStartIterateInitializer::RegisterOptions(roptions);
   // zhangduo added
   roptions->SetRegisteringCategory("Homotopy Update");
   HomotopyUpdate::RegisterOptions(roptions);
}

} // namespace Ipopt
