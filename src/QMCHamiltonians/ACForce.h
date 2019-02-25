//////////////////////////////////////////////////////////////////////////////////////
// This file is distributed under the University of Illinois/NCSA Open Source License.
// See LICENSE file in top directory for details.
//
// Copyright (c) 2019 Jeongnim Kim and QMCPACK developers.
//
// File developed by: Raymond Clay, Sandia National Laboratories
//
// File created by: Raymond Clay, rclay@sandia.gov, Sandia National Laboratories
//////////////////////////////////////////////////////////////////////////////////////
    
    
/**@file ACForce.h
 *@brief Declaration of ACForce, Assaraf-Caffarel ZVZB style force estimation.
 */
#ifndef QMCPLUSPLUS_ACFORCE_H
#define QMCPLUSPLUS_ACFORCE_H
#include "QMCHamiltonians/QMCHamiltonianBase.h"

namespace qmcplusplus
{
struct ACForce: public QMCHamiltonianBase
{
  /** Constructor **/
  ACForce(ParticleSet& source, ParticleSet& target, TrialWaveFunction& psi, QMCHamiltonian& H);
  /** Destructor **/
  ~ACForce(){};
  /** Copy constructor **/
  ACForce(const ACForce& ac){};
 
  /** I/O Routines */
  bool put(xmlNodePtr cur){return true;};
  bool get(std::ostream& os) const {return true;};

  /** Cloning **/
  QMCHamiltonianBase* makeClone(ParticleSet& qp, TrialWaveFunction& psi){return 0;};
  
  /** Initialization/assignment **/
  void resetTargetParticleSet(ParticleSet& P){};
  void addObservables(PropertySetType& plist, BufferType& collectables);
  void setObservables(PropertySetType& plist);
  void setParticlePropertyList(PropertySetType& plist, int offset);

  /** Evaluate **/
  Return_t evaluate(ParticleSet& P);  

};

}
#endif

