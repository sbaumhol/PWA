#ifndef __Multipoles__
#define __Multipoles__

#include "Constants.h"
#include "Globals.h"
#include "Legendre.h"

//-----------------------------------------------------------------------------

//Multipoles
extern TComplex Ep[LBINS];
extern TComplex Em[LBINS];
extern TComplex Mp[LBINS];
extern TComplex Mm[LBINS];

//-----------------------------------------------------------------------------

inline Double_t q_mes(Double_t omega_lab)
{
  Double_t s = MASS2_INITIAL + 2.0*omega_lab*MASS_INITIAL;
  Double_t sqrt_s = Sqrt(s);
  Double_t epsilon = (s + MASS2_MESON - MASS2_FINAL)/(2.0*sqrt_s);
  if(epsilon < MASS_MESON) return 0.0;
  Double_t q = Sqrt(epsilon*epsilon - MASS2_MESON);

  //printf("w_lab = %f: q_mes = %f\n", omega_lab, q);
  return q;
}

//-----------------------------------------------------------------------------

inline Double_t q_pip(Double_t omega_lab)
{
  Double_t s = MASS2_PROTON + 2.0*omega_lab*MASS_PROTON;
  Double_t sqrt_s = Sqrt(s);
  Double_t epsilon = (s + MASS2_PIPLUS - MASS2_NEUTRON)/(2.0*sqrt_s);
  if(epsilon < MASS_PIPLUS) return 0.0;
  Double_t q = Sqrt(epsilon*epsilon - MASS2_PIPLUS);

  //printf("w_lab = %f: q_pi+ = %f\n", omega_lab, q);
  return q;
}

//-----------------------------------------------------------------------------

inline Double_t omega_cm(Double_t omega_lab)
{
  Double_t s = MASS2_INITIAL + 2.0*omega_lab*MASS_INITIAL;
  Double_t sqrt_s = Sqrt(s);
  Double_t omega = (s - MASS2_INITIAL)/(2.0*sqrt_s);

  //printf("w_lab = %f: w_cm = %f\n", omega_lab, omega);
  return omega;
}

//-----------------------------------------------------------------------------

inline Double_t omega_lab(Double_t W_cm)
{
  Double_t s = W_cm*W_cm;
  Double_t omega = (s - MASS2_INITIAL)/(2.0*MASS_INITIAL);

  //printf("w_lab = %f: W_cm = %f\n", omega, W_cm);
  return omega;
}

//-----------------------------------------------------------------------------

inline Double_t W_cm(Double_t omega_lab)
{
  Double_t s = MASS2_INITIAL + 2.0*omega_lab*MASS_INITIAL;
  Double_t sqrt_s = Sqrt(s);

  //printf("w_lab = %f: W_cm = %f\n", omega_lab, sqrt_s);
  return sqrt_s;
}

//-----------------------------------------------------------------------------

inline Double_t rho(Double_t Omega)
{
  Double_t q = q_mes(Omega);
  Double_t k = omega_cm(Omega);

  return (q/k);
}

//-----------------------------------------------------------------------------

inline Double_t W_thres()
{
  Double_t thres = (MASS2_FINAL + MASS2_MESON + 2.0*MASS_FINAL*MASS_MESON - MASS2_INITIAL)/(2.0*MASS_INITIAL);

  return thres;
}

//-----------------------------------------------------------------------------

inline Double_t ImE0p()
{
  return BETA*q_pip(gEnergy)/MASS_PIPLUS;
}

//-----------------------------------------------------------------------------

//CGLN amplitude F1 in expansion up to l_max
inline TComplex F1(Double_t CosTheta)
{
  TComplex Complex(0.0, 0.0);

  for(Int_t l=0; l<L_MAX+1; l++)
    Complex+=((Mp[l]*(1.0*l) + Ep[l]) * DL(l+1, CosTheta) + (Mm[l]*(1.0*l + 1.0) + Em[l]) * DL(l-1, CosTheta));

  return Complex;
}

//-----------------------------------------------------------------------------

//CGLN amplitude F2 in expansion up to l_max
inline TComplex F2(Double_t CosTheta)
{
  TComplex Complex(0.0, 0.0);

  for(Int_t l=1; l<L_MAX+1; l++)
    Complex+=((Mp[l]*(1.0*l + 1.0) + Mm[l]*(1.0*l)) * DL(l, CosTheta));

  return Complex;
}

//-----------------------------------------------------------------------------

//CGLN amplitude F3 in expansion up to l_max
inline TComplex F3(Double_t CosTheta)
{
  TComplex Complex(0.0, 0.0);

  for(Int_t l=1; l<L_MAX+1; l++)
    Complex+=((Ep[l] - Mp[l]) * D2L(l+1, CosTheta) + (Em[l] + Mm[l]) * D2L(l-1, CosTheta));

  return Complex;
}

//-----------------------------------------------------------------------------

//CGLN amplitude F4 in expansion up to l_max
inline TComplex F4(Double_t CosTheta)
{
  TComplex Complex(0.0, 0.0);

  for(Int_t l=2; l<L_MAX+1; l++)
    Complex+=((Mp[l] - Ep[l] - Mm[l] - Em[l]) * D2L(l, CosTheta));

  return Complex;
}

//-----------------------------------------------------------------------------

//Wrapper for explicit CGLN amplitudes F_i
inline TComplex F(Int_t i, Double_t CosTheta)
{
  switch(i)
  {
    case 1: return F1(CosTheta);
    case 2: return F2(CosTheta);
    case 3: return F3(CosTheta);
    case 4: return F4(CosTheta);
    default: return TComplex(0.0, 0.0);
  }
}

//-----------------------------------------------------------------------------

inline TComplex F1cc(Double_t CosTheta){ return TComplex::Conjugate(F1(CosTheta)); }
inline TComplex F2cc(Double_t CosTheta){ return TComplex::Conjugate(F2(CosTheta)); }
inline TComplex F3cc(Double_t CosTheta){ return TComplex::Conjugate(F3(CosTheta)); }
inline TComplex F4cc(Double_t CosTheta){ return TComplex::Conjugate(F4(CosTheta)); }

//-----------------------------------------------------------------------------

//Wrapper for explicit CGLN amplitudes F_i*
inline TComplex Fcc(Int_t i, Double_t CosTheta)
{
  switch(i)
  {
    case 1: return F1cc(CosTheta);
    case 2: return F2cc(CosTheta);
    case 3: return F3cc(CosTheta);
    case 4: return F4cc(CosTheta);
    default: return TComplex(0.0, 0.0);
  }
}

//-----------------------------------------------------------------------------

//Helicity amplitude H1 (transformed from CGLN amplitudes)
inline TComplex H1(Double_t CosTheta)
{
  Double_t SinTheta = Sqrt(1.0 - CosTheta*CosTheta);
  Double_t CosThetaHalf = Sqrt(0.5*(1.0 + CosTheta));
  Double_t Sqrt2 = Sqrt(2.0);

  return (-1.0/Sqrt2)*SinTheta*CosThetaHalf*(F3(CosTheta) + F4(CosTheta));
}

//-----------------------------------------------------------------------------

//Helicity amplitude H2 (transformed from CGLN amplitudes)
inline TComplex H2(Double_t CosTheta)
{
  Double_t CosThetaHalf = Sqrt(0.5*(1.0 + CosTheta));
  Double_t Sqrt2 = Sqrt(2.0);

  return Sqrt2*CosThetaHalf*((F2(CosTheta) - F1(CosTheta)) + 0.5*(1.0-CosTheta)*(F3(CosTheta) - F4(CosTheta)));
}

//-----------------------------------------------------------------------------

//Helicity amplitude H3 (transformed from CGLN amplitudes)
inline TComplex H3(Double_t CosTheta)
{
  Double_t SinTheta = Sqrt(1.0 - CosTheta*CosTheta);
  Double_t SinThetaHalf = Sqrt(0.5*(1.0 - CosTheta));
  Double_t Sqrt2 = Sqrt(2.0);

  return (+1.0/Sqrt2)*SinTheta*SinThetaHalf*(F3(CosTheta) - F4(CosTheta));
}

//-----------------------------------------------------------------------------

//Helicity amplitude H4 (transformed from CGLN amplitudes)
inline TComplex H4(Double_t CosTheta)
{
  Double_t SinThetaHalf = Sqrt(0.5*(1.0 - CosTheta));
  Double_t Sqrt2 = Sqrt(2.0);

  return Sqrt2*SinThetaHalf*((F1(CosTheta) + F2(CosTheta)) + 0.5*(1.0+CosTheta)*(F3(CosTheta) + F4(CosTheta)));
}

//-----------------------------------------------------------------------------

//Wrapper for explicit helicity amplitudes H_i
inline TComplex H(Int_t i, Double_t CosTheta)
{
  switch(i)
  {
    case 1: return H1(CosTheta);
    case 2: return H2(CosTheta);
    case 3: return H3(CosTheta);
    case 4: return H4(CosTheta);
    default: return TComplex(0.0, 0.0);
  }
}

//-----------------------------------------------------------------------------

inline TComplex H1cc(Double_t CosTheta){ return TComplex::Conjugate(H1(CosTheta)); }
inline TComplex H2cc(Double_t CosTheta){ return TComplex::Conjugate(H2(CosTheta)); }
inline TComplex H3cc(Double_t CosTheta){ return TComplex::Conjugate(H3(CosTheta)); }
inline TComplex H4cc(Double_t CosTheta){ return TComplex::Conjugate(H4(CosTheta)); }

//-----------------------------------------------------------------------------

//Wrapper for explicit helicity amplitudes H_i*
inline TComplex Hcc(Int_t i, Double_t CosTheta)
{
  switch(i)
  {
    case 1: return H1cc(CosTheta);
    case 2: return H2cc(CosTheta);
    case 3: return H3cc(CosTheta);
    case 4: return H4cc(CosTheta);
    default: return TComplex(0.0, 0.0);
  }
}

//-----------------------------------------------------------------------------

inline Double_t sigma0(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1(CosTheta).Rho2() + F2(CosTheta).Rho2()
                   + Sin2Theta*(0.5*F3(CosTheta).Rho2() + 0.5*F4(CosTheta).Rho2() + F2cc(CosTheta)*F3(CosTheta) + F1cc(CosTheta)*F4(CosTheta) + CosTheta*F3cc(CosTheta)*F4(CosTheta))
                   - 2.0*CosTheta*F1cc(CosTheta)*F2(CosTheta);

  return Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaS(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = 0.5*(F3(CosTheta).Rho2() + F4(CosTheta).Rho2()) + F2cc(CosTheta)*F3(CosTheta) + F1cc(CosTheta)*F4(CosTheta) + CosTheta*F3cc(CosTheta)*F4(CosTheta);
  return -Sin2Theta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaT(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta)
                   + CosTheta*(F1cc(CosTheta)*F4(CosTheta) - F2cc(CosTheta)*F3(CosTheta))
                   - Sin2Theta*F3cc(CosTheta)*F4(CosTheta);
  return SinTheta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaP(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = 2.0*F1cc(CosTheta)*F2(CosTheta) + F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta)
                   - CosTheta*(F2cc(CosTheta)*F3(CosTheta) - F1cc(CosTheta)*F4(CosTheta))
                   - Sin2Theta*F3cc(CosTheta)*F4(CosTheta);
  return -SinTheta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaH(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());

  TComplex Complex = 2.0*F1cc(CosTheta)*F2(CosTheta) + F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta)
                   + CosTheta*(F1cc(CosTheta)*F4(CosTheta) - F2cc(CosTheta)*F3(CosTheta));
  return SinTheta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaG(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F2cc(CosTheta)*F3(CosTheta) + F1cc(CosTheta)*F4(CosTheta);
  return Sin2Theta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaF(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());

  TComplex Complex = F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta)
                   - CosTheta*(F2cc(CosTheta)*F3(CosTheta) - F1cc(CosTheta)*F4(CosTheta));
  return SinTheta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaE(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1(CosTheta).Rho2() + F2(CosTheta).Rho2()
                   - 2.0*CosTheta*F1cc(CosTheta)*F2(CosTheta)
                   + Sin2Theta*(F2cc(CosTheta)*F3(CosTheta) + F1cc(CosTheta)*F4(CosTheta));
  return Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaCx(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());

  TComplex Complex = F1(CosTheta).Rho2() - F2(CosTheta).Rho2()
                   + F1cc(CosTheta)*F4(CosTheta) - F2cc(CosTheta)*F3(CosTheta)
                   + CosTheta*(F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta));
  return SinTheta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaCz(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = 2.0*F1cc(CosTheta)*F2(CosTheta)
                   + Sin2Theta*(F1cc(CosTheta)*F3(CosTheta) + F2cc(CosTheta)*F4(CosTheta))
                   - CosTheta*(F1(CosTheta).Rho2() + F2(CosTheta).Rho2());
  return Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaOx(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());

  TComplex Complex = F1cc(CosTheta)*F4(CosTheta) - F2cc(CosTheta)*F3(CosTheta)
                   + CosTheta*(F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta));
  return -SinTheta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaOz(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1cc(CosTheta)*F3(CosTheta) + F2cc(CosTheta)*F4(CosTheta);
  return -Sin2Theta*Complex.Im()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaLx(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1(CosTheta).Rho2() - F2(CosTheta).Rho2() - F2cc(CosTheta)*F3(CosTheta) + F1cc(CosTheta)*F4(CosTheta)
                   + 0.5*Sin2Theta*(F4(CosTheta).Rho2() - F3(CosTheta).Rho2())
                   + CosTheta*(F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta));
  return -SinTheta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaLz(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = 2.0*F1cc(CosTheta)*F2(CosTheta) - CosTheta*(F1(CosTheta).Rho2() + F2(CosTheta).Rho2())
                   + Sin2Theta*(F1cc(CosTheta)*F3(CosTheta) + F2cc(CosTheta)*F4(CosTheta) + F3cc(CosTheta)*F4(CosTheta))
                   + 0.5*CosTheta*Sin2Theta*(F3(CosTheta).Rho2() + F4(CosTheta).Rho2());
  return Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaTx(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1cc(CosTheta)*F3(CosTheta) + F2cc(CosTheta)*F4(CosTheta) + F3cc(CosTheta)*F4(CosTheta)
                   + 0.5*CosTheta*(F3(CosTheta).Rho2() + F4(CosTheta).Rho2());
  return -Sin2Theta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t sigmaTz(Double_t Theta, Double_t Omega)
{
  Double_t SinTheta = Sin(Theta*DegToRad());
  Double_t CosTheta = Cos(Theta*DegToRad());
  Double_t Sin2Theta = SinTheta*SinTheta;

  TComplex Complex = F1cc(CosTheta)*F4(CosTheta) - F2cc(CosTheta)*F3(CosTheta)
                   + CosTheta*(F1cc(CosTheta)*F3(CosTheta) - F2cc(CosTheta)*F4(CosTheta))
                   + 0.5*Sin2Theta*(F4(CosTheta).Rho2() - F3(CosTheta).Rho2());
  return SinTheta*Complex.Re()*rho(Omega)*UNIT;
}

//-----------------------------------------------------------------------------

inline Double_t S(Double_t Theta, Double_t Omega)
{
  return sigmaS(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t T(Double_t Theta, Double_t Omega)
{
  return sigmaT(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t P(Double_t Theta, Double_t Omega)
{
  return sigmaP(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t H(Double_t Theta, Double_t Omega)
{
  return sigmaH(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t G(Double_t Theta, Double_t Omega)
{
  return sigmaG(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t F(Double_t Theta, Double_t Omega)
{
  return sigmaF(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t E(Double_t Theta, Double_t Omega)
{
  return sigmaE(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Cx(Double_t Theta, Double_t Omega)
{
  return sigmaCx(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Cz(Double_t Theta, Double_t Omega)
{
  return sigmaCz(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Ox(Double_t Theta, Double_t Omega)
{
  return sigmaOx(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Oz(Double_t Theta, Double_t Omega)
{
  return sigmaOz(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Lx(Double_t Theta, Double_t Omega)
{
  return sigmaLx(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Lz(Double_t Theta, Double_t Omega)
{
  return sigmaLz(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Tx(Double_t Theta, Double_t Omega)
{
  return sigmaTx(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

inline Double_t Tz(Double_t Theta, Double_t Omega)
{
  return sigmaTz(Theta, Omega)/sigma0(Theta, Omega);
}

//-----------------------------------------------------------------------------

#endif
