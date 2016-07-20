/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * custom_nvram_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The file contains nvram configuration default value.
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"

#include "nvram_enums.h"            /* NVRAM_CLEAN_FOLDER_FACTORY */
#include "custom_nvram_int_config.h"
#include "nvram_data_items.h"
#include "ccci_if.h" //for SBP ccci misc info
#include "ps_public_utility.h"
#include "nvram_interface.h"
#include "nvram_editor_data_item.h"

kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id);
#if defined (__MOD_IMC__)
static kal_bool nvram_custom_config_ims_profile(kal_uint32 sbp_id);
#endif /* __MOD_IMC__ */

#ifdef __VOLTE_SUPPORT__
kal_bool nvram_custom_config_vdm_ads_profile(kal_uint32 sbp_id);
#endif /* __VOLTE_SUPPORT__ */

#ifdef __LTE_RAT__
void custom_nvram_set_errc_band_para(kal_uint32 sbp_id);
void custom_nvram_set_errc_para(kal_uint32 sbp_id);
#endif

kal_bool nvram_custom_config_rrc_dynamic_cap(kal_uint32 sbp_id);
/*
 * Restore factory begin
 */

/*****************************************************************************
 * FUNCTION
 *  nvram_custom_get_max_record_size
 * DESCRIPTION
 *  Return the maximum record size, every nvram lid record size cannot bigger than this
 * PARAMETERS
 * RETURNS
 *  maximum record size
 *****************************************************************************/
kal_uint32 nvram_custom_max_record_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_lock_pattern
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_custom_lock_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS == __UNLOCKED__)
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_config
 * DESCRIPTION
 *  Pre-process nvram data items at nvram task init.
 *  This function will be always invoked at nvram task init, right after NVRAM initialization.
 *  User can pre-process nvram data items via using NVRMA external API here.
 *     nvram_external_write_data()
 *     nvram_external_read_data()
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
 
void custom_nvram_config(void)
{
#if !defined(L4_NOT_PRESENT) && !defined(__L4_TASK_DISABLE__)
    kal_uint32 sbp_id = 0;   
#ifdef __HIF_CCCI_SUPPORT__
    if (ccci_misc_data_feature_support(CCMSG_ID_MISCINFO_SBP_ID, 4, &sbp_id) == CCCI_MISC_INFO_SUPPORT)
#endif
    {
        custom_nvram_set_sbp_id(sbp_id);
    }
#endif /* !defined(L4_NOT_PRESENT) && !defined(__L4_TASK_DISABLE__) */
}
    
/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sbp_id
 * DESCRIPTION
 * similar to custom_nvram_config()
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
kal_bool custom_nvram_set_sbp_id(kal_uint32 sbp_id)
{
    nvram_ef_sbp_modem_config_struct *default_sbp_feature = NULL;
    nvram_ef_sbp_modem_config_struct sbp_feature_buf;
    nvram_ef_sbp_modem_data_config_struct *default_sbp_data = NULL;
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;

    /* CCCI_MISC_INFO_SUPPORT means AP has sent SBP ID to modem */
    if (NVRAM_DEFAULT_VALUE_POINT == 
        nvram_get_default_value(NVRAM_EF_SBP_MODEM_CONFIG_LID, 1, (kal_uint8**)&default_sbp_feature))
    {
        /* Reset to the default value first */
        kal_mem_cpy(&sbp_feature_buf, default_sbp_feature, sizeof(nvram_ef_sbp_modem_config_struct));
    }
    else
    {
        /* Read current settings in NVRAM */
        nvram_external_read_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                 1, 
                                 (kal_uint8*)&sbp_feature_buf, 
                                 NVRAM_EF_SBP_MODEM_CONFIG_SIZE);
    }
        
    if (NVRAM_DEFAULT_VALUE_POINT == 
        nvram_get_default_value(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 1, (kal_uint8**)&default_sbp_data))
    {
        /* Reset to the default value first */
        kal_mem_cpy(&sbp_data_buf, default_sbp_data, sizeof(nvram_ef_sbp_modem_data_config_struct));
    }
    else
    {
        /* Read current settings in NVRAM */
        nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                 1, 
                                 (kal_uint8*)&sbp_data_buf, 
                                 NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
    }
        
    sbp_feature_buf.sbp_mode = sbp_id;
    sbp_data_buf.sbp_mode = sbp_id;
    
    /* Update related NVRAM files if received SBP ID is not 0 */
    if (sbp_id != 0)
    {
        if (sbp_id == 1) //for CMCC
        {
            //sbp_set_md_feature(SBP_OP01_ROAMING_RAT_ORDER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_OP01_TEST_MODE_CONSIDER_SIM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_ALWAYS_CS_WHEN_2G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_ALWAYS_CS_WHEN_3G, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_EMM_IGNORE_MT_CS_WHEN_IMS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_T3212_OPTION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CMHK_CUSTOMIZE_EPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CMCC_VOLTE_FT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
//#if (defined(__CMCC_ROAMING_IMPROVEMENT__) || defined(__MT6735M_NEW_FEATURE__)) && defined(__UMTS_TDD128_MODE__)
#if defined(__UMTS_TDD128_MODE__)
            sbp_set_md_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
#endif
            sbp_set_md_feature(SBP_VDM_REDIAL_IMS_VT_TO_CS_VOICE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_RAC_CHANGE_VDP_WHEN_IMS_ONOFF, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			sbp_set_md_feature(SBP_CUSTOM_FPLMN_USED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
			
            sbp_set_md_feature(SBP_CMCC_SRVCC_CDRX_EHEN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SRVCC_STOP_UAS_MEAS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SRVCC_DRX_INC_GAP, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SRVCC_STOP_EAS_MEAS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

#if defined (__MOD_IMC__)
            nvram_custom_config_ims_profile(sbp_id);
#endif /* __MOD_IMC__ */            
        }
        else if (sbp_id == 3) //for Orange
        {
#ifdef __LTE_RAT__
            custom_nvram_set_errc_para(sbp_id);
#endif
            sbp_set_md_feature(SBP_HPPLMN_REGARDLESS_ANY_MCC, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ORANGE_H_PLUS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

#if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__)
            nvram_custom_config_rrc_dynamic_cap(sbp_id);
#endif
        }
        else if (sbp_id == 5) // for DTAG
        {
#ifndef L4_NOT_PRESENT
            kal_uint8 buf_smsal_common_param[NVRAM_EF_SMSAL_COMMON_PARAM_SIZE];
            nvram_ef_smsal_common_param_struct* pSmsal_common_param;
#endif
#ifdef __LTE_RAT__
	          custom_nvram_set_errc_para(sbp_id);
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R9__)
            nvram_custom_config_rrc_dynamic_cap(sbp_id);
#endif
#endif
#ifndef L4_NOT_PRESENT
            //Set SMS domain preference
            nvram_external_read_data(NVRAM_EF_SMSAL_COMMON_PARAM_LID,
                                     1,
                                     buf_smsal_common_param,
                                     NVRAM_EF_SMSAL_COMMON_PARAM_SIZE);
                                              
            pSmsal_common_param = (nvram_ef_smsal_common_param_struct*)buf_smsal_common_param;
            pSmsal_common_param->bearer_service = 2;

            nvram_external_write_data(NVRAM_EF_SMSAL_COMMON_PARAM_LID,
                                      1,
                                      buf_smsal_common_param,
                                      NVRAM_EF_SMSAL_COMMON_PARAM_SIZE);
            
#endif
            sbp_set_md_feature(SBP_L2_RANDOM_FILL_BIT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_NO_SUPPORT_A5_3, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_EUTRAN_MEAS_AND_REP_CAP, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

            sbp_set_md_feature_data(SBP_DATA_VAMOS, 0, (nvram_ef_sbp_modem_data_config_struct*) &sbp_data_buf); 
            sbp_set_md_feature_data(SBP_GERAN_TO_EUTRAN_SUPPORT_IN_GERAN_PTM, 1, (nvram_ef_sbp_modem_data_config_struct*) &sbp_data_buf);       	
        }
        else if (sbp_id == 6) //for Vodafone
        {
            nvram_ef_regional_phone_mode_struct regional_phone_mode;
            
            regional_phone_mode.mode = 1;
            nvram_external_write_data(NVRAM_EF_REGIONAL_PHONE_MODE_LID, 
                                      1, 
                                      (kal_uint8*)&regional_phone_mode, 
                                      NVRAM_EF_REGIONAL_PHONE_MODE_SIZE);
            
            sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

#if defined (__MOD_IMC__)
            nvram_custom_config_ims_profile(sbp_id);
#endif /* __MOD_IMC__ */            
        }
        else if (sbp_id == 7) //for AT&T
        {
#ifdef __LTE_RAT__
            custom_nvram_set_errc_para(sbp_id);
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R9__)
            nvram_custom_config_rrc_dynamic_cap(sbp_id);
#endif
#endif
            sbp_set_md_feature(SBP_USIM_CSP_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ENS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ENS_RAT_BALANCING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_AUTO_RETURN_PRE_RPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_RPLMN_FROM_GLOCI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_AT_ME_IDENTIFICATION_WITHOUT_HEADER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SAT_NO_EVDL_IN_SESSION, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_IMEI_LOCK_SUPPORT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_STAR_SHORT_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CUSTOMIZED_IDLE_STRING_AS_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_DISABLE_RETRY_ABNORMAL_LAI, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_NOT_TRY_ANOTHER_RAT_FOR_LU_ABNORMAL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SAT_REISSUE_REFRESH_AFTER_CALL_END, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_IS_ATT_CONN_REJ, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

            sbp_set_md_feature(SBP_IS_OP07, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_IMSI_DETACH_WHEN_MM_CONN_ACTIVE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_3G_CSG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_DISABLE_4G_CSG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_FINGERPRINT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);        
            sbp_set_md_feature(SBP_R11_COMB_BUT_EPS_ABNORMAL_HANDLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CSFB_REJECT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CONSERVATIVE_IPV4V6_FALLBACK_STRATEGY, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_TRY_CS_WHEN_2G_VOICE_CALL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_FALSE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_REPORT_CSG_LIST_IN_SIGNAL_DECREASING_ORDER, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_CLEAR_LOCI_WHEN_UICC_RESET, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if (sbp_id == 8) //for T-Mobile
        {
            sbp_set_md_feature(SBP_ATNT_HPPLMN_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMO_PLMN_MATCHING, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMO_ECC_NOTIFICATION_ENABLE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_USE_SM_QOS_SUBSCRIBED, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_EMR_REPORTING_WITH_SI2Q_BSIC_PARA, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_NOT_STAY_ON_FBLA_FOR_REG_PROV, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_NO_OPTIONAL_RAU_AFTER_CCO_FAILURE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMO_IRAT_SET_ACTIVE_FLAG, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            /* If require TMO SML support, please unmask the following code */
            //sbp_set_md_feature(SBP_TMO_REMOTE_SIM_LOCK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

            sbp_set_md_feature(SBP_AMR_WB_GSM, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_AMR_WB_UMTS, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_RELEASE_DEACTIVATING_BEARER_DURING_IRAT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_GSMA_NETWORK_ACCESS_CONTROL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_TMOUS_VOLTE_FT, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_SDM_RETRY_CS_WHEN_IMS_SEND_FAIL, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);

#if defined (__MOD_IMC__)
            /* TMO GBA flag checking in ISIM */
            sbp_set_md_feature(SBP_TMO_GBA, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            nvram_custom_config_ims_profile(sbp_id);
#endif /* __MOD_IMC__ */            

#ifdef __VOLTE_SUPPORT__
// update VDM ADS profile based on TMOUS requirement
            nvram_custom_config_vdm_ads_profile(sbp_id);
#endif /* __VOLTE_SUPPORT__ */
        }
		else if (sbp_id == 9) // for CT
		{
#ifdef __LTE_RAT__
              custom_nvram_set_errc_para(sbp_id);
#endif
            sbp_set_md_feature(SBP_OP09_SIM_LOCK, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
		}
        else if (sbp_id == 11) //for H3G
        {
            sbp_set_md_feature(SBP_PERMANENT_AUTO_SEL_MODE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_TRY_ABNORMAL_LAI_ONCE_MORE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_HPPLMN_1ST_ATTEMPT_ENHANCE, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
            sbp_set_md_feature(SBP_MM_SEARCH_HPLMN_BEFORE_RPLMN, KAL_TRUE, (nvram_ef_sbp_modem_config_struct*)&sbp_feature_buf);
        }
        else if(sbp_id == 50) //for Softbank
        {
#ifdef __LTE_RAT__
            custom_nvram_set_errc_para(sbp_id);
#endif
            /* ALPS02096485: SoftBank requests UE to set supportOfInterRATHOToEUTRAFDD
             * and supportOfInterRATHOToEUTRATDD to FALSE.
             */
#ifdef __LTE_RAT__
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R9__)
            nvram_custom_config_rrc_dynamic_cap(sbp_id);
#endif
#endif //LTE_RAT
        }
        else
        {
            /* incorect sbp id */
            return KAL_FALSE;
        }
        /* Write the new settings back to NVRAM */
        nvram_external_write_data(NVRAM_EF_SBP_MODEM_CONFIG_LID, 
                                  1, 
                                  (kal_uint8*)&sbp_feature_buf, 
                                  NVRAM_EF_SBP_MODEM_CONFIG_SIZE);
                                  
        nvram_external_write_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                  1, 
                                  (kal_uint8*)&sbp_data_buf, 
                                  NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);                          
    }
    else
    {
        /* incorect sbp id */
        return KAL_FALSE;
    }
        
    return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  nvram_custom_config_ims_profile
 * DESCRIPTION
 *  Pre-process nvram data items for IMS PROFILE at customer function.
 *  User can pre-process nvram data items using NVRAM external API here.
 *  nvram_external_write_data()
 *  nvram_external_read_data()
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
#if defined (__MOD_IMC__)
 static kal_bool nvram_custom_config_ims_profile(kal_uint32 sbp_id)
 {
    kal_uint8* nvram_read_buf_ptr = NULL;
    nvram_ef_ims_profile_record_struct* nvram_ims_profile_ptr = NULL; 
        
    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_IMS_PROFILE_SIZE);

    nvram_external_read_data(NVRAM_EF_IMS_PROFILE_LID, 
                             1, 
                             nvram_read_buf_ptr, 
                             NVRAM_EF_IMS_PROFILE_SIZE);
    
    nvram_ims_profile_ptr = (nvram_ef_ims_profile_record_struct*)nvram_read_buf_ptr;

    switch(sbp_id)
    {
        case 1: /* CMCC */
        {
            nvram_ims_profile_ptr->ua_config.operator_code             = 0x0001;      //operator_code = 1(CMCC)
            nvram_ims_profile_ptr->ua_config.UA_call_rej_by_user_code  = 603;
            nvram_ims_profile_ptr->ua_config.UA_call_no_resource_code  = 580;
            nvram_ims_profile_ptr->imc_config.resouce_retain_timer     = 0x00001770;  // 6000ms (6 seconds) 
            nvram_ims_profile_ptr->imc_config.mncmcc_pass_flag         = 1;
            strncpy ( nvram_ims_profile_ptr->imc_config.mncmcc_whitelist,  
                    "210200346020234602073460227346023034602313460233346020130013001300130003000",    //<num><mnc_len><MNC><mcc_len><MCC>
                    sizeof (nvram_ims_profile_ptr->imc_config.mncmcc_whitelist)
                    );
            
            break;
        }
        case 6: /* Vodafone */
        {
            nvram_ims_profile_ptr->ua_config.operator_code                     = 0x0006;      //operator_code = 6(VDF)
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_TCP_MTU_Size    = 1500;
            break;
        }
        case 8: /* TMOUS */
        {
            nvram_ims_profile_ptr->ua_config.UA_call_session_timer   = 0x00000708;  // UA_call_session_timer = 1800
            nvram_ims_profile_ptr->ua_config.operator_code           = 0x0008;      //operator_code = 8(TMOUS)
            nvram_ims_profile_ptr->ua_config.local_sip_protocol_type = 0x00;        // local_sip_protocol_type = 2(UDP/TCP)                    

            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_TCP_On_Demand = 1;
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_TCP_MTU_Size  = 1300;
            nvram_ims_profile_ptr->ua_config.UA_call_mo_invite_to_bw_cnf_time = 10;
            nvram_ims_profile_ptr->ua_config.UA_call_def_max_ptime = 80;


            strncpy ( nvram_ims_profile_ptr->ua_config.user_agent,  
                      "T-Mobile VoLTE MTK/0.0.9 K2", 
                      sizeof (nvram_ims_profile_ptr->ua_config.user_agent)
                    );

            strncpy ( nvram_ims_profile_ptr->ua_config.UA_conf_factory_uri,  
                      "sip:+18881112663@msg.pc.t-mobile.com", 
                      sizeof (nvram_ims_profile_ptr->ua_config.UA_conf_factory_uri)
                    );

            nvram_ims_profile_ptr->imc_config.resouce_retain_timer   = 0x00001388;  // resource_retain_timer = 5000ms (5 seconds)                    
            break;
        }
        case 100: /* CSL */
        {
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            break;
        }
        case 101: /* PCCW */
        {
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            break;
        }
        case 102: /* SMT */
        {
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            break;
        }
        case 103: /* SingTel */
        {
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            break;
        }
        case 106: /* 3HK */
        {
            nvram_ims_profile_ptr->ua_config.VoLTE_Setting_SIP_Force_Use_UDP = 1;
            break;
        }
        default:
        {
            break;
        }
    }

    nvram_external_write_data(NVRAM_EF_IMS_PROFILE_LID, 
                              1, 
                              nvram_read_buf_ptr, 
                              NVRAM_EF_IMS_PROFILE_SIZE);

    // Free allocated buffer
    free_ctrl_buffer(nvram_read_buf_ptr);
    nvram_read_buf_ptr = NULL;


    return KAL_FALSE;
 }
 #endif /* __MOD_IMC__ */

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_sms_bearer_preference_sbp
 * DESCRIPTION
 * Set SMS bearer preference in nvram
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void custom_nvram_set_sms_bearer_preference_sbp(kal_uint8 bearer_service)
{
#ifndef L4_NOT_PRESENT
	kal_uint8 buf_smsal_common_param[NVRAM_EF_SMSAL_COMMON_PARAM_SIZE];
	nvram_ef_smsal_common_param_struct* pSmsal_common_param;

	//Set SMS domain preference
	nvram_external_read_data(NVRAM_EF_SMSAL_COMMON_PARAM_LID,
							 1,
							 buf_smsal_common_param,
							 NVRAM_EF_SMSAL_COMMON_PARAM_SIZE);
	
	pSmsal_common_param = (nvram_ef_smsal_common_param_struct*)buf_smsal_common_param;
	pSmsal_common_param->bearer_service = bearer_service;
	
	nvram_external_write_data(NVRAM_EF_SMSAL_COMMON_PARAM_LID,
							  1,
							  buf_smsal_common_param,
							  NVRAM_EF_SMSAL_COMMON_PARAM_SIZE);
#endif
}

#ifdef __VOLTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  nvram_custom_config_vdm_ads_profile
 * DESCRIPTION
 *  Pre-process nvram data items for VDM ADS PROFILE at customer function.
 *  User can pre-process nvram data items using NVRAM external API here.
 *  nvram_external_write_data()
 *  nvram_external_read_data()
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
kal_bool nvram_custom_config_vdm_ads_profile(kal_uint32 sbp_id)
{
    kal_bool is_nvram_need_update = KAL_FALSE;
    kal_uint8* nvram_read_buf_ptr = NULL;
    nvram_ef_vdm_ads_profile_struct* nvram_vdm_ads_profile_ptr = NULL;


    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_VDM_ADS_PROFILE_SIZE);


    // Read NVRAM setting
    nvram_external_read_data(NVRAM_EF_VDM_ADS_PROFILE_LID,
                             1,
                             nvram_read_buf_ptr,
                             NVRAM_EF_VDM_ADS_PROFILE_SIZE);

    nvram_vdm_ads_profile_ptr = (nvram_ef_vdm_ads_profile_struct*)nvram_read_buf_ptr;

    switch (sbp_id)
    {
        case 8: /* TMOUS */
            // Disallow IMS emergency call with negative IMS voice over PS session indicator
            nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_eutran = 0;
            nvram_vdm_ads_profile_ptr->profile_emerg.general_setting_emerg.allow_ims_with_negative_imsvops_utran = 0;

            // Prefer CS domain for emergency call in limited service
            nvram_vdm_ads_profile_ptr->profile_emerg.prefer_ims_in_lte_limited_srv = 0;

            // Update flag
            is_nvram_need_update = KAL_TRUE;
            break;

        default:
            // No need to update NVRAM
            is_nvram_need_update = KAL_FALSE;
            break;
    }

    // Update NVRAM setting if needed
    if (is_nvram_need_update == KAL_TRUE)
    {
        nvram_external_write_data(NVRAM_EF_VDM_ADS_PROFILE_LID,
                                  1,
                                  nvram_read_buf_ptr,
                                  NVRAM_EF_VDM_ADS_PROFILE_SIZE);
    }

    // Free allocated buffer
    if (nvram_read_buf_ptr != NULL)
    {
        free_ctrl_buffer(nvram_read_buf_ptr);
        nvram_read_buf_ptr = NULL;
    }

    return is_nvram_need_update;
}
#endif /* __VOLTE_SUPPORT__ */


#ifdef __LTE_RAT__
/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_errc_band_para
 * DESCRIPTION
 * Set Eas band parameter in nvram
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  none
 *****************************************************************************/

void custom_nvram_set_errc_band_para(kal_uint32 sbp_id)
{
    nvram_ef_as_band_setting_struct* pAs_band;

    switch (sbp_id)
      {
          case 7:  //for AT&T

              /* turn off TDD bands */

              pAs_band = get_ctrl_buffer(sizeof(nvram_ef_as_band_setting_struct));
              memset(pAs_band,0,sizeof(nvram_ef_as_band_setting_struct));

              nvram_external_read_data(NVRAM_EF_AS_BAND_SETTING_LID,1, pAs_band,  NVRAM_EF_AS_BAND_SETTING_SIZE);

              pAs_band->lte_band[4] = 0x00;
              pAs_band->lte_band[5] = 0x00;
              pAs_band->lte_band[6] = 0x00;
              pAs_band->lte_band[7] = 0x00;
                          
              nvram_external_write_data(NVRAM_EF_AS_BAND_SETTING_LID, 1, pAs_band, NVRAM_EF_AS_BAND_SETTING_SIZE);
              free_ctrl_buffer(pAs_band);

              break;
      
          default:
              // No need to update NVRAM
              break;
      }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_errc_para
 * DESCRIPTION
 * Set ERRC para in nvram
 * PARAMETERS
 *  sbp_id
 * RETURNS
 *  none
 *****************************************************************************/
void custom_nvram_set_errc_para(kal_uint32 sbp_id)
{
    kal_uint8 *buf_performance;
	kal_uint8 *buf_eutra_cap_csfb;
    kal_uint8 *buf_eutra_cap_mmdc;
        
    if (sbp_id == 3) //for Orange
    {
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        nvram_ef_ue_eutra_cap_struct* pEutra_cap;        
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        /* modify ERRC_PERFORMANCE_PARA_LID */
		nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;
		
		//disable 3G AFR
        pERRC_performance_para->csfb_enhancement_item_status &= 0xEF;

		nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);

		/* set ORG specific FGI */
		nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        pEutra_cap = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap->feature_group_ind_fdd = 0x5D0FFE80;
		pEutra_cap->feature_group_ind_tdd = 0x5D0FFE80;

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        free_ctrl_buffer(buf_performance);
        free_ctrl_buffer(buf_eutra_cap_csfb);
    }
    else if (sbp_id == 5) // for DTAG
    {
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);
        
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                 1,
                                 buf_eutra_cap_csfb,
                                 NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
                    
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                 1,
                                 buf_eutra_cap_mmdc,
                                 NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);
        
        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap_csfb->feature_group_ind_fdd = 0x2F8FF6B8;
        pEutra_cap_csfb->feature_group_ind_add_r9_fdd = 0xE0000000;
        pEutra_cap_csfb->phylayer_param.ue_specific_ref_sigs = 0;
        pEutra_cap_csfb->phylayer_param_v920.enhancedDualLayerFDD_r9 = 0;
        pEutra_cap_csfb->son_param_r9.rach_Report_r9 = 0;
        
        pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;
        pEutra_cap_mmdc->feature_group_ind_fdd = 0x2F8FF6B8;
        pEutra_cap_mmdc->feature_group_ind_add_r9_fdd = 0xE0000000;
        pEutra_cap_mmdc->phylayer_param.ue_specific_ref_sigs = 0;
        pEutra_cap_mmdc->phylayer_param_v920.enhancedDualLayerFDD_r9 = 0;
        pEutra_cap_mmdc->son_param_r9.rach_Report_r9 = 0;
        
        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                  1,
                                  buf_eutra_cap_csfb,
                                  NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
                    
        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                  1,
                                  buf_eutra_cap_mmdc,
                                  NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_csfb);
        free_ctrl_buffer(buf_eutra_cap_mmdc);
    }
    else if (sbp_id == 7) //for AT&T
    {
        nvram_ef_errc_performance_para_struct* pERRC_performance_para;
        nvram_ef_ue_eutra_cap_struct* pEutra_cap;
        buf_performance = get_ctrl_buffer(NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
        
        /* modify ERRC_PERFORMANCE_PARA_LID */
        nvram_external_read_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        
        pERRC_performance_para = (nvram_ef_errc_performance_para_struct*)buf_performance;
        
        //disable AFR
        pERRC_performance_para->csfb_enhancement_item_status &= 0xE7;
        
        //adjust 'bar cell' mechanism
        pERRC_performance_para->trach = 6;
        pERRC_performance_para->max_kraerr = 5;
        pERRC_performance_para->traerr = 60;
        pERRC_performance_para->tvalid_raerr = 80;
        
        nvram_external_write_data(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
                                1,
                                buf_performance,
                                NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE);
        /*turn off TDD bands */
        custom_nvram_set_errc_band_para(sbp_id);
        
        /* enable MFBI */
        //set FGI bit 31 to 1
        nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
        
        pEutra_cap = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap->feature_group_ind_fdd |= 0x00000002;
        pEutra_cap->feature_group_ind_tdd |= 0x00000002;
        
        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);

        free_ctrl_buffer(buf_performance);
        free_ctrl_buffer(buf_eutra_cap_csfb);
    }
	else if (sbp_id == 9) // for CT
	{
	    nvram_ef_ue_eutra_cap_struct* pEutra_cap_csfb;
        nvram_ef_ue_eutra_cap_struct* pEutra_cap_mmdc;
        buf_eutra_cap_csfb = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
        buf_eutra_cap_mmdc = get_ctrl_buffer(NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);
		
		/* disable ue-SpecificRefSigsSupported */
		nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
		nvram_external_read_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                1,
                                buf_eutra_cap_mmdc,
                                NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        pEutra_cap_csfb = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_csfb;
        pEutra_cap_csfb->phylayer_param.ue_specific_ref_sigs = 0;
		pEutra_cap_mmdc = (nvram_ef_ue_eutra_cap_struct*)buf_eutra_cap_mmdc;
        pEutra_cap_mmdc->phylayer_param.ue_specific_ref_sigs = 0;

        nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
                                1,
                                buf_eutra_cap_csfb,
                                NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE);
		
		nvram_external_write_data(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
                                1,
                                buf_eutra_cap_mmdc,
                                NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE);

        free_ctrl_buffer(buf_eutra_cap_csfb);
        free_ctrl_buffer(buf_eutra_cap_mmdc);
	}
}
#endif

kal_bool nvram_custom_config_rrc_dynamic_cap(kal_uint32 sbp_id)
{
    kal_uint8* nvram_read_buf_ptr = NULL;
    nvram_ef_umts_usime_rrc_dynamic_struct* pUMTS_USIME_RRC_dynamic_cap;
    kal_bool is_nvram_need_update = KAL_FALSE;


    // Allocate buffer to read NVRAM setting
    nvram_read_buf_ptr = (kal_uint8*)get_ctrl_buffer(sizeof(kal_uint8) * NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);


    // Read NVRAM setting
    nvram_external_read_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                             1,
                             nvram_read_buf_ptr,
                             NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);
    pUMTS_USIME_RRC_dynamic_cap = (nvram_ef_umts_usime_rrc_dynamic_struct*)nvram_read_buf_ptr;


    switch (sbp_id)
    {
        case 3: /* Orange */
            pUMTS_USIME_RRC_dynamic_cap->rrce_feature_cap |= 0x10;  
           
            is_nvram_need_update = KAL_TRUE;
            break;
#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R9__)
        case 5: /* DTAG */
            pUMTS_USIME_RRC_dynamic_cap->r7_cap2 &= 0xFE; //set r7_cap2 bit 1 to 0
            pUMTS_USIME_RRC_dynamic_cap->r8_cap1 &= 0xF7; //set r8_cap1 bit 4 to 0
            pUMTS_USIME_RRC_dynamic_cap->r8_cap2 &= 0x7F; //set r8_cap2 bit 8 to 0

            is_nvram_need_update = KAL_TRUE;
            break;
        case 7: /* AT&T */
            pUMTS_USIME_RRC_dynamic_cap->r9_cap1 |= 0x04;

            is_nvram_need_update = KAL_TRUE;
            break;       
        case 50: /* Softbank */
            pUMTS_USIME_RRC_dynamic_cap->r8_cap1 &= 0xF7; //set r8_cap1 bit 4 to 0
            pUMTS_USIME_RRC_dynamic_cap->r8_cap2 &= 0x7F; //set r8_cap2 bit 8 to 0

            is_nvram_need_update = KAL_TRUE;
            break;                  
#endif
        default:
            // No need to update NVRAM
            is_nvram_need_update = KAL_FALSE;
            break;
    }

    // Update NVRAM setting if needed
    if (is_nvram_need_update == KAL_TRUE)
    {
        nvram_external_write_data(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
                                  1,
                                  nvram_read_buf_ptr,
                                  NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE);
    }

    // Free allocated buffer
    if (nvram_read_buf_ptr != NULL)
    {
        free_ctrl_buffer(nvram_read_buf_ptr);
        nvram_read_buf_ptr = NULL;
    }

    return is_nvram_need_update;
}

#endif /* NVRAM_NOT_PRESENT */
