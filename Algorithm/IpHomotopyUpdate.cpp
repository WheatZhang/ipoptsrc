// Authors:  Duo Zhang, Zhejiang University, 2023.01.17

#include "IpHomotopyUpdate.hpp"

namespace Ipopt
{
void HomotopyUpdate::RegisterOptions(
   const SmartPtr<RegisteredOptions>& roptions
)
{
   roptions->SetRegisteringCategory("Homotopy Update");

   roptions->AddNumberOption(
        "homotopy_term_coeff",
        "Coefficient before the quadratic homotopy term.",
        100.,
        "This is the long describie. Line 1."
        "This is the long describie. Line 2.");

   roptions->AddNumberOption(
        "homotopy_stepsize",
        "Homotopy stepsize \\in (0,1)",
        0.1,
        "This is the long describie. Line 1."
        "This is the long describie. Line 2.");
}

bool HomotopyUpdate::InitializeImpl(
   const OptionsList& options,
   const std::string& prefix
)
{
   options.GetNumericValue("homotopy_term_coeff", homotopy_term_coeff_, prefix);
   options.GetNumericValue("homotopy_stepsize", homotopy_stepsize_, prefix);
   return true;
}

} // namespace Ipopt