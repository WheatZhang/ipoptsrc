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
        "homotopy_l1_term_coeff",
        "Coefficient before the L1 homotopy penalty term.",
        100.,
        "This is the long describie. Line 1."
        "This is the long describie. Line 2.");

   roptions->AddNumberOption(
        "homotopy_l2_term_coeff",
        "Coefficient before the L2 homotopy penalty term.",
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
   first_iter_ = true;
   homotopy_finish_flag = false;
   options.GetNumericValue("homotopy_l1_term_coeff", homotopy_l1_term_coeff_, prefix);
   options.GetNumericValue("homotopy_l2_term_coeff", homotopy_l2_term_coeff_, prefix);
   options.GetNumericValue("homotopy_stepsize", homotopy_stepsize_, prefix);
   IpData().Set_homo_L1_weight(homotopy_l1_term_coeff_);
   IpData().Set_homo_L1_weight(homotopy_l2_term_coeff_);
   return true;
}

bool HomotopyUpdate::UpdateHomotopyParameter()
{
   bool distance_to_target;
   IpCq().curr_t()->Print(Jnlst(), J_VECTOR, J_HOMOTOPY, "original t unscaled");
   IpCq().curr_t_normalized()->Print(Jnlst(), J_VECTOR, J_HOMOTOPY, "original t scaled");

   if (!first_iter_)
   {
      SmartPtr<Vector> t_diff;
      t_diff = IpNLP().t_space()->MakeNew();
      t_diff->Copy(*(IpData().t_target_normalized()));
      t_diff->AddOneVector(-1.0, *(IpCq().curr_t_normalized()), 1.0);
      distance_to_target = t_diff->Nrm2();
      if (distance_to_target <= homotopy_stepsize_)
      {
         IpData().Set_t_target_normalized(IpNLP().t_destination());
         homotopy_finish_flag = true;
      }
      else
      {
         SmartPtr<Vector> new_t_target = IpNLP().t_space()->MakeNew();
         new_t_target->AddTwoVectors(1.0, *(IpCq().curr_t()), homotopy_stepsize_, *t_diff, 0.0);
         IpData().Set_t_target_normalized(new_t_target);
      }
   }
   else
   {
      IpData().Set_t_target_normalized(IpNLP().t_origin());
      first_iter_=false;
   }
   return true;
}

} // namespace Ipopt