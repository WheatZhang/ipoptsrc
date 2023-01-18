
// Authors:  Duo Zhang, Zhejiang University, 2023.01.17

#ifndef __IPHOMOTOPYUPDATE_HPP__
#define __IPHOMOTOPYUPDATE_HPP__

#include "IpAlgStrategy.hpp"

namespace Ipopt
{

class IPOPTLIB_EXPORT HomotopyUpdate: public AlgorithmStrategyObject
{
public:
   /**@name Constructors / Destructor */
   ///@{
   /** Default Constructor */
   HomotopyUpdate();

   /** Destructor */
   virtual ~HomotopyUpdate()
   { }
   ///@}

   virtual bool InitializeImpl(
      const OptionsList& options,
      const std::string& prefix
   ) = 0;

   /** Register the options for this class */
   static void RegisterOptions(
      const SmartPtr<RegisteredOptions>& roptions
   );

private:
   /**@name Default Compiler Generated Methods
    * (Hidden to avoid implicit creation/calling).
    *
    * These methods are not implemented and
    * we do not want the compiler to implement
    * them for us, so we declare them private
    * and do not define them. This ensures that
    * they will not be implicitly created/called.
    */
   ///@{
   /** Copy Constructor */
   HomotopyUpdate(
      const HomotopyUpdate&
   );

   /** Default Assignment Operator */
   void operator=(
      const HomotopyUpdate&
   );
   ///@}

};

} // namespace Ipopt

#endif
