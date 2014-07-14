
//-----------------------------------------------------------------------------

Double_t sg0_val[EBINS][THBINS];
Double_t sg0_err[EBINS][THBINS];
Double_t sg0_th[EBINS][THBINS];
Double_t sg0_en[EBINS];
Double_t sg0_wt[EBINS];
Double_t sg0_sy[EBINS];
Int_t sg0_pts[EBINS];
Int_t sg0_bin;

//-----------------------------------------------------------------------------

Double_t sgS_val[EBINS][THBINS];
Double_t sgS_err[EBINS][THBINS];
Double_t sgS_th[EBINS][THBINS];
Double_t sgS_en[EBINS];
Double_t sgS_wt[EBINS];
Double_t sgS_sy[EBINS];
Int_t sgS_pts[EBINS];
Int_t sgS_bin;

Double_t S_val[EBINS][THBINS];
Double_t S_err[EBINS][THBINS];
Double_t S_th[EBINS][THBINS];
Double_t S_en[EBINS];
Double_t S_wt[EBINS];
Double_t S_sy[EBINS];
Int_t S_pts[EBINS];
Int_t S_bin;

//-----------------------------------------------------------------------------

Double_t sgT_val[EBINS][THBINS];
Double_t sgT_err[EBINS][THBINS];
Double_t sgT_th[EBINS][THBINS];
Double_t sgT_en[EBINS];
Double_t sgT_wt[EBINS];
Double_t sgT_sy[EBINS];
Int_t sgT_pts[EBINS];
Int_t sgT_bin;

Double_t T_val[EBINS][THBINS];
Double_t T_err[EBINS][THBINS];
Double_t T_th[EBINS][THBINS];
Double_t T_en[EBINS];
Double_t T_wt[EBINS];
Double_t T_sy[EBINS];
Int_t T_pts[EBINS];
Int_t T_bin;

//-----------------------------------------------------------------------------

Double_t sgP_val[EBINS][THBINS];
Double_t sgP_err[EBINS][THBINS];
Double_t sgP_th[EBINS][THBINS];
Double_t sgP_en[EBINS];
Double_t sgP_wt[EBINS];
Double_t sgP_sy[EBINS];
Int_t sgP_pts[EBINS];
Int_t sgP_bin;

Double_t P_val[EBINS][THBINS];
Double_t P_err[EBINS][THBINS];
Double_t P_th[EBINS][THBINS];
Double_t P_en[EBINS];
Double_t P_wt[EBINS];
Double_t P_sy[EBINS];
Int_t P_pts[EBINS];
Int_t P_bin;

//-----------------------------------------------------------------------------

Double_t sgF_val[EBINS][THBINS];
Double_t sgF_err[EBINS][THBINS];
Double_t sgF_th[EBINS][THBINS];
Double_t sgF_en[EBINS];
Double_t sgF_wt[EBINS];
Double_t sgF_sy[EBINS];
Int_t sgF_pts[EBINS];
Int_t sgF_bin;

Double_t F_val[EBINS][THBINS];
Double_t F_err[EBINS][THBINS];
Double_t F_th[EBINS][THBINS];
Double_t F_en[EBINS];
Double_t F_wt[EBINS];
Double_t F_sy[EBINS];
Int_t F_pts[EBINS];
Int_t F_bin;

//-----------------------------------------------------------------------------

Double_t sgE_val[EBINS][THBINS];
Double_t sgE_err[EBINS][THBINS];
Double_t sgE_th[EBINS][THBINS];
Double_t sgE_en[EBINS];
Double_t sgE_wt[EBINS];
Double_t sgE_sy[EBINS];
Int_t sgE_pts[EBINS];
Int_t sgE_bin;

Double_t E_val[EBINS][THBINS];
Double_t E_err[EBINS][THBINS];
Double_t E_th[EBINS][THBINS];
Double_t E_en[EBINS];
Double_t E_wt[EBINS];
Double_t E_sy[EBINS];
Int_t E_pts[EBINS];
Int_t E_bin;

//-----------------------------------------------------------------------------

Double_t sgG_val[EBINS][THBINS];
Double_t sgG_err[EBINS][THBINS];
Double_t sgG_th[EBINS][THBINS];
Double_t sgG_en[EBINS];
Double_t sgG_wt[EBINS];
Double_t sgG_sy[EBINS];
Int_t sgG_pts[EBINS];
Int_t sgG_bin;

Double_t G_val[EBINS][THBINS];
Double_t G_err[EBINS][THBINS];
Double_t G_th[EBINS][THBINS];
Double_t G_en[EBINS];
Double_t G_wt[EBINS];
Double_t G_sy[EBINS];
Int_t G_pts[EBINS];
Int_t G_bin;

//-----------------------------------------------------------------------------

Double_t sgH_val[EBINS][THBINS];
Double_t sgH_err[EBINS][THBINS];
Double_t sgH_th[EBINS][THBINS];
Double_t sgH_en[EBINS];
Double_t sgH_wt[EBINS];
Double_t sgH_sy[EBINS];
Int_t sgH_pts[EBINS];
Int_t sgH_bin;

Double_t H_val[EBINS][THBINS];
Double_t H_err[EBINS][THBINS];
Double_t H_th[EBINS][THBINS];
Double_t H_en[EBINS];
Double_t H_wt[EBINS];
Double_t H_sy[EBINS];
Int_t H_pts[EBINS];
Int_t H_bin;

//-----------------------------------------------------------------------------

TComplex maid_Ep[LBINS][EBINS];
TComplex maid_Em[LBINS][EBINS];
TComplex maid_Mp[LBINS][EBINS];
TComplex maid_Mm[LBINS][EBINS];
Double_t maid_en[EBINS];
Int_t maid_bin;

//-----------------------------------------------------------------------------

TComplex Ep[LBINS];
TComplex Em[LBINS];
TComplex Mp[LBINS];
TComplex Mm[LBINS];

TComplex DEp[LBINS];
TComplex DEm[LBINS];
TComplex DMp[LBINS];
TComplex DMm[LBINS];

Double_t f_obs[OBS];
Double_t Df_obs[OBS];

//-----------------------------------------------------------------------------

TMinuit* gMinuit;

//-----------------------------------------------------------------------------

Double_t gEnergy;

//-----------------------------------------------------------------------------

Double_t Fit_en[SOL][EBINS];
Double_t Fit_chi[SOL][EBINS];
Double_t Fit_pen[SOL][EBINS];
Double_t Fit_val[SOL][8*(LBINS-1)][EBINS];
Double_t Fit_err[SOL][8*(LBINS-1)][EBINS];
Int_t Fit_pts[SOL];
Double_t Model_en[EBINS];
Double_t Model_val[8*(LBINS-1)][EBINS];
Double_t Model_err[8*(LBINS-1)][EBINS];
Int_t Model_pts;

//-----------------------------------------------------------------------------

Bool_t FIX_EP[LBINS];
Bool_t FIX_EM[LBINS];
Bool_t FIX_MP[LBINS];
Bool_t FIX_MM[LBINS];
Bool_t FIX_IM_E0P;
Bool_t ONLY_CROSS_S;
Bool_t ONLY_CROSS_F;
Bool_t FIX_EP_PHASE[LBINS];
Bool_t FIX_EM_PHASE[LBINS];
Bool_t FIX_MP_PHASE[LBINS];
Bool_t FIX_MM_PHASE[LBINS];
Bool_t FIX_SCALES;
Bool_t PRINT_PENALTY;
Int_t ERROR_MODE;
Int_t PENALTY_MODE;
Int_t D_WAVES;
Int_t L_MAX;
Int_t ITERATIONS;
Int_t SOLUTIONS;
Double_t PENALTY[4];
Double_t SCALING;
Double_t VARIATION;
Double_t MIN_ENERGY;
Double_t MAX_ENERGY;
Double_t MASS_MESON;
Double_t MASS_INITIAL;
Double_t MASS_FINAL;
Double_t MASS2_MESON;
Double_t MASS2_INITIAL;
Double_t MASS2_FINAL;
Double_t THRESHOLD;
Double_t EPSILON;
Double_t EPSILON2;

//-----------------------------------------------------------------------------
