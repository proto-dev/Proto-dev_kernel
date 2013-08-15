#ifndef __CUST_PANTECH_MMP_H__
#define __CUST_PANTECH_MMP_H__

/*
  2011/03/02 �ǿ���
  PANTECH multimedia ���� ���� ���� �ֻ��� feature.
  ���� feature�� �����ϱ� ����� �κ� �Ǵ� multimedia���� �ҽ��� �ƴ� �κ���
  �����ϴ� ��� ���. (make file ���� ��� #�ּ� �κп� �߰�)
*/
#define FEATURE_PANTECH_MMP

/*
  2011/03/02 �ǿ���
  VisuialOn VOME engine���� /external/vome/... ���� �κ��� �����ϰų�
  VisualOn �ҽ��� �Ϻ� �����ؼ� ����ϴ� �κп� ���� feature�۾�
*/
#define FEATURE_PANTECH_MMP_VOME
/*****************************************************************/
/*
   2012/04/03 Heekyoung Seo.
   VisualOn Engine Enable Features..
*/
#define FEATURE_PANTECH_MMP_VOME_AVI
#define FEATURE_PANTECH_MMP_VOME_ASF
#define FEATURE_PANTECH_MMP_VOME_MKV
/*#define FEATURE_PANTECH_MMP_VOME_FLAC // Using Stagefrightplayer */
#define FEATURE_PANTECH_MMP_VOME_QTIME

/*#define FEATURE_PANTECH_MMP_VOME_RTSP // We don't use this feature, now.
RTSP Engine is hard coded by apk team in MediaPlayerService.cpp*/

#define FEATURE_PANTECH_MMP_VOME_DLNA

#if defined(T_STARQ)
#define FEATURE_PANTECH_MMP_VOME_ADPCM_WAV
#endif
/******************************************************************/

/* 
  2011/03/10 �ֺ���
  QualComm Patch ������ �κп� ���� frature �۾�
*/
#define FEATURE_PANTECH_MMP_QCOM_CR

/* 
  2011/03/11 �ǿ���
  StageFright ���� �����ϴ� �κе��� ã�� ���� �ϱ� ���� ���
*/
#define FEATURE_PANTECH_MMP_STAGEFRIGHT
 
/*
  2011/05/13 Heekyoung Seo
  Add Qualcomm VC-1 Patch.
  Fis timeStamp order is up so down with a few WMV8 streams.
  */
#define FEATURE_PANTECH_MMP_VC1_DEC_PATCH

#if (MODEL_ID == MODEL_EF35L)
#define FEATURE_PANTECH_MMP_LGT
#endif


/*
 2011/06/26 �ֺ���

 TestSBA_M8260AAABQNLZA3040_Pantech_EF33S-EF34K_05252011_Case00518255

 Qcom H/W Dec�� ����Ͽ� XivD ���� ����� ȭ���� �ϱ׷����� ������ �ذ��ϱ� ���� Test SBA
 
 ( simple profile B-frame )
 */
#define FEATURE_PANTECH_MMP_XVID_QCOM_HWDEC_SBA

/*
 2011/07/12 �ֺ���

 SBA_M8660AAABQNLYA109020_Pantech_EF33S_07122011_Case00522374_00522374

 */
#define FEATURE_PANTECH_MMP_QCOM_SBA_TIMESTAMP

/*
  2012/05/08 hjkim
  Support widevine for EF34K/35L
  Widevine uses the SF player
*/
#define FEATURE_WIDEVINE_VISUALON


/*
  2011/mm/dd who
  ...description...
*/
#define FEATURE_PANTECH_MMP_xxx

/*
  2011/mm/dd who
  ...description...
*/
#define FEATURE_PANTECH_MMP_zzz


#endif/* __CUST_PANTECH_MMP_H__ */
